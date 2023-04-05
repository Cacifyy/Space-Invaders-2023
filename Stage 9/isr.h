#ifndef ISR_H
#define ISR_H

#include "vbl.h"
#include "music.h"
#include "types.h"
#include "def.h"

typedef void (*Vector) ();

extern int vbl_music_timer;
extern int vbl_game_timer;
extern int vbl_armada_fire_timer;
extern int vbl_move_projectiles_timer;
extern int vbl_move_armada_timer;

extern Vector vbl_vector;

void vbl_timers();

Vector install_vector(int num, Vector vector);

void install_vbl_vector();

void uninstall_vbl_vector();


#endif