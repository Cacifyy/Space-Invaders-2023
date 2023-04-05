#ifndef SPACEINV_H
#define SPACEINV_H
#define MAX_X 624
#define MIN_X 16
#define CANNON_START_X 296
#define CANNON_Y 336
#define LEFT_ARROW 0x4B00
#define RIGHT_ARROW 0x4D00
#define SPACE 0x3920
#define NUM_OF_LASER 10

#include "model.h"
#include "types.h"
#include "events.h"
#include "raster.h"
#include "render.h"
#include "clear.h"

#include <osbind.h>
#include <stdlib.h>
#include <stdio.h>
#include <linea.h>
#include <string.h>

void sync_ev (Invader *invader, Laser *laser, Score *score, Laser_Cannon *laser_cannon, Game *game);

void async_ev ( Laser_Cannon *laser_cannon, Laser *laser, char input );

UINT32 game_clock();

UINT8 *get_base(UINT8 *buffer);

#endif