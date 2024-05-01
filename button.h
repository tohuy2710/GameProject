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

    void initHighScore(Button &button)
    {
        SDL_Rect rectPlay;
        rectPlay.x = 170;
        rectPlay.y = 800;
        rectPlay.w = 200;
        rectPlay.h = 100;
        initButton(button, rectPlay);
    }

    void init_Choose_Aircraft_Pre(Button &button)
    {
        SDL_Rect rectPlay;
        rectPlay.x = 120;
        rectPlay.y = 300;
        rectPlay.w = 50;
        rectPlay.h = 200;
        initButton(button, rectPlay);
    }

        void init_Choose_Aircraft_Next(Button &button)
    {
        SDL_Rect rectPlay;
        rectPlay.x = 370;
        rectPlay.y = 300;
        rectPlay.w = 50;
        rectPlay.h = 200;
        initButton(button, rectPlay);
    }
};

Button initButtonPlayAgain()
{
    Button playAgain;
    playAgain.rect = {120, 700, 300, 100};
    return playAgain;
}

Button initButtonNewGame()
{
    Button newGame;
    newGame.rect = {170,650, 300, 100};
    return newGame;
}

Button initButtonReturnMenu()
{
    Button returnMenu;
    returnMenu.rect = {170, 800, 300, 100};
    return returnMenu;
}

void initMenu(Button &buttonPlay, Button &buttonHowToPlay, Button &buttonHighScore, Button &buttonPre, Button &buttonNext)
{
    buttonPlay.initPlay(buttonPlay);
    buttonHowToPlay.initHowToPlay(buttonHowToPlay);
    buttonHighScore.initHighScore(buttonHighScore);
    buttonPre.init_Choose_Aircraft_Pre(buttonPre);
    buttonNext.init_Choose_Aircraft_Next(buttonNext);
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
