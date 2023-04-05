 #include "events.h"

/* 
    Authors:    Ben Cacic, Jason Szeto 
    Description:    The purpose of this file is to handle the the synchronous and 
                    asynchronous events that will happen in the game. All functions
                    require atleast one or multiple of the objects.
*/

/* Laser_cannon_input( Laser_Cannon *laser_cannon): Is called from the game's main when a sideways 
                        arrow is pressed. It determines if the laser cannon will be able to move
                        in that direction. The case where it cannot is when the laser cannon is
                        on the edge of the screen, and the input is the same as the edge.*/

void Laser_cannon_input( Laser_Cannon *laser_cannon) {

    if( laser_cannon->delta_x < 0 && laser_cannon->x > MIN_X)  
    {  
        move_laser_cannon(laser_cannon);
    }
    else if (laser_cannon->delta_x > 0 && laser_cannon->x < MAX_X ) 
    {
        move_laser_cannon(laser_cannon);
    }

    return;
}

/* Player_laser_input(Laser_Cannon *laser_cannon, Laser *laser): Is called from main when the space bar is 
    pressed, and will determine if the laser can be fired.*/

void Player_laser_input(Laser_Cannon *laser_cannon, Laser *laser) {
    
    UINT16 i;
    for (i = 0; i < PLR_SHOTS; i++) {
        if (laser->is_on_screen[i] == FALSE ) {
            laser->delta_y[i] = -8;
            laser->x[i] = laser_cannon->x;
            laser->y[i] = laser_cannon->y;
            laser->is_on_screen[i] = TRUE;

            return;
        }
    }

    return;
}

/* Alien_fires_laser(Invader *armada, Laser* laser): determines if an alien can fire, and 
    selects which alien will fire.*/

void Alien_fires_laser(Invader *armada, Laser* laser) {

    UINT16 i;
    UINT16 top_row = 0;
    UINT16 alien = rand() % 9; 

if (armada->is_alive[top_row][alien] == TRUE) {
    for (i = 6; i < SHOTS; i++) {
        if (laser->is_on_screen[i] == FALSE) {
            laser->x[i] = alien + armada->x; 
            laser->y[i] = armada->y;
            laser->delta_y[i] = 8; 
            laser->is_on_screen[i] = TRUE;

            return;
        }
    }
} 
}
