#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED
#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include "Graphics.h"
#include "defs.h"
#include "ammo.h"
#include "Bot.h"
#include "item.h"
#include "onTarget.h"
#include "scoreTarget.h"


struct Button
{
    SDL_Rect rect;
    bool mouseInButton = 0;

    void initButton(Button &button, SDL_Rect &rct)
    {
        rect = rct;
        button.mouseInButton = 0;
    }

    void initPlay(Button &button)
    {
        SDL_Rect rectPlay;
        rectPlay.x = 170;
        rectPlay.y = 600;
        rectPlay.w = 200;
        rectPlay.h = 100;
        initButton(button, rectPlay);
    }

    void initHowToPlay(Button &button)
    {
        SDL_Rect rectPlay;
        rectPlay.x = 170;
        rectPlay.y = 700;
        rectPlay.w = 200;
        rectPlay.h = 100;
        initButton(button, rectPlay);
    }



};

Button initButtonPlayAgain()
{
    Button playAgain;
    playAgain.rect = {120, 700, 300, 100};
    return playAgain;
}

void initMenu(Button &buttonPlay, Button &buttonHowToPlay)
{
    buttonPlay.initPlay(buttonPlay);
    buttonHowToPlay.initHowToPlay(buttonHowToPlay);
}

bool inButton(Button &button, int posMouse_x, int posMouse_y)
{
    if(posMouse_x >= button.rect.x && posMouse_x <= button.rect.x + button.rect.w
        && posMouse_y >= button.rect.y && posMouse_y <= button.rect.y + button.rect.h)
    {
        return 1;
    }
    return 0;
}


#endif // BUTTON_H_INCLUDED
