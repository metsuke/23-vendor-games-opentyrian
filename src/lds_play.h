/* vim: set noet:
 *
 * OpenTyrian Classic: A modern cross-platform port of Tyrian
 * Copyright (C) 2007  The OpenTyrian Team
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

int lds_update( void );
int lds_load( JE_byte* );
void lds_rewind( int ); /* default value: subsong = -1 */

#define REFRESH 70.0f

/*unsigned int getorders() { return numposi; }
unsigned int getorder() { return posplay; }
unsigned int getrow() { return pattplay; }
unsigned int getspeed() { return speed; }
unsigned int getinstruments() { return numpatch; }*/

typedef struct {
	unsigned char mod_misc, mod_vol, mod_ad, mod_sr, mod_wave,
		car_misc, car_vol, car_ad, car_sr, car_wave, feedback, keyoff,
		portamento, glide, finetune, vibrato, vibdelay, mod_trem, car_trem,
		tremwait, arpeggio, arp_tab[12];
	unsigned short start, size;
	unsigned char fms;
	unsigned short transp;
	unsigned char midinst, midvelo, midkey, midtrans, middum1, middum2;
} SoundBank;

typedef struct {
	unsigned short gototune, lasttune, packpos;
	unsigned char finetune, glideto, portspeed, nextvol, volmod, volcar,
		vibwait, vibspeed, vibrate, trmstay, trmwait, trmspeed, trmrate, trmcount,
		trcwait, trcspeed, trcrate, trccount, arp_size, arp_speed, keycount,
		vibcount, arp_pos, arp_count, packwait, arp_tab[12];
	struct {
		unsigned char chandelay, sound;
		unsigned short high;
	} chancheat;
} Channel;

typedef struct {
	unsigned short patnum;
	unsigned char transpose;
} Position;

const unsigned short frequency[(13 * 15) - 3];
const unsigned char vibta[25 + (13 * 3)];
const unsigned char tremtab[128];
const unsigned short maxsound, maxpos;

SoundBank *soundbank;
Channel channel[9];
Position *positions;

unsigned char fmchip[0xff], jumping, fadeonoff, allvolume, hardfade, tempo_now, pattplay, tempo, regbd, chandelay[9], mode, pattlen;
unsigned short posplay, jumppos, *patterns, speed;
int playing, songlooped;
unsigned int numpatch, numposi, patterns_size, mainvolume;

void lds_playsound(int inst_number, int channel_number, int tunehigh);
void lds_setregs(unsigned char reg, unsigned char val);
void lds_setregs_adv(unsigned char reg, unsigned char mask, unsigned char val);