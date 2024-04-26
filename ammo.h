#ifndef AMMO_H_INCLUDED
#define AMMO_H_INCLUDED
#include <bits/stdc++.h>
#include "player.h"
#include "Bot.h"
#include "Graphics.h"
using namespace std;

struct Bullet
{
    SDL_Rect rect;
    bool active = true;
    char typeBullet = '0';
    double speed;
    double acceleration = 0;
    double slope;
    int damage = 1;
};

struct Shield
{
    SDL_Rect rect;
    bool active = false;
    int hp = 15;
};

void initMeteorite(vector<Bullet> &meteorites)
{
    Bullet meteo;
    meteo.rect.w = rand()%60 + 20;
    meteo.rect.h = meteo.rect.w;
    meteo.rect.x = rand()%(540 - meteo.rect.w);
    meteo.rect.y = 0;
    meteo.damage = meteo.rect.w/10;
    meteo.speed = 5;
    meteo.acceleration = 0.3;
    meteorites.push_back(meteo);
}

void initMeteoDebris(Bullet meteo, vector<Bullet> &vectorMeteorites)
{
    int numDebris = rand() % 4 + 4;
    for(int i = 0; i < numDebris; i++)
    {
        Bullet debris;
        debris.rect.x = meteo.rect.x;
        debris.rect.y = meteo.rect.y;
        debris.rect.w = meteo.rect.w*2/numDebris;
        debris.rect.h = meteo.rect.h*2/numDebris;
        debris.speed = rand() % 5 + 3;
        debris.acceleration = 0;
        debris.slope = 2*3.14 - i*2*3.14/numDebris;
        debris.damage = debris.rect.x/10;
        vectorMeteorites.push_back(debris);
    }
}

void initPlayerBullets(Player &player, vector<Bullet> &vectorPlayerBullets)
{
    Bullet playerBullets[3];
    for(int i = 0; i < 3; i++)
    {
        playerBullets[i].rect.w = 8;
        playerBullets[i].rect.h = 20;
        playerBullets[i].speed = 20;
    }
    playerBullets[0].rect.x = player.rect.x + player.rect.w/2 - playerBullets[0].rect.w;
    playerBullets[0].rect.y = player.rect.y;
    playerBullets[0].slope = 0;
    playerBullets[1].rect.x = player.rect.x;
    playerBullets[1].rect.y = player.rect.y + 20;
    playerBullets[1].slope = -10*3.14/180;
    playerBullets[2].rect.x = player.rect.x + player.rect.w - playerBullets[2].rect.w;
    playerBullets[2].rect.y = player.rect.y + 20;
    playerBullets[2].slope = 10*3.14/180;
    for(int i = 0; i < 3; i++)
    {
        vectorPlayerBullets.push_back(playerBullets[i]);
    }
}

void initSkill_Bot_Skill_E(vector<Bots> &vectorBots_Skill_E, vector<Bullet> &vectorPlayerBullets)
{
    Bullet skill_e;
    skill_e.rect.w = 10;
    skill_e.rect.h = 10;
    skill_e.acceleration = 2;
    skill_e.speed = 10;
    for(size_t i = 0; i < vectorBots_Skill_E.size(); i++)
    {
        skill_e.rect.x = vectorBots_Skill_E[i].rect.x + 10;
        skill_e.rect.y = vectorBots_Skill_E[i].rect.y;
        vectorPlayerBullets.push_back(skill_e);
    }
}

void initBot_Skill_E(Player &player, vector<Bots> &vectorBots_Skill_E)
{
    Bots boss;
    boss.rect.w = 40;
    boss.rect.h = 40;
    boss.rect.x = player.rect.x - 10;
    boss.rect.y = player.rect.y -= 50;
    boss.hearts = 100;
    boss.typeBot = 'e';
    vectorBots_Skill_E.push_back(boss);
    boss.rect.x = player.rect.x + player.rect.w + 10;
    vectorBots_Skill_E.push_back(boss);
}

void initPlayerSkillW(Player &player, vector<Bullet> &vectorplayerBullets)
{
    Bullet playerBullets[5];
    double slope_tmp = -20*3.14/180;
    for(int i = 0; i < 5; i++)
    {
        playerBullets[i].rect.w = 20;
        playerBullets[i].rect.h = 40;
        playerBullets[i].rect.x = player.rect.x + player.rect.w/2 - playerBullets[i].rect.w/2;
        playerBullets[i].rect.y = player.rect.y;
        playerBullets[i].speed = 1;
        playerBullets[i].acceleration = 2;
        playerBullets[i].slope = slope_tmp;
        playerBullets[i].typeBullet = 'w';
        slope_tmp += 10*3.14/180;
        vectorplayerBullets.push_back(playerBullets[i]);
    }
}

Shield initPlayerSkillQ(Player &player)
{
    Shield q;
    q.rect.x = player.rect.x - 22;
    q.rect.y = player.rect.y - 22;
    q.rect.w = 120;
    q.rect.h = 120;
    q.active = true;
    return q;
}

void initBotBullets(vector<Bots> &vectorBots, vector<Bullet> &vectorBotsBullets)
{
    Bullet botBullets;
    for(size_t j = 0; j < vectorBots.size(); j++)
    {
        botBullets.rect.w = 20;
        botBullets.rect.h = 20;
        botBullets.rect.x = vectorBots[j].rect.x + vectorBots[j].rect.w/2;
        botBullets.rect.y = vectorBots[j].rect.y + vectorBots[j].rect.h;
        botBullets.speed = 8;
        vectorBotsBullets.push_back(botBullets);
    }
}

void initBoss_A_Skill(Bots &bigBot, vector<Bullet> &vectorBigBotBullets)
{
    Bullet botBullets;

    botBullets.rect.w = 50;
    botBullets.rect.h = 50;
    botBullets.rect.x = bigBot.rect.x + bigBot.rect.w/2 - botBullets.rect.w/2;
    botBullets.rect.y = bigBot.rect.y + bigBot.rect.h - 15;
    botBullets.speed = 15;
    botBullets.slope = 30*3.14/180;
    botBullets.typeBullet = 'A';
    botBullets.damage = 2;

    for(int i = 0; i < 3; i++)
    {
    vectorBigBotBullets.push_back(botBullets);
    botBullets.slope -= 30*3.14/180;
    }
}

void initBoss_B_Skill(SDL_Rect& rect, vector<Bullet> &vectorBigBotBullets)
{
    Bullet botBullets;

    botBullets.rect.w = 20;
    botBullets.rect.h = 20;
    botBullets.rect.x = rect.x + rect.w/2 - botBullets.rect.w/2;
    botBullets.rect.y = rect.y + rect.h/2;
    botBullets.speed = 1;
    botBullets.slope = 360*3.14/180;
    botBullets.acceleration = 1;
    botBullets.typeBullet = 'B';
    botBullets.damage = 2;

    for(int i = 0; i < 24; i++)
    {
    vectorBigBotBullets.push_back(botBullets);
    botBullets.slope -= 15*3.14/180;
    }
}

void initBoss_C_Skill(Bots &bigBot, vector<Bullet> &vectorBigBotBullets)
{
    Bullet botBullets[2];

    botBullets[0].rect.x = bigBot.rect.x + 50;
    botBullets[1].rect.x = bigBot.rect.x + bigBot.rect.w - 50;

    for(int i = 0; i <= 1; i++)
    {
        botBullets[i].rect.y = bigBot.rect.y + bigBot.rect.h;
        botBullets[i].rect.w = 30;
        botBullets[i].rect.h = 30;
        botBullets[i].speed = 15;
        botBullets[i].typeBullet = 'C';
        botBullets[i].damage = 3;
        vectorBigBotBullets.push_back(botBullets[i]);
    }
}

void initBoss_C_Skill_Pro(Bots &bigBot, vector<Bullet> &vectorBigBotBullets)
{
    Bullet botBullets;
    botBullets.rect.x = bigBot.rect.x + bigBot.rect.w/2;

    for(int i = 0; i <= 2; i++)
    {
        botBullets.rect.y = bigBot.rect.y + bigBot.rect.h - i*40;
        botBullets.rect.w = 30;
        botBullets.rect.h = 30;
        botBullets.speed = 15;
        botBullets.typeBullet = 'C';
        botBullets.damage = 3;
        vectorBigBotBullets.push_back(botBullets);
    }
}

void initBoss_C_Bullet_Skill(SDL_Rect& rect, vector<Bullet> &vectorBigBotBullets)
{
    Bullet botBullets;

    botBullets.rect.w = 10;
    botBullets.rect.h = 10;
    botBullets.rect.x = rect.x + rect.w/2 - botBullets.rect.w/2;
    botBullets.rect.y = rect.y + rect.h/2;
    botBullets.speed = 10;
    botBullets.slope = 360*3.14/180;
    botBullets.typeBullet = '1';
    botBullets.damage = 1;

    for(int i = 0; i < 10; i++)
    {
    vectorBigBotBullets.push_back(botBullets);
    botBullets.slope -= 36*3.14/180;
    }
}

void initItem(Bots &bot, vector<Bullet> &vectorItem)
{
    int ranNum;
    switch(bot.typeBot)
    {
    case 't':
        ranNum = rand()%20 + 1;
        break;
    case 'a':
        ranNum = rand()%5 + 1;
        break;
    case 'b':
        ranNum = rand()%3 + 1;
        break;
    case 'c':
        ranNum = 1;
        break;
    }
    if(ranNum == 1)
    {
        int randomSkill = rand()%5 + 1;
        Bullet item;
        switch(randomSkill)
        {
        case 1:
            item.typeBullet = 'Q';
            break;
        case 2:
            item.typeBullet = 'W';
            break;
        case 3:
            item.typeBullet = 'E';
            break;
        case 4:
            item.typeBullet = 'H';
            break;
        case 5:
            item.typeBullet = 'F';
            break;
        }

        item.rect.w = 50;
        item.rect.h = 50;
        item.rect.x = bot.rect.x + bot.rect.w/2 - item.rect.w/2;
        item.rect.y = bot.rect.y + bot.rect.h/2 - item.rect.h/2;

        item.speed = 5;
        item.damage = 0;
        vectorItem.push_back(item);
    }

}

#endif // AMMO_H_INCLUDED


