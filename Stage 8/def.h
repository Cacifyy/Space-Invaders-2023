#ifndef DEF_H
#define DEF_H

#define ROWS 10
#define COLUMNS 5
#define LIFE_COUNT 3
#define SHOTS 10    /* Total shots that can exist in the game at once */
#define PLR_SHOTS 6 /* Number of laser shots dedicated to the player (0 - 5), where as the alien has 6 - 9 */

#define MAX_X 39    /* Max x value in terms of words */
#define MAX_X_PIXELS 640 /* Max x value in terms of pixels */
#define MIN_X 0
#define MAX_Y 400
#define MIN_Y 0

#define WIDTH 10    /* In terms of words */    
#define HEIGHT 80 /* In terms of pixels, 5 * 16 */

#define TRUE 1
#define FALSE 0

#define CANNON_START_X 20
#define CANNON_Y 336
#define LIVES_X 28
#define LIVES_Y 8 
#define LIFE_COUNT 3

#define INVADER_START_X 20
#define INVADER_START_Y 20
#define INVADER_LEFT 0
#define INVADER_RIGHT 9
#define INVADER_BOTTOM 4
#define ALIENS_TOTAL 50
#define ALIEN_HEIGHT 16

#define SCORE_X 1
#define SCORE_Y 8

#define CHANNEL_A 0
#define CHANNEL_B 1
#define CHANNEL_C 2
#define A_NOISE_C_MUSIC 3

#define SAW_REGULAR 0x8
#define TRIANGLE_PERIOD_INVERSE 0x00
#define TRIANGLE_INVERSE 0xA
#define SAW_PERIOD_INVERSE 0xB
#define SAW_INVERSE 0xC
#define TRIANGLE_PERIOD_REGULAR 0xD
#define TRIANGLE_REGULAR 0xE
#define SAW_PERIOD_REGULAR 0xF

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 400
#define BLACK 0xFF

#endif
