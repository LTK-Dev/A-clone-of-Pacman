#pragma once
#include "src/include/SDL2/SDL.h"
#include "src/include/SDL2/SDL_mixer.h"
#include "Map.h"
#include "Pacman.h"
#include "Ghost.h"
#include "TextureSrc.h"
#include "TickManager.h"
#include "GameManager.h"
#include "SoundManager.h"

class Engine {
    private:
        Map* map = NULL;

        Pacman* pacman = NULL;

        Ghost* blinky = NULL;
        Ghost* pinky = NULL;
        Ghost* inky = NULL;
        Ghost* clyde = NULL;

        TextureSrc* objectTexture;
        TickManager* tickManager;
        GameManager* gameManager;
        SoundManager* soundManager;

        SDL_Texture* nextLevel;
        SDL_Texture* ready;

        bool runningEGBoard = false;
        int waitTime = 0;
    protected:
        void respawnObject();

        void ghostMove(Ghost* &ghost);

        void pacmanMeatGhost(Ghost* &ghost);

        void renderGhost(SDL_Renderer* &renderer, Ghost* &ghost, int ghostID);
    public:
        Engine() 
        {
            map = nullptr;
            pacman = nullptr;
            blinky = nullptr;
            pinky  = nullptr;
            clyde  = nullptr;
            inky   = nullptr;
            objectTexture = nullptr;
            tickManager   = nullptr;
            gameManager   = nullptr;
            soundManager  = nullptr;
        }

        ~Engine() {
            delete map;
            map = nullptr;
            delete pacman;
            pacman = nullptr;
            delete blinky;
            blinky = nullptr;
            delete pinky;
            pinky = nullptr;
            delete clyde;
            clyde = nullptr;
            delete inky;
            inky = nullptr;
            SDL_DestroyTexture(nextLevel);
            nextLevel = nullptr;
            SDL_DestroyTexture(ready);
            ready = nullptr;
            delete objectTexture;
            objectTexture = nullptr;
            delete tickManager;
            tickManager = nullptr;
            delete gameManager;
            gameManager = nullptr;
            delete soundManager;
            soundManager = nullptr;
        }

        void newGame();

        void init(SDL_Renderer* &renderer);

        void handleEvent(SDL_Event &e, std::vector<std::string> &scoreData);

        void loop(bool &exitToMenu);

        void render(SDL_Renderer* &renderer, const std::vector<std::string> &scoreData);

};


