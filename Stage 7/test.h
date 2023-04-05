/*    
Group Student Name: Jason Szeto, Ben Cacic
Student Email: jszet006@mtroyal.ca, bcaci729@mtroyal.ca
File Name: test.H
Instructor: Paul Pospisil
Assignment: Space Invaders - Stage 2
Recent Update: March 28th, 2023
*/

#ifndef TEST_H
#define TEST_H

#include "types.h"
#include "music.h"
#include "effects.h"

#include <osbind.h>
#include <stdlib.h>
#include <stdio.h>
#include <linea.h>
#include <string.h>


/* 
Function name: game_clock
Input:  

Output: internal clock for the atari ST
Function details: clock for the music to run on
*/

UINT32 game_clock();

#endif