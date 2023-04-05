/*    
Group Student Name: Jason Szeto, Ben Cacic
Student Email: jszet006@mtroyal.ca, bcaci729@mtroyal.ca
File Name: events.H
Instructor: Paul Pospisil
Assignment: Space Invaders - Stage 2
Recent Update: March 4th, 2023
*/

#ifndef EVENTS_H
#define EVENTS_H

#include <osbind.h>
#include "model.h"
#include "types.h"
#include <stdlib.h>
#include <stdio.h>

/* 
Function name: Laser_cannon_input
Input: Laser_Cannon *laser_cannon
Output: 
Function details: 
*/

void Laser_cannon_input(Laser_Cannon *laser_cannon);

/* 
Function name: Player_laser_input
Input: Laser_Cannon *laser_cannon
       Laser *laser

Output: 
Function details:
*/

void Player_laser_input(Laser_Cannon *laser_cannon, Laser *laser);

/* 
Function name: Alien_reaches_bottom
Input: Invader *invader
    
Output: 
Function details:
*/

void Alien_reaches_bottom(Invader *invader); 

/* 
Function name: Alien_fires_laser
Input: Invader *invader
       Laser *laser
    
Output: 
Function details:
*/

void Alien_fires_laser(Invader *invader, Laser *laser);

#endif