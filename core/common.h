#pragma once

#include <cstdint>
#include <cstdlib>

typedef uint8_t	 u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t	i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef float  f32;
typedef double f64;

typedef unsigned char byte;

#define NTT_ASSERT(x)                                                                                                  \
	do                                                                                                                 \
	{                                                                                                                  \
		if (!(x))                                                                                                      \
		{                                                                                                              \
			fprintf(stderr, "Assertion failed: %s, file %s, line %d\n", #x, __FILE__, __LINE__);                       \
			std::abort();                                                                                              \
		}                                                                                                              \
	} while (0)