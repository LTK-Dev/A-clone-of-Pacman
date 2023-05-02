/* 
    A clone of Pacman by LTK-DEV
*/

#include "System.h"

int main(int argc, char* argv[]) {

    System* system = new System();

    system->initSDL();

    system->runGame();

    system->quitSDL();

    delete system;
    system = NULL;
    return 0;
}