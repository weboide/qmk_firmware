#pragma once

#include "no_split.h"

#include "quantum.h"

#ifdef USE_I2C
#include <stddef.h>
#ifdef __AVR__
	#include <avr/io.h>
	#include <avr/interrupt.h>
#endif
#endif

// Standard Keymap
#define LAYOUT( \
	L00, L01, L02, L03, L04, L05, \
	L10, L11, L12, L13, L14, L15, \
	L20, L21, L22, L23, L24, L25, \
	L30, L31, L32, L33, L34, L35 \
	) \
	{ \
		{ L00, L01, L02, L03, L04, L05 }, \
		{ L10, L11, L12, L13, L14, L15 }, \
		{ L20, L21, L22, L23, L24, L25 }, \
		{ L30, L31, L32, L33, L34, L35 } \
	}

#define LAYOUT_ortho_4x6 LAYOUT
