#include "SPACEINV.h"

UINT8 buffer[32256];

int main () {

    UINT32 curr_clock;
    UINT32 old_clock = 0;
    UINT32 time;
    UINT8 input;
    BOOL move = TRUE;

    UINT16 buffer_num = 1;

    void *base = Physbase(); 
    void *second_base = get_base(buffer);

    Laser laser;
    Laser_Cannon laser_cannon;
    Invader invader;
    Score score;
    Game game;

    init_laser_cannon(&laser_cannon);
    init_armada(&invader);
    init_score(&score);
    init_laser(&laser);
    init_game(&game);

    disable_cursor();

    clear();
    
    while (Cconis() == 0) {
        render_splash((UINT32*) base);
    }

    render_master(base, &laser_cannon, &laser, &invader, &score);

    while(game.game_over == FALSE) {

        if(Cconis()) {
            input = (char)Cnecin();
            async_ev(&laser_cannon, &laser, input);
        }   

        curr_clock = game_clock();
        time = curr_clock - old_clock; 
        if (time > 0)
        {      
            sync_ev(&invader, &laser, &score, &laser_cannon, &game);

            if (buffer_num == 1) {

                clear_screen(base);

                render_master(base, &laser_cannon, &laser, &invader, &score);

                Setscreen(-1, base, -1);
                Vsync();

                buffer_num = 0;

            } 
            else if (buffer_num == 0) {

                clear_screen(second_base);

                render_master(second_base, &laser_cannon, &laser, &invader, &score);

                Setscreen(-1, second_base, -1);
                Vsync();

                buffer_num = 1;
            }
            }
        } 
        old_clock = curr_clock; 
        
        Setscreen(-1, base, -1);
        Vsync();

    return 0;

}

void sync_ev (Invader *invader, Laser *laser, Score *score , Laser_Cannon *laser_cannon, Game *game ) {

    move_laser(laser);
    hit_det_on_armada(invader, laser, score);
    hit_det_on_player(laser_cannon, laser, game);
    boundary_checker(invader);
    
    if (invader->x == laser_cannon->x) {
        Alien_fires_laser(invader, laser);
    }

    if (invader->move == TRUE ) { 
        switch (invader->dir)
        {
            case 0:
                if((invader->x + invader->left) > 0) {
                    invader->delta_x = -1;
                    invader->delta_y = 0;
                    move_invaders(invader);
                    if ((invader->x + invader->left) == MIN_X) {
                        invader->dir = 1;
                        invader->delta_y = 3;
                        move_invaders_down(invader);
                    }
                }
                break;

            case 1:
                if((invader->x + invader->right) < 39) {
                    invader->delta_x = 1;
                    invader->delta_y = 0;
                    move_invaders(invader);
                    if ((invader->x + invader->right) == 39) { 
                        invader->dir = 0;
                        invader->delta_y = 3;
                        move_invaders_down(invader);
                    }
                }
                break; 
        } 
        invader->move = FALSE;
    }
    else 
    {
        invader->move = TRUE;
    }

    if (invader->delta_y > 0) {
        find_bottom_of_armada(invader);
        if((invader->y + (invader->bottom * ALIEN_HEIGHT)) >= CANNON_Y) {
            game->game_over = TRUE;
        }
    }
}

void async_ev ( Laser_Cannon *laser_cannon, Laser *laser, char input ) {

    if( input == 'a') 
    {  
        laser_cannon->delta_x = -1; 
        Laser_cannon_input(laser_cannon);
    }
    if ( input == 'd') 
    {
        laser_cannon->delta_x = 1;
        Laser_cannon_input(laser_cannon);
    }
    if (input == 'w') {

        Player_laser_input(laser_cannon, laser);
    }
    
    return;

}

UINT32 game_clock() {

    UINT32 curr_clock;
    UINT32 old_ssp;

    old_ssp = Super(0);
    curr_clock = *((UINT32 *)0x462);
    Super(old_ssp);

    return curr_clock;

}

UINT8 *get_base(UINT8 *buffer) {

    UINT8 *base;
    UINT16 difference;
    base = buffer;
    difference = (int)base;
    difference %= 0x100;
    difference = 0x100 - difference;
    
    return base + difference;

}