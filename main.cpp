/* 
    A clone of Pacman by LTK-DEV
    https://github.com/LTK-Dev/A-clone-of-Pacman
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
