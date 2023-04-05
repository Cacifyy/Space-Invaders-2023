/*    
Group Student Name: Jason Szeto, Ben Cacic
Student Email: jszet006@mtroyal.ca, bcaci729@mtroyal.ca
File Name: psg.H
Instructor: Paul Pospisil
Assignment: Space Invaders - Stage 2
Recent Update: March 28th, 2023
*/

#ifndef PSG_H
#define PSG_H

#include <osbind.h>

#include "types.h"


#define CHANNEL_A 0
#define CHANNEL_B 1
#define CHANNEL_C 2
#define A_NOISE_C_MUSIC 3
#define TRUE 1
#define FALSE 0


#define SAW_REGULAR 0x8
#define TRIANGLE_PERIOD_INVERSE 0x00
#define TRIANGLE_INVERSE 0xA
#define SAW_PERIOD_INVERSE 0xB
#define SAW_INVERSE 0xC
#define TRIANGLE_PERIOD_REGULAR 0xD
#define TRIANGLE_REGULAR 0xE
#define SAW_PERIOD_REGULAR 0xF



extern volatile char* PSG_reg_select = 0xFF8800;
extern volatile char* PSG_reg_write  = 0xFF8802;

/* 
Function name: write_psg
Input:  int reg
        UINT8 val

Output: writes to the PSG, according to the register value and the "val" value. 
Function details: helper function to uses supervisor mode to access the PSG chip and 
                  writes to the PSG using the address of the select and write registers.
*/

void write_psg(int reg, UINT8 val);

/* 
Function name: read_psg
Input:  int reg
        

Output: none
Function details: optional helper function that was not used.
*/

UINT8 read_psg(int reg); 

/* 
Function name: set_tone
Input: int channel
       int tuning
        
Output: writes to the tone registers in the PSG
Function details: Sets the fine and course tone registers in the PSG for the 3 channels
*/

void set_tone(int channel, int tuning);

/* 
Function name: set_volume
Input: int channel
       int volume
        
Output: writes to the volume registers in the PSG
Function details: Sets the volume registers in the PSG for the 3 channels
*/

void set_volume(int channel, int volume); 

/* 
Function name: enable_channel
Input: int channel
       int tone_on
       int noise_on
        
Output: writes to the mixer register in the PSG
Function details: changes the bit values in the mixer register in the PSG, different 
                  cases are written and are used depending on whether make use the tone bits,
                  noise bits or both in the mixer for the 3 channels
*/

void enable_channel(int channel, int tone_on, int noise_on);

/* 
Function name: stop_sound
Input: 
        
Output: writes to the volume and mixer registers
Function details: When called this function sets the volume to 0 and turns off all the mixer channels
*/

void stop_sound();

/* 
Function name: set_noise
Input: int tuning
        
Output: writes to the noise registers
Function details: When called this function sets the noise register to the value desired, useful for noise based 
                  sound effects.
*/

void set_noise(int tuning); 

/* 
Function name: set_envelope
Input: int shape
       unsigned int sustain
        
Output: writes to the fine and course envelope registers and the shape envelope register
Function details: When called this function sets the shape, fine and course registers for the envelope. The envelope registers
                  are usually used for sound effects.
*/

void set_envelope(int shape, unsigned int sustain); 



#endif

