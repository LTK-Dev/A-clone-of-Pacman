#pragma once
#include "src/include/SDL2/SDL.h"
#include "src/include/SDL2/SDL_mixer.h"
#include "src/include/SDL2/SDL_image.h"
#include <vector>
#include <string>
#include <iostream>
#include "Button.h"

class Menu {
    private:
        // Thong so menu
        int arrowHSPos;
        int currentButtonID;
        int currentMenuStatus;
        int currentHTPid;
        // Thong so nut
        int TOTAL_BUTTON;
        int MENU_BUTTON_WIDTH;
        int MENU_BUTTON_HEIGHT;
        int baseScrPosX;
        int baseScrPosY;
        // Thong so text
        TextManager* scoreText = NULL;
        // Thong so sound
        Mix_Chunk* navigationSound = Mix_LoadWAV("Assets/button.wav");
        Mix_Chunk* selectionSound = Mix_LoadWAV("Assets/button.wav");
        // Thong so anh
        SDL_Texture* menuTexture;
        SDL_Texture* howToPlayTexture[3];
        SDL_Texture* highScoreTexture;
        // So luong nut
        std::vector<Button* > menuButton;

        // Bien check running menu
        bool running = false;
        // Ham loadIMG
        SDL_Texture* loadImage(SDL_Renderer* &renderer, const std::string imgPath);
    public:
        // Enum button
        static const int RESUME = 0;
        static const int RUNNING = 1;
        static const int PLAY_BUTTON_PRESSED = 2;
        static const int EXIT_BUTTON_PRESSED = 3;
        static const int HOW_TO_PLAY = 4;
        static const int HIGH_SCORES = 5;
        static const bool ON = true;
        static const bool OFF = false;

        Menu(const int baseScrPosX, const int baseScrPosY, const int totalButton, const int buttonWidth, const int buttonHeight);

        ~Menu();

        void init(SDL_Renderer* &renderer, const std::string imgPath, std::vector<std::string> &buttonText);

        void render(SDL_Renderer* &renderer, const std::vector<std::string> &scoreData);

        void handleEvent(SDL_Event &e, SDL_Renderer* &renderer);

        bool isRunning() const;

        int getStatus() const;

        void reOpen();

        void changeRunStatus();
};

