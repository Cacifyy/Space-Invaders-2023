/*    
Group Student Name: Jason Szeto, Ben Cacic
Student Email: jszet006@mtroyal.ca, bcaci729@mtroyal.ca
File Name: music.H
Instructor: Paul Pospisil
Assignment: Space Invaders - Stage 2
Recent Update: March 28th, 2023
*/

#ifndef MUSIC_H
#define MUSIC_H
#include <stdio.h>

#include "psg.h"
#include "types.h"

/* 
structure name: tones
Input:  int period;
        int duration;

Output: tone values 
structure details: Stores the tone period and duration of each tone in an array
*/

typedef struct {
    int period;
    int duration;
} tones;

/* 
Function name: start_music
Input:  

Output: Start the music outside of the game loop
Function details: When called it initializes the song and plays the first tone/note in the array and increments the array          
*/

void start_music();

/* 
Function name: update_music
Input:  UINT32 time_elapsed

Output: Plays the song in repeatedly
Function details: When called it plays the rest of the song according to the atari ST's internal clock and once the song is completely it 
                  repeats until a game ending condition is true.         
*/

void update_music(UINT32 time_elapsed); 

#endif