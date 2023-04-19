#ifndef PROTOTYPE_H
#define PROTOTYPE_H

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

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
int LoadSound(void);
//int HitBoxPlayer(APPLE* a);

#endif