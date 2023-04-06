/*    
Group Student Name: Jason Szeto, Ben Cacic
Student Email: jszet006@mtroyal.ca, bcaci729@mtroyal.ca
File Name: render.H
Instructor: Paul Pospisil
Assignment: Space Invaders - Stage 4
Recent Update: March 11th, 2023
*/

#ifndef RENDER_H
#define RENDER_H

#include <stdio.h>
#include <osbind.h>

#include "model.h"
#include "raster.h"
#include "types.h"
#include "def.h"

/* 
Function name: render_master
Input:  UINT16 *base
        const Laser_Cannon *laser_cannon
        const Laser *laser
        const Invader *invader
        const Score *score
Output: all declared bitmaps to the screen
Function details: renders all the bitmaps to the screen according to the data structure declarations, word-aligned for the bitmap.
*/

void render_master(UINT16 *base, const Laser_Cannon *laser_cannon, const Laser *laser, const Invader *invader, const Score *score);

/* 
Function name: render_cannon
Input:  UINT16 *base
        const Laser_Cannon *laser_cannon
Output: Renders the cannon to the screen
Function details: Renders the cannon to the screen according to the data structure declarations, word-aligned for the bitmap.
*/

void render_cannon( const Laser_Cannon *laser_cannon,  UINT16 *base);

/* 
Function name: render_invader
Input:  UINT16 *base
        const Invader *invader
        int x_index
        int y_index
Output: Renders a single invader to the screen
Function details: Renders a single invader to the screen, according to the data structure declarations, word-aligned for the bitmap.
                  There are several different bitmaps for the invader so the y_index will be used to determine which bitmap gets drawn where.
*/

void render_invader( const Invader *invader,  UINT16 *base, int x_index, int y_index);

/* 
Function name: render_laser
Input:  UINT16 *base
        const Laser *laser
Output: Renders a single laser shot to the screen
Function details: Renders the laser to the screen according to the data structure declarations, word-aligned for the bitmap.
*/

void render_laser( const Laser *laser,  UINT16 *base);

/* 
Function name: render_armada
Input:  UINT16 *base
        const Invader *invader
Output: Renders the entire armada to the screen.
Function details: Loops the render invader function using the I, J local variables as the x and y index to properly place the different bitmaps 
to generate the 10 x 5 armada. The armada will move according to the data structure declarations, and word-aligned for the bitmaps.
*/

void render_armada(  const Invader *invader, UINT16 *base);

/* 
Function name: render_score
Input:  UINT16 *base
        const Score *score
Output: 
Function details: renders armada.
*/

void render_score (const Score *score, UINT16 *base);

/* 
Function name: render_lives
Input:  UINT16 *base
        const Score *score
Output: 
Function details: renders score
*/

void render_lives (const Laser_Cannon *laser_cannon, UINT16 *base);

/* 
Function name: render_splash
Input:  UINT16 *base
Output: 
Function details: renders splash screen
*/

void render_splash(UINT32 *base);

#endif
