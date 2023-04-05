#include "effects.h"

void cannon_shot(){
    int vol = 8;
    int sustain = 0x8;
    int noise = 0x0F;

    set_noise(noise);
    enable_channel(A_NOISE_C_MUSIC, 0, 1);
    
    set_volume(CHANNEL_A, vol);
    set_envelope(1, sustain);

}

void explosion_sound(){
    int vol = 16;
    int noise = 0x1F;
    int sustain = 0x8;
    
    set_noise(noise);
    
    enable_channel(A_NOISE_C_MUSIC, 0, 1);
    set_volume(CHANNEL_A, vol);
    set_envelope(1, sustain);
}