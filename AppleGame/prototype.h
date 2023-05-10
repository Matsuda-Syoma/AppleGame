#ifndef PROTOTYPE_H
#define PROTOTYPE_H

//const int SCREEN_WIDTH = 640;
//const int SCREEN_HEIGHT = 480;

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;


extern struct PLAYER;
extern struct APPLE;

int LoadImages(void);

void AppleControl(void);
void PlayerControl(void);
int CreateApple(void);
int LoadImages(void);
void GameInit(void);
void DrawGame(void);
int HitBoxPlayer(PLAYER* p, APPLE* e);
void PlayerControl(void);
void DrawTitle(void);
void DrawHelp(void);
void DrawEnd(void);
int LoadSound(void);
void DrawGameOver(void);

void DrawRanking(void);
void InputName(void);
void SortRanking(void);
int SaveRanking(void);
int ReadRanking(void);

//int HitBoxPlayer(APPLE* a);

#endif