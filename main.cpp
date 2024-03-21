#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include "Graphics.h"
#include "defs.h"
#include "ammo.h"
#include "Bot.h"
#include "onTarget.h"
#include "scoreTarget.h"

using namespace std;

void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if ( SDL_PollEvent(&e) != 0 &&
             (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(100);
    }
}


int main(int argc, char *argv[])
{
    Graphics graphics;
    graphics.init();

    ScrollingBackground background;
    background.setTexture(graphics.loadTexture("assets/tet.png"));

    Sprite playerSprite;
    SDL_Texture* playerSpriteTexture = graphics.loadTexture(PLAYER_SPRITE_FILE);
    playerSprite.init(playerSpriteTexture, PLAYER_FRAMES, PLAYER_CLIPS);

//
    Player player;
    player.initPlayer(player, graphics);
//
    Bots bot;
    bot.initBot(bot, graphics, 1, 100);

    ScoreBoard scoreBoard;
    scoreBoard.initScoreBoard(graphics);

    vector<Bullet> playerBullets;
    Bullet botBullet;
    bool bulletInRange = false;

    bool quit = 0;
    SDL_Event e;

    Uint32 lastBotShotTime = 0;
    Uint32 botShotCooldown = 1000;

    int speedScroll = 1;

    while (!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                quit = 1;
            }
            else if (player.alive)
            {
                if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
                {
                    Bullet playerBullet;
                    playerBullet.initBullet(playerBullet, graphics, player.rect, 0);
                    playerBullets.push_back(playerBullet);
                }
            }
        }
//
        SDL_GetMouseState(&player.rect.x, &player.rect.y);
        player.rect.x = player.rect.x - player.rect.w / 2;
        player.rect.y = player.rect.y - player.rect.h / 2;
        playerSprite.tick();
//        graphics.prepareScene(background);



//

        background.scroll(speedScroll);
        graphics.renderBackground(background);
//        graphics.renderSprite(player.rect.x, player.rect.y, playerSprite);
//        graphics.presentScene();

        for (size_t i = 0; i < playerBullets.size(); i++)
        {
            if (playerBullets[i].active)
            {
                playerBullets[i].rect.y -= playerBullets[i].speed;
                graphics.renderTexture(playerBullets[i].texture, playerBullets[i].rect.x, playerBullets[i].rect.y, 4, 20, graphics.renderer);
                if (playerBullets[i].rect.x > SCREEN_WIDTH || playerBullets[i].rect.x + playerBullets[i].rect.w < 0)
                {
                    playerBullets[i].active = false;
                    playerBullets[i].texture = NULL;
                }
                else if (checkCollision(playerBullets[i].rect, bot.rect))
                {
                    cout << "On target\n";
                    bot.hp -= 10;
                    playerBullets[i].active = false;
                    playerBullets[i].texture = NULL;
                    graphics.presentScene();
                }
                else
                {
                    scoreBoard.scoreCount(playerBullets[i]);
                }
            }
        }



        if(player.alive && player.hp <= 0)
        {
            cout << "loss\n";
            cout << "score: " << scoreBoard.score << endl;

//            player.isLoss();
            player.alive = false;
        }

        if (bot.alive)
        {
            bot.botMoving();
            graphics.renderTexture(bot.texture, bot.rect.x, bot.rect.y, bot.rect.w, bot.rect.h, graphics.renderer);

            if (bot.hp <= 0)
            {
                bot.botBeKilled();
                graphics.presentScene();
            }

            Uint32 currentTime = SDL_GetTicks();
            if (currentTime - lastBotShotTime >= botShotCooldown)
            {
                bulletInRange = true;
                botBullet.initBullet(botBullet, graphics, bot.rect, 1);
                lastBotShotTime = currentTime;
            }
        }

        while(bulletInRange)
        {
            if(botBullet.active)
            {
                botBullet.rect.y += botBullet.speed;
                graphics.renderTexture(botBullet.texture, botBullet.rect.x, botBullet.rect.y, 20, 20, graphics.renderer);

                if (botBullet.rect.y > SCREEN_HEIGHT)
                {
                    botBullet.active = false;
                    botBullet.texture = NULL;
                }

                if (checkCollision(botBullet.rect, player.rect))
                {
                    botBullet.active = false;
                    botBullet.texture = NULL;
                    player.hp -= 20;
                    cout << "an dan\n";
                }
            }

            else bulletInRange = false;
        }

        scoreBoard.scoreReset();

        scoreBoard.moving();
        graphics.renderTexture(scoreBoard.texture, scoreBoard.rect.x, scoreBoard.rect.y, scoreBoard.rect.w, scoreBoard.rect.h, graphics.renderer);

//
//        player.rect.x = player.rect.x - player.rect.w / 2;
//        player.rect.y = player.rect.y - player.rect.h / 2;
//        SDL_RenderCopy(graphics.renderer, player.texture, NULL, &player.rect);
        graphics.renderSprite(player.rect.x, player.rect.y, playerSprite);
        graphics.presentScene();
    }


    //del

    SDL_DestroyTexture(bot.texture);
    bot.texture = NULL;

//    SDL_DestroyTexture( background );
//    background = NULL;

    SDL_DestroyTexture( background.texture );
    //quit
    graphics.quit();


    return 0;
}
