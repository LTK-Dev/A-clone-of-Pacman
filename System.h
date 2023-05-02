#pragma once
#include "src/include/SDL2/SDL.h"
#include "src/include/SDL2/SDL_ttf.h"
#include "src/include/SDL2/SDL_mixer.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "GameStateManager.h"
#include "Button.h"

class System {
    private:
        // Thong so window
        SDL_Window* window = NULL;
        SDL_Renderer* renderer = NULL;
        // Cac bien file khac
        Menu* startMenu = NULL;
        GameStateManager* gameState = NULL;
        // Bien ghi va doc highscore
        std::vector<std::string> highScore;
        // Bien kiem tra chay
        bool Running = false;
        bool runningMenu = false;
    public:
        static const int SCREEN_WIDTH = 882;
        static const int SCREEN_HEIGHT = 496;
        
        const std::string WINDOW_TITTLE = "A clone of Pacman";
        
        std::vector<std::string> startMenuButtonText = {"New Game", "How to Play", "High Scores", "Sound: ON", "Quit Game"};

        System();

        ~System();

        void initSDL();

        void quitSDL();

        void runGame();

};


