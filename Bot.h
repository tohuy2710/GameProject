#ifndef BOT_H_INCLUDED
#define BOT_H_INCLUDED

#include <SDL.h>
#include <SDL_image.h>
#include "Graphics.h"
#include "ammo.h"


class Bots
{
public:
    SDL_Texture* texture;
    SDL_Rect rect;
    int hp;
    int typeOfBot;
    bool alive;
    bool movingRight = 1;

    void initBot(Bots& bot, Graphics& graphics, int typeOfBot, int x)
    {
        switch(typeOfBot)
        {
        case 1:
            bot.texture = graphics.loadTexture("assets/bot/botTest.png");
            bot.rect.x = x;
            bot.rect.y = 100;
            bot.rect.w = 150;
            bot.rect.h = 150;
            bot.hp = 100;
            break;
        case 2:
            bot.texture = graphics.loadTexture("assets/item/targetA.png");
            bot.rect.x = x;
            bot.rect.y = 0;
            bot.rect.w = 200;
            bot.rect.h = 40;
            bot.hp = 100;
            break;
        }
    }
    void botBeKilled()
    {
        std::cout << "bot.beKilled\n";
        alive = 0;
        rect.w = 0;
        rect.h = 0;
    }
    void botMoving()
    {
        if(rect.x > 400){
            movingRight = 0;
        }
        else if(rect.x <= 0){
            movingRight = 1;
        }
        if(movingRight)
        {
            rect.x += 5;
        }
        else{
            rect.x -= 5;
        }
    }
};

#endif // BOT_H_INCLUDED
