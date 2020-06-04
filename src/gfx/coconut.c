// convpng v6.8
#include <stdint.h>
#include "logo_gfx.h"

// 8 bpp image
uint8_t coconut_data[1026] = {
 32,32,  // width,height
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0A,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFD,0xFD,0xFD,0xFD,0x0A,0xFD,0xFD,0xFD,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0A,0xFD,0xFD,0xFD,0xF9,0xF9,0xFB,0x50,0xFB,0xFB,0xF9,0xF9,0xF9,0xFD,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFD,0xFD,0xF9,0xF9,0x20,0xF9,0xF9,0xFB,0xFB,0xFB,0xFB,0xF9,0xF9,0xF9,0xF9,0xF9,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x50,0xFB,0xF9,0xFD,0xF9,0xF9,0xF9,0xF9,0xF9,0xFB,0xFB,0xFB,0xFB,0x20,0xF9,0xF9,0xF9,0xF9,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0xFB,0x50,0x20,0xFD,0xF9,0xF9,0xF9,0xFD,0xFD,0xFD,0xF9,0xF9,0x20,0xF9,0xFB,0xFB,0xFB,0x20,0x20,0xF9,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0xF9,0xFB,0xFB,0xF9,0xFD,0xF9,0xF9,0x20,0xFD,0x5E,0x20,0xFB,0xF9,0x20,0xF9,0xF9,0xF9,0xFB,0x50,0xF9,0xF9,0x0A,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x0A,0xFD,0xFD,0xFD,0xFD,0xF9,0xF9,0x0A,0x0A,0x0A,0x39,0xF9,0xFB,0xFB,0xFB,0x20,0xF9,0xF9,0xF9,0xF9,0x50,0xF9,0xF9,0x20,0xFD,0x00,0x00,0x00,0x00,
 0x00,0x00,0x0A,0x0A,0xF9,0xF9,0xF9,0xFD,0xF9,0x20,0xB2,0x0A,0x0A,0x0A,0xF9,0xFB,0xFB,0xFB,0xF9,0xF9,0x20,0xF9,0xF9,0xFB,0xFB,0xF9,0xF9,0xFD,0x0A,0x0A,0x00,0x00,
 0x00,0x00,0x00,0xFD,0xF9,0xFB,0x50,0xFB,0xFB,0xFB,0x0A,0xFB,0x7F,0xFD,0xF9,0xFB,0xFB,0xFB,0xF9,0xF9,0xF9,0xF9,0xF9,0xF9,0xFB,0xF9,0xF9,0xFD,0x0A,0x00,0x00,0x00,
 0x00,0x00,0x00,0xFD,0xF9,0xFB,0xFB,0xF9,0xFD,0xFD,0xFD,0xFD,0x0A,0xFD,0x20,0xF9,0xF9,0xFD,0xF9,0xF9,0xF9,0xFD,0xF9,0xF9,0xFB,0xF9,0xF9,0xFD,0xFD,0x00,0x00,0x00,
 0x00,0x00,0xF9,0xF9,0xF9,0xF9,0xF9,0xFB,0xF9,0xF9,0x0A,0x0A,0x39,0xFD,0xF9,0xF9,0xF9,0xFD,0x20,0xF9,0xF9,0xFD,0xF9,0xF9,0xFB,0xF9,0xF9,0xFD,0xFD,0xFD,0x00,0x00,
 0x00,0x00,0xF9,0xF9,0xF9,0xF9,0x7F,0x5E,0x5E,0x40,0xFD,0x20,0x0A,0xF9,0xF9,0xF9,0xF9,0x0A,0xF9,0xF9,0xF9,0xFD,0xF9,0x20,0x50,0x20,0xF9,0xFD,0xFD,0xFD,0x00,0x00,
 0x00,0x00,0x20,0xF9,0xF9,0xF9,0x5E,0x5E,0x40,0xF9,0xFD,0xF9,0x5D,0xF9,0xF9,0xF9,0x20,0xF9,0xF9,0xF9,0xF9,0xFD,0x20,0x20,0xFB,0xFB,0xF9,0x0A,0x0A,0xFD,0x00,0x00,
 0x00,0x00,0xFD,0xFD,0xFD,0xF9,0x40,0x0A,0x40,0xF9,0xFD,0xF9,0x5E,0xF9,0xF9,0x20,0xF9,0xF9,0xF9,0xF9,0xF9,0xFD,0xF9,0xF9,0xFB,0xFB,0xF9,0xFD,0xFD,0x0A,0x00,0x00,
 0x00,0x00,0xF9,0xF9,0xF9,0xF9,0x40,0x40,0x40,0xF9,0xFD,0xFD,0x39,0xFD,0xFD,0x20,0xF9,0xF9,0x20,0xF9,0xF9,0xFD,0xFD,0xF9,0xFB,0xFB,0xF9,0xFD,0xFD,0xFD,0x00,0x00,
 0x00,0x00,0xF9,0xF9,0x20,0xF9,0x5E,0x5E,0x5E,0xF9,0xFD,0xFD,0x39,0xFD,0xFD,0x20,0xF9,0xF9,0xF9,0xF9,0xF9,0xFD,0xFD,0xF9,0xFB,0x50,0xF9,0xFD,0xFD,0xFD,0x00,0x00,
 0x00,0x00,0xF9,0x20,0x20,0x20,0x0A,0x0A,0x0A,0xFB,0xFD,0xF9,0x0A,0x20,0xFD,0xF9,0xF9,0xF9,0x20,0xF9,0xF9,0xF9,0xFD,0xF9,0xFB,0xFB,0xF9,0xFD,0x0A,0x0A,0x0A,0x00,
 0x00,0x00,0xFD,0xFD,0xFD,0xFD,0x40,0x40,0x40,0xFB,0xFD,0xF9,0x5D,0xF9,0xFD,0xF9,0xF9,0xF9,0xF9,0xF9,0xF9,0xF9,0xFD,0xF9,0xFB,0xFB,0xF9,0xFD,0xFD,0xFD,0x00,0x00,
 0x00,0x00,0x00,0xFD,0xFD,0xFD,0x39,0x39,0x39,0xFB,0xF9,0xF9,0x5D,0xF9,0xFD,0xF9,0xF9,0xF9,0xFD,0xF9,0x20,0x20,0xFD,0xFB,0x0A,0xCA,0xFB,0xFD,0xFD,0x00,0x00,0x00,
 0x00,0x00,0x00,0xF9,0xF9,0xF9,0x40,0x0A,0x40,0xFB,0xF9,0xFD,0xFD,0x39,0xFD,0xF9,0x20,0x20,0x20,0x20,0x20,0xF9,0x50,0xFB,0x0A,0x0A,0xFB,0xFD,0xFD,0x00,0x00,0x00,
 0x00,0x00,0x00,0xF9,0xF9,0xFB,0x5E,0x40,0x39,0xFB,0xFB,0xFD,0xFD,0x39,0xFD,0xF9,0xF9,0xF9,0xF9,0xF9,0xF9,0xF9,0xFB,0xFB,0x0A,0x0A,0xFB,0xFD,0xFD,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0xF9,0xFB,0xF9,0xF9,0xC7,0xFB,0x7F,0xFD,0xFD,0x39,0xFD,0xFD,0xF9,0xF9,0xF9,0xFD,0xFB,0xFB,0xFB,0xFB,0x0A,0xFB,0x20,0x0A,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0xF9,0x39,0x7F,0x40,0xCA,0x50,0xFD,0xFD,0x0A,0x0A,0x0A,0xF9,0xF9,0xF9,0xF9,0xFB,0xFB,0xFB,0xFB,0x0A,0xFB,0xF9,0x0A,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x0A,0x0A,0x0A,0xB2,0x0A,0xFB,0xFD,0x39,0xFD,0x0A,0xF9,0xF9,0xFB,0xFB,0x50,0xFB,0xFB,0xFB,0xF9,0xF9,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x0A,0x40,0xF9,0xB2,0x50,0xFB,0xFD,0x39,0xFD,0x0A,0xF9,0xFB,0xFB,0xFB,0xF9,0xF9,0xFD,0xF9,0xF9,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0A,0x5E,0x7F,0xFB,0xFD,0xF9,0xFB,0xFB,0x7F,0xFB,0xFB,0xFB,0xF9,0xFD,0xF9,0xF9,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0A,0x0A,0xFD,0xFD,0x20,0xFB,0xFB,0xFB,0xF9,0xF9,0xF9,0xFD,0x0A,0xF9,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0A,0x00,0x00,0xFD,0xF9,0xFB,0xFB,0xFB,0xF9,0xF9,0xF9,0x00,0x0A,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};