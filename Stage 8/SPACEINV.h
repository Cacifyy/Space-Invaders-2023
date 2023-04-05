#ifndef SPACEINV_H
#define SPACEINV_H

#include "model.h"
#include "types.h"
#include "events.h"
#include "raster.h"
#include "render.h"
#include "clear.h"
#include "def.h"

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