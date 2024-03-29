#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Engine.h"
#include "src/include/SDL2/SDL_mixer.h"
#include "Button.h"
#include "Menu.h"

class GameStateManager 
{
    private:
        std::vector<std::string> scoreData;
        std::vector<int> muteChannel;
        Engine* engine = NULL;
        Menu* pauseMenu = NULL;
        //bool running = true;
        bool runPauseMenu = false;
    public:
        std::vector<std::string> pauseMenuButtonText = {"Resume", "New Game", "How to Play", "Sound: ON", "Exit to Start Menu"};
        
        GameStateManager();

        ~GameStateManager();

        void handleEvent(SDL_Event &e, SDL_Renderer* &renderer, bool &runningMain, std::vector<std::string> &scoreData);

        void newGame(SDL_Renderer* &renderer);

        void runGame(bool &exitToMenu);

        void render(SDL_Renderer* &renderer, const std::vector<std::string> &scoreData);
};


