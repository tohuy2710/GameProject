#ifndef DEFS_H_INCLUDED
#define DEFS_H_INCLUDED

const int SCREEN_WIDTH = 540;
const int SCREEN_HEIGHT = 960; //540 960
const char* WINDOW_TITLE = "Game";

const char* MENU_BACKGROUND_FILE = "assets2/gameMenuBackground.png";
const char* BACKGROUND_FILE = "assets2/background.jpg";

const char* PLAYER_SPRITE_FILE_1 = "assets2/aircraft_1.png";
const char* PLAYER_SPRITE_FILE_2 = "assets2/aircraft_2.png";
const char* PLAYER_SPRITE_FILE_3 = "assets2/aircraft_3.png";
const char* PLAYER_SPRITE_FILE_4 = "assets2/aircraft_4.png";
const char* BOT_SPRITE_FILE = "assets2/bot02Sprite.png";
const char* BOSS_A_SPRITE_FILE = "assets2/bossASprite.png";
const char* BOSS_B_SPRITE_FILE = "assets2/bossBSprite.png";
const char* BOSS_C_SPRITE_FILE = "assets2/bossCSprite.png";
const char* METEORITE_FILE = "assets2/meteo.png";

const char* BUTTON_PLAY_SPRITE_FILE = "assets2/playButtonSprite.png";
const char* CHOOSE_AIRCRAFT_SPRITE_FILE = "assets2/choose_aircraft_sprite.png";
const char* BUTTON_HTP_SPRITE_FILE = "assets2/htpButtonSprite.png";
const char* BUTTON_HIGH_SCORE_FILE = "assets2/highScore_button.png";
const char* BUTTON_PLAY_AGAIN_FILE = "assets2/playAgain_button.png";
const char* BUTTON_PRE_FILE = "assets2/pre.png";
const char* BUTTON_NEXT_FILE = "assets2/next.png";
const char* BUTTON_RETURN_MENU_FILE = "assets2/returnMenu.png";
const char* PRESS_TO_CONTINUE_FILE = "assets2/press_ctn.png";
const char* NEW_GAME_FILE = "assets2/newGame.png";
const char* BUTTON_PAUSE_FILE = "assets2/pause.png";
const char* HIGH_SCORE_PLAYERS_BOX_FILE = "assets2/highScore_players.png";
const char* GUIDE_FILE = "assets2/guideTheme.png";

const char* PLAYER_BULLET_FILE = "assets2/player_laser.png";
const char* BOT_BULLET_FILE = "assets2/enemy_laser.png";
const char* BIGBOT_A_SKILL_FILE = "assets2/bossASkill.png";
const char* BIGBOT_B_SKILL_FILE = "assets2/bossBSkill.png";
const char* BIGBOT_C_SKILL_FILE = "assets2/bossCSkill.png";
const char* BIGBOT_C_BULLET_SKILL_FILE = "assets2/bossCBulletSkill.png";

const char* PLAYER_SKILL_Q_SPRITE_FILE = "assets2/skill_Q.png";
const char* PLAYER_SKILL_W_FILE = "assets2/skill_W.png";
const char* PLAYER_SKILL_E_SPRITE_FILE = "assets2/skill_E.png";

const char* BOOM_FILE = "assets2/boom.png";
const char* BUMBUM_SPRITE_FILE = "assets2/bumbumSprite.png";

const char* ICON_BUFF_FILE = "assets2/buff.png";
const char* Q_ICON_FILE = "assets2/q.png";
const char* Q_0_ICON_FILE = "assets2/q_0.png";
const char* W_ICON_FILE = "assets2/w.png";
const char* W_0_ICON_FILE = "assets2/w_0.png";
const char* E_ICON_FILE = "assets2/e.png";
const char* E_0_ICON_FILE = "assets2/e_0.png";
const char* Q_ICON_ITEM_FILE = "assets2/q_item.png";
const char* W_ICON_ITEM_FILE = "assets2/w_item.png";
const char* E_ICON_ITEM_FILE = "assets2/e_item.png";

const char* ICON_HEART_FILE = "assets2/icon_heart.png";
const char* ICON_SCORE_FILE = "assets2/icon_score.png";
const char* ICON_CUP_FILE = "assets2/icon_cup.png";

const char* HIGH_SCORE_FILE = "highScore.txt";
const char* RANK_FILE = "assets2/rank.png";
const char* RANK_PLAYER_FILE = "assets2/rank_player.png";

const char* WAIT_SPRITE_FILE = "assets2/wait.png";
const char* WARN_SPRITE_FILE = "assets2/meteorShowerWarn_Sprite.png";
const char* SIGN_FILE = "assets2/sign.png";
const char* RED_FILE = "assets2/red.png";
const char* WHITE_FILE = "assets2/white.png";


const int CHOOSE_AIRCRAFT_CLIPS[][4] = {
    {  0, 0, 200, 200},
    {200, 0, 200, 200},
    {400, 0, 200, 200},
    {600, 0, 200, 200},};

const int PLAYER_CLIPS[][4] = {
    {  0, 0, 75, 75},
    { 75, 0, 75, 75},
    {150, 0, 75, 75},
    {225, 0, 75, 75},
    {300, 0, 75, 75},
    {375, 0, 75, 75},
    {450, 0, 75, 75},
    {525, 0, 75, 75},
    {600, 0, 75, 75},
    {675, 0, 75, 75},
    {750, 0, 75, 75},
    {825, 0, 75, 75},};

const int PLAYER_SKILL_Q_CLIPS[][4] = {
    {  0, 0, 120, 120},
    {  120, 0, 120, 120},
    {  240, 0, 120, 120},
    {  360, 0, 120, 120},
    {  480, 0, 120, 120},
    {  600, 0, 120, 120},
    {  720, 0, 120, 120},
    {  840, 0, 120, 120},
    {  960, 0, 120, 120},
    {  1080, 0, 120, 120},
    {  1200, 0, 120, 120},
    {  1320, 0, 120, 120},
    {  1440, 0, 120, 120},
    {  1680, 0, 120, 120},
    {  1800, 0, 120, 120},
    {  1920, 0, 120, 120},
    {  2040, 0, 120, 120},
    {  2160, 0, 120, 120},
    {  2280, 0, 120, 120},
    };
const int PLAYER_SKILL_E_CLIPS[][4] = {
    {  0, 0, 40, 40},
    {  40, 0, 40, 40},
    {  80, 0, 40, 40},
    {  120, 0, 40, 40},
    {  160, 0, 40, 40},
    {  200, 0, 40, 40},
    {  240, 0, 40, 40},
    {  280, 0, 40, 40},
    {  320, 0, 40, 40},
    {  360, 0, 40, 40},
    {  400, 0, 40, 40},
    {  440, 0, 40, 40},
};

const int BUMBUM_CLIPS[][4] = {
    {  0, 0, 75, 75},
    {  75, 0, 75, 75},
    {  150, 0, 75, 75},
    {  225, 0, 75, 75},
    {  300, 0, 75, 75},
    {  375, 0, 75, 75},};

const int BOT_CLIPS[][4] = {
    {  0, 0, 50, 50},
    { 50, 0, 50, 50},
    {100, 0, 50, 50},
    {150, 0, 50, 50},
    {200, 0, 50, 50},
    {250, 0, 50, 50},};

const int STONE_01_CLIPS[][4] = {
    {  0, 0, 100, 100},
    { 100, 0, 100, 100},
    {200, 0, 100, 100},
    {300, 0, 100, 100},
    {400, 0, 100, 100},
    {500, 0, 100, 100},};

const int BOSS_A_CLIPS[][4] = {
    {  0, 0, 125, 100},
    {  125, 0, 125, 100},
    {  250, 0, 125, 100},
    {  375, 0, 125, 100},
    {  500, 0, 125, 100},
    {  625, 0, 125, 100},
    {  750, 0, 125, 100},
    {  875, 0, 125, 100},
    {  1000, 0, 125, 100},
    {  1125, 0, 125, 100},};

const int BOSS_B_CLIPS[][4] = {
    {  0, 0, 200, 175},
    {  200, 0, 200, 175},
    {  400, 0, 200, 175},
    {  600, 0, 200, 175},
    {  800, 0, 200, 175},
    {  1000, 0, 200, 175},
    {  1200, 0, 200, 175},
    {  1400, 0, 200, 175},
    {  1600, 0, 200, 175},
    {  1800, 0, 200, 175},
    {  2000, 0, 200, 175},
    {  2200, 0, 200, 175},
    {  2400, 0, 200, 175},
    {  2600, 0, 200, 175},
    {  2800, 0, 200, 175},
    {  3000, 0, 200, 175},
    {  3200, 0, 200, 175},
    {  3400, 0, 200, 175},
    {  3600, 0, 200, 175},
    {  3800, 0, 200, 175},
    {  4000, 0, 200, 175},};

const int BOSS_C_CLIPS[][4] = {
    {0, 0, 255, 175},
    {255, 0, 255, 175},
    {510, 0, 255, 175},
    {765, 0, 255, 175},
    {1020, 0, 255, 175},
    {1275, 0, 255, 175},
    {1530, 0, 255, 175},
    {1785, 0, 255, 175},
    {2040, 0, 255, 175},
    {2295, 0, 255, 175},
    {2550, 0, 255, 175},
    {2805, 0, 255, 175},};

const int BUTTON_PLAY_CLIPS[][4] = {
    {  0, 0, 200, 100},
    { 200, 0, 200, 100},};

const int BUTTON_RETURN_MENU_CLIPS[][4] = {
    {  0, 0, 200, 100},
    { 200, 0, 200, 100},};

const int BUTTON_HIGH_SCORE_CLIPS[][4] = {
    {  0, 0, 200, 100},
    { 200, 0, 200, 100},};

const int BUTTON_HTP_CLIPS[][4] = {
    {  0, 0, 200, 100},
    { 200, 0, 200, 100},};

const int NEW_GAME_CLIPS[][4] = {
    {  0, 0, 200, 100},
    { 200, 0, 200, 100},};

const int PRESS_TO_CONTINUE_CLIPS[][4] = {
    {  0, 0, 540, 50},
    { 0, 50, 540, 50},};

const int BUTTON_PLAY_AGAIN_CLIPS[][4] = {
    {  0, 0, 300, 100},
    { 300, 0, 300, 100},};

const int RANK_CLIPS[][4] = {
    {  0, 0, 200, 200},
    {  200, 0, 200, 200},
    {  400, 0, 200, 200},
    {  600, 0, 200, 200},
    {  800, 0, 200, 200},
    {  1000, 0, 200, 200},};

const int RANK_PLAYER_CLIPS[][4] = {
    {  0, 0, 80, 80},
    { 80, 0, 80, 80},
    { 160, 0, 80, 80},
    { 240, 0, 80, 80},
    { 320, 0, 80, 80},
    { 400, 0, 80, 80},
    { 480, 0, 80, 80},};

const int WAIT_CLIPS[][4] = {
    {  0, 0, 540, 100},
    {  540, 0, 540, 100},};

const int WARN_CLIPS[][4] = {
    {  0, 0, 200, 200},
    {  200, 0, 200, 200},};

const int PLAYER_FRAMES = sizeof(PLAYER_CLIPS)/sizeof(int)/4;
const int PLAYER_SKILL_Q_FRAMES = sizeof(PLAYER_SKILL_Q_CLIPS)/sizeof(int)/4;
const int PLAYER_SKILL_E_FRAMES = sizeof(PLAYER_SKILL_E_CLIPS)/sizeof(int)/4;
const int BOT_FRAMES = sizeof(BOT_CLIPS)/sizeof(int)/4;
const int BOSS_A_FRAMES = sizeof(BOSS_A_CLIPS)/sizeof(int)/4;
const int BOSS_B_FRAMES = sizeof(BOSS_B_CLIPS)/sizeof(int)/4;
const int BOSS_C_FRAMES = sizeof(BOSS_C_CLIPS)/sizeof(int)/4;
const int STONE_01_FRAMES = sizeof(STONE_01_CLIPS)/sizeof(int)/4;
const int BUTTON_PLAY_FRAMES = sizeof(BUTTON_PLAY_CLIPS)/sizeof(int)/4;
const int BUTTON_HTP_FRAMES = sizeof(BUTTON_HTP_CLIPS)/sizeof(int)/4;
const int BUTTON_HIGH_SCORE_FRAMES = sizeof(BUTTON_HIGH_SCORE_CLIPS)/sizeof(int)/4;
const int BUTTON_PLAY_AGAIN_FRAMES = sizeof(BUTTON_PLAY_AGAIN_CLIPS)/sizeof(int)/4;
const int BUTTON_RETURN_MENU_FRAMES = sizeof(BUTTON_RETURN_MENU_CLIPS)/sizeof(int)/4;
const int BUMBUM_FRAMES = sizeof(BUMBUM_CLIPS)/sizeof(int)/4;
const int RANK_FRAMES = sizeof(RANK_CLIPS)/sizeof(int)/4;
const int RANK_PLAYER_FRAMES = sizeof(RANK_PLAYER_CLIPS)/sizeof(int)/4;
const int WAIT_FRAMES = sizeof(WAIT_CLIPS)/sizeof(int)/4;
const int WARN_FRAMES = sizeof(WARN_CLIPS)/sizeof(int)/4;
const int NEW_GAME_FRAMES = sizeof(NEW_GAME_CLIPS)/sizeof(int)/4;
const int PRESS_TO_CONTINUE_FRAMES = sizeof(PRESS_TO_CONTINUE_CLIPS)/sizeof(int)/4;
const int CHOOSE_AIRCRAFT_FRAMES = sizeof(CHOOSE_AIRCRAFT_CLIPS)/sizeof(int)/4;

#endif // DEFS_H_INCLUDED
