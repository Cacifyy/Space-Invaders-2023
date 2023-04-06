/*    
Group Student Name: Jason Szeto, Ben Cacic
Student Email: jszet006@mtroyal.ca, bcaci729@mtroyal.ca
File Name: effects.H
Instructor: Paul Pospisil
Assignment: Space Invaders - Stage 2
Recent Update: March 28th, 2023
*/

#ifndef EFFECTS_H
#define EFFECTS_H

#include "psg.h"
#include "types.h"

/* 
Function name: cannon_shot
Input: 
Output: Cannon firing sound
Function details: Using registers from the PSG, function outputs a gunshot-like sound when called, it is a noise based sound effect.
*/

void cannon_shot();

/* 
Function name: explosion_sound
Input: 
Output: explosion sound
Function details: Using registers from the PSG, function outputs a explosion-like sound when called, it is a noise based sound effect.
*/

void explosion_sound();





#endif