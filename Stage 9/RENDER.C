#include "render.h"

/* Function to render a entire frame to the screen, draws the laser cannon, the laser projectile and the armada all in a single frame*/

void render_master(UINT16 *base, const Laser_Cannon *laser_cannon, const Laser *laser, const Invader *invader, const Score *score)
{
    render_cannon(laser_cannon, base);
    render_armada(invader, base); 
    render_laser(laser, base);
    render_score (score, base); /*can be removed from render master later because it will only be rendered once.*/
    render_lives(laser_cannon, base);
}

/*Renders the cannon to the screen by using the laser cannon data structure as well*/

void render_cannon( const Laser_Cannon *laser_cannon,  UINT16 *base)
{
    draw_cannon_word(base, laser_cannon->x, laser_cannon->y);
}

/*Renders a single invader bitmap to the screen depending on what row it is on and it's location is determined by
the invader data structure.*/

void render_invader( const Invader *invader,  UINT16 *base, int x_index, int y_index)
{
    UINT16 x, y;

    x = (x_index) + (invader->x) ;
    y = (y_index * 16) + (invader->y);
    

    if ( y_index == 4)
    {                                                 /* depends on the columns value as referenced in model.h*/
        draw_alien_begin_word(base, x, y);
    }
    else if (y_index == 3)
    {                                                 /* depends on the columns value as referenced in model.h*/
        draw_alien_begin_word(base, x, y);
    }
    else if (y_index == 2)
    {                                                 /* depends on the columns value as referenced in model.h*/
        draw_alien_middle_word(base, x, y);
    }
 
    else if (y_index == 1)
    {
        draw_alien_middle_word(base, x, y);
    }
    else if (y_index == 0)
    {
        draw_alien_end_word(base, x, y);
    }   
}

/*Renders the laser projectile to the screen by using the bitmap and the laser data structure*/

void render_laser( const Laser *laser,  UINT16 *base)
{
    UINT16 i;
    for (i = 0; i < SHOTS; i++)
    {
        if (laser->is_on_screen[i] == TRUE) 
        {
            draw_laser_word(base, laser->x[i], laser->y[i]);    /*same thing as above*/
        }
    }
}
/* renders the entire 2D array of invaders to the screen all at once, takes the information given from the 
render invaders function to determine which bitmap to use when plotting the 2D array.*/ 

void render_armada( const Invader *invader, UINT16 *base)
{
   UINT16 i, j;
   for (i = 0; i < ROWS; i++)
   {
       for (j = 0; j < COLUMNS; j++)
       {
            if(invader->is_alive[i][j] == TRUE) 
            {
                render_invader(invader, base, i, j);
            }
        }
    }
}

void render_score (const Score *score, UINT16 *base) 
{ 
   UINT16 i, j, x, score_dig, second_dig, first_dig, n, num_place;
   UINT16 score_word[] = {448,192,384,432,224};

   x = score->x;

   for (i = 0; i < 5; i++) {
    draw_word(base, x, score->y, score_word[i]);
    x++;
   }

    score_dig = (score->score_arr[0]);
    if (score_dig < 1000) {
        n = 3;
    }
    if (score_dig < 100) {
        n = 2;
    }
    if (score_dig < 10) {
        n = 1;
    }


    if (n == 3) { 
        first_dig = score_dig / 100;
        second_dig = (first_dig * 100);
        second_dig = score_dig - second_dig;
        second_dig /= 10;
        score_dig /= 100;
    }

    if (n == 2) {
        score_dig /= 10;
    }

    /*score_dig /= (UINT16) pow((double)10,(double)n-1);*/ /* need to comment this shit, looks like it amkes no snese*/
    if (score_dig == 0) {
        num_place = 0;
    }
    if (score_dig == 1) {
        num_place = 16;
    }
    if (score_dig == 2) {
        num_place = 32;
    }
    if (score_dig == 3) {
        num_place = 48;
    }
    if (score_dig == 4) {
        num_place = 64;
    }
    if (score_dig == 5) {
        num_place = 80;
    }
    if (score_dig == 6) {
        num_place = 96;
    }
    if (score_dig == 7) {
        num_place = 112;
    }
    if (score_dig == 8) {
        num_place = 128;
    }
    if (score_dig == 9) {
        num_place = 146;
    }

    if (n == 3) {
        x += 1;
        for (j = 0; j < n - 1; j++ ) {
            draw_word(base, x, score->y, num_place );
                    
            if (second_dig == 0) {
                num_place = 0;
            }
            if (second_dig == 1) {
                num_place = 16;
            }
            if (second_dig == 2) {
                num_place = 32;
            }
            if (second_dig == 3) {
                num_place = 48;
            }
            if (second_dig == 4) {
                num_place = 64;
            }   
            if (second_dig == 5) {
                num_place = 80;
            }   
            if (second_dig == 6) {
                num_place = 96;
            }
            if (second_dig == 7) {
                num_place = 112;
            }
            if (second_dig == 8) {
                num_place = 128;
            }
            if (second_dig == 9) {
                num_place = 146;
            }
            x++;
        }
        draw_word(base, x, score->y, 0);
    }
    else if (n == 2) {
    x += 1;
    for (j = 0; j < n; j++ ) {
        draw_word(base, x, score->y, num_place );
        num_place = 0;
        x++;
    }
    }
    else if (n == 1) {
        x += 1;
        draw_word(base, x, score->y, 0 );
    }
}

void render_lives (const Laser_Cannon *laser_cannon, UINT16 *base) {

    UINT16 lives_ar[] = {336, 288, 496, 224, 448};
    UINT16 i, x, j;

    x = laser_cannon->lives_x;

    for (i = 0; i < 5; i++) {
        draw_word(base, x, laser_cannon->lives_y, lives_ar[i]);
        x++;
    }

    x++;
    for (j = 0; j < LIFE_COUNT; j++) {
        if (laser_cannon->lives[j] == TRUE) {
            draw_cannon_word(base, x, laser_cannon->lives_y);
            x++;
        }
    }

}

void render_splash(UINT32 *base, UINT16 game_selection ) {
    draw_splash(base);
/*
    if (game_selection == 0) {
        draw_word((UINT16 *)base, 16, 200, 0);
    }
    else if (game_selection == 1 ) {
        draw_word((UINT16 *)base, 16, 300, 0);
    }
    else if (game_selection == 2) {
        draw_word((UINT16 *)base, 16, 400, 0);
    }
    */
}

