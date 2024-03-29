#ifndef BOT_H_INCLUDED
#define BOT_H_INCLUDED

#include <SDL.h>
#include <SDL_image.h>
#include <bits/stdc++.h>
#include "Graphics.h"
#include "ammo.h"
using namespace std;

struct Bots
{
    SDL_Rect rect;
    int hearts = 3;
    bool alive = true;
    int posY;
};

void initBotsWave(vector<Bots>& vectorBots)
{
    int numberOfBotsInit = rand()%6 + 5;

    map<int, int> preBotsPos;

    Bots botTmp;
    botTmp.rect.w = 50;
    botTmp.rect.h = 50;
    botTmp.rect.x = rand()%(SCREEN_WIDTH - botTmp.rect.w);
    botTmp.rect.y = rand()%(SCREEN_HEIGHT/2);

    preBotsPos[botTmp.rect.x] = botTmp.rect.y;

    vectorBots.push_back(botTmp);

    for(int i = 0; i < numberOfBotsInit - 1; i++)
    {
        botTmp.rect.x = rand()%(SCREEN_WIDTH - botTmp.rect.w);
        botTmp.rect.y = rand()%(SCREEN_HEIGHT/2);
        for(auto it : preBotsPos)
        {
            while((botTmp.rect.x >= it.first
                   && botTmp.rect.x <= (it.first + botTmp.rect.w))
                    && (botTmp.rect.y >= it.second
                         && botTmp.rect.y <= (it.second + botTmp.rect.h)))
            {
                botTmp.rect.x = rand()%(SCREEN_WIDTH - botTmp.rect.w);
                botTmp.rect.y = rand()%(SCREEN_HEIGHT/2);
            }
        }
        preBotsPos[botTmp.rect.x] = botTmp.rect.y;
        vectorBots.push_back(botTmp);
    }
}

#endif // BOT_H_INCLUDED
