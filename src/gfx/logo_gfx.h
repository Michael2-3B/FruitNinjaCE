// convpng v6.8
// this file contains all the graphics sources for easy inclusion in a project
#ifndef __logo_gfx__
#define __logo_gfx__
#include <stdint.h>

#define logo_gfx_transparent_color_index 0

#define watermelon_width 32
#define watermelon_height 32
#define watermelon_size 1026
extern uint8_t watermelon_data[1026];
#define watermelon ((gfx_sprite_t*)watermelon_data)
#define sizeof_logo_gfx_pal 8
extern uint16_t logo_gfx_pal[4];

#endif
