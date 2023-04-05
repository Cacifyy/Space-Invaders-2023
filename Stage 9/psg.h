#ifndef PSG_H
#define PSG_H

#include <osbind.h>

#include "types.h"
#include "def.h"


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

