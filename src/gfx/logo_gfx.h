// convpng v6.8
// this file contains all the graphics sources for easy inclusion in a project
#ifndef __logo_gfx__
#define __logo_gfx__
#include <stdint.h>

#define logo_gfx_transparent_color_index 0

#define strawberry_width 32
#define strawberry_height 32
#define strawberry_size 1026
extern uint8_t strawberry_data[1026];
#define strawberry ((gfx_sprite_t*)strawberry_data)
#define watermelon_width 32
#define watermelon_height 32
#define watermelon_size 1026
extern uint8_t watermelon_data[1026];
#define watermelon ((gfx_sprite_t*)watermelon_data)
#define pineapple_width 32
#define pineapple_height 32
#define pineapple_size 1026
extern uint8_t pineapple_data[1026];
#define pineapple ((gfx_sprite_t*)pineapple_data)
#define apple_width 32
#define apple_height 32
#define apple_size 1026
extern uint8_t apple_data[1026];
#define apple ((gfx_sprite_t*)apple_data)
#define pear_width 32
#define pear_height 32
#define pear_size 1026
extern uint8_t pear_data[1026];
#define pear ((gfx_sprite_t*)pear_data)
#define sizeof_logo_gfx_pal 42
extern uint16_t logo_gfx_pal[21];

#endif
