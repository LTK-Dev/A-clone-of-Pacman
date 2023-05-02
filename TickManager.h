#pragma once

#include "src/include/SDL2/SDL.h"
#include <stack>

typedef std::pair<const int, double> CID;

class TickManager 
{
    private:
        Uint32 lastTick;
        Uint32 FlastTick;
        Uint32 GlastTick;
        Uint32 lastFrame = 0;

        std::stack<CID> mode;

        int lastStatus;
        bool pause;
        double FRIGHTEN_TIME = 7.0;
        double SCATTERING_TIME = 7.0;
        double CHASING_TIME = 20.0;
    public:
        const int FPS = 60;
        const int FRIGHTEN_MODE = 0;
        const int SCATTERING_MODE = 1;
        const int CHASING_MODE = 2;
        const double oo = -1;

        TickManager();

        double remainFrightenTime() const;

        bool isFrightenTime() const;

        bool isScatteringTime() const;

        void setFrightenTime();

        void resetTick(const int level);

        void updateStatus();

        void stablizeFPS();

        bool pauseTick(const bool status);
};

