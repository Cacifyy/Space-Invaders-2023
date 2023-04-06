/*    
Group Student Name: Jason Szeto, Ben Cacic
Student Email: jszet006@mtroyal.ca, bcaci729@mtroyal.ca
File Name: events.h
Instructor: Paul Pospisil
Assignment: Space Invaders - Stage 3
Recent Update: March 26th, 2023

Description: Handles all asynchronous events that happen in the main.
*/

#ifndef EVENTS_H
#define EVENTS_H

#include <osbind.h>
#include <stdlib.h>
#include <stdio.h>

#include "model.h"
#include "types.h"
#include "def.h"
#include "effects.h"

/*
Function name: Laser_cannon_input 
Input: Laser_Cannon *laser_cannon
Output: void
Function details: Is called from the main game loop when the player requests a laser cannon movement by either pressing the left or 
    right arrow. This function also handles the boundary checking to make sure that the cannon is not moved off screen and out of bounds.
*/

void Laser_cannon_input(Laser_Cannon *laser_cannon); 

/*
Function name: Player_laser_input 
Input: Laser_Cannon *laser_cannon, Laser *laser
Output: void
Function details: Is called from the main game loop when the player requests a laser shot by pressing the spacebar. If the player has an available shot (6 max
    on screen at a time), the function will set the data for the laser.
*/

void Player_laser_input(Laser_Cannon *laser_cannon, Laser *laser);

/*
Function name: Alien_fires_laser 
Input: Invader *invader, Laser *laser
Output: void
Function details: This function determines which alien should fire a laser to move down screen to attack the cannon. It is called based on the positon of the model (when invader->x and laser_cannon->x) cross
    on the horizontal axis. It will also limit the amount of invader lasers can be fired (4 on screen at a time), and ensures that more cannot be fired.
*/

void Alien_fires_laser(Invader *invader, Laser *laser);

#endif