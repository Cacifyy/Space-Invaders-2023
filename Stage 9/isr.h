/*   
Group Student Name: Ben Cacic, Jason Szeto
Student Email: bcaci729@mtroyal.ca, jszet006@mtroyal.ca
File Name: isr.h
Instructor: Paul Pospisil
Assignment: Space invaders - Stage 9a
Recent Update: April 5th, 2023
*/

#ifndef ISR_H
#define ISR_H


#include "music.h"
#include "types.h"
#include "def.h"
#include "vbl.h"

typedef void (*Vector) ();

extern int vbl_music_timer;
extern int vbl_game_timer;




/* 
Function name: vbl_req
Input: None
Output: increments the vbl timers
Function details: Increments the game and music timers according to the VBL
*/

void vbl_req();

/* 
Function name: install_vector
Input: int num, Vector vector
Output: returns original vector
Function details: installs a single vector
*/

Vector install_vector(int num, Vector vector);

/* 
Function name: install_vbl_vector
Input: none
Output: none
Function details: installs VBL vector
*/

void install_vbl_vector();

/* 
Function name: uninstall_vbl_vector
Input: none
Output: none
Function details: uninstalls VBL vector
*/

void uninstall_vbl_vector();


#endif