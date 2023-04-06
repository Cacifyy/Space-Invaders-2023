#include "isr.h"

Vector vbl_vector;

vbl_music_timer = 0;
vbl_game_timer = 0;


void vbl_timers(){
    vbl_music_timer++;
    vbl_game_timer++;
   
}

Vector install_vector(int num, Vector vector){
    
    Vector orig;
    Vector *vectp = (Vector *) ((long) num << 2);

    long old_ssp = Super(0);

    orig = *vectp;
    *vectp = vector;

    Super(old_ssp);
    return orig;
}

void install_vbl_vector(){
    vbl_vector = install_vector(VBL_VECTOR_NUMBER, vbl_isr);
}

void uninstall_vbl_vector(){
    install_vector(VBL_VECTOR_NUMBER, vbl_vector);
}
