/*
Group Student Name: Jason Szeto, Ben Cacic
Student Email: jszet006@mtroyal.ca, bcaci729@mtroyal.ca
File Name: base.h
Instructor: Paul Pospisil
Assignment: Space Invaders - Stage 8
Recent Update: April 5, 2023

Description: Replaces Physbase() and Setscreen(), handles manual video base addressing.
*/

#ifndef BASE_H
#define BASE_H

#include "types.h"

/*
Function name: get_video_base
Input:
Output: UINT16 *base
Function details: Enters supervisor mode to grab the video base register address.
*/

UINT16 *get_video_base();

/*
Function name: set_video_base
Input: UINT16 base
Output: void
Function details: Enters supervisor mode to set the UINT16 *base's screen address. 
*/
void set_video_base(UINT16 *base);

#endif