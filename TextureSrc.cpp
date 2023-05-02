#include "TextureSrc.h"

TextureSrc::TextureSrc() 
{
    tileTexture = NULL;
    pacmanTexture = NULL;
    ghostTexture = NULL;
    ghostScore = NULL;
    pacmanFrame = 0;
    for (int i = 0; i < 5; i++) ghostFrame[i] = 0;
}

TextureSrc::~TextureSrc() 
{
    SDL_DestroyTexture(tileTexture);
    tileTexture = NULL;

    SDL_DestroyTexture(pacmanTexture);
    pacmanTexture = NULL;

    SDL_DestroyTexture(ghostTexture);
    ghostTexture = NULL;

    SDL_DestroyTexture(ghostScore);
    ghostScore = NULL;

    for (int i = 0; i < 5; i++) ghostFrame[i] = 0;
}

bool TextureSrc::pacmanIsDead() 
{
    if (pacmanFrame == 109) 
    {
        pacmanFrame = 0; 
        return true;
    }
    return false;
}

void TextureSrc::loadTileTexture(SDL_Renderer* &renderer) 
{
    SDL_Surface* Image = IMG_Load("Assets/Pacman Tile Labyrinth.png");

    if (Image == NULL) 
    {
        std::cout << "Texture : " << IMG_GetError() << std::endl;
    }
    else 
    {
        tileTexture = SDL_CreateTextureFromSurface(renderer, Image);
        // Load tung tile mot
        int x = 0, y = 0;
        for (int i = 0; i < 32; i++) 
        {
            tileSprite[i] = {x, y, 16, 16};
            y += 17;
            if (i % 4 == 3) x += 17, y = 0;
        }

        std::cout << "Texture : Tile Texture got successfully!" << std::endl;
    }

    SDL_FreeSurface(Image);
    Image = NULL;
}
// Load tile texture
void TextureSrc::renderTileTexture(SDL_Renderer* &renderer, int tileID, SDL_Rect* dsRect) 
{
    SDL_RenderCopy(renderer, tileTexture, &tileSprite[ tileID ], dsRect);
}
// Load Pacman va Ghost
void TextureSrc::loadPacmanAndGhostTexture(SDL_Renderer* &renderer) 
{
    SDL_Surface* Image = IMG_Load("Assets/Pacman and Ghost Texture.png");

    if (Image == NULL) 
    {
        std::cout << "Texture : " <<  IMG_GetError() << std::endl;
    }
    else 
    {
        pacmanTexture = SDL_CreateTextureFromSurface(renderer, Image);

        int posTexX = 0, posTexY = 0;

        /// Pacman up
        for (int i = 0; i < 3; i++)  pacmanUP[i] = {posTexX, posTexY, 30, 30}, posTexX += 31;
        /// Pacman down
        for (int i = 0; i < 3; i++)  pacmanDOWN[i] = {posTexX, posTexY, 30, 30}, posTexX += 31;
        /// Pacman left
        for (int i = 0; i < 3; i++)  pacmanLEFT[i] = {posTexX, posTexY, 30, 30}, posTexX += 31;
        /// Pacman right
        for (int i = 0; i < 3; i++) pacmanRIGHT[i] = {posTexX, posTexY, 30, 30}, posTexX += 31;
        // Set lai vi tri x
        posTexX = 0;
        /// Pacman dead
        for (int i = 0; i < 11; i++) pacmanDEAD[i] = {posTexX, 155, 30, 30}, posTexX += 31;

        std::cout << "Texture : Pacman Texture got successfully!" << std::endl;

        SDL_FreeSurface(Image);
        Image = IMG_Load("Assets/Object.png");
        ghostTexture = SDL_CreateTextureFromSurface(renderer, Image);

        posTexX = 0; posTexY = 0;
        for (int i = 0 ; i < TOTAL_GHOST - 1 ; i++) 
        {
            ghost[i][UP   ][0] = {posTexX, posTexY, 47, 47}; posTexX += 48;
            ghost[i][UP   ][1] = {posTexX, posTexY, 47, 47}; posTexX += 48;
            ghost[i][RIGHT ][0] = {posTexX, posTexY, 47, 47}; posTexX += 48;
            ghost[i][RIGHT ][1] = {posTexX, posTexY, 47, 47}; posTexX += 48;
            ghost[i][DOWN ][0] = {posTexX, posTexY, 47, 47}; posTexX += 48;
            ghost[i][DOWN ][1] = {posTexX, posTexY, 47, 47}; posTexX += 48;
            ghost[i][LEFT ][0] = {posTexX, posTexY, 47, 47}; posTexX += 48;
            ghost[i][LEFT ][1] = {posTexX, posTexY, 47, 47}; posTexX = 0;
            posTexY += 48;
        }
        std::cout << "Texture : Basic ghost Texture load successfully!" << std::endl;

    
        for (int i = 0 ; i < TOTAL_GHOST -1 ; i++)
        {
            // Set anh frighten ghost
            ghost[i][FRIGHTEN_GHOST_1][0] = {0, 193, 48, 48};
            ghost[i][FRIGHTEN_GHOST_1][1] = {49, 193, 48, 48};
            ghost[i][FRIGHTEN_GHOST_2][0] = {98, 193, 48, 48};
            ghost[i][FRIGHTEN_GHOST_2][1] = {147, 193, 48, 48};
            // Set anh ghost bi an
            ghost[GHOST_SPIRIT][UP   ][0] = {196, 193, 48, 48};
            ghost[GHOST_SPIRIT][UP   ][1] = {196, 193, 48, 48};
            ghost[GHOST_SPIRIT][RIGHT ][0] = {245, 193, 48, 48};
            ghost[GHOST_SPIRIT][RIGHT ][1] = {245, 193, 48, 48};
            ghost[GHOST_SPIRIT][DOWN ][0] = {294, 193, 48, 48};
            ghost[GHOST_SPIRIT][DOWN ][1] = {294, 193, 48, 48};
            ghost[GHOST_SPIRIT][LEFT][0] = {343, 193, 48, 48};
            ghost[GHOST_SPIRIT][LEFT][1] = {343, 193, 48, 48};
        }

        std::cout << "Texture : Fighten ghost load successfully!" << std::endl;
        
        // Load score ghost
        SDL_FreeSurface(Image);
        Image = IMG_Load("Assets/ghostscore.png");
        ghostScore = SDL_CreateTextureFromSurface(renderer, Image);

        std::cout << "Texture : Ghost Texture got successfully!" << std::endl;
    }

    SDL_FreeSurface(Image);
    Image = NULL;
}

void TextureSrc::renderPacmanTexture(SDL_Renderer* &renderer, int posX, int posY, int status) 
{
    SDL_Rect srcRect, dsRect;
    dsRect = {posX - 7 + 217, posY - 7, 30, 30};
    ++pacmanFrame;

    if (status != DEAD_PACMAN && pacmanFrame == 30) pacmanFrame = 0;

    switch (status) 
    {
        case -1: srcRect = pacmanUP[0]; break;
        case UP:    srcRect = pacmanUP   [ pacmanFrame / 10 ]; break;
        case RIGHT: srcRect = pacmanRIGHT[ pacmanFrame / 10 ]; break;
        case DOWN:  srcRect = pacmanDOWN [ pacmanFrame / 10 ]; break;
        case LEFT:  srcRect = pacmanLEFT [ pacmanFrame / 10 ]; break;
        case DEAD_PACMAN: srcRect = pacmanDEAD[pacmanFrame / 10]; break;
    }

    SDL_RenderCopy(renderer, pacmanTexture, &srcRect, &dsRect);
}

void TextureSrc::renderGhostTexture(SDL_Renderer* &renderer, int posX, int posY, int ghostID, int status) 
{
    SDL_Rect srcRect, dsRect;
    dsRect = {posX - 7 + 217, posY - 7, 30, 30};
    ++ghostFrame[ghostID];

    if (ghostFrame[ghostID] == 10) ghostFrame[ghostID] = 0;

    switch (status) 
    {
        case UP:    srcRect = ghost[ ghostID ][UP   ][ ghostFrame[ghostID] / 5 ]; break;
        case RIGHT: srcRect = ghost[ ghostID ][RIGHT][ ghostFrame[ghostID] / 5 ]; break;
        case DOWN:  srcRect = ghost[ ghostID ][DOWN ][ ghostFrame[ghostID] / 5 ]; break;
        case LEFT:  srcRect = ghost[ ghostID ][LEFT ][ ghostFrame[ghostID] / 5 ]; break;
        case FRIGHTEN_GHOST_1: srcRect = ghost[ghostID][FRIGHTEN_GHOST_1][ghostFrame[ghostID] / 5]; break;
        case FRIGHTEN_GHOST_2:
            if (ghostFrame[ghostID] / 5 == 0) srcRect = ghost[ghostID][FRIGHTEN_GHOST_1][ghostFrame[ghostID] / 5];
            else srcRect = ghost[ghostID][FRIGHTEN_GHOST_2][ghostFrame[ghostID] / 5];
            break;
    }

    SDL_RenderCopy(renderer, ghostTexture, &srcRect, &dsRect);
}

void TextureSrc::renderGhostScore(SDL_Renderer* &renderer, const int eatenGhostPosX, const int eatenGhostPosY, const int eatenGhostStreak) 
{
    SDL_Rect srcRect, dsRect;
    switch (eatenGhostStreak) {
        case 0: srcRect = { 0,  0, 50, 50}; break;
        case 1: srcRect = {50,  0, 50, 50}; break;
        case 2: srcRect = { 0, 50, 50, 50}; break;
        case 3: srcRect = {50, 50, 50, 50}; break;
    }
    dsRect = {eatenGhostPosX + 210, eatenGhostPosY - 7, 30, 30};
    SDL_RenderCopy(renderer, ghostScore, &srcRect, &dsRect);
}
