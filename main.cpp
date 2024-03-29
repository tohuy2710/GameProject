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
#include "button.h"
using namespace std;

int main(int argc, char *argv[])
{
    Graphics graphics;
    graphics.init();

    SDL_Texture* menuBackground = graphics.loadTexture(MENU_BACKGROUND_FILE);

    Button buttonPlay, buttonHowToPlay;
    initMenu(buttonPlay, buttonHowToPlay, graphics);

    Sprite buttonPlaySprite;
    SDL_Texture* buttonPlaySpriteTexture = graphics.loadTexture(BUTTON_PLAY_SPRITE_FILE);
    buttonPlaySprite.init(buttonPlaySpriteTexture, BUTTON_PLAY_FRAMES, BUTTON_PLAY_CLIPS);

    Sprite buttonHTPSprite;
    SDL_Texture* buttonHTPSpriteTexture = graphics.loadTexture(BUTTON_HTP_SPRITE_FILE);
    buttonHTPSprite.init(buttonHTPSpriteTexture, BUTTON_HTP_FRAMES, BUTTON_HTP_CLIPS);

    SDL_Texture* guideTexture = graphics.loadTexture(GUIDE_FILE);

    bool quit_menu = false;
    bool playGame = false;
    bool readGuide = false;
    SDL_Event e;

//    graphics.presentScene();

    int posMouse_x, posMouse_y;
    int speedScroll = 1;
    while(!quit_menu)
    {
        while(SDL_PollEvent(&e) != 0)
        {
            if(e.type == SDL_QUIT)
            {
                quit_menu = true;
            }
            SDL_GetMouseState(&posMouse_x, &posMouse_y);
            if(inButton(buttonPlay, graphics, posMouse_x, posMouse_y))
            {
                buttonPlaySprite.currentFrame = 1;
                if(e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
                {
                    playGame = true;
                    quit_menu = true;
                }
            }
            else
            {
                buttonPlaySprite.currentFrame = 0;
            }
            if(inButton(buttonHowToPlay, graphics, posMouse_x, posMouse_y))
            {
                buttonHTPSprite.currentFrame = 1;
                if(e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
                {
                    menuBackground = graphics.loadTexture(BACKGROUND_FILE);
                    readGuide = true;
                    buttonPlay.rect.y = 800;
                }
            }
            else
            {
                buttonHTPSprite.currentFrame = 0;
            }
        }
        graphics.renderFullscreen(menuBackground);
        graphics.renderSprite(buttonPlay.rect.x, buttonPlay.rect.y, buttonPlaySprite);
        graphics.renderSprite(buttonHowToPlay.rect.x, buttonHowToPlay.rect.y, buttonHTPSprite);
        if(readGuide)
        {
            graphics.renderTexture(guideTexture, 0, 0, 540, 800, graphics.renderer);
        }
        else
        {
            graphics.renderSprite(buttonHowToPlay.rect.x, buttonHowToPlay.rect.y, buttonHTPSprite);
        }
        graphics.presentScene();
    }
    cout << "out loop\n";

    SDL_DestroyTexture(buttonPlaySpriteTexture); buttonPlaySpriteTexture = NULL;
    SDL_DestroyTexture(buttonHTPSpriteTexture); buttonHTPSpriteTexture = NULL;
    SDL_DestroyTexture(menuBackground); menuBackground = NULL;

    if(playGame)
    {
        ScrollingBackground background;
        background.setTexture(graphics.loadTexture(BACKGROUND_FILE));

        Sprite playerSprite;
        SDL_Texture* playerSpriteTexture = graphics.loadTexture(PLAYER_SPRITE_FILE);
        playerSprite.init(playerSpriteTexture, PLAYER_FRAMES, PLAYER_CLIPS);

        Sprite botSprite;
        SDL_Texture* botSpriteTexture = graphics.loadTexture(BOT_SPRITE_FILE);
        botSprite.init(botSpriteTexture, BOT_FRAMES, BOT_CLIPS);

        Sprite stone_01_Sprite;
        SDL_Texture* stone_01_SpriteTexture = graphics.loadTexture(STONE_01_SPRITE_FILE);
        stone_01_Sprite.init(stone_01_SpriteTexture, STONE_01_FRAMES, STONE_01_CLIPS);

        SDL_Texture* playerBulletTexture = graphics.loadTexture(PLAYER_BULLET_FILE);

        Player player;
        player.initPlayer(player);

        vector<Bullet> vectorPlayerBullets;
        Bullet botBullet;
        bool bulletInRange = false;

        int numOfBots = 0;
        vector<Bots> vectorBots;
        bool quitGame = false;

        while(!quitGame)
        {
            while(SDL_PollEvent(&e) != 0)
            {
                if(e.type == SDL_QUIT)
                {
                    quitGame = true;
                    cerr << "score: " << player.score << endl;
                }
                else if(player.alive)
        //=====player=====
                {
                    if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
                    {
                        initPlayerBullets(player, vectorPlayerBullets);
                    }
                    SDL_GetMouseState(&player.rect.x, &player.rect.y);
                    player.rect.x = player.rect.x - player.rect.w/2;
                    player.rect.y = player.rect.y - player.rect.h/2;
                }
            }

        //====Bot====

            if(numOfBots == 0)
            {
                initBotsWave(vectorBots);
                numOfBots += vectorBots.size();
            }

        //====load background (load first for load item after)====
            background.scroll(speedScroll);
            graphics.renderBackground(background);

        //====load player skill====
            for (int i = 0; i < vectorPlayerBullets.size(); i++)
            {
                if (vectorPlayerBullets[i].active)
                {
                    vectorPlayerBullets[i].rect.y -= vectorPlayerBullets[i].speed;
                    graphics.renderInRect(playerBulletTexture, vectorPlayerBullets[i].rect); //
                    if (vectorPlayerBullets[i].rect.x > SCREEN_WIDTH || vectorPlayerBullets[i].rect.x + vectorPlayerBullets[i].rect.w < 0)
                    {
                        vectorPlayerBullets[i].active = false;
                    }
                    else
                    {
                        for(int j = 0; j < vectorBots.size(); j++)
                        {
                            if (checkCollision(vectorPlayerBullets[i].rect, vectorBots[j].rect))
                            {
                                vectorPlayerBullets[i].active = false;
                                vectorBots[j].hearts--;
                            }
                        }
                    }
                }
            }

            for(int i = 0; i < vectorBots.size(); i++)
            {
                if(vectorBots[i].hearts <= 0)
                {
                    numOfBots--;
                    player.score++;
                    vectorBots[i].alive = false;
                    vectorBots.erase(vectorBots.begin() + i);
                    break;
                }
            }

            for(int i = 0; i < vectorBots.size(); i++)
            {
                botSprite.tick();
                graphics.renderSprite(vectorBots[i].rect.x, vectorBots[i].rect.y, botSprite);
            }

            playerSprite.tick();
            graphics.renderSprite(player.rect.x, player.rect.y, playerSprite);
            graphics.presentScene();
        }
    }
    return 0;
}
