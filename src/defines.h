#pragma once

//Types

#include <stdint.h>

typedef uint8_t     U8;
typedef uint16_t    U16;
typedef uint32_t    U32;
typedef uint64_t    U64;

typedef int8_t      S8;
typedef int16_t     S16;
typedef int32_t     S32;
typedef int64_t     S64;

typedef S8          B8;
typedef S16         B16;
typedef S32         B32;
typedef S64         B64;

typedef float       F32;
typedef double      F64;

typedef void VoidFunction(void);

//Macros

#define Statement(s) do{ s }while(0)

//Keywords

#define global      static
#define function    static
#define local       static

//Integer/pointer/array/type helpers

#define Bytes(n)        (n)
#define Kilobytes(n)    (n << 10)
#define Megabytes(n)    (n << 20)
#define Gigabytes(n)    (((U64)n) << 30)

#define Thousand(n)     ((n) * 1000)
#define Million(n)      ((n) * 1000000)
#define Billion(n)      ((n) * 1000000000LL)

#define Swap(type, a, b) Statement(type _swap_ = a; a = b; b = _swap_;)

#define ArrayCount(a) (sizeof(a) / sizeof((a)[0]))

#define AlignUpPow2(x,p) (((x) + (p) - 1)&~((p) - 1))
#define AlignDownPow2(x,p) ((x)&~((p) - 1))
#define IsPow2(x) (((x)&((x)-1)) == 0)

//Clamps, mins, maxes, aligns

#define Min(a, b) (((a) < (b))? (a) : (b))
#define Max(a, b) (((a) > (b))? (a) : (b))

#define Clamp(a,x,b) (((x)<(a))?(a):((b)<(x))?(b):(x))
#define ClampTop(a,b) Min(a,b)
#define ClampBot(a,b) Max(a,b)

//Limits

global U8   U8Min  = 0;
global U16  U16Min = 0;
global U32  U32Min = 0;
global U64  U64Min= 0;

global U8  U8Max = 0xff;
global U16 U16Max = 0xffff;
global U32 U32Max = 0xffffffff;
global U64 U64Max = 0xffffffffffffffffllu;

global S8  S8Min  = (S8) 0x80;
global S16 S16Min = (S16)0x8000;
global S32 S32Min = (S32)0x80000000;
global S64 S64Min = (S64)0x8000000000000000llu;

global S8  S8Max  = (S8) 0x7f;
global S16 S16Max = (S16)0x7fff;
global S32 S32Max = (S32)0x7fffffff;
global S64 S64Max = (S64)0x7fffffffffffffffllu;

//Constants

global F32 machine_epsilon_F32 = 1.1920929e-7f;
global F32 pi_F32  = 3.14159265359f;
global F32 tau_F32 = 6.28318530718f;
global F32 e_F32 = 2.71828182846f;
global F32 gold_big_F32 = 1.61803398875f;
global F32 gold_small_F32 = 0.61803398875f;

global F64 machine_epsilon_F64 = 2.220446e-16;
global F64 pi_F64  = 3.14159265359;
global F64 tau_F64 = 6.28318530718;
global F64 e_F64 = 2.71828182846;
global F64 gold_big_F64 = 1.61803398875;
global F64 gold_small_F64 = 0.61803398875; 

//Asserts

#if !defined(AssertBreak)
#define AssertBreak() (*(volatile int*)0 = 0)
#endif

#ifdef ENABLE_ASSERT
#define Assert(c) Statement( if(!(c)){AssertBreak();} )
#else
#define Assert(c)
#endif

#define StaticAssert(Expr) static_assert(Expr, "Assertion failed: " #Expr)

//Memory

#define MemorySet(dst, val, size)   memset(dst, val, size)

#define MemoryCopy(dst, src, size)  memmove((dst), (src), (size))
#define MemoryCopyStruct(dst, src)  MemoryCopy((dst),(src), Min(sizeof(*(dst)), sizeof(*(src))))
#define MemoryCopyArray(dst, src)   MemoryCopy((dst),(src), Min(sizeof(dst), sizeof(src)))

#define MemoryZero(ptr,size)        MemorySet((ptr), 0, (size))
#define MemoryZeroStruct(ptr)       MemoryZero((ptr), sizeof(*(ptr)))
#define MemoryZeroArray(arr)        MemoryZero((arr), sizeof(arr))

//