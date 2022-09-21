/** (C) Matt Hughson 2020 */

#include "LIB/neslib.h"
#include "LIB/nesdoug.h"
#include "A53/bank_helpers.h"
#include "../include/stdlib.h"

#include "main.h"
#include "PRG0.h"

#pragma rodata-name ("CODE")
#pragma code-name ("CODE")

#include "NES_ST/meta_player.h"

const unsigned char palette[16]={ 0x0f,0x05,0x23,0x37,0x0f,0x01,0x21,0x31,0x0f,0x06,0x16,0x26,0x0f,0x09,0x19,0x29 };

// Initalized RAM variables
//

unsigned char tick_count;
unsigned char pads;
unsigned char pads_new;
unsigned char px;
unsigned char py;

#pragma rodata-name ("CODE")
#pragma code-name ("CODE")


// It seems like main() MUST be in fixed back!
void main (void) 
{
	ppu_off(); // screen off

	set_vram_buffer(); // do at least once, sets a pointer to a buffer
	clear_vram_buffer();

	set_chr_bank_0(0);
	bank_bg(0);
	bank_spr(1);

	pal_bg(palette);
	pal_spr(palette);

	vram_adr(NTADR_A(7, 4));
	vram_write("MINIMAL A53 PROJECT", 19);

	ppu_on_all(); // turn on screen

	pal_bright(4);

	music_play(0);

	px = 128;
	py = 120;

	// infinite loop
	while (1)
	{
		++tick_count;

		ppu_wait_nmi(); // wait till beginning of the frame

		oam_clear();

		pads = pad_poll(0) | pad_poll(1); // read the first controller
		pads_new = get_pad_new(0) | get_pad_new(1); // newly pressed button. do pad_poll first

		clear_vram_buffer(); // do at the beginning of each frame

		oam_meta_spr(px, py, meta_player_list[(tick_count >> 4) % 3]);

		if (pads_new & PAD_A)
		{
			sfx_play(0, 0);
		}
		if (pads_new & PAD_B)
		{
			sfx_play(2, 0);
		}

		if (pads & PAD_LEFT) --px;
		if (pads & PAD_RIGHT) ++px;
		if (pads & PAD_UP) --py;
		if (pads & PAD_DOWN) ++py;
	}
}