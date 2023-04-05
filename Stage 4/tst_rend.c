
#include <linea.h>

#include "render.h"

int main(){
    void *laser_base = Physbase(); 
    void *cannon_base = Physbase(); 
    void *armada_base = Physbase();
    
    int i;
    int j;

    Laser laser;
    Laser_Cannon laser_cannon;
    Invader invader;
  

    printf("\033E\033f\n");
    


    init_laser(&laser);
    init_armada(&invader);
    init_laser_cannon(&laser_cannon);

    /*
    render_cannon(&laser_cannon, base);
    render_invader(&invader, base, i , j);
    render_laser(&laser, base);
    render_armada(&invader, base);
	*/

    render_master(laser_base, cannon_base, armada_base, &laser_cannon, &laser, &invader);

    Cnecin();
    return 0;

}
