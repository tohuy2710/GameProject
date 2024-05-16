#ifndef BOT_H_INCLUDED
#define BOT_H_INCLUDED

#include <SDL.h>
#include <SDL_image.h>
#include <bits/stdc++.h>
#include "Graphics.h"
#include "ammo.h"
#include "player.h"
using namespace std;

struct Bots
{
    SDL_Rect rect;
    int hearts = 1;
    bool alive = true;
    char typeBot = 't';
    int init_Hearts = 1;
};

void randomBotsPos(Bots &botTmp, map<int, int> &preBotsPos) {
    botTmp.hearts = 2;
    botTmp.init_Hearts = 2;
    botTmp.rect.x = rand() % (SCREEN_WIDTH - botTmp.rect.w);
    botTmp.rect.y = rand() % (SCREEN_HEIGHT / 2 - 80) + 80;

    for (auto it : preBotsPos) {
        if (botTmp.rect.x >= it.first - botTmp.rect.w &&
            botTmp.rect.x <= it.first + botTmp.rect.w &&
            botTmp.rect.y >= it.second - botTmp.rect.h &&
            botTmp.rect.y <= it.second + botTmp.rect.h) {
            randomBotsPos(botTmp, preBotsPos);
            return;
        }
    }
}

void initBotsWave(vector<Bots>& vectorBots) {
    int numberOfBotsInit = rand() % 6 + 6;
    map<int, int> preBotsPos;

    for (int i = 0; i < numberOfBotsInit; i++) {
        Bots botTmp;
        botTmp.rect.w = 50;
        botTmp.rect.h = 50;

        randomBotsPos(botTmp, preBotsPos);


        vectorBots.push_back(botTmp);
        preBotsPos[botTmp.rect.x] = botTmp.rect.y;
    }
}


Bots initBoss_A()
{
    Bots boss;
    boss.rect.y = 300;
    boss.rect.w = 125;
    boss.rect.h = 100;
    boss.rect.x = SCREEN_WIDTH/2 - boss.rect.w/2;
    boss.hearts = 30;
    boss.init_Hearts = 30;
    boss.typeBot = 'a';
    return boss;
}

Bots initBoss_B()
{
    Bots boss;
    boss.rect.y = 300;
    boss.rect.w = 200;
    boss.rect.h = 175;
    boss.rect.x = SCREEN_WIDTH/2 - boss.rect.w/2;
    boss.hearts = 60;
    boss.init_Hearts = 60;
    boss.typeBot = 'b';
    return boss;
}

void movingCircle(SDL_Rect &rect, int& movingDegree, int r,
                   int deltaSlope, int firstX, int firstY)
{
    rect.x = firstX + r*cos(3.14*(movingDegree%360)/180);
    rect.y = firstY + r*sin(3.14*(movingDegree%360)/180);
    movingDegree += deltaSlope;
    movingDegree %= 360;
}

void movingHorizontalRandom(Bots &bot)
{
    bool right = rand()%2;
    if(bot.rect.x + bot.rect.w >= SCREEN_WIDTH)
    {
        right = 0;
    }
    if(bot.rect.x <= 0)
    {
        right = 1;
    }
    if(right)
    {
        bot.rect.x += 5;
    }
    else
    {
        bot.rect.x -= 5;
    }
}

void movingVerticalRandom(Bots &bot)
{
    bool down = rand()%2;
    if(bot.rect.y + bot.rect.h >= SCREEN_HEIGHT/2)
    {
        down = 0;
    }
    if(bot.rect.y <= 80)
    {
        down = 1;
    }
    if(down)
    {
        bot.rect.y += 5;
    }
    else
    {
        bot.rect.y -= 5;
    }
}

Bots initBoss_C()
{
    Bots boss;
    boss.rect.w = 255;
    boss.rect.h = 175;
    boss.rect.x = SCREEN_WIDTH/2 - boss.rect.w/2;
    boss.rect.y = 300;
    boss.hearts = 100;
    boss.init_Hearts = 100;
    boss.typeBot = 'c';
    return boss;
}

void initHPBar(vector<SDL_Rect>& hpBarWhite, vector<SDL_Rect>& hpBarRed, vector<Bots>& bots)
{
    for(Bots bot : bots)
    {
        SDL_Rect tmp;
        tmp.x = bot.rect.x;
        tmp.y = bot.rect.y - 10;
        tmp.h = 10;
        tmp.w = 50;

        hpBarWhite.push_back(tmp);

        tmp.w = (bot.hearts/2)*50;

        hpBarRed.push_back(tmp);
    }
}


void initHPBar_BigBot(vector<SDL_Rect>& hpBarWhite, vector<SDL_Rect>& hpBarRed, Bots bigBot)
{
    SDL_Rect tmp;
    tmp.x = bigBot.rect.x;
    tmp.y = bigBot.rect.y - 10;
    tmp.w = bigBot.rect.w;
    tmp.h = 10;

    hpBarWhite.push_back(tmp);
    hpBarRed.push_back(tmp);
}



#endif // BOT_H_INCLUDED
