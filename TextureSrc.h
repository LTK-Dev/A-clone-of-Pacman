#pragma once


#include "src/include/SDL2/SDL.h"
#include "src/include/SDL2/SDL_image.h"
#include <iostream>

class TextureSrc {
    private:
        // Map texture 
        SDL_Texture* tileTexture;
        // Map tile
        SDL_Rect tileSprite[32];
        // Object texture
        SDL_Texture*  pacmanTexture;
        SDL_Texture*  ghostTexture; 
        SDL_Texture* ghostScore;
        // Object sprite
        SDL_Rect pacmanUP[3];
        SDL_Rect pacmanDOWN[3];
        SDL_Rect pacmanLEFT[3];
        SDL_Rect pacmanRIGHT[3];
        SDL_Rect pacmanDEAD[11];
        SDL_Rect ghost[5][6][2];
        // Object frame
        int pacmanFrame;
        int ghostFrame[5];
    public:
        static const int UP = 0;
        static const int RIGHT = 1;
        static const int DOWN = 2;
        static const int LEFT = 3;

        static const int FRIGHTEN_GHOST_2 = 5;
        static const int FRIGHTEN_GHOST_1 = 4;
        static const int DEAD_PACMAN = 5;

        static const int BLINKY = 0;
        static const int PINKY  = 1;
        static const int INKY   = 2;
        static const int CLYDE  = 3;
        static const int GHOST_SPIRIT = 4;
        static const int TOTAL_GHOST = 5;

        TextureSrc();

        ~TextureSrc();

        bool pacmanIsDead();

        void loadTileTexture(SDL_Renderer* &renderer);

        void renderTileTexture(SDL_Renderer* &renderer, int tileID, SDL_Rect* dsRect);

        void loadPacmanAndGhostTexture(SDL_Renderer* &renderer);

        void renderPacmanTexture(SDL_Renderer* &renderer, int posX, int posY, int status);

        void renderGhostTexture(SDL_Renderer* &renderer, int posX, int posY, int ghostID, int status);

        void renderGhostScore(SDL_Renderer* &renderer, const int eatenGhostPosX, const int eantenGhostPosY, const int eatenGhostStreak);
};


