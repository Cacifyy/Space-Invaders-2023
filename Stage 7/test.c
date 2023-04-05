#include "test.h"

/* 
Function name: main
Input:  

Output: music and sound effectss
Function details: test function to see if the music and sound effects work before game 
                  implementation
*/


int main(){
    UINT32 curr_clock;
    UINT32 old_clock = 0;
    UINT32 time;
    int test = 1;
    
    start_music();
    
    while( test){
        curr_clock = game_clock();
        time = curr_clock - old_clock; 
        
         if (time > 0) {
            
            update_music(time);
            
            /*
            explosion_sound();
            */
            
            
            
             
        }
        
       
        if (Cconis())
        {
            
            test = 0;
            
            Cnecin();
        } 
        old_clock = curr_clock; 
    }
    

     
    stop_sound();
    return 0;
}



UINT32 game_clock() {

    UINT32 curr_clock;
    long old_ssp;

    old_ssp = Super(0);
    curr_clock = *((UINT32 *)0x462);
    Super(old_ssp);

    return curr_clock;

}