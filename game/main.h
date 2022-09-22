/** (C) Matt Hughson 2020 */

// Note: all variables need extern and should be defined in main.c

#ifndef ONCE_MAIN_H
#define ONCE_MAIN_H

#define DEBUG_ENABLED 0

#if DEBUG_ENABLED
#define PROFILE_POKE(val) //POKE((0x2001),(val));
#else
#define PROFILE_POKE(val)
#endif

#define PROF_CLEAR 0x1e // none
#define PROF_R_TINT 0x3e // red
#define PROF_G_TINT 0x5e // green
#define PROF_B_TINT 0x9e // blue
#define PROF_W_TINT 0x1e // white
#define PROF_R 0x3f // red + grey
#define PROF_G 0x5f // green + grey
#define PROF_B 0x9f // blue + grey
#define PROF_W 0x1f // white + grey

#define ROOM_WIDTH_PAGES (1)
#define ROOM_WIDTH_PIXELS (256*ROOM_WIDTH_PAGES)
#define ROOM_WIDTH_TILES (16*ROOM_WIDTH_PAGES)
#define GRID_XY_TO_ROOM_INDEX(x,y) (((y) * ROOM_WIDTH_TILES) + (x))

#define META_TILE_NUM_BYTES (6)


#pragma bss-name(push, "ZEROPAGE")

extern unsigned char i;
extern unsigned char index;
extern unsigned int index16;
extern unsigned char x;
extern unsigned char y;
extern unsigned char tick_count;
extern unsigned char pads;
extern unsigned char pads_new;

extern unsigned char px;
extern unsigned char py;

#pragma bss-name(pop)

// TODO: Where is non-zero page? Is this just starting at zero page?

#endif // ONCE_MAIN_H