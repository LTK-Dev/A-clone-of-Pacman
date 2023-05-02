#pragma once
#include "Object.h"
#include <stack>

class Pacman : public Object 
{
    private:
        std::stack<int> Direction;
        std::stack< std::pair<int, std::pair<int, int> > > Special;

    public:
        static const int pacmanVelocity = 2;
        static const int PACMAN_START_TILE_X = 13;
        static const int PACMAN_START_TILE_Y = 23;

        Pacman();

        ~Pacman();

        bool emptyDirStack();

        bool emptySpecial();

        void pushtoStack(int newDir);

        void pushSpecialStack(int newDir, std::pair<int, int> nextCross);

        int getDir() const;

        std::pair<int, int> getSpecial();

        void moving();

        void stopmoving();

        void turn();

        void eraseSpecial();

        void respawn();
};


