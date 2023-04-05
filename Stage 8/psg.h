#ifndef PSG_H
#define PSG_H

#include <osbind.h>

#include "types.h"


#define CHANNEL_A 0
#define CHANNEL_B 1
#define CHANNEL_C 2
#define A_NOISE_C_MUSIC 3
#define TRUE 1
#define FALSE 0


#define SAW_REGULAR 0x8
#define TRIANGLE_PERIOD_INVERSE 0x00
#define TRIANGLE_INVERSE 0xA
#define SAW_PERIOD_INVERSE 0xB
#define SAW_INVERSE 0xC
#define TRIANGLE_PERIOD_REGULAR 0xD
#define TRIANGLE_REGULAR 0xE
#define SAW_PERIOD_REGULAR 0xF



extern volatile char* PSG_reg_select = 0xFF8800;
extern volatile char* PSG_reg_write  = 0xFF8802;

void write_psg(int reg, UINT8 val);

UINT8 read_psg(int reg); 

void set_tone(int channel, int tuning);

void set_volume(int channel, int volume); 

void enable_channel(int channel, int tone_on, int noise_on);

void stop_sound();

void set_noise(int tuning); 

void set_envelope(int shape, unsigned int sustain); 



#endif

