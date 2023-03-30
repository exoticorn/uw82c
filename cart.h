/* Automatically generated by wasm2c */
#ifndef CART_H_GENERATED_
#define CART_H_GENERATED_

#include <stdint.h>

#include "wasm-rt.h"

/* TODO(binji): only use stdint.h types in header */
#ifndef WASM_RT_CORE_TYPES_DEFINED
#define WASM_RT_CORE_TYPES_DEFINED
typedef uint8_t u8;
typedef int8_t s8;
typedef uint16_t u16;
typedef int16_t s16;
typedef uint32_t u32;
typedef int32_t s32;
typedef uint64_t u64;
typedef int64_t s64;
typedef float f32;
typedef double f64;
#endif

#ifdef __cplusplus
extern "C" {
#endif

struct Z_env_instance_t;
extern u32* Z_envZ_g_reserved0(struct Z_env_instance_t*);
extern u32* Z_envZ_g_reserved1(struct Z_env_instance_t*);
extern u32* Z_envZ_g_reserved10(struct Z_env_instance_t*);
extern u32* Z_envZ_g_reserved11(struct Z_env_instance_t*);
extern u32* Z_envZ_g_reserved12(struct Z_env_instance_t*);
extern u32* Z_envZ_g_reserved13(struct Z_env_instance_t*);
extern u32* Z_envZ_g_reserved14(struct Z_env_instance_t*);
extern u32* Z_envZ_g_reserved15(struct Z_env_instance_t*);
extern u32* Z_envZ_g_reserved2(struct Z_env_instance_t*);
extern u32* Z_envZ_g_reserved3(struct Z_env_instance_t*);
extern u32* Z_envZ_g_reserved4(struct Z_env_instance_t*);
extern u32* Z_envZ_g_reserved5(struct Z_env_instance_t*);
extern u32* Z_envZ_g_reserved6(struct Z_env_instance_t*);
extern u32* Z_envZ_g_reserved7(struct Z_env_instance_t*);
extern u32* Z_envZ_g_reserved8(struct Z_env_instance_t*);
extern u32* Z_envZ_g_reserved9(struct Z_env_instance_t*);
extern wasm_rt_memory_t* Z_envZ_memory(struct Z_env_instance_t*);

typedef struct Z_cart_instance_t {
  struct Z_env_instance_t* Z_env_instance;
  /* import: 'env' 'g_reserved0' */
  u32 *Z_envZ_g_reserved0;
  /* import: 'env' 'g_reserved1' */
  u32 *Z_envZ_g_reserved1;
  /* import: 'env' 'g_reserved10' */
  u32 *Z_envZ_g_reserved10;
  /* import: 'env' 'g_reserved11' */
  u32 *Z_envZ_g_reserved11;
  /* import: 'env' 'g_reserved12' */
  u32 *Z_envZ_g_reserved12;
  /* import: 'env' 'g_reserved13' */
  u32 *Z_envZ_g_reserved13;
  /* import: 'env' 'g_reserved14' */
  u32 *Z_envZ_g_reserved14;
  /* import: 'env' 'g_reserved15' */
  u32 *Z_envZ_g_reserved15;
  /* import: 'env' 'g_reserved2' */
  u32 *Z_envZ_g_reserved2;
  /* import: 'env' 'g_reserved3' */
  u32 *Z_envZ_g_reserved3;
  /* import: 'env' 'g_reserved4' */
  u32 *Z_envZ_g_reserved4;
  /* import: 'env' 'g_reserved5' */
  u32 *Z_envZ_g_reserved5;
  /* import: 'env' 'g_reserved6' */
  u32 *Z_envZ_g_reserved6;
  /* import: 'env' 'g_reserved7' */
  u32 *Z_envZ_g_reserved7;
  /* import: 'env' 'g_reserved8' */
  u32 *Z_envZ_g_reserved8;
  /* import: 'env' 'g_reserved9' */
  u32 *Z_envZ_g_reserved9;
  /* import: 'env' 'memory' */
  wasm_rt_memory_t *Z_envZ_memory;
} Z_cart_instance_t;

void Z_cart_init_module(void);
void Z_cart_instantiate(Z_cart_instance_t*, struct Z_env_instance_t*);
void Z_cart_free(Z_cart_instance_t*);

/* import: 'env' 'acos' */
f32 Z_envZ_acos(struct Z_env_instance_t*, f32);
/* import: 'env' 'asin' */
f32 Z_envZ_asin(struct Z_env_instance_t*, f32);
/* import: 'env' 'atan' */
f32 Z_envZ_atan(struct Z_env_instance_t*, f32);
/* import: 'env' 'atan2' */
f32 Z_envZ_atan2(struct Z_env_instance_t*, f32, f32);
/* import: 'env' 'circle' */
void Z_envZ_circle(struct Z_env_instance_t*, f32, f32, f32, u32);
/* import: 'env' 'circle_outline' */
void Z_envZ_circle_outline(struct Z_env_instance_t*, f32, f32, f32, u32);
/* import: 'env' 'cls' */
void Z_envZ_cls(struct Z_env_instance_t*, u32);
/* import: 'env' 'cos' */
f32 Z_envZ_cos(struct Z_env_instance_t*, f32);
/* import: 'env' 'exp' */
f32 Z_envZ_exp(struct Z_env_instance_t*, f32);
/* import: 'env' 'fmod' */
f32 Z_envZ_fmod(struct Z_env_instance_t*, f32, f32);
/* import: 'env' 'getPixel' */
u32 Z_envZ_getPixel(struct Z_env_instance_t*, u32, u32);
/* import: 'env' 'hline' */
void Z_envZ_hline(struct Z_env_instance_t*, u32, u32, u32, u32);
/* import: 'env' 'isButtonPressed' */
u32 Z_envZ_isButtonPressed(struct Z_env_instance_t*, u32);
/* import: 'env' 'isButtonTriggered' */
u32 Z_envZ_isButtonTriggered(struct Z_env_instance_t*, u32);
/* import: 'env' 'line' */
void Z_envZ_line(struct Z_env_instance_t*, f32, f32, f32, f32, u32);
/* import: 'env' 'log' */
f32 Z_envZ_log(struct Z_env_instance_t*, f32);
/* import: 'env' 'playNote' */
void Z_envZ_playNote(struct Z_env_instance_t*, u32, u32);
/* import: 'env' 'pow' */
f32 Z_envZ_pow(struct Z_env_instance_t*, f32, f32);
/* import: 'env' 'printChar' */
void Z_envZ_printChar(struct Z_env_instance_t*, u32);
/* import: 'env' 'printInt' */
void Z_envZ_printInt(struct Z_env_instance_t*, u32);
/* import: 'env' 'printString' */
void Z_envZ_printString(struct Z_env_instance_t*, u32);
/* import: 'env' 'random' */
u32 Z_envZ_random(struct Z_env_instance_t*);
/* import: 'env' 'randomSeed' */
void Z_envZ_randomSeed(struct Z_env_instance_t*, u32);
/* import: 'env' 'randomf' */
f32 Z_envZ_randomf(struct Z_env_instance_t*);
/* import: 'env' 'rectangle' */
void Z_envZ_rectangle(struct Z_env_instance_t*, f32, f32, f32, f32, u32);
/* import: 'env' 'rectangle_outline' */
void Z_envZ_rectangle_outline(struct Z_env_instance_t*, f32, f32, f32, f32, u32);
/* import: 'env' 'reserved34' */
void Z_envZ_reserved34(struct Z_env_instance_t*);
/* import: 'env' 'reserved35' */
void Z_envZ_reserved35(struct Z_env_instance_t*);
/* import: 'env' 'reserved36' */
void Z_envZ_reserved36(struct Z_env_instance_t*);
/* import: 'env' 'reserved37' */
void Z_envZ_reserved37(struct Z_env_instance_t*);
/* import: 'env' 'reserved38' */
void Z_envZ_reserved38(struct Z_env_instance_t*);
/* import: 'env' 'reserved39' */
void Z_envZ_reserved39(struct Z_env_instance_t*);
/* import: 'env' 'reserved40' */
void Z_envZ_reserved40(struct Z_env_instance_t*);
/* import: 'env' 'reserved41' */
void Z_envZ_reserved41(struct Z_env_instance_t*);
/* import: 'env' 'reserved42' */
void Z_envZ_reserved42(struct Z_env_instance_t*);
/* import: 'env' 'reserved43' */
void Z_envZ_reserved43(struct Z_env_instance_t*);
/* import: 'env' 'reserved44' */
void Z_envZ_reserved44(struct Z_env_instance_t*);
/* import: 'env' 'reserved45' */
void Z_envZ_reserved45(struct Z_env_instance_t*);
/* import: 'env' 'reserved46' */
void Z_envZ_reserved46(struct Z_env_instance_t*);
/* import: 'env' 'reserved47' */
void Z_envZ_reserved47(struct Z_env_instance_t*);
/* import: 'env' 'reserved48' */
void Z_envZ_reserved48(struct Z_env_instance_t*);
/* import: 'env' 'reserved49' */
void Z_envZ_reserved49(struct Z_env_instance_t*);
/* import: 'env' 'reserved50' */
void Z_envZ_reserved50(struct Z_env_instance_t*);
/* import: 'env' 'reserved51' */
void Z_envZ_reserved51(struct Z_env_instance_t*);
/* import: 'env' 'reserved52' */
void Z_envZ_reserved52(struct Z_env_instance_t*);
/* import: 'env' 'reserved53' */
void Z_envZ_reserved53(struct Z_env_instance_t*);
/* import: 'env' 'reserved54' */
void Z_envZ_reserved54(struct Z_env_instance_t*);
/* import: 'env' 'reserved55' */
void Z_envZ_reserved55(struct Z_env_instance_t*);
/* import: 'env' 'reserved56' */
void Z_envZ_reserved56(struct Z_env_instance_t*);
/* import: 'env' 'reserved57' */
void Z_envZ_reserved57(struct Z_env_instance_t*);
/* import: 'env' 'reserved58' */
void Z_envZ_reserved58(struct Z_env_instance_t*);
/* import: 'env' 'reserved59' */
void Z_envZ_reserved59(struct Z_env_instance_t*);
/* import: 'env' 'reserved60' */
void Z_envZ_reserved60(struct Z_env_instance_t*);
/* import: 'env' 'reserved61' */
void Z_envZ_reserved61(struct Z_env_instance_t*);
/* import: 'env' 'reserved62' */
void Z_envZ_reserved62(struct Z_env_instance_t*);
/* import: 'env' 'reserved63' */
void Z_envZ_reserved63(struct Z_env_instance_t*);
/* import: 'env' 'setBackgroundColor' */
void Z_envZ_setBackgroundColor(struct Z_env_instance_t*, u32);
/* import: 'env' 'setCursorPosition' */
void Z_envZ_setCursorPosition(struct Z_env_instance_t*, u32, u32);
/* import: 'env' 'setPixel' */
void Z_envZ_setPixel(struct Z_env_instance_t*, u32, u32, u32);
/* import: 'env' 'setTextColor' */
void Z_envZ_setTextColor(struct Z_env_instance_t*, u32);
/* import: 'env' 'sin' */
f32 Z_envZ_sin(struct Z_env_instance_t*, f32);
/* import: 'env' 'sndGes' */
f32 Z_envZ_sndGes(struct Z_env_instance_t*, u32);
/* import: 'env' 'tan' */
f32 Z_envZ_tan(struct Z_env_instance_t*, f32);
/* import: 'env' 'time' */
f32 Z_envZ_time(struct Z_env_instance_t*);

/* export: 'upd' */
void Z_cartZ_upd(Z_cart_instance_t*);

#ifdef __cplusplus
}
#endif

#endif  /* CART_H_GENERATED_ */
