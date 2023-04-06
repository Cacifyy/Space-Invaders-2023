/*
Group Student Name: Jason Szeto, Ben Cacic
Student Email: jszet006@mtroyal.ca, bcaci729@mtroyal.ca
File Name: model.h
Instructor: Paul Pospisil
Assignment: Space Invaders - Stage 3
Recent Update: April 4, 2023

Description: Initializes all structs used by the game, and is responsible for updating the game model.
*/

#ifndef MODEL_H
#define MODEL_H

#include <stdio.h>
#include <osbind.h>
#include "types.h"
#include "raster.h"
#include "def.h"
#include "effects.h"

typedef struct 
{
    UINT16 x, y;
    int delta_x;
    BOOL lives[LIFE_COUNT]; 
    UINT16 lives_x, lives_y;
} Laser_Cannon;

typedef struct
{
    UINT16 x, y;
    int delta_x, delta_y;
    BOOL is_alive[ROWS][COLUMNS];
    UINT16 row[COLUMNS]; 
    UINT16 left, right, bottom, dir;
    BOOL move;
} Invader;

typedef struct 
{
    UINT16 x[SHOTS]; /*6 are reserved for the player, and 4 are reserved for the armada. */
    UINT16 y[SHOTS];
    int delta_y[SHOTS];
    BOOL is_on_screen[SHOTS]; 
} Laser;

typedef struct
{
    UINT16 x, y;
    UINT16 score_arr[1];
} Score;

typedef struct 
{
    BOOL game_over;
    UINT16 alien_counter;
} Game;

/*
Function name: Init_laser_cannon
Input: 
Output: void
Function details: Initializes laser_cannon 
*/

void init_laser_cannon(Laser_Cannon *laser_cannon);

/*
Function name: Init_armada
Input: Invader *invader
Output: void
Function details: Initializes invader
*/

void init_armada(Invader *invader);

/*
Function name: Init_laser
Input: Laser *laser
Output: void
Function details: Initializes laser 
*/

void init_laser(Laser *laser);

/*
Function name: Init_score
Input: Score *score
Output: void
Function details: Initializes score 
*/

void init_score(Score *score);

/*
Function name: Init_game
Input: Game *game
Output: void
Function details: Initializes game. 
*/

void init_game(Game *game);

/*
Function name: move_laser_cannon
Input: Laser_Cannon *laser_cannon
Output: void
Function details: moves laser cannon. 
*/

void move_laser_cannon(Laser_Cannon *laser_cannon);

/*
Function name: move_laser
Input: Laser *laser
Output: void
Function details: moves laser. 
*/

void move_laser(Laser *laser);

/*
Function name: reduce_player_lives
Input: Laser_Cannon *laser_cannon, Game *game
Output: void
Function details: Is called when the player is hit by a laser, and reduces lives. If the player has run out of all 3, the struct game is updated to terminate the main game loop.  
*/

void reduce_player_lives(Laser_Cannon *laser_cannon, Game *game);

/*
Function name: move_invaders
Input: Invader *invader
Output: void
Function details: moves invaders horizontally based on whether invader->delta_y is positive or negative. 
*/

void move_invaders(Invader *invader);

/*
Function name: move_invaders_down
Input: Invader *invader
Output: void
Function details: moves invaders vertically. Only called when the armada hits a boundary.
*/

void move_invaders_down(Invader *invader);

/*
Function name: boundary_checker
Input: Invader *invader
Output: void
Function details: Serves as a master boundary checker for both left and right walls. Determines what the most outside column is and accounts for the offset 
    to ensure that the armada still always hits the wall.
*/

void boundary_checker(Invader *invader);

/*
Function name: find_bottom_of_armada
Input: Invader *invader
Output: void
Function details: Determines what the lowest living row in the armada is, to determine when the game should end as the invaders get close to the bottom of the screen.
*/

void find_bottom_of_armada(Invader *invader);

/*
Function name: find_right_of_armada
Input: Invader *invader
Output: void
Function details: Checks where the most right living column of aliens are, and finds the offset to ensure that the aliens bounce properly off the right wall.
*/

void find_right_of_armada(Invader *invader); 

/*
Function name: find_left_of_armada
Input: Invader *invader
Output: void
Function details: Checks where the most left living column of aliens are, and finds the offset to ensure that the aliens bounce properly off the left wall.
*/

void find_left_of_armada(Invader *invader); 

/*
Function name: hit_det_on_armada
Input: Invader *invader, Laser *laser, Score *score, Game *game 
Output: void
Function details: Checks whether or not a laser fired by the player hits an element in the armada. Will update game struct if player kills all 50. Also updates score when
    an alien is hit.
*/

void hit_det_on_armada (Invader *invader, Laser *laser, Score *score, Game *game );

/*
Function name: hit_det_on_player
Input: Laser_Cannon *laser_cannon, Laser *laser, Game *game
Output: void
Function details: Checks whether or not a laser fired by the invaders hits the laser_cannon. If that is the case, reduce_player_lives is called to update the life counter.
*/

void hit_det_on_player (Laser_Cannon *laser_cannon, Laser *laser, Game *game);

/*
Function name: Update_score
Input: Score *score
Output: void
Function details: Updates the score when an alien is hit.
*/

void Update_score(Score *score); 


#endif