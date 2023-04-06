
/*
Group Student Name: Jason Szeto, Ben Cacic
Student Email: jszet006@mtroyal.ca, bcaci729@mtroyal.ca
File Name: spaceinv.h
Instructor: Paul Pospisil
Assignment: Space Invaders - Stage 5
Recent Update: April 5, 2023

Description: Serves as the main for the program, and includes the main game loop, clock, music and menu.
*/

#ifndef SPACEINV_H
#define SPACEINV_H

#include "model.h"
#include "types.h"
#include "events.h"
#include "raster.h"
#include "render.h"
#include "clear.h"
#include "def.h"
#include "music.h"
#include "base.h"

#include <osbind.h>
#include <stdlib.h>
#include <stdio.h>

/* 
Function name: sync_events
Input:  Invader *invader, 
        Laser *laser, 
        Score *score, 
        Laser_Cannon *laser_cannon, 
        Game *game
Output: void
Function details: Handles all the synchronous events that happen though out the game loop. These events include moving the laser when it should be rendered on screen,
        the armada of aliens, seeing if either the player or alien was hit since the last time the model was updated, and finding the boundaries for the armada. A large 
        portion of the code in the function is determining the direction the armada should be moving, and when it should move down. It is also imporant to note, that the 
        typedef struct Game is used to determine when the game should end, and all of those game over cases are handled in this function.
*/

void sync_ev (Invader *invader, Laser *laser, Score *score, Laser_Cannon *laser_cannon, Game *game);

/* 
Function name: async_events
Input:  Laser_Cannon *laser_cannon,
        Laser *laser, 
        UINT32 input
Output: void
Function details: This function handles the asynchronous events of the game, which are the movement of the laser cannon and the firing of the laser. Both of which 
        are determined by the players' inputs. After determining what event should take place based on the input received, it then calls the events module 
        handles the action that the player requested.
*/

void async_ev ( Laser_Cannon *laser_cannon, Laser *laser, UINT32 input );

/*
Function name: menu
Input:
Output: UINT16 game_selection - This return holds the game type that the player selected.
Function details: Maintains a continous loop until an option is selected, which then the function will return. Inside the loop, keyboard input will be polled and handled. 
        If a valid input is received, it will then determine what game mode should be returned to indicate to where ever it is called from what the player chose.
*/

UINT16 menu(UINT32 *base);

/*
Function name: game_start
Input:  UINT16 *base, 
        UINT16 *second_base
Output: void 
Function details: This function serves as the game loop. The loop continues while the game over signal has not been turned on. Inside the game loop, the clock is 
            ran and checked. The clock will determine the timing of the music, as well as the rendering of the model and the synchronous events. Also, along with rendering 
            game, this part of the loop is responsible for the double buffering of the game, hence why the game loop has two bases as inputs. Independently of the clock, 
            within the game loop is also where inputs will be polled and sent to async_events. On top of the loop itself, this is where the model of the game is initialized. 
*/

void game_start(UINT16 *base, UINT16 *second_base);

/*
Function name: game_clock
Input:
Output: UINT32 current_clock
Function details: Enters supervisor mode and returns the updated clock timer.
*/

UINT32 game_clock();

/*
Function name: align_base
Input: UINT8 *buffer
Output: UINT8 base
Function details: Uses a *base pointer to find how many bytes the current address is off from the 265 byte block, and returns the new memory address to get the second base to be
        used by the game.
*/

UINT8 *align_base(UINT8 *buffer);

#endif