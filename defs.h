#ifndef DEFS_H_INCLUDED
#define DEFS_H_INCLUDED

const int SCREEN_WIDTH = 540;
const int SCREEN_HEIGHT = 960;
const char* WINDOW_TITLE = "Game";

const char* MENU_BACKGROUND_FILE = "assets2/gameMenuBackground.png";
const char* BACKGROUND_FILE = "assets2/background.jpg";

const char* PLAYER_SPRITE_FILE = "assets2/tests.png";
const char* BOT_SPRITE_FILE = "assets2/bot02Sprite.png";
const char* BOSS_A_SPRITE_FILE = "assets2/bossASprite.png";
const char* BOSS_B_SPRITE_FILE = "assets2/bossBSprite.png";
const char* BOSS_C_SPRITE_FILE = "assets2/bossCSprite.png";

const char* STONE_01_SPRITE_FILE = "assets2/stone_01.png";
const char* STONE_02_SPRITE_FILE = "assets2/stone_02.png";
const char* STONE_03_SPRITE_FILE = "assets2/stone_03.png";

const char* BUTTON_PLAY_SPRITE_FILE = "assets2/playButtonSprite.png";
const char* BUTTON_HTP_SPRITE_FILE = "assets2/htpButtonSprite.png";
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

const int BOT_CLIPS[][4] = {
    {  0, 0, 50, 50},
    { 50, 0, 50, 50},
    {100, 0, 50, 50},
    {150, 0, 50, 50},
    {200, 0, 50, 50},
    {250, 0, 50, 50},
    {300, 0, 50, 50},
    {350, 0, 50, 50},};

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

const int BUTTON_HTP_CLIPS[][4] = {
    {  0, 0, 200, 100},
    { 200, 0, 200, 100},};

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

#endif // DEFS_H_INCLUDED
