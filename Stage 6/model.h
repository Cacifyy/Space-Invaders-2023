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

typedef struct 
{
    UINT16 x, y;
    int delta_x;
    BOOL lives[life_count]; 
    UINT16 lives_x, lives_y;
} Laser_Cannon;

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

void init_laser_cannon(Laser_Cannon *laser_cannon);

void init_armada(Invader *invader);

void init_laser(Laser *laser);

void init_score(Score *score);

void move_laser_cannon(Laser_Cannon *laser_cannon);

void move_laser(Laser *laser);

void reduce_player_lives(Laser_Cannon *laser_cannon);

void move_invaders(Invader *invader);

void move_invaders_down(Invader *invader);

void boundary_checker(Invader *invader);

void find_bottom_of_armada(Invader *invader);

void find_right_of_armada(Invader *invader); 

void find_left_of_armada(Invader *invader); 

void hit_det_on_armada (Invader *invader, Laser *laser, Score *score);

void hit_det_on_player (Laser_Cannon *laser_cannon, Laser *laser);

void Update_score(Score *score); 

UINT16 pow(UINT16 num_base, UINT16 power);

BOOL Player_loses(BOOL lost);




#endif