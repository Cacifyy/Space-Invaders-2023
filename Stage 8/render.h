#ifndef RENDER_H
#define RENDER_H

#include <stdio.h>
#include <osbind.h>

#include "model.h"
#include "raster.h"
#include "types.h"
#include "def.h"

void render_master(UINT16 *base, const Laser_Cannon *laser_cannon, const Laser *laser, const Invader *invader, const Score *score);
void render_cannon( const Laser_Cannon *laser_cannon,  UINT16 *base);
void render_invader( const Invader *invader,  UINT16 *base, int x_index, int y_index);
void render_laser( const Laser *laser,  UINT16 *base);
void render_armada(  const Invader *invader, UINT16 *base);
void render_score (const Score *score, UINT16 *base);
void render_lives (const Laser_Cannon *laser_cannon, UINT16 *base);
void render_splash(UINT32 *base, UINT16 game_selection);

#endif
