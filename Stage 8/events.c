 #include "events.h"

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

void Player_laser_input(Laser_Cannon *laser_cannon, Laser *laser) {
    
    UINT16 i;
    for (i = 0; i < PLR_SHOTS; i++) {
        if (laser->is_on_screen[i] == FALSE ) {
            laser->delta_y[i] = -LASER_SPEED;
            laser->x[i] = laser_cannon->x;
            laser->y[i] = laser_cannon->y;
            laser->is_on_screen[i] = TRUE;

            cannon_shot();
            return;
        }
    }

    return;
}

void Alien_fires_laser(Invader *armada, Laser* laser) {

    UINT16 i;
    UINT16 top_row = 0;
    UINT16 alien = rand() % 9; 

    if (armada->is_alive[top_row][alien] == TRUE) {
        for (i = 6; i < SHOTS; i++) {
            if (laser->is_on_screen[i] == FALSE) {
                laser->x[i] = alien + armada->x; 
                laser->y[i] = armada->y;
                laser->delta_y[i] = LASER_SPEED; 
                laser->is_on_screen[i] = TRUE;

                return;
            }
        }
    } 
}
