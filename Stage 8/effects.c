#include "effects.h"

void cannon_shot(){
    int vol = 0x10;
    int noise = 0x0F;
    int sustain = 0x10;

    set_noise(noise);
    
    enable_channel(A_NOISE_C_MUSIC, 1, 1);
    set_volume(CHANNEL_A, vol);
    set_envelope(1, sustain);

}

void explosion_sound(){
    int vol = 0x10;
    int noise = 0x1F;
    int sustain = 0x38;
    
    set_noise(noise);
    
    enable_channel(A_NOISE_C_MUSIC, 1, 1);
    set_volume(CHANNEL_A, vol);
    set_envelope(1, sustain);
}