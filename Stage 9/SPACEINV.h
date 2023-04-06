#ifndef SPACEINV_H
#define SPACEINV_H

#include "model.h"
#include "types.h"
#include "events.h"
#include "raster.h"
#include "render.h"
#include "clear.h"
#include "def.h"
#include "music.h"
#include "base.h"
#include "isr.h"

#include <osbind.h>
#include <stdlib.h>
#include <stdio.h>


void sync_ev (Invader *invader, Laser *laser, Score *score, Laser_Cannon *laser_cannon, Game *game);

void async_ev ( Laser_Cannon *laser_cannon, Laser *laser, UINT32 input );

UINT16 menu(UINT32 *base);

void game_start(UINT16 *base, UINT16 *second_base);

UINT32 game_clock();

UINT8 *align_base(UINT8 *buffer);

#endif