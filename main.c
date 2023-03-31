#include "platform.h"
#include "cart.h"
#include "wasm-rt-impl.h"
#include <math.h>
#include <SDL2/SDL.h>

f32 Z_envZ_acos(struct Z_env_instance_t* i, f32 v) {
  return acosf(v);
}

f32 Z_envZ_asin(struct Z_env_instance_t* i, f32 v) {
  return asinf(v);
}

f32 Z_envZ_atan(struct Z_env_instance_t* i, f32 v) {
  return atanf(v);
}

f32 Z_envZ_atan2(struct Z_env_instance_t* i, f32 a, f32 b) {
  return atan2f(a, b);
}

f32 Z_envZ_cos(struct Z_env_instance_t* i, f32 v) {
  return cosf(v);
}

f32 Z_envZ_exp(struct Z_env_instance_t* i, f32 v) {
  return expf(v);
}

f32 Z_envZ_pow(struct Z_env_instance_t* i, f32 a, f32 b) {
  return powf(a, b);
}

f32 Z_envZ_sin(struct Z_env_instance_t* i, f32 v) {
  return sinf(v);
}

f32 Z_envZ_tan(struct Z_env_instance_t* i, f32 v) {
  return tanf(v);
}

void Z_envZ_logChar(struct Z_env_instance_t* i, u32 c) {
}

u32 dummyGlobal;

u32* Z_envZ_g_reserved0(struct Z_env_instance_t* i) { return &dummyGlobal; }
u32* Z_envZ_g_reserved1(struct Z_env_instance_t* i) { return &dummyGlobal; }
u32* Z_envZ_g_reserved2(struct Z_env_instance_t* i) { return &dummyGlobal; }
u32* Z_envZ_g_reserved3(struct Z_env_instance_t* i) { return &dummyGlobal; }
u32* Z_envZ_g_reserved4(struct Z_env_instance_t* i) { return &dummyGlobal; }
u32* Z_envZ_g_reserved5(struct Z_env_instance_t* i) { return &dummyGlobal; }
u32* Z_envZ_g_reserved6(struct Z_env_instance_t* i) { return &dummyGlobal; }
u32* Z_envZ_g_reserved7(struct Z_env_instance_t* i) { return &dummyGlobal; }
u32* Z_envZ_g_reserved8(struct Z_env_instance_t* i) { return &dummyGlobal; }
u32* Z_envZ_g_reserved9(struct Z_env_instance_t* i) { return &dummyGlobal; }
u32* Z_envZ_g_reserved10(struct Z_env_instance_t* i) { return &dummyGlobal; }
u32* Z_envZ_g_reserved11(struct Z_env_instance_t* i) { return &dummyGlobal; }
u32* Z_envZ_g_reserved12(struct Z_env_instance_t* i) { return &dummyGlobal; }
u32* Z_envZ_g_reserved13(struct Z_env_instance_t* i) { return &dummyGlobal; }
u32* Z_envZ_g_reserved14(struct Z_env_instance_t* i) { return &dummyGlobal; }
u32* Z_envZ_g_reserved15(struct Z_env_instance_t* i) { return &dummyGlobal; }
wasm_rt_memory_t* Z_envZ_memory(struct Z_env_instance_t* i) { return i->Z_envZ_memory; }

const uint32_t uw8buttonScanCodes[] = {
  SDL_SCANCODE_UP,
  SDL_SCANCODE_DOWN,
  SDL_SCANCODE_LEFT,
  SDL_SCANCODE_RIGHT,
  SDL_SCANCODE_Z,
  SDL_SCANCODE_X,
  SDL_SCANCODE_A,
  SDL_SCANCODE_S
};

int main() {
  wasm_rt_init();

  wasm_rt_memory_t mainMemory;
  wasm_rt_allocate_memory(&mainMemory, 4, 4);
  Z_env_instance_t platformInstance;
  platformInstance.Z_envZ_memory = &mainMemory;
  Z_env_init_module();
  Z_env_instantiate(&platformInstance, &platformInstance);
  Z_cart_instance_t cartInstance;
  Z_cart_init_module();
  Z_cart_instantiate(&cartInstance, &platformInstance);

  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window* window;
  SDL_Renderer* renderer;
  SDL_CreateWindowAndRenderer(320, 240, SDL_WINDOW_RESIZABLE, &window, &renderer);
  SDL_RenderSetLogicalSize(renderer, 320, 240);
  SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STREAMING, 320, 240);

  uint32_t* pixels32 = malloc(320*240*4);

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

    *(uint32_t*)(mainMemory.data + 64) = time;

    int numKeys;
    const Uint8* keyState = SDL_GetKeyboardState(&numKeys);
    uint8_t buttons = 0;
    for(int i = 0; i < 8; ++i) {
      if(keyState[uw8buttonScanCodes[i]]) {
        buttons |= 1 << i;
      }
    }
    mainMemory.data[0x44] = buttons;
    
    Z_cartZ_upd(&cartInstance);

    uint32_t* palette = (uint32_t*)(mainMemory.data + 0x13000);
    uint8_t* pixels = mainMemory.data + 120;
    for(uint32_t i = 0; i < 320*240; ++i) {
      pixels32[i] = palette[pixels[i]];
    }
    SDL_UpdateTexture(texture, NULL, pixels32, 320*4);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);

    uint32_t frame = (uint32_t)((uint64_t)time * 60 / 1000);
    uint32_t nextFrameTime = (uint32_t)((uint64_t)(frame + 1) * 1000 / 60 + 4);
    uint32_t delay = startTime + nextFrameTime - SDL_GetTicks();
    if(delay < 17) {
      SDL_Delay(delay);
    }
  }

  return 0;
}
