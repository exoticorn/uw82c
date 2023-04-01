#include "platform.h"
#include "cart.h"
#include "wasm-rt-impl.h"
#include <math.h>
#include <SDL2/SDL.h>

#define MATH1(name) \
f32 Z_envZ_##name(struct Z_env_instance_t* i, f32 v) { \
  return name##f(v); \
}
#define MATH2(name) \
f32 Z_envZ_##name(struct Z_env_instance_t* i, f32 a, f32 b) { \
  return name##f(a, b); \
}
MATH1(acos); MATH1(asin); MATH1(atan); MATH2(atan2);
MATH1(cos); MATH1(sin); MATH1(tan);
MATH1(exp); MATH2(pow);
void Z_envZ_logChar(struct Z_env_instance_t* i, u32 c) {}

u32 reservedGlobal;
#define G_RESERVED(n) u32* Z_envZ_g_reserved##n(struct Z_env_instance_t* i) { return &reservedGlobal; }
G_RESERVED(0); G_RESERVED(1); G_RESERVED(2); G_RESERVED(3);
G_RESERVED(4); G_RESERVED(5); G_RESERVED(6); G_RESERVED(7);
G_RESERVED(8); G_RESERVED(9); G_RESERVED(10); G_RESERVED(11);
G_RESERVED(12); G_RESERVED(13); G_RESERVED(14); G_RESERVED(15);
wasm_rt_memory_t* Z_envZ_memory(struct Z_env_instance_t* i) { return i->Z_envZ_memory; }

const uint32_t uw8buttonScanCodes[] = {
  SDL_SCANCODE_UP, SDL_SCANCODE_DOWN, SDL_SCANCODE_LEFT, SDL_SCANCODE_RIGHT,
  SDL_SCANCODE_Z, SDL_SCANCODE_X, SDL_SCANCODE_A, SDL_SCANCODE_S
};

__attribute__((weak)) void Z_cartZ_upd(Z_cart_instance_t* i) {};
__attribute__((weak)) float Z_cartZ_snd(Z_cart_instance_t* i, uint32_t s) {
  return Z_envZ_sndGes(i->Z_env_instance, s);
}

typedef struct AudioState {
  wasm_rt_memory_t memory;
  Z_env_instance_t platformInstance;
  Z_cart_instance_t cartInstance;
  uint8_t registers[32];
  uint32_t sampleIndex;
} AudioState;

void audioCallback(void* userdata, Uint8* stream, int len) {
  AudioState* pState = (AudioState*)userdata;
  float* pSamples = (float*)stream;
  int numSamples = len / sizeof(float);
  memcpy(pState->memory.data + 0x50, pState->registers, 32);
  for(int i = 0; i < numSamples; ++i) {
    *pSamples++ = Z_cartZ_snd(&pState->cartInstance, pState->sampleIndex++);
  }
}

int main() {
  wasm_rt_init();
  wasm_rt_memory_t memory;
  wasm_rt_allocate_memory(&memory, 4, 4);
  Z_env_instance_t platformInstance;
  platformInstance.Z_envZ_memory = &memory;
  Z_env_init_module();
  Z_env_instantiate(&platformInstance, &platformInstance);
  Z_cart_instance_t cartInstance;
  Z_cart_init_module();
  Z_cart_instantiate(&cartInstance, &platformInstance);

  AudioState audioState;
  wasm_rt_allocate_memory(&audioState.memory, 4, 4);
  audioState.platformInstance.Z_envZ_memory = &audioState.memory;
  Z_env_instantiate(&audioState.platformInstance, &audioState.platformInstance);
  Z_cart_instantiate(&audioState.cartInstance, &audioState.platformInstance);
  memcpy(audioState.registers, memory.data + 0x50, 32);
  audioState.sampleIndex = 0;

  SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
  SDL_Window* window;
  SDL_Renderer* renderer;
  SDL_CreateWindowAndRenderer(640, 480, SDL_WINDOW_RESIZABLE, &window, &renderer);
  SDL_RenderSetLogicalSize(renderer, 320, 240);
  SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STREAMING, 320, 240);

  uint32_t* pixels32 = malloc(320*240*4);

  SDL_AudioSpec audioSpec;
  audioSpec.freq = 44100;
  audioSpec.format = AUDIO_F32SYS;
  audioSpec.channels = 2;
  audioSpec.samples = 256;
  audioSpec.callback = audioCallback;
  audioSpec.userdata = &audioState;
  SDL_AudioDeviceID audioDevice = SDL_OpenAudioDevice(NULL, 0, &audioSpec, &audioSpec, 0);
  SDL_PauseAudioDevice(audioDevice, 0);

  uint32_t startTime = SDL_GetTicks();

  for( ;; ) {
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
      switch(event.type) {
      case SDL_QUIT:
        exit(0);
      }
    }

    uint32_t time = SDL_GetTicks() - startTime;
    *(uint32_t*)(memory.data + 64) = time;

    int numKeys;
    const Uint8* keyState = SDL_GetKeyboardState(&numKeys);
    uint8_t buttons = 0;
    for(int i = 0; i < 8; ++i) {
      if(keyState[uw8buttonScanCodes[i]]) {
        buttons |= 1 << i;
      }
    }
    memory.data[0x44] = buttons;
    
    Z_cartZ_upd(&cartInstance);
    memcpy(audioState.registers, memory.data + 0x50, 32);

    uint32_t* palette = (uint32_t*)(memory.data + 0x13000);
    uint8_t* pixels = memory.data + 120;
    for(uint32_t i = 0; i < 320*240; ++i) {
      pixels32[i] = palette[pixels[i]];
    }
    SDL_UpdateTexture(texture, NULL, pixels32, 320*4);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);

    uint32_t frame = (uint32_t)((uint64_t)time * 60 / 1000);
    uint32_t offset = time - (uint32_t)((uint64_t)frame * 1000 / 60);
    uint32_t nextFrameTime = (uint32_t)((uint64_t)(frame + 1) * 1000 / 60 + (offset < 4 ? offset : 4));
    uint32_t delay = startTime + nextFrameTime - SDL_GetTicks();
    if(delay < 33) {
      SDL_Delay(delay);
    }
  }

  return 0;
}
