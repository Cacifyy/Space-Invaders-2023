#ifndef MUSIC_H
#define MUSIC_H
#include <stdio.h>

#include "psg.h"
#include "types.h"

typedef struct {
    int period;
    int duration;
} tones;

void start_music();

void update_music(UINT32 time_elapsed); 

#endif