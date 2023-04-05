#include "music.h"

int note_playing = 0;
int duration;

const tones imperial_march[] = {
   /* bar 1 and 2 good*/
    {0,  0.1},
    {79.75, 30},
    {0,  0.1},
    {79.75, 30},
    {0,  0.1},
    {79.75, 30},
    {100.5, 22.5},
    {67, 7.5},
    {79.75, 30},
    {100.5, 22.5},
    {67, 7.5},
    {79.75, 60},
    
    /*bar 3 and 4 good*/
    {53.25, 30},
    {0,  0.1},
    {53.25, 30},
    {0,  0.1},
    {53.25, 30},
    {50.25, 22.5},
    {67, 7.5},
    {84.5, 30},
    {100.5, 22.5},
    {67, 7.5},
    {79.75, 60},
    
    /*bar 5  good */
    {39.875, 30},
    {79.75, 22.5},
    {0,  0.1},
    {79.75, 7.5},
    {39.875, 30},
    {42.25, 22.5},
    {44.75, 7.5},
    
    /*bar 6 good*/
    {47.375, 7.5},
    {50.25, 7.5}, 
    {47.375, 15}, 
    {0, 15}, 
    {75.25, 15},
    {56.375, 30},
    {59.75, 22.5},
    {63.25, 7.5},
    
    /* bar 7 good*/
    {67, 7.5},
    {71, 7.5},
    {67, 15},
    {0,  15},
    {100.5, 15},
    {84.5, 30},
    {100.5, 22.5},
    {84.5, 7.5},
    
    /* bar 8 good*/
    {67, 30},
    {79.75, 22.5},
    {67, 7.5},
    {53.25, 60},
    
    /*bar 9 good*/
    {39.875, 30},
    {79.75, 22.5},
    {0,  0.1},
    {79.75, 7.5},
    {39.875, 30},
    {42.25, 22.5},
    {44.75, 7.5},
    
    /*bar 10 good*/
    {47.375, 7.5},
    {50.25, 7.5},
    {47.375, 15},
    {0, 15},
    {75.25, 15},
    {56.375 ,30},
    {59.75 ,22.5},
    {63.25, 7.5},
    
    /*bar 11 good*/
    {67, 7.5},
    {71, 7.5},
    {67, 15},
    {0, 15},
    {100.5, 15},
    {84.5, 30},
    {100.5, 22.5},
    {67, 7.5},
    
    /*bar 12 good*/
    {79.75, 30},
    {100.5, 22.5},
    {67, 7.5},
    {79.75, 60},
    {0, 10}
};

void start_music(){
    
    int volume = 10;

    set_tone(CHANNEL_C, imperial_march[note_playing].period);
    enable_channel(CHANNEL_C, 1, 0);
    set_volume(CHANNEL_C, volume);
    duration = imperial_march[note_playing].duration;
    note_playing++;
}

void update_music(UINT32 time_elapsed){

    duration -= time_elapsed;
    
    if(duration <= 0){
        
        set_tone(CHANNEL_C, imperial_march[note_playing].period);
        duration = imperial_march[note_playing].duration;
        note_playing++;

        if(note_playing == 77){
             note_playing = 0;
        
        } 
            
    }
    
}
