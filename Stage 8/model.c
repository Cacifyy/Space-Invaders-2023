#include "model.h"

/*  Authors: Ben Cacic and Jason Szeto

    Description: The purpose of this source file is to
        initialize the objects, and provide functions
        to update them and the game state. 

*/

void init_laser_cannon(Laser_Cannon *laser_cannon) {
    int i;

    laser_cannon->x = CANNON_START_X;
    laser_cannon->y = CANNON_Y;
    laser_cannon->delta_x = 0;
    for( i = 0; i < 3; i++ ) {
        laser_cannon->lives[i] = TRUE;
    }       
    laser_cannon->lives_x = LIVES_X;
    laser_cannon->lives_y = LIVES_Y;

    return;
}

void init_armada(Invader *invader) {

    int i,j;

    invader->x = INVADER_START_X;
    invader->y = INVADER_START_Y;
    invader->delta_x = -1;
    invader->delta_y = 0;
    for ( i = 0; i < ROWS; i++ ) {
        for( j = 0; j < COLUMNS; j++ ) {
            invader->is_alive[i][j] = TRUE;
        }
    }
    invader->left = INVADER_LEFT;
    invader->right = INVADER_RIGHT;
    invader->bottom = INVADER_BOTTOM;
    invader->dir = 0; 
    invader->move = TRUE;

    return;
}

void init_laser(Laser *laser) {

    UINT16 i;    
    for (i = 0; i < SHOTS; i++ ) {
        laser->x[i] = 0;
        laser->y[i] = 0;
        laser->delta_y[i] = 0;
        laser->is_on_screen[i] = FALSE;
   }
    return;
}

void init_score(Score *score) {

    score->x = SCORE_X;
    score->y = SCORE_Y;
    score->score_arr[0] = 0;

    return;
}

void init_game(Game *game) {
    game->game_over = FALSE;
    game->alien_counter = ALIENS_TOTAL;
}

/* move_laser_cannon(Laser_Cannon *laser_cannon): move laser cannon 
    horizontally. */
void move_laser_cannon(Laser_Cannon *laser_cannon) {
    laser_cannon->x += laser_cannon->delta_x;

}

/* move_laser(Laser *laser): move laser vertically. */ 
void move_laser(Laser *laser) {

    UINT16 i;
    for (i = 0; i < SHOTS; i++)
    {
        if(laser->is_on_screen[i] == TRUE) 
        {
            if (laser->delta_y[i] > 0 && laser->y[i] >= (MAX_Y - 16)) 
            {
                laser->is_on_screen[i] = FALSE;
                laser->y[i] = 0; 

            }
            else if (laser->delta_y[i] < 0 && laser->y[i] <= MIN_Y ) 
            {
                laser->is_on_screen[i] = FALSE;
                laser->y[i] = 0; 
            }
            else 
            {
                laser->y[i] += laser->delta_y[i]; 
            }
        }
    }
    return; 

        }

/* reduce_player_lives(Laser_Cannon *laser_cannon): decrease players' 
    life count. Called when the player is hit. */
void reduce_player_lives(Laser_Cannon *laser_cannon, Game *game) {

   if(laser_cannon->lives[0] == FALSE)
    {
        if (laser_cannon->lives[1] == FALSE) {
            laser_cannon->lives[2] = FALSE; 
            game->game_over = TRUE;
        }
        else {
            laser_cannon->lives[1] = FALSE;
            return;
        }
    }
    else {
        laser_cannon->lives[0] = FALSE;
    }
    return;
}

/* move_invaders(Invader *invader): move armada vertically and horizontally. */ 
void move_invaders(Invader *invader) {

    invader->x += invader->delta_x;
    return;
}

void move_invaders_down(Invader *invader) {

    invader->y += invader->delta_y;
    return;
}

/*boundary_checker(Invader *invader): master function for checking boundaries.*/
void boundary_checker(Invader *invader) {

    if (invader->dir == 0 && invader->x < 5) { 
        find_left_of_armada(invader);
    }
    
    if (invader->dir == 1 && (invader->x + 10) > 38 ) {
        find_right_of_armada(invader);
    }
}

/*find_bottom_of_armada(Invader *invader): find bottom of armada. */
void find_bottom_of_armada(Invader *invader) {
 
    BOOL same_edge = FALSE;
    UINT16 x, y;

    y = invader->bottom;

    for (x = 0; x < ROWS; x++) {
        if (invader->is_alive[x][y] == TRUE ) {
            same_edge = TRUE;
        }
    }
    if (same_edge == FALSE ) {
        invader->bottom -= 1;
    }
        return;
    }

/* find_right_of_armada(Invader *invader): find right edge of armada. */
void find_right_of_armada(Invader *invader) {
   
    BOOL same_edge = FALSE;
    UINT16 x, y;

    x = invader->right;

    for (y = 0; y < COLUMNS; y++) {
        if (invader->is_alive[x][y] == TRUE ) {
            same_edge = TRUE;
        }
    }
    if (same_edge == FALSE ) {
        invader->right -= 1;
    }
        return;
    }

/* find_left_of_armada(Invader *invader): find left edge of armada. */
void find_left_of_armada(Invader *invader) {
    
    BOOL same_edge = FALSE;
    UINT16 x, y;

    x = invader->left;

    for (y = 0; y < COLUMNS; y++) {
        if (invader->is_alive[x][y] == TRUE ) {
            same_edge = TRUE;
        }
    }
    if (same_edge == FALSE ) {
        invader->left += 1;
    } 
    return;
}

/* hit_det_on_armada (Invader *invader, Laser *laser, Score *score): determines if the player hit
    an alien and updates the score if it did. */
void hit_det_on_armada (Invader *invader, Laser *laser, Score *score, Game *game ) {

    UINT16 i, j, k; 

    for (k = 0; k < PLR_SHOTS; k++)
    {
        if (laser->is_on_screen[k] == TRUE) {
            if(laser->y[k] <= (invader->y + HEIGHT)) 
            {
                if (laser->x[k] >= invader->x && laser->x[k] <= (invader->x + WIDTH )) {
                    i = (laser->x[k] - invader->x);
                    j = (laser->y[k] - invader->y) / 16;

                /* Handles case where laser is exactly 80 pixels away from the top of the armada. The correct element can not be found because
                80 (Height of armada) / 16 (height of each alien) == 5. */
                if ((laser->y[k] - invader->y) == 80 ) {
                    j = 4;
                }

                if (invader->is_alive[i][j] == TRUE) {
                    invader->is_alive[i][j] = FALSE;
                    laser->is_on_screen[k] = FALSE;

                    
                    game->alien_counter--;

                    if (game->alien_counter == 0) {
                        game->game_over = TRUE;
                    }
                    Update_score(score);
                } 
                }
            }
        }
    }
} 

/* hit_det_on_player (Laser_Cannon *laser_cannon, Laser *laser): determines if a laser fired
    by an alien hits the player. */
void hit_det_on_player (Laser_Cannon *laser_cannon, Laser *laser, Game *game) {

    UINT16 i;
    
    for (i = 6; i < SHOTS; i++) {   /* elements 6 to 9 are only fireable by the armada and not the player, that is why the loop begins at 6 and is terninated right before 10. */
        if (laser->is_on_screen[i] == TRUE) {
            if (laser->y[i] >= CANNON_Y && laser->y[i] <= CANNON_Y + 16 ) {
                if (laser_cannon->x == laser->x[i]) {
                    if (laser->delta_y[i] > 0) {
                        reduce_player_lives(laser_cannon, game);
                        laser->is_on_screen[i] = FALSE;
                    }
                }   
            }
        }
    }
    return;
}

/* Update_score(Score *score): Update the score value. */
void Update_score(Score *score) {

    score->score_arr[0] += 10; /*just temporary. */

    return;
}

UINT16 pow(UINT16 num_base, UINT16 power) {

    UINT16 result = num_base;
    UINT16 temp = num_base;

    if (power == 1) {
        return result;
    }
    else if (power == 2) {
        result = result * temp;
    }

/*
    UINT16 result, i;
    result = num_base;

    for(i = 0; i < power - 1; i++ ) {
        result *= result;
    }
   */
    return result;
}

BOOL Player_loses(BOOL lost) {
    return lost;
}
