#include "TextManager.h"

TextManager::TextManager(int fontSize) 
{
    font = TTF_OpenFont(FONT_NAME.c_str(), fontSize);
    textTexture = NULL;
    textSurface = NULL;
}

TextManager:: ~TextManager() 
{
    if (font != NULL) 
    {
        TTF_CloseFont(font);
        font = NULL;
    }

    if (textTexture != NULL) 
    {
        SDL_DestroyTexture(textTexture);
        textTexture = NULL;
    }

    if (textSurface != NULL) 
    {
        SDL_FreeSurface(textSurface);
        textSurface = NULL;
    }
}

int TextManager::getTextWidth() const 
{
    return textSurface->w;
}

void TextManager::loadRenderText(SDL_Renderer* &renderer, std::string text, SDL_Color textColor) 
{
    // Load font vao surface
    if (textSurface != NULL) SDL_FreeSurface(textSurface);
    textSurface = TTF_RenderText_Blended(font, text.c_str(), textColor);
    // Tao texture tuong ung voi surface
    if (textTexture != NULL) SDL_DestroyTexture(textTexture);
    textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
}

void TextManager::renderText(SDL_Renderer* &renderer, int scrPosX, int scrPosY, const int type)
{
    dsRect = {scrPosX, scrPosY, textSurface->w, textSurface->h};
    // Render text ra giua window
    if (type == CENTER) 
    {
        dsRect.x = scrPosX - textSurface->w / 2;
        dsRect.y = scrPosY - textSurface->h / 2;
    }
    SDL_RenderCopy(renderer, textTexture, NULL, &dsRect);
}
