/*    
Group Student Name: Jason Szeto, Ben Cacic
Student Email: jszet006@mtroyal.ca, bcaci729@mtroyal.ca
File Name: def.H
Instructor: Paul Pospisil
Assignment: Space Invaders
Recent Update: April 4th, 2023

Description: Helper header file to house all the defines of previous stages to reduce redundant defines
*/

#ifndef DEF_H
#define DEF_H

#define ROWS 10
#define COLUMNS 5
#define LIFE_COUNT 3
#define SHOTS 10    /* Total shots that can exist in the game at once */
#define PLR_SHOTS 6 /* Number of laser shots dedicated to the player (0 - 5), where as the alien has 6 - 9 */
#define LASER_SPEED 8

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

#define VIDEO_BASE_HIGH 0xFFFF8201
#define BYTE_BOUNDARY 256

#define LEFT_ARROW 0x004B0000
#define RIGHT_ARROW 0x004D0000
#define UP_ARROW 0x00480000
#define DOWN_ARROW 0x0050000
#define SPACE 0x00390020
#define ENTER 0x001C000D
#define ESC 0x0001001B

#define PLYR_1_MODE 0
#define PLYR_2_MODE 1
#define EXIT_GAME 2


#endif
