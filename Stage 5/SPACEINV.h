/*    
Group Student Name: Jason Szeto, Ben Cacic
Student Email: jszet006@mtroyal.ca, bcaci729@mtroyal.ca
File Name: spaceinv.H
Instructor: Paul Pospisil
Assignment: Space Invaders - Stage 2
Recent Update: March 18th, 2023
*/

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

/* 
Function name: sync_ev
Input:  Invader *invader
        Laser *laser
        Score *score 
        Laser_Cannon *laser_cannon

Output: 
Function details: 
*/

void sync_ev (Invader *invader, Laser *laser, Score *score, Laser_Cannon *laser_cannon);

/* 
Function name: async_ev
Input:  Laser *laser 
        Laser_Cannon *laser_cannon
        char input

Output: 
Function details: 
*/

void async_ev ( Laser_Cannon *laser_cannon, Laser *laser, char input );

/* 
Function name: game_clock
Input: 
Output: 
Function details: 
*/

UINT32 game_clock();

/* 
Function name: get_base
Input: UINT8 *buffer
Output: 
Function details: 
*/

UINT8 *get_base(UINT8 *buffer);

#endif