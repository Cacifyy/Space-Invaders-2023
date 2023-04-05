/*    
Group Student Name: Jason Szeto, Ben Cacic
Student Email: jszet006@mtroyal.ca, bcaci729@mtroyal.ca
File Name: model.H
Instructor: Paul Pospisil
Assignment: Space Invaders - Stage 2
Recent Update: March 4th, 2023
*/

#ifndef MODEL_H
#define MODEL_H

#define rows 10
#define columns 5
#define life_count 3
#define SHOTS 10
#define PLR_SHOTS 6

#define MAX_X 640
#define MIN_X 0
#define MAX_Y 400
#define MIN_Y 0

#define WIDTH 10
#define HEIGHT 5

#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include <osbind.h>
#include "types.h"
#include "raster.h"

/* 
structure name: Laser_Cannon
Input:  UINT16 x
        UINT16 y
        int delta_x
        BOOL lives[life_count]
        UINT16 live_x
Output: 
Function details: 
*/

typedef struct 
{
    UINT16 x, y;
    int delta_x;
    BOOL lives[life_count]; 
    UINT16 lives_x, lives_y;
} Laser_Cannon;

/* 
structure name: Invader
Input:  UINT16 x
        UINT16 y
        int delta_x
        int delta_y
        BOOL is_alive[rows][columns]
        UINT16 row[columns]
        UINT16 left, right, bottom
        UINT16 dir
        BOOL move
Output: 
Function details: 
*/


typedef struct
{
    UINT16 x, y;
    int delta_x, delta_y;
    BOOL is_alive[rows][columns];
    UINT16 row[columns]; 
    UINT16 left, right, bottom;
    UINT16 dir;
    BOOL move;
} Invader;

/* 
structure name: Laser
Input:  UINT16 x[SHOTS];
        UINT16 y[SHOTS];
        int delta_y[SHOTS];
        BOOL is_on_screen[SHOTS]; 
Output: 
Function details: 
*/

typedef struct 
{
    UINT16 x[SHOTS]; /*6 are reserved for the player, and 4 are reserved for the armada. */
    UINT16 y[SHOTS];
    int delta_y[SHOTS];
    BOOL is_on_screen[SHOTS]; 
} Laser;

/* 
structure name: Score
Input:  UINT16 x, y;
        UINT16 score_arr[1]; 
Output: 
Function details: 
*/

typedef struct
{
    UINT16 x, y;
    UINT16 score_arr[1];
} Score;

/* 
Function name: init_laser_cannon
Input: Laser_Cannon *laser_cannon
      
Output: 
Function details:
*/

void init_laser_cannon(Laser_Cannon *laser_cannon);

/* 
Function name: init_armada
Input: Invader *invader
      
Output: 
Function details:
*/

void init_armada(Invader *invader);

/* 
Function name: init_laser
Input: Laser *laser
      
Output: 
Function details:
*/

void init_laser(Laser *laser);

/* 
Function name: init_score
Input: Score *score
      
Output: 
Function details:
*/

void init_score(Score *score);

/* 
Function name: move_laser_cannon
Input: Laser_Cannon *laser_cannon
      
Output: 
Function details:
*/

void move_laser_cannon(Laser_Cannon *laser_cannon);

/* 
Function name: move_laser
Input: Laser *laser
      
Output: 
Function details:
*/

void move_laser(Laser *laser);

/* 
Function name: reduce_player_lives
Input: Laser_Cannon *laser_cannon
      
Output: 
Function details:
*/

void reduce_player_lives(Laser_Cannon *laser_cannon);

/* 
Function name: move_invaders
Input: Invader *invader
      
Output: 
Function details:
*/

void move_invaders(Invader *invader);

/* 
Function name: move_invaders_down
Input: Invader *invader
      
Output: 
Function details:
*/

void move_invaders_down(Invader *invader);


/* 
Function name: boundary_checker
Input: Invader *invader
      
Output: 
Function details:
*/

void boundary_checker(Invader *invader);

/* 
Function name: find_bottom_of_armada
Input: Invader *invader
      
Output: 
Function details:
*/

void find_bottom_of_armada(Invader *invader);

/* 
Function name: find_right_of_armada
Input: Invader *invader
      
Output: 
Function details:
*/

void find_right_of_armada(Invader *invader); 


/* 
Function name: find_left_of_armada
Input: Invader *invader
      
Output: 
Function details:
*/

void find_left_of_armada(Invader *invader); 

/* 
Function name: hit_det_on_armada
Input: Invader *invader
       Laser *laser
       Score *score
Output: 
Function details:
*/

void hit_det_on_armada(Invader *invader, Laser *laser, Score *score);

/* 
Function name: hit_det_on_player
Input: Invader *invader
       Laser *laser
      
Output: 
Function details:
*/

void hit_det_on_player (Laser_Cannon *laser_cannon, Laser *laser);

/* 
Function name: Update_score
Input:  Score *score
Output: 
Function details:
*/

void Update_score(Score *score); 

/* 
Function name: pow
Input:  UINT16 num_base
        UINT16 power
Output: 
Function details:
*/

UINT16 pow(UINT16 num_base, UINT16 power);

/* 
Function name: Player_loses
Input:  BOOL lost
Output: 
Function details:
*/

BOOL Player_loses(BOOL lost);




#endif