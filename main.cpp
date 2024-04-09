#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
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
    initMenu(buttonPlay, buttonHowToPlay);

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
            if(inButton(buttonPlay, posMouse_x, posMouse_y))
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
            if(inButton(buttonHowToPlay, posMouse_x, posMouse_y))
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

        Sprite playerSprite; playerSprite.RenderBeat = 3;
        SDL_Texture* playerSpriteTexture = graphics.loadTexture(PLAYER_SPRITE_FILE);
        playerSprite.init(playerSpriteTexture, PLAYER_FRAMES, PLAYER_CLIPS);

        Sprite playerSkill_Q_Sprite; playerSkill_Q_Sprite.RenderBeat = 2;
        SDL_Texture* playerSkill_Q_SpriteTexture = graphics.loadTexture(PLAYER_SKILL_Q_SPRITE_FILE);
        playerSkill_Q_Sprite.init(playerSkill_Q_SpriteTexture, PLAYER_SKILL_Q_FRAMES, PLAYER_SKILL_Q_CLIPS);

        Sprite playerSkill_E_Sprite; playerSkill_E_Sprite.RenderBeat = 3;
        SDL_Texture* playerSkill_E_SpriteTexture = graphics.loadTexture(PLAYER_SKILL_E_SPRITE_FILE);
        playerSkill_E_Sprite.init(playerSkill_E_SpriteTexture, PLAYER_SKILL_E_FRAMES, PLAYER_SKILL_E_CLIPS);

        Sprite botSprite; botSprite.RenderBeat = 3;
        SDL_Texture* botSpriteTexture = graphics.loadTexture(BOT_SPRITE_FILE);
        botSprite.init(botSpriteTexture, BOT_FRAMES, BOT_CLIPS);

        Sprite bossA_Sprite; bossA_Sprite.RenderBeat = 3;
        SDL_Texture* bossA_SpriteTexture = graphics.loadTexture(BOSS_A_SPRITE_FILE);
        bossA_Sprite.init(bossA_SpriteTexture, BOSS_A_FRAMES, BOSS_A_CLIPS);

        Sprite bossB_Sprite; bossB_Sprite.RenderBeat = 3;
        SDL_Texture* bossB_SpriteTexture = graphics.loadTexture(BOSS_B_SPRITE_FILE);
        bossB_Sprite.init(bossB_SpriteTexture, BOSS_B_FRAMES, BOSS_B_CLIPS);

        Sprite bossC_Sprite; bossC_Sprite.RenderBeat = 3;
        SDL_Texture* bossC_SpriteTexture = graphics.loadTexture(BOSS_C_SPRITE_FILE);
        bossC_Sprite.init(bossC_SpriteTexture, BOSS_C_FRAMES, BOSS_C_CLIPS);

        SDL_Texture* playerBulletTexture = graphics.loadTexture(PLAYER_BULLET_FILE);
        SDL_Texture* playerSkillWTexture = graphics.loadTexture(PLAYER_SKILL_W_FILE);
        SDL_Texture* botBulletTexture = graphics.loadTexture(BOT_BULLET_FILE);
        SDL_Texture* bossASkillTexture = graphics.loadTexture(BIGBOT_A_SKILL_FILE);
        SDL_Texture* bossBSkillTexture = graphics.loadTexture(BIGBOT_B_SKILL_FILE);
        SDL_Texture* bossCSkillTexture = graphics.loadTexture(BIGBOT_C_SKILL_FILE);
        SDL_Texture* bossCBulletSkillTexture = graphics.loadTexture(BIGBOT_C_BULLET_SKILL_FILE);
        SDL_Texture* meteoriteTexture = graphics.loadTexture(METEORITE_FILE);

        SDL_Texture* icon_Q_Texture = graphics.loadTexture(Q_ICON_FILE);
        SDL_Texture* icon_Q_0_Texture = graphics.loadTexture(Q_0_ICON_FILE);
        SDL_Texture* icon_Q_item_Texture = graphics.loadTexture(Q_ICON_ITEM_FILE);
        SDL_Texture* icon_W_Texture = graphics.loadTexture(W_ICON_FILE);
        SDL_Texture* icon_W_0_Texture = graphics.loadTexture(W_0_ICON_FILE);
        SDL_Texture* icon_W_item_Texture = graphics.loadTexture(W_ICON_ITEM_FILE);
        SDL_Texture* icon_E_Texture = graphics.loadTexture(E_ICON_FILE);
        SDL_Texture* icon_E_0_Texture = graphics.loadTexture(E_0_ICON_FILE);
        SDL_Texture* icon_E_item_Texture = graphics.loadTexture(E_ICON_ITEM_FILE);

        SDL_Texture* icon_Cup_Texture = graphics.loadTexture(ICON_CUP_FILE);
        SDL_Texture* icon_Heart_Texture = graphics.loadTexture(ICON_HEART_FILE);
        SDL_Texture* icon_Score_Texture = graphics.loadTexture(ICON_SCORE_FILE);

        SDL_Texture* boomTexture = graphics.loadTexture(BOOM_FILE);

        Player player;
        player.initPlayer(player);

        Shield skillQ;

        vector<Bullet> vectorPlayerBullets;
        vector<Bots> vectorBots_Skill_E;
        vector<Bullet> vectorBots_Skill_E_Skill;

        vector<Bullet> vectorMeteorites;

        bool existBigBot = false;
        int numOfBots = 0;
        Bots BigBot;
        vector<Bots> vectorBots;
        vector<Bullet> vectorBotsBullets;
        vector<Bullet> vectorBigBotBullets;

        int countWaveBot = 0;
        bool waitNewWave = false;

        SDL_Rect skill_Q_rect = {300, 0, 80, 80};
        SDL_Rect skill_W_rect = {380, 0, 80, 80};
        SDL_Rect skill_E_rect = {460, 0, 80, 80};

        SDL_Rect icon_Score_Rect = {0, 10, 30, 30};
        SDL_Rect icon_Heart_Rect = {0, 50, 30, 30};
        SDL_Rect icon_Cup_Rect = {100, 10, 30, 30};

        int skill_Q_having = 3;

        int skill_W_having = 3;
        bool skill_W_using = false;

        int skill_E_having = 3;
        bool skill_E_using = false;

        Uint32 time_current;

        Uint32 time_Meoterite_last;
        Uint32 time_Meteorite_cooldown = 3000;

        Uint32 time_W_start;
        Uint32 time_W = 3000;

        Uint32 time_E_start;
        Uint32 time_E = 10000;
        Uint32 time_E_BotsSkill_start;
        Uint32 time_E_BotsSkill_cooldown = 200;

        Uint32 time_lastBotShot;
        Uint32 time_clearWave;
        Uint32 time_waveDelay = 0000;
        Uint32 time_cooldownBotShot = 1000;

        Uint32 time_boss_A_cooldown = 300;

        Uint32 time_boss_B_shot_cooldown = 200;
        Uint32 time_boss_B_skill_start;
        Uint32 time_boss_B_wait = 1000;
        Uint32 time_boss_B_skilling = 3000;
        Uint32 time_boss_B_skill_cooldown = 1000;

        Uint32 time_boss_C_cooldown = 500;
        Uint32 time_boss_C_SkillPro_cooldown = 500;
        Uint32 time_last_C_SkillPro_Shot = 0;

        bool   boss_B_waiting = false;
        int b_movingDegree = 0, b_radius = 50;

        vector<Bullet> vectorItem;

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
                        if(time_current - time_W_start <= time_W && time_current > time_W)
                        {
                            initPlayerSkillW(player, vectorPlayerBullets);
                        }
                        else
                        {
                            if(skill_W_using)
                            {
                                skill_W_using = false;
                            }
                            initPlayerBullets(player, vectorPlayerBullets);
                        }
                    }
                    else if(e.type == SDL_KEYDOWN)
                    {
                        switch(e.key.keysym.sym)
                        {
                        case SDLK_q:
                            cerr << "Q down\n";
                            if(skill_Q_having && skillQ.active == false)
                            {
                                skillQ = initPlayerSkillQ(player);
                            }

                            break;
                        case SDLK_w:
                            cerr << "W down\n";
                            if(skill_W_having && skill_W_using == false)
                            {
                                skill_W_using = true;
                                time_W_start = time_current;
                                skill_W_having--;
                            }
                            break;
                        case SDLK_e:
                            cerr << "E down\n";
                            if(skill_E_having && skill_E_using == false)
                            {
                                initBot_Skill_E(player, vectorBots_Skill_E);
                                skill_E_using = true;
                                time_E_start = time_current;
                                skill_E_having--;

                                initSkill_Bot_Skill_E(vectorBots_Skill_E, vectorBots_Skill_E_Skill);
                                time_E_BotsSkill_start = time_current;
                            }
                            break;
                        }
                    }
                    SDL_GetMouseState(&player.rect.x, &player.rect.y);
                    player.rect.x = player.rect.x - player.rect.w/2;
                    player.rect.y = player.rect.y - player.rect.h/2;

                }
            }

        //====get Current time====

            time_current = SDL_GetTicks();

        //====time Wave====
            if((numOfBots == 0 && waitNewWave == false))
            {
                time_clearWave = time_current;
                waitNewWave = true;
            }
        //====init Bot ====
            if(numOfBots == 0
                &&(countWaveBot%11 == 0 && countWaveBot >=11)
                    &&(existBigBot == false)
                        &&(time_current - time_clearWave >= time_waveDelay))
            {
                cerr << "init Boss B\n";
                BigBot = initBoss_B();
                existBigBot = true;
                countWaveBot++;
                numOfBots = 1;

                waitNewWave = false;

                time_lastBotShot = time_current;
                time_boss_B_skill_start = time_current;
            }

            if(numOfBots == 0
               && (countWaveBot%7==0 && countWaveBot >= 7)
                    && (existBigBot == false)
                        && (time_current - time_clearWave >= time_waveDelay))

            {
                cerr << "init Boss C \n";
                BigBot = initBoss_C();
                existBigBot = true;
                countWaveBot++;
                numOfBots = 1;
                waitNewWave = false;

                initBoss_C_Skill(BigBot, vectorBigBotBullets);
                time_lastBotShot = time_current;
            }

            if(numOfBots == 0
               && (countWaveBot%3==0 && countWaveBot >= 3)
                    && (existBigBot == false)
                        && (time_current - time_clearWave >= time_waveDelay))

            {
                BigBot = initBoss_A();

                existBigBot = true;
                countWaveBot++;
                numOfBots = 1;

                waitNewWave = false;

                initBoss_A_Skill(BigBot, vectorBigBotBullets);
                cerr << "init Boss A\n";
                time_lastBotShot = time_current;
            }

            if((numOfBots == 0
                && existBigBot == false
                    &&(time_current - time_clearWave >= time_waveDelay))
               || countWaveBot == 0)
            {
                initBotsWave(vectorBots);
                numOfBots += vectorBots.size();
                initBotBullets(vectorBots, vectorBotsBullets);
                time_lastBotShot = time_current;
                countWaveBot++;
                waitNewWave = false;
            }



            if(time_current - time_lastBotShot >= time_cooldownBotShot)
            {
                initBotBullets(vectorBots, vectorBotsBullets);
                time_lastBotShot = time_current;
            }

        //====load background (load first for load item after)====
            background.scroll(speedScroll);
            graphics.renderBackground(background);

        //====load player skill====
            for (size_t i = 0; i < vectorPlayerBullets.size(); i++)
            {
                if (vectorPlayerBullets[i].active)
                {
                    vectorPlayerBullets[i].speed += vectorPlayerBullets[i].acceleration;
                    vectorPlayerBullets[i].rect.x += vectorPlayerBullets[i].speed*sin(vectorPlayerBullets[i].slope);
                    vectorPlayerBullets[i].rect.y -= vectorPlayerBullets[i].speed*cos(vectorPlayerBullets[i].slope);
                    if(vectorPlayerBullets[i].typeBullet == 'w')
                    {
                        graphics.renderInRect(playerSkillWTexture, vectorPlayerBullets[i].rect);
                    }

                    else
                    {
                        graphics.renderInRect(playerBulletTexture, vectorPlayerBullets[i].rect);
                    }

                    if (vectorPlayerBullets[i].rect.y < 0)
                    {
                        vectorPlayerBullets[i].active = false;
                    }
                    else
                    {
                        for(size_t j = 0; j < vectorBots.size(); j++)
                        {
                            if (checkCollision(vectorPlayerBullets[i].rect, vectorBots[j].rect))
                            {
                                vectorPlayerBullets[i].active = false;
                                vectorBots[j].hearts--;
                            }
                        }
                        if(existBigBot)
                        {
                            if(checkCollision(vectorPlayerBullets[i].rect, BigBot.rect))
                            {
                                vectorPlayerBullets[i].active = false;
                                BigBot.hearts-= 1; cout << BigBot.hearts << endl;
                            }
                        }
                    }
                }
                else if(vectorPlayerBullets[i].active == false)
                {
                    vectorPlayerBullets.erase(vectorPlayerBullets.begin() + i);
                }
            }

            if(skillQ.hp <= 0)
            {
                skillQ.active = false;
            }

            if(skillQ.active)
            {
                graphics.renderSprite(player.rect.x - 22, player.rect.y - 22, playerSkill_Q_Sprite);
                playerSkill_Q_Sprite.tick();
            }

            if(skill_E_using)
            {
                if(time_current - time_E_start >= time_E)
                {
                    skill_E_using = false;
                    vectorBots_Skill_E.clear();
                }

                if(time_current - time_E_BotsSkill_start >= time_E_BotsSkill_cooldown)
                {
                    initSkill_Bot_Skill_E(vectorBots_Skill_E, vectorPlayerBullets);
                    time_E_BotsSkill_start = time_current;
                }

                vectorBots_Skill_E[0].rect.x = player.rect.x - vectorBots_Skill_E[0].rect.w - 10;
                vectorBots_Skill_E[1].rect.x = player.rect.x + player.rect.w + 10;
                for(size_t i = 0; i < vectorBots_Skill_E.size(); i++)
                {
                    vectorBots_Skill_E[i].rect.y = player.rect.y + 50;
                    playerSkill_E_Sprite.tick();
                    graphics.renderSprite(vectorBots_Skill_E[i].rect.x, vectorBots_Skill_E[i].rect.y, playerSkill_E_Sprite);
                }
            }

        //====load meteorite====
        if(time_current - time_Meoterite_last >= time_Meteorite_cooldown)
        {
            initMeteorite(vectorMeteorites);
            time_Meoterite_last = time_current;
        }
        for(size_t i = 0; i < vectorMeteorites.size(); i++)
        {
            if(vectorMeteorites[i].active)
            {
                vectorMeteorites[i].speed += vectorMeteorites[i].acceleration;
                vectorMeteorites[i].rect.x += vectorMeteorites[i].speed*sin(vectorMeteorites[i].slope);
                vectorMeteorites[i].rect.y += vectorMeteorites[i].speed*cos(vectorMeteorites[i].slope);
                for(size_t j = 0; j < vectorPlayerBullets.size(); j++)
                {
                    if(vectorPlayerBullets[j].active && checkCollision(vectorMeteorites[i].rect, vectorPlayerBullets[j].rect))
                    {
                        cerr << "shot on meteo\n";
                        vectorMeteorites[i].active = false;
                        vectorPlayerBullets[j].active = false;
                        graphics.renderInRect(boomTexture, vectorMeteorites[i].rect);

                        if(vectorMeteorites[i].rect.w/2 >= 10)
                        {
                            initMeteoDebris(vectorMeteorites[i], vectorMeteorites);
                        }

                    }
                }
                graphics.renderInRect(meteoriteTexture, vectorMeteorites[i].rect);
                if (vectorMeteorites[i].rect.x > SCREEN_HEIGHT)
                {
                    vectorMeteorites[i].active = false;
                }
                else if(skillQ.active)
                {
                    if(checkCollision(vectorMeteorites[i].rect, skillQ.rect))
                    {
                        vectorMeteorites[i].active = false;
                        skillQ.hp--;
                    }
                }
                else
                {
                    if (checkCollision(vectorMeteorites[i].rect, player.rect))
                    {
                        vectorMeteorites[i].active = false;
                        player.heart -= vectorMeteorites[i].damage;
                    }
                }
            }

        }

        //====load bot Skill====

            for(size_t i = 0; i < vectorBotsBullets.size(); i++)
            {
                if(vectorBotsBullets[i].active)
                {
                    vectorBotsBullets[i].rect.y += vectorBotsBullets[i].speed;
                    graphics.renderInRect(botBulletTexture, vectorBotsBullets[i].rect);

                    if (vectorBotsBullets[i].rect.x > SCREEN_HEIGHT)
                    {
                        vectorBotsBullets[i].active = false;
                    }
                    else if(skillQ.active)
                    {
                        if(checkCollision(vectorBotsBullets[i].rect, skillQ.rect))
                        {
                            vectorBotsBullets[i].active = false;
                            skillQ.hp--;
                        }
                    }
                    else
                    {
                        if (checkCollision(vectorBotsBullets[i].rect, player.rect))
                        {
                            vectorBotsBullets[i].active = false;
                            player.heart--;
                        }
                    }
                }
            }

            for(size_t i = 0; i < vectorBigBotBullets.size(); i++)
            {
                if(vectorBigBotBullets[i].active)
                {
                    vectorBigBotBullets[i].speed += vectorBigBotBullets[i].acceleration;
                    vectorBigBotBullets[i].rect.x += vectorBigBotBullets[i].speed*sin(vectorBigBotBullets[i].slope);
                    vectorBigBotBullets[i].rect.y += vectorBigBotBullets[i].speed*cos(vectorBigBotBullets[i].slope);
                    switch (vectorBigBotBullets[i].typeBullet)
                    {
                    case 'A':
                        graphics.renderInRect(bossASkillTexture, vectorBigBotBullets[i].rect);
                        break;
                    case 'B':
                        graphics.renderInRect(bossBSkillTexture, vectorBigBotBullets[i].rect);
                        break;
                    case 'C':
                        for(size_t j = 0; j < vectorPlayerBullets.size(); j++)
                        {
                            if(checkCollision(vectorBigBotBullets[i].rect, vectorPlayerBullets[j].rect))
                            {
                                vectorBigBotBullets[i].active = false;
                                vectorPlayerBullets[j].active = false;
                            }
                        }
                        graphics.renderInRect(bossCSkillTexture, vectorBigBotBullets[i].rect);
                        break;
                    case '1':
                        graphics.renderInRect(bossCBulletSkillTexture, vectorBigBotBullets[i].rect);
                        break;
                    }

                    if (vectorBigBotBullets[i].rect.x > SCREEN_HEIGHT)
                    {
                        vectorBigBotBullets[i].active = false;
                    }
                    else if(skillQ.active)
                    {
                        if(checkCollision(vectorBigBotBullets[i].rect, skillQ.rect))
                        {
                            vectorBigBotBullets[i].active = false;
                            skillQ.hp--;
                        }
                    }
                    else
                    {
                        if (checkCollision(vectorBigBotBullets[i].rect, player.rect))
                        {
                            vectorBigBotBullets[i].active = false;
                            player.heart -= vectorBigBotBullets[i].damage;
                        }
                    }
                    if(vectorBigBotBullets[i].active == false)
                    {
                        if(vectorBigBotBullets[i].typeBullet == 'C')
                        {
                            initBoss_C_Bullet_Skill(vectorBigBotBullets[i].rect, vectorBigBotBullets);
                        }
                    }
                }
            }

         //====load bot====
            for(size_t i = 0; i < vectorBots.size(); i++)
            {
                if(vectorBots[i].hearts <= 0)
                {
                    numOfBots--;
                    player.score++;
                    vectorBots[i].alive = false;
                    graphics.renderInRect(boomTexture, vectorBots[i].rect);
                    initItem(vectorBots[i], vectorItem);
                    vectorBots.erase(vectorBots.begin() + i);
                    break;
                }
            }

            for(size_t i = 0; i < vectorBots.size(); i++)
            {
                botSprite.tick();
                graphics.renderSprite(vectorBots[i].rect.x, vectorBots[i].rect.y, botSprite);
            }

            if(existBigBot && BigBot.alive)
            {
                switch (BigBot.typeBot)
                {
                case 'a':
                    if(time_current - time_lastBotShot >= time_boss_A_cooldown)
                    {
                        initBoss_A_Skill(BigBot, vectorBigBotBullets);
                        time_lastBotShot = time_current;
                    }
                    bossA_Sprite.tick();
                    graphics.renderSprite(BigBot.rect.x, BigBot.rect.y, bossA_Sprite);
                    break;
                case 'b':
                    if((time_current - time_boss_B_wait >= time_boss_B_skill_cooldown)
                        && (time_current - time_boss_B_skill_start < time_boss_B_skilling))
                    {
                        if(time_current - time_lastBotShot >= time_boss_B_shot_cooldown)
                        {
                            initBoss_B_Skill(BigBot.rect, vectorBigBotBullets);
                            time_lastBotShot = time_current;
                        }
                    }
                    if(time_current - time_boss_B_skill_start >= time_boss_B_skilling && (boss_B_waiting == false))
                    {
                        cerr << "run this block 1\n";
                        time_boss_B_wait = time_current;
                        boss_B_waiting = true;
                    }
                    if((time_current - time_boss_B_wait >= time_boss_B_skill_cooldown) && (boss_B_waiting == true))
                    {
                        cerr << "run block 2\n";
                        time_boss_B_skill_start = time_current;
                        boss_B_waiting = false; cerr << "false \n";
                    }

                    movingCircle(BigBot.rect, b_movingDegree, b_radius, 5, 170, 300);

                    bossB_Sprite.tick();;
                    graphics.renderSprite(BigBot.rect.x, BigBot.rect.y, bossB_Sprite);
                    break;
                case 'c':
                    if(time_current - time_lastBotShot >= time_boss_C_cooldown)
                    {
                        initBoss_C_Skill(BigBot, vectorBigBotBullets);
                        time_lastBotShot = time_current;
                        cerr << "run this\n";
                    }

                    if((player.rect.y - (BigBot.rect.y + BigBot.rect.h) <= 100)
                        && (time_current - time_last_C_SkillPro_Shot >= time_boss_C_SkillPro_cooldown))
                    {
                        initBoss_C_Skill_Pro(BigBot, vectorBigBotBullets);
                        time_last_C_SkillPro_Shot = time_current;
                    }

                    if(bossC_Sprite.countBeat == 0)
                    {
                        movingHorizontalRandom(BigBot);
                    }
                    bossC_Sprite.tick();
                    graphics.renderSprite(BigBot.rect.x, BigBot.rect.y, bossC_Sprite);
                    break;

                }
                if(BigBot.hearts <= 0)
                {
                    player.score += 10;
                    BigBot.alive = false;
                    existBigBot = false;
                    numOfBots -= 1;
                    graphics.renderInRect(boomTexture, BigBot.rect);
                    initItem(BigBot, vectorItem);
                    cout << "Big Bot die\n";
                }
            }

            for(size_t i = 0; i < vectorItem.size(); i++)
            {
                if(vectorItem[i].active)
                {
                    vectorItem[i].speed += vectorItem[i].acceleration;
                    vectorItem[i].rect.x += vectorItem[i].speed*sin(vectorItem[i].slope);
                    vectorItem[i].rect.y += vectorItem[i].speed*cos(vectorItem[i].slope);

                    switch(vectorItem[i].typeBullet)
                    {
                    case 'Q':
                        graphics.renderInRect(icon_Q_item_Texture, vectorItem[i].rect);
                        break;
                    case 'W':
                        graphics.renderInRect(icon_W_item_Texture, vectorItem[i].rect);
                        break;
                    case 'E':
                        graphics.renderInRect(icon_E_item_Texture, vectorItem[i].rect);
                        break;
                    }

                    if(checkCollision(player.rect, vectorItem[i].rect))
                    {
                        switch(vectorItem[i].typeBullet)
                        {
                        case 'Q':
                            if(skill_Q_having < 5)
                            {
                                skill_Q_having++;
                            }
                            break;
                        case 'W':
                            if(skill_W_having < 3)
                            {
                                skill_W_having++;
                            }
                            break;
                        case 'E':
                            if(skill_E_having < 2)
                            {
                                skill_E_having++;
                            }
                            break;
                        }
                        vectorItem[i].active = false;
                    }
                }
            }

            playerSprite.tick();
            graphics.renderSprite(player.rect.x, player.rect.y, playerSprite);

            if(skill_Q_having)
            {
                graphics.renderInRect(icon_Q_Texture, skill_Q_rect);
            }
            else
            {
                graphics.renderInRect(icon_Q_0_Texture, skill_Q_rect);
            }
            if(skill_W_having)
            {
                graphics.renderInRect(icon_W_Texture, skill_W_rect);
            }
            else
            {
                graphics.renderInRect(icon_W_0_Texture, skill_W_rect);
            }
            if(skill_E_having)
            {
                graphics.renderInRect(icon_E_Texture, skill_E_rect);
            }
            else
            {
                graphics.renderInRect(icon_E_0_Texture, skill_E_rect);
            }

            graphics.renderInRect(icon_Cup_Texture, icon_Cup_Rect);
            graphics.renderInRect(icon_Heart_Texture, icon_Heart_Rect);
            graphics.renderInRect(icon_Score_Texture, icon_Score_Rect);

            graphics.presentScene();
        }
    }
    return 0;
}
