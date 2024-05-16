#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "Graphics.h"
#include "defs.h"
#include "ammo.h"
#include "Bot.h"
#include "onTarget.h"
#include "button.h"
using namespace std;

int main(int argc, char *argv[])
{
    Graphics graphics;
    graphics.init();

    bool outGame = false;

    while(!outGame)
    {
        outGame = true;

        SDL_Texture* menuBackground = graphics.loadTexture(MENU_BACKGROUND_FILE);

        Button buttonPlay, buttonHowToPlay, buttonHighScore, buttonPre, buttonNext;
        initMenu(buttonPlay, buttonHowToPlay, buttonHighScore, buttonPre, buttonNext);

        Button buttonReturnMenu = initButtonReturnMenu();

        Sprite buttonPlaySprite;
        SDL_Texture* buttonPlaySpriteTexture = graphics.loadTexture(BUTTON_PLAY_SPRITE_FILE);
        buttonPlaySprite.init(buttonPlaySpriteTexture, BUTTON_PLAY_FRAMES, BUTTON_PLAY_CLIPS);

        Sprite buttonHTPSprite;
        SDL_Texture* buttonHTPSpriteTexture = graphics.loadTexture(BUTTON_HTP_SPRITE_FILE);
        buttonHTPSprite.init(buttonHTPSpriteTexture, BUTTON_HTP_FRAMES, BUTTON_HTP_CLIPS);

        Sprite buttonHighScoreSprite;
        SDL_Texture* buttonHighScoreSpriteTexture = graphics.loadTexture(BUTTON_HIGH_SCORE_FILE);
        buttonHighScoreSprite.init(buttonHighScoreSpriteTexture, BUTTON_HIGH_SCORE_FRAMES, BUTTON_HIGH_SCORE_CLIPS);

        Sprite buttonReturnMenuSprite;
        SDL_Texture* buttonReturnMenuSpriteTexture = graphics.loadTexture(BUTTON_RETURN_MENU_FILE);
        buttonReturnMenuSprite.init(buttonReturnMenuSpriteTexture, BUTTON_RETURN_MENU_FRAMES, BUTTON_RETURN_MENU_CLIPS);


        Sprite rankSprite;
        SDL_Texture* rankSpriteTexture = graphics.loadTexture(RANK_FILE);
        rankSprite.init(rankSpriteTexture, RANK_FRAMES, RANK_CLIPS);

        Sprite chooseAircraftSprite;
        SDL_Texture* chooseAircraftSpriteTexture = graphics.loadTexture(CHOOSE_AIRCRAFT_SPRITE_FILE);
        chooseAircraftSprite.init(chooseAircraftSpriteTexture, CHOOSE_AIRCRAFT_FRAMES, CHOOSE_AIRCRAFT_CLIPS);

        SDL_Texture* guideTexture = graphics.loadTexture(GUIDE_FILE);
        SDL_Texture* highScore_Box_Texture = graphics.loadTexture(HIGH_SCORE_PLAYERS_BOX_FILE);
        SDL_Texture* preButtonTexture = graphics.loadTexture(BUTTON_PRE_FILE);
        SDL_Texture* nextButtonTexture = graphics.loadTexture(BUTTON_NEXT_FILE);


        TTF_Font* size_30 = graphics.loadFont("assets2/Minecraft.ttf", 30);
        TTF_Font* size_50 = graphics.loadFont("assets2/Minecraft.ttf", 50);

        SDL_Color orange = {255, 153, 51, 0};
        SDL_Color white = {255, 255, 255, 0};

        Mix_Music* themeMenuMusic = graphics.loadMusic("assets2/theme.mp3");
        graphics.play(themeMenuMusic);

        bool quit_menu = false;
        bool playAgain = false;
        bool readGuide = false;
        bool highScore_check = false;

        bool quitPlayAgainMenu = false;

        pair<int, string> highScore_rank;
        vector<pair<string, string>> highScore;

        readRankFile(highScore_rank, highScore, rankSprite);
        SDL_Texture* highScore_text_score[5];
        SDL_Texture* highScore_text_name[5];
        for(int i = 0; i < 5; i++)
        {
            highScore_text_name[i] = graphics.renderText(highScore[i].first.c_str(), size_30, white);
            highScore_text_score[i] = graphics.renderText(highScore[i].second.c_str(), size_30, white);
        }


        SDL_Event e;

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
                        playAgain = true;
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
                        readGuide = true;                }
                }
                else
                {
                    buttonHTPSprite.currentFrame = 0;
                }

                if(inButton(buttonHighScore, posMouse_x, posMouse_y))
                {
                    buttonHighScoreSprite.currentFrame = 1;
                    if(e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
                    {
                        if(highScore_check == false) highScore_check = true;
                        else if(highScore_check == true) highScore_check = false;
                    }
                }
                else
                {
                    buttonHighScoreSprite.currentFrame = 0;
                }


                if(highScore_check == false)
                {
                    if(inButton(buttonNext, posMouse_x, posMouse_y))
                    {
                        if(e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
                        {
                            chooseAircraftSprite.currentFrame = abs((chooseAircraftSprite.currentFrame + 1)%4);
                        }
                    }
                    if(inButton(buttonPre, posMouse_x, posMouse_y))
                    {
                        if(e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
                        {
                            chooseAircraftSprite.currentFrame = abs((chooseAircraftSprite.currentFrame - 1 + 4)%4);
                        }
                    }
                }
            }
            while(readGuide)
            {
                while(SDL_PollEvent(&e) != 0)
                {
                    if(e.type == SDL_QUIT)
                    {
                        readGuide = false;
                        quit_menu = true;
                    }
                    SDL_GetMouseState(&posMouse_x, &posMouse_y);

                    if(inButton(buttonReturnMenu, posMouse_x, posMouse_y))
                    {
                        buttonReturnMenuSprite.currentFrame = 1;
                        if(e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
                        {
                            readGuide = false;
                        }
                    }
                    else
                    {
                        buttonReturnMenuSprite.currentFrame = 0;
                    }
                }

                graphics.renderFullscreen(menuBackground);
                graphics.renderTexture(guideTexture, 0, 0, 540, 800, graphics.renderer);
                graphics.renderSprite(buttonReturnMenu.rect.x, buttonReturnMenu.rect.y, buttonReturnMenuSprite);
                graphics.presentScene();
            }

            graphics.renderFullscreen(menuBackground);
            if(highScore_check)
            {
                graphics.renderTexture(highScore_Box_Texture, 70, 70);
                for(int i = 0; i < 5; i++)
                {
                    graphics.renderTexture(highScore_text_name[i], 100, 250 + i*50);
                    graphics.renderTexture(highScore_text_score[i], 350, 250 + i*50);
                }
            }
            else
            {
                graphics.renderSprite(170, 300, chooseAircraftSprite);
                graphics.renderInRect(preButtonTexture, buttonPre.rect);
                graphics.renderInRect(nextButtonTexture, buttonNext.rect);
            }
            graphics.renderSprite(buttonHowToPlay.rect.x, buttonHowToPlay.rect.y, buttonHTPSprite);
            graphics.renderSprite(buttonHighScore.rect.x, buttonHighScore.rect.y, buttonHighScoreSprite);
            graphics.renderSprite(buttonPlay.rect.x, buttonPlay.rect.y, buttonPlaySprite);
            graphics.presentScene();
        }

        if(themeMenuMusic != nullptr)
        {
            Mix_FreeMusic(themeMenuMusic);
        }




        while(playAgain)
        {
            quitPlayAgainMenu = false;
            ScrollingBackground background;
            background.setTexture(graphics.loadTexture(BACKGROUND_FILE));

            TTF_Font* fontFor_Score_and_Heart = graphics.loadFont("assets2/Minecraft.ttf", 40);
            TTF_Font* fontFor_countSkillHaving = graphics.loadFont("assets2/Minecraft.ttf", 20);

            SDL_Color orange = {255, 153, 51, 0};
            SDL_Color white = {255, 255, 255, 0};

            SDL_Texture* scoreTexture = graphics.renderText("0", fontFor_Score_and_Heart, orange);
            SDL_Texture* heartTexture = graphics.renderText("5", fontFor_Score_and_Heart, orange);

            highScore_text_score[4] = graphics.renderText(highScore[4].second.c_str(), size_50, orange);
            buttonReturnMenu.rect.y = 750;

            SDL_Texture* skill_Q_having_num_Texture = graphics.renderText("3", fontFor_countSkillHaving, white);
            SDL_Texture* skill_W_having_num_Texture = graphics.renderText("3", fontFor_countSkillHaving, white);
            SDL_Texture* skill_E_having_num_Texture = graphics.renderText("2", fontFor_countSkillHaving, white);

            Sprite waitSprite; waitSprite.RenderBeat = 10;
            SDL_Texture* waitSpriteTexture = graphics.loadTexture(WAIT_SPRITE_FILE);
            waitSprite.init(waitSpriteTexture, WAIT_FRAMES, WAIT_CLIPS);

            Sprite playerSprite; playerSprite.RenderBeat = 3;
            SDL_Texture* playerSpriteTexture = graphics.loadTexture(PLAYER_SPRITE_FILE_1);
            switch(chooseAircraftSprite.currentFrame)
            {
            case 0:
                playerSpriteTexture = graphics.loadTexture(PLAYER_SPRITE_FILE_1);
                break;
            case 1:
                playerSpriteTexture = graphics.loadTexture(PLAYER_SPRITE_FILE_2);
                break;
            case 2:
                playerSpriteTexture = graphics.loadTexture(PLAYER_SPRITE_FILE_3);
                break;
            case 3:
                playerSpriteTexture = graphics.loadTexture(PLAYER_SPRITE_FILE_4);
                break;
            }
            playerSprite.init(playerSpriteTexture, PLAYER_FRAMES, PLAYER_CLIPS);

            Sprite rankPlayerSprite;
            SDL_Texture* rankPlayerSpriteTexture = graphics.loadTexture(RANK_PLAYER_FILE);
            rankPlayerSprite.init(rankPlayerSpriteTexture, RANK_PLAYER_FRAMES, RANK_PLAYER_CLIPS);

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

            Sprite bumbum_Sprite; bumbum_Sprite.RenderBeat = 2;
            SDL_Texture* bumbum_SpriteTexture = graphics.loadTexture(BUMBUM_SPRITE_FILE);
            bumbum_Sprite.init(bumbum_SpriteTexture, BUMBUM_FRAMES, BUMBUM_CLIPS);

            Sprite warnSprite; warnSprite.RenderBeat = 4;
            SDL_Texture* warnSpriteTexture = graphics.loadTexture(WARN_SPRITE_FILE);
            warnSprite.init(warnSpriteTexture, WARN_FRAMES, WARN_CLIPS);

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

            SDL_Texture* icon_Buff_item_Texture = graphics.loadTexture(ICON_BUFF_FILE);

            SDL_Texture* icon_Cup_Texture = graphics.loadTexture(ICON_CUP_FILE);
            SDL_Texture* icon_Heart_Texture = graphics.loadTexture(ICON_HEART_FILE);
            SDL_Texture* icon_Score_Texture = graphics.loadTexture(ICON_SCORE_FILE);

            SDL_Texture* boomTexture = graphics.loadTexture(BOOM_FILE);

            SDL_Texture* redHPBarTexture = graphics.loadTexture(RED_FILE);
            SDL_Texture* whiteHPBarTexture = graphics.loadTexture(WHITE_FILE);

            SDL_Texture* pauseTexture = graphics.loadTexture(BUTTON_PAUSE_FILE);

            Mix_Music* gamingTheme = graphics.loadMusic("assets2/gametheme.mp3");
            graphics.play(gamingTheme);

            Mix_Chunk* playerShot = graphics.loadSound("assets2/playerShot.wav");
            Mix_Chunk* wShot = graphics.loadSound("assets2/w.wav");

            Mix_Chunk* botShot = graphics.loadSound("assets2/botShot.wav");
            Mix_Chunk* bossAShot = graphics.loadSound("assets2/bossA.wav");
            Mix_Chunk* bossBShot = graphics.loadSound("assets2/bossB_out.wav");
            Mix_Chunk* bossCShot = graphics.loadSound("assets2/bossC.wav");

            pair<int, string> ranking;
            Player player;
            player.initPlayer(player);
            string playerHeart = to_string(player.heart);
            string playerScore = to_string(player.score);

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
            SDL_Rect pause_rect = {220, 0, 80, 80};

            SDL_Rect icon_Score_Rect = {0, 10, 30, 30};
            SDL_Rect icon_Heart_Rect = {0, 50, 30, 30};
            SDL_Rect icon_Cup_Rect = {100, 10, 30, 30};

            int skill_Q_having = 3;
            string skill_Q_having_str = to_string(skill_Q_having);

            int skill_W_having = 3;
            string skill_W_having_str = to_string(skill_W_having);

            bool skill_W_using = false;

            int skill_E_having = 2;
            string skill_E_having_str = to_string(skill_E_having);
            bool skill_E_using = false;

            bool buffSpeed = false;

            Uint32 time_current;

            Uint32 time_Meoterite_last;
            Uint32 time_Meteorite_cooldown = 3000;

            Uint32 time_playerShotCooldown = 200;
            Uint32 time_playerLastShot;

            Uint32 time_buffSpeedStart;
            Uint32 time_buffTime = 200;

            Uint32 time_W_start;
            Uint32 time_W = 3000;

            Uint32 time_E_start;
            Uint32 time_E = 10000;
            Uint32 time_E_BotsSkill_start;
            Uint32 time_E_BotsSkill_cooldown = 200;

            Uint32 time_lastBotShot;
            Uint32 time_clearWave;
            Uint32 time_waveDelay = 2000;
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

            Uint32 time_die;
            Uint32 time_loadBumBum = 1000;

            Uint32 time_pause = 0;

            bool   boss_B_waiting = false;
            int b_movingDegree = 0, b_radius = 50;

            vector<Bullet> vectorItem;

            vector<SDL_Rect> hpBarWhite;
            vector<SDL_Rect> hpBarRed;


            bool loss = false;
            bool quit = false;

            while(!loss)
            {
                //====get Current time====

                time_current = SDL_GetTicks() - time_pause;

                while(SDL_PollEvent(&e) != 0)
                {
                    if(e.type == SDL_QUIT)
                    {
                        quit = true;
                        playAgain = false;
                        loss = true;
                    }
                    if(player.alive)
            //=====player=====
                    {
                        if(e.type == SDL_KEYDOWN)
                        {
                            switch(e.key.keysym.sym)
                            {
                            case SDLK_q:
                                if(skill_Q_having && skillQ.active == false)
                                {
                                    skillQ = initPlayerSkillQ(player);
                                    skill_Q_having--;
                                }

                                break;
                            case SDLK_w:
                                if(skill_W_having && skill_W_using == false)
                                {
                                    skill_W_using = true;
                                    time_W_start = time_current;
                                    skill_W_having--;
                                }
                                break;
                            case SDLK_e:
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
                            case SDLK_p:
                                Sprite newGameSprite;
                                SDL_Texture* newGameTexture = graphics.loadTexture(NEW_GAME_FILE);
                                newGameSprite.init(newGameTexture, NEW_GAME_FRAMES, NEW_GAME_CLIPS);
                                Button newGame = initButtonNewGame();

                                Sprite pressToContinueSprite; pressToContinueSprite.RenderBeat = 15;
                                SDL_Texture* pressToContinueTexture = graphics.loadTexture(PRESS_TO_CONTINUE_FILE);
                                pressToContinueSprite.init(pressToContinueTexture, PRESS_TO_CONTINUE_FRAMES, PRESS_TO_CONTINUE_CLIPS);

                                scoreTexture = graphics.renderText(playerScore.c_str(), size_50, orange);
                                string yourScore = "Your Score: ";
                                SDL_Texture* yourScoreTexture = graphics.renderText(yourScore.c_str(), size_30, white);
                                string highScore = "High Score: ";
                                SDL_Texture* highScoreTexture = graphics.renderText(highScore.c_str(), size_30, white);


                                Uint32 time_startPause = SDL_GetTicks();
                                bool pause = true;
                                while(pause)
                                {
                                    while(SDL_PollEvent(&e) != 0)
                                    {
                                        if(e.type == SDL_QUIT)
                                        {
                                            quit = true;
                                            playAgain = false;
                                            loss = true;
                                            pause = false;
                                        }
                                        else if(e.type == SDL_KEYDOWN)
                                        {
                                            pause = false;
                                        }

                                        SDL_GetMouseState(&posMouse_x, &posMouse_y);

                                        if(inButton(newGame, posMouse_x, posMouse_y))
                                        {
                                            newGameSprite.currentFrame = 1;
                                            if(e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
                                            {
                                                pause = false;
                                                loss = true;
                                                quitPlayAgainMenu = true;
                                            }
                                        }
                                        else
                                        {
                                           newGameSprite.currentFrame = 0;
                                        }

                                        if(inButton(buttonReturnMenu, posMouse_x, posMouse_y))
                                        {
                                            buttonReturnMenuSprite.currentFrame = 1;
                                            if(e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
                                            {
                                                outGame = false;
                                                pause = false;
                                                loss = true;
                                                quitPlayAgainMenu = true;
                                                playAgain = false;
                                                quit = true;
                                            }
                                        }
                                        else
                                        {
                                            buttonReturnMenuSprite.currentFrame = 0;
                                        }
                                    }

                                    background.scroll(1);
                                    graphics.renderBackground(background);
                                    graphics.renderTexture(highScoreTexture, 180, 410);
                                    graphics.renderTexture(highScore_text_score[4], 250, 460);
                                    graphics.renderTexture(scoreTexture, 250, 340);
                                    graphics.renderTexture(yourScoreTexture, 180, 290);
                                    graphics.renderSprite(buttonReturnMenu.rect.x, buttonReturnMenu.rect.y, buttonReturnMenuSprite);
                                    graphics.renderSprite(newGame.rect.x, newGame.rect.y, newGameSprite);
                                    graphics.renderSprite(0, 600, pressToContinueSprite); pressToContinueSprite.tick();
                                    graphics.presentScene();
                                }

                                time_pause += SDL_GetTicks() - time_startPause;
                                break;
                            }
                        }
                        SDL_GetMouseState(&player.rect.x, &player.rect.y);
                        player.rect.x = player.rect.x - player.rect.w/2;
                        player.rect.y = player.rect.y - player.rect.h/2;

                    }
                }

                if(time_current - time_playerLastShot >= time_playerShotCooldown && numOfBots > 0)
                {
                    if(time_current - time_W_start <= time_W && time_current > time_W && skill_W_using)
                    {
                        initPlayerSkillW(player, vectorPlayerBullets);
                        graphics.play(wShot);
                    }
                    else
                    {
                        if(skill_W_using)
                        {
                            skill_W_using = false;
                        }
                        initPlayerBullets(player, vectorPlayerBullets);
                        graphics.play(playerShot);
                    }
                    time_playerLastShot = time_current;
                }

                if(player.heart <= 0)
                {
                    player.rect.w = 0;
                    player.rect.h = 0;
                    loss = true;
                    playAgain = false;
                    time_die = time_current;
                    while(time_current - time_die < time_loadBumBum)
                    {
                        bumbum_Sprite.tick();
                        graphics.renderSprite(player.rect.x, player.rect.y, bumbum_Sprite);
                        time_current = SDL_GetTicks();
                        graphics.presentScene();
                    }
                }

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
                    BigBot = initBoss_B();
                    existBigBot = true;
                    countWaveBot++;
                    numOfBots = 1;

                    waitNewWave = false;

                    time_lastBotShot = time_current;
                    time_boss_B_skill_start = time_current;

                    initHPBar_BigBot(hpBarWhite, hpBarRed, BigBot);
                }

                if(numOfBots == 0
                   && (countWaveBot%7==0 && countWaveBot >= 7)
                        && (existBigBot == false)
                            && (time_current - time_clearWave >= time_waveDelay))

                {
                    BigBot = initBoss_C();
                    existBigBot = true;
                    countWaveBot++;
                    numOfBots = 1;
                    waitNewWave = false;

                    initBoss_C_Skill(BigBot, vectorBigBotBullets);
                    time_lastBotShot = time_current;

                    initHPBar_BigBot(hpBarWhite, hpBarRed, BigBot);
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
                    time_lastBotShot = time_current;

                    initHPBar_BigBot(hpBarWhite, hpBarRed, BigBot);
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

                    initHPBar(hpBarWhite, hpBarRed, vectorBots);
                }

                if(time_current - time_lastBotShot >= time_cooldownBotShot && vectorBots.size() > 0)
                {
                    graphics.play(botShot);
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
                                    BigBot.hearts-= 1;
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
                        hpBarRed.erase(hpBarRed.begin() + i);
                        hpBarWhite.erase(hpBarWhite.begin() + i);
                        numOfBots--;
                        player.score++;
                        vectorBots[i].alive = false;
                        graphics.renderInRect(boomTexture, vectorBots[i].rect);
                        initItem(vectorBots[i], vectorItem);
                        vectorBots.erase(vectorBots.begin() + i);
                        break;
                    }
                    else
                    {
                        hpBarRed[i].w = (vectorBots[i].hearts*50/2);
                        graphics.renderInRect(whiteHPBarTexture, hpBarWhite[i]);
                        graphics.renderInRect(redHPBarTexture, hpBarRed[i]);
                    }
                    if(checkCollision(player.rect, vectorBots[i].rect))
                    {
                        player.heart--;
                    }
                    botSprite.tick();
                    graphics.renderSprite(vectorBots[i].rect.x, vectorBots[i].rect.y, botSprite);
                }

                if(existBigBot && BigBot.alive)
                {
                    if(BigBot.hearts > 0)
                    {
                        hpBarRed[0].w = (BigBot.hearts*BigBot.rect.w/BigBot.init_Hearts);
                        hpBarRed[0].x = BigBot.rect.x;
                        hpBarWhite[0].x = BigBot.rect.x;
                        hpBarRed[0].y = BigBot.rect.y - 10;
                        hpBarWhite[0].y = BigBot.rect.y - 10;
                        graphics.renderInRect(whiteHPBarTexture, hpBarWhite[0]);
                        graphics.renderInRect(redHPBarTexture, hpBarRed[0]);
                    }
                    else
                    {
                        hpBarRed.erase(hpBarRed.begin());
                        hpBarWhite.erase(hpBarWhite.begin());
                    }

                    switch (BigBot.typeBot)
                    {
                    case 'a':
                        if(time_current - time_lastBotShot >= time_boss_A_cooldown)
                        {
                            graphics.play(bossAShot);
                            initBoss_A_Skill(BigBot, vectorBigBotBullets);
                            time_lastBotShot = time_current;
                        }
                        if(bossA_Sprite.countBeat == 0)
                        {
                            movingHorizontalRandom(BigBot);
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
                                graphics.play(bossBShot);
                                initBoss_B_Skill(BigBot.rect, vectorBigBotBullets);
                                time_lastBotShot = time_current;
                            }
                        }
                        if(time_current - time_boss_B_skill_start >= time_boss_B_skilling && (boss_B_waiting == false))
                        {
                            time_boss_B_wait = time_current;
                            boss_B_waiting = true;
                        }
                        if((time_current - time_boss_B_wait >= time_boss_B_skill_cooldown) && (boss_B_waiting == true))
                        {
                            time_boss_B_skill_start = time_current;
                            boss_B_waiting = false;
                        }

                        movingCircle(BigBot.rect, b_movingDegree, b_radius, 5, 170, 300);

                        bossB_Sprite.tick();;
                        graphics.renderSprite(BigBot.rect.x, BigBot.rect.y, bossB_Sprite);
                        break;
                    case 'c':
                        if(time_current - time_lastBotShot >= time_boss_C_cooldown)
                        {
                            graphics.play(bossCShot);
                            initBoss_C_Skill(BigBot, vectorBigBotBullets);
                            time_lastBotShot = time_current;
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
                            movingVerticalRandom(BigBot);
                        }
                        bossC_Sprite.tick();
                        graphics.renderSprite(BigBot.rect.x, BigBot.rect.y, bossC_Sprite);
                        break;

                    }
                    if(checkCollision(player.rect, BigBot.rect))
                    {
                        player.heart -= 2;
                    }
                    if(BigBot.hearts <= 0)
                    {
                        player.score += 10;
                        BigBot.alive = false;
                        existBigBot = false;
                        numOfBots -= 1;
                        graphics.renderInRect(boomTexture, BigBot.rect);
                        initItem(BigBot, vectorItem);
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
                        case 'H':
                            graphics.renderInRect(icon_Heart_Texture, vectorItem[i].rect);
                            break;
                        case 'F':
                            graphics.renderInRect(icon_Buff_item_Texture, vectorItem[i].rect);
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
                            case 'H':
                                player.heart += 10;
                                break;
                            case 'F':
                                buffSpeed = true;
                                time_buffSpeedStart = time_current;
                                break;
                            }
                            vectorItem[i].active = false;
                        }
                    }
                }

                playerSprite.tick();
                graphics.renderSprite(player.rect.x, player.rect.y, playerSprite);

                if(buffSpeed == true)
                {
                    if(time_current - time_buffSpeedStart <= time_buffTime)
                    {
                        time_playerShotCooldown = 100;
                    }
                    else
                    {
                        buffSpeed = false;
                        time_playerShotCooldown = 200;
                    }
                }

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

                ranking = getRank(rankPlayerSprite, player.score);
                rankPlayerSprite.currentFrame = ranking.first;
                graphics.renderSprite(125, 3, rankPlayerSprite);
                graphics.renderInRect(icon_Heart_Texture, icon_Heart_Rect);
                graphics.renderInRect(icon_Score_Texture, icon_Score_Rect);

                skill_Q_having_str = to_string(skill_Q_having);
                skill_W_having_str = to_string(skill_W_having);
                skill_E_having_str = to_string(skill_E_having);

                skill_Q_having_num_Texture = graphics.renderText(skill_Q_having_str.c_str(), fontFor_countSkillHaving, white);
                skill_W_having_num_Texture = graphics.renderText(skill_W_having_str.c_str(), fontFor_countSkillHaving, white);
                skill_E_having_num_Texture = graphics.renderText(skill_E_having_str.c_str(), fontFor_countSkillHaving, white);

                playerHeart = to_string(player.heart);
                playerScore = to_string(player.score);

                heartTexture = graphics.renderText(playerHeart.c_str(), fontFor_Score_and_Heart, orange);
                scoreTexture = graphics.renderText(playerScore.c_str(), fontFor_Score_and_Heart, orange);

                graphics.renderTexture(scoreTexture, 40, 10);
                graphics.renderTexture(heartTexture, 40, 50);
                graphics.renderTexture(skill_Q_having_num_Texture, 303, 55);
                graphics.renderTexture(skill_W_having_num_Texture, 383, 55);
                graphics.renderTexture(skill_E_having_num_Texture, 463, 55);

                if(time_current - time_clearWave <= time_waveDelay - 500 && time_current - time_clearWave >= 500 && countWaveBot > 1)
                {
                    graphics.renderSprite(0, 300, waitSprite);
                    waitSprite.tick();
                }

                if(time_Meteorite_cooldown > 10)
                {
                    time_Meteorite_cooldown -= 1;
                }
                else if(time_Meteorite_cooldown <= 10)
                {
                    time_Meteorite_cooldown = 3000 - time_current%1000;
                }

                if(time_Meteorite_cooldown <= 500 && time_Meoterite_last >= 200)
                {
                    warnSprite.tick();
                    graphics.renderSprite(170, 200, warnSprite);
                }

                graphics.renderInRect(pauseTexture, pause_rect);

                graphics.presentScene();
            }
            //destroy all texture
            if(gamingTheme != nullptr)
            {
                Mix_FreeMusic(gamingTheme);
            }

            //load play again menu
            if(!quit)
            {
                Button buttonPlayAgain = initButtonPlayAgain();
                Sprite buttonPlayAgainSprite;
                SDL_Texture* buttonPlayAgainSpriteTexture = graphics.loadTexture(BUTTON_PLAY_AGAIN_FILE);
                SDL_Texture* signImageTexture = graphics.loadTexture(SIGN_FILE);
                buttonPlayAgainSprite.init(buttonPlayAgainSpriteTexture, BUTTON_PLAY_AGAIN_FRAMES, BUTTON_PLAY_AGAIN_CLIPS);

                TTF_Font* fontFor_Score_and_Heart = graphics.loadFont("assets2/Minecraft.ttf", 100);

                scoreTexture = graphics.renderText(playerScore.c_str(), fontFor_Score_and_Heart, orange);

                string yourScore = "Your Score: ";
                SDL_Texture* yourScoreTexture = graphics.renderText(yourScore.c_str(), size_30, white);

                pair<int, string> rank_now = getRank(rankSprite, player.score);
                SDL_Texture* yourRankTexture = graphics.renderText(rank_now.second.c_str(), size_30, white);

                string signName = "", preSignName = "";
                SDL_Texture* signNameTexture = graphics.renderText(signName.c_str(), size_50, white);

                SDL_StartTextInput();

                int posMouse_x, posMouse_y;

                while(!quitPlayAgainMenu)
                {
                    while(SDL_PollEvent(&e) != 0)
                    {
                        if(e.type == SDL_QUIT)
                        {
                            quitPlayAgainMenu = true;
                        }
                        else if(e.type == SDL_TEXTINPUT && signName.length() < 12)
                        {
                            signName += e.text.text;
                        }
                        else if(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_BACKSPACE && signName.length() > 0)
                        {
                            signName.pop_back();
                        }
                        SDL_GetMouseState(&posMouse_x, &posMouse_y);
                        if(inButton(buttonPlayAgain, posMouse_x, posMouse_y))
                        {
                            buttonPlayAgainSprite.currentFrame = 1;
                            if(e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
                            {
                                playAgain = true;
                                quitPlayAgainMenu = true;
                            }
                        }
                        else
                        {
                            buttonPlayAgainSprite.currentFrame = 0;
                        }
                    }

                    if(signName != preSignName)
                    {
                        signNameTexture = graphics.renderText(signName.c_str(), size_30, white);
                        preSignName = signName;
                    }

                    background.scroll(1);
                    graphics.renderBackground(background);
                    graphics.renderTexture(yourScoreTexture, 200, 200);
                    graphics.renderTexture(scoreTexture, 230, 240);
                    graphics.renderSprite(170, 280, rankSprite);
                    graphics.renderTexture(yourRankTexture, 230, 450);
                    graphics.renderTexture(signImageTexture, 70, 550);
                    graphics.renderTexture(signNameTexture, 200, 580);
                    graphics.renderSprite(buttonPlayAgain.rect.x, buttonPlayAgain.rect.y, buttonPlayAgainSprite);
                    graphics.presentScene();
                }

                if(signName.length() == 0)
                {
                    signName = "Anonymous";
                }
                pair<string, string> player_pair = {signName, to_string(player.score)};
                highScore.push_back(player_pair);

                writeRankFile(highScore);

                SDL_StopTextInput();

            }

            SDL_DestroyTexture(scoreTexture); scoreTexture = NULL;
            SDL_DestroyTexture(heartTexture); heartTexture = NULL;
            SDL_DestroyTexture(skill_Q_having_num_Texture); skill_Q_having_num_Texture = NULL;
            SDL_DestroyTexture(skill_W_having_num_Texture); skill_W_having_num_Texture = NULL;
            SDL_DestroyTexture(skill_E_having_num_Texture); skill_E_having_num_Texture = NULL;
            SDL_DestroyTexture(waitSpriteTexture); waitSpriteTexture = NULL;
            SDL_DestroyTexture(playerSpriteTexture); playerSpriteTexture = NULL;
            SDL_DestroyTexture(rankPlayerSpriteTexture); rankPlayerSpriteTexture = NULL;
            SDL_DestroyTexture(playerSkill_Q_SpriteTexture); playerSkill_Q_SpriteTexture = NULL;
            SDL_DestroyTexture(playerSkill_E_SpriteTexture); playerSkill_E_SpriteTexture = NULL;
            SDL_DestroyTexture(botSpriteTexture); botSpriteTexture = NULL;
            SDL_DestroyTexture(bossA_SpriteTexture); bossA_SpriteTexture = NULL;
            SDL_DestroyTexture(bossB_SpriteTexture); bossB_SpriteTexture = NULL;
            SDL_DestroyTexture(bossC_SpriteTexture); bossC_SpriteTexture = NULL;
            SDL_DestroyTexture(bumbum_SpriteTexture); bumbum_SpriteTexture = NULL;
            SDL_DestroyTexture(warnSpriteTexture); warnSpriteTexture = NULL;
            SDL_DestroyTexture(playerBulletTexture); playerBulletTexture = NULL;
            SDL_DestroyTexture(playerSkillWTexture); playerSkillWTexture = NULL;
            SDL_DestroyTexture(botBulletTexture); botBulletTexture = NULL;
            SDL_DestroyTexture(bossASkillTexture); bossASkillTexture = NULL;
            SDL_DestroyTexture(bossBSkillTexture); bossBSkillTexture = NULL;
            SDL_DestroyTexture(bossCSkillTexture); bossCSkillTexture = NULL;
            SDL_DestroyTexture(bossCBulletSkillTexture); bossCBulletSkillTexture = NULL;
            SDL_DestroyTexture(meteoriteTexture); meteoriteTexture = NULL;
            SDL_DestroyTexture(icon_Q_Texture); icon_Q_Texture = NULL;
            SDL_DestroyTexture(icon_Q_0_Texture); icon_Q_0_Texture = NULL;
            SDL_DestroyTexture(icon_Q_item_Texture); icon_Q_item_Texture = NULL;
            SDL_DestroyTexture(icon_W_Texture); icon_W_Texture = NULL;
            SDL_DestroyTexture(icon_W_0_Texture); icon_W_0_Texture = NULL;
            SDL_DestroyTexture(icon_W_item_Texture); icon_W_item_Texture = NULL;
            SDL_DestroyTexture(icon_E_Texture); icon_E_Texture = NULL;
            SDL_DestroyTexture(icon_E_0_Texture); icon_E_0_Texture = NULL;
            SDL_DestroyTexture(icon_E_item_Texture); icon_E_item_Texture = NULL;
            SDL_DestroyTexture(icon_Buff_item_Texture); icon_Buff_item_Texture = NULL;
            SDL_DestroyTexture(icon_Cup_Texture); icon_Cup_Texture = NULL;
            SDL_DestroyTexture(icon_Heart_Texture); icon_Heart_Texture = NULL;
            SDL_DestroyTexture(icon_Score_Texture); icon_Score_Texture = NULL;
            SDL_DestroyTexture(boomTexture); boomTexture = NULL;
            SDL_DestroyTexture(redHPBarTexture); redHPBarTexture = NULL;
            SDL_DestroyTexture(whiteHPBarTexture); whiteHPBarTexture = NULL;
            SDL_DestroyTexture(pauseTexture); pauseTexture = NULL;
//
            if (playerShot != nullptr) {
                Mix_FreeChunk(playerShot);
            }

            if (wShot != nullptr) {
                Mix_FreeChunk(wShot);
            }

            if (botShot != nullptr) {
                Mix_FreeChunk(botShot);
            }

            if (bossAShot != nullptr) {
                Mix_FreeChunk(bossAShot);
            }

            if (bossBShot != nullptr) {
                Mix_FreeChunk(bossBShot);
            }

            if (bossCShot != nullptr) {
                Mix_FreeChunk(bossCShot);
            }
        }
        SDL_DestroyTexture(menuBackground); menuBackground = NULL;
        SDL_DestroyTexture(buttonPlaySpriteTexture); buttonPlaySpriteTexture = NULL;
        SDL_DestroyTexture(buttonHTPSpriteTexture); buttonHTPSpriteTexture = NULL;
        SDL_DestroyTexture(buttonHighScoreSpriteTexture); buttonHighScoreSpriteTexture = NULL;
        SDL_DestroyTexture(buttonReturnMenuSpriteTexture); buttonReturnMenuSpriteTexture = NULL;
        SDL_DestroyTexture(rankSpriteTexture); rankSpriteTexture = NULL;
        SDL_DestroyTexture(chooseAircraftSpriteTexture); chooseAircraftSpriteTexture = NULL;
        SDL_DestroyTexture(guideTexture); guideTexture = NULL;
        SDL_DestroyTexture(highScore_Box_Texture); highScore_Box_Texture = NULL;
        SDL_DestroyTexture(preButtonTexture); preButtonTexture = NULL;
        SDL_DestroyTexture(nextButtonTexture); nextButtonTexture = NULL;

        TTF_CloseFont(size_30);
        TTF_CloseFont(size_50);

        for(int i = 0; i < 5; i++)
        {
            SDL_DestroyTexture(highScore_text_name[i]);
            highScore_text_name[i] = NULL;
            SDL_DestroyTexture(highScore_text_score[i]);
            highScore_text_score[i] = NULL;
        }


    }
    return 0;
}
