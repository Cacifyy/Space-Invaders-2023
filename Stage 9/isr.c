#include "isr.h"

int vbl_music_timer = 0;
int vbl_game_timer = 0;
int vbl_armada_fire_timer = 0;
int vbl_move_projectiles_timer = 0;
int vbl_move_armada_timer = 0;

Vector vbl_vector;

void vbl_timers(){
    vbl_music_timer++;
    vbl_game_timer++;
    vbl_armada_fire_timer++;
    vbl_move_projectiles_timer++;
    vbl_move_armada_timer++;
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
