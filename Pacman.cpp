#include "Pacman.h"
#include <iostream>
#include <algorithm>

typedef std::pair<int, std::pair<int, int> > IP;

Pacman::Pacman() : Object(13, 23) 
{
    while (!Direction.empty()) Direction.pop();
    while (!Special.empty())   Special.pop();
}

Pacman::~Pacman()  
{
    while (!Direction.empty()) Direction.pop();
    while (!Special.empty()) Special.pop();
}

bool Pacman::emptyDirStack() 
{
    return Direction.empty();
}

bool Pacman::emptySpecial() 
{
    return Special.empty();
}

void Pacman::pushtoStack(int newDir) 
{
    if (!Direction.empty()) Direction.pop();
    Direction.push(newDir);
}

void Pacman::pushSpecialStack(int newDir, std::pair<int, int> nextCross) 
{
    if (!Special.empty()) 
    {
        if (Special.top().first != newDir) 
        {
            Special.pop();
            Special.push( IP(newDir, nextCross) );
        }
    }
    else Special.push( IP(newDir,nextCross) );
}

int Pacman::getDir() const 
{
    return Direction.top();
}

std::pair<int, int> Pacman::getSpecial() 
{
    return Special.top().second;
}

void Pacman::moving() 
{
    if (!Direction.empty()) 
    {
        int velX = 0, velY = 0, dir = -1;

        switch (Direction.top()) 
        {
            case UP   : velX = 0; velY = -pacmanVelocity; dir = 0; break;
            case DOWN : velX = 0; velY =  pacmanVelocity; dir = 2; break;
            case LEFT : velX = -pacmanVelocity; velY = 0; dir = 3; break;
            case RIGHT: velX =  pacmanVelocity; velY = 0; dir = 1; break;
        }

        changeVelocityDir(velX, velY, dir);

        move();
    }
}

void Pacman::turn() 
{
    if (!Direction.empty()) stopmoving();
    Direction.push(Special.top().first);
    Special.pop();
    //moving();
}

void Pacman::stopmoving() 
{
    while (!Direction.empty()) Direction.pop();
}

void Pacman::eraseSpecial() 
{
    while (!Special.empty()) Special.pop();
}

void Pacman::respawn()
{
    resetObjectTile(PACMAN_START_TILE_X, PACMAN_START_TILE_Y);
    while (!Direction.empty()) Direction.pop();
    while (!Special.empty())   Special.pop();
}