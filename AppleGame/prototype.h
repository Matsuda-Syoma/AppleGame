#ifndef PROTOTYPE_H
#define PROTOTYPE_H

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int LoadImages(void);

void AppleControl(void);
void PlayerControl(void);
int CreateApple(void);
int LoadImages(void);
void GameInit(void);
void DrawGame(void);
//int HitBoxPlayer(PLAYER* p, APPLE* e);

#endif