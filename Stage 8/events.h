#ifndef EVENTS_H
#define EVENTS_H

#include <osbind.h>
#include <stdlib.h>
#include <stdio.h>

#include "model.h"
#include "types.h"
#include "def.h"

void Laser_cannon_input(Laser_Cannon *laser_cannon); 

void Player_laser_input(Laser_Cannon *laser_cannon, Laser *laser);

void Alien_fires_laser(Invader *invader, Laser *laser);

#endif