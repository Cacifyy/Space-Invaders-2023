#include "psg.h"



void write_psg(int reg, UINT8 val){
    long old_ssp;
    int Valid_register = FALSE;
    if (reg >= 0 && reg <= 15){
        Valid_register = TRUE;
        if(Valid_register = TRUE){
            old_ssp = Super(0);

            *PSG_reg_select = reg;
            *PSG_reg_write = val;

            Super(old_ssp);
        }   
    }
}

UINT8 read_psg(int reg){
   
}

void set_tone(int channel, int tuning){
    switch(channel){
        case CHANNEL_A:
            write_psg(0x0, tuning);
            write_psg(0x1, 0);
            break;
        case CHANNEL_B: 
            write_psg(0x2, tuning);
            write_psg(0x3, 0);
            break;
        case CHANNEL_C:
            write_psg(0x4, tuning);
            write_psg(0x5, 0);
            break;
        
    }
}


void set_volume(int channel, int volume){
    switch(channel){
        case CHANNEL_A:
            write_psg(0x8, volume);
            break;
        case CHANNEL_B:
            write_psg(0x9, volume);
            break;
        case CHANNEL_C:
            write_psg(0xA, volume);
            break;
    

    }
}

void enable_channel(int channel, int tone_on, int noise_on){
    
    int enable_val;
 
    switch(channel){
        case CHANNEL_A:
            if(tone_on == 1 && noise_on == 0){
                    enable_val = 0x3E;
            }
            else if(tone_on == 0 && noise_on == 1){
                    enable_val = 0x37;
            }
            else if(tone_on == 1 && noise_on == 1){
                    enable_val = (0x3E & 0x37);
            }
            break;
        case CHANNEL_B:
            if(tone_on == 1 && noise_on == 0){
                    enable_val = 0x3D;
            }
            else if(tone_on == 0 && noise_on == 1){
                    enable_val = 0x2F;
            }
            else if(tone_on == 1 && noise_on == 1){
                    enable_val = (0x3D & 0x2F);
            }
            break; 
        case CHANNEL_C:
            if(tone_on == 1 && noise_on == 0){
                    enable_val = 0x3B;
            }
            else if(tone_on == 0 && noise_on == 1){
                    enable_val = 0x1F;
            }
            else if(tone_on == 1 && noise_on == 1){
                    enable_val = (0x3B & 0x1F);
            }
            break; 
        case A_NOISE_C_MUSIC:
            if(tone_on == 1 && noise_on == 1){
                enable_val = (0x33);
            }
            break;

    }

    write_psg(0x7, enable_val);
}


void stop_sound(){
    write_psg(0x7, 0x00);
    
    set_volume(CHANNEL_A, 0);
    set_volume(CHANNEL_B, 0);
    set_volume(CHANNEL_C, 0);
}

void set_noise(int tuning){
    write_psg(0x6, tuning);
}

void set_envelope(int shape, unsigned int sustain){
    int shape_version;
    write_psg(0xB, sustain);
    write_psg(0xC, sustain);

    switch(shape) {
        case 0:
            shape_version = SAW_REGULAR;
            break;
        case 1:
            shape_version = TRIANGLE_PERIOD_INVERSE;
            break;
        case 2:
            shape_version = TRIANGLE_INVERSE;
            break;
        case 3:
            shape_version = SAW_PERIOD_INVERSE;
            break;
        case 4:
            shape_version = SAW_INVERSE;
            break;
        case 5:
            shape_version = TRIANGLE_PERIOD_REGULAR;
            break;
        case 6: 
            shape_version = TRIANGLE_REGULAR;
            break;
        case 7:
            shape_version = SAW_PERIOD_REGULAR;
            break;
        
    }

    write_psg(0xD, shape_version);
}