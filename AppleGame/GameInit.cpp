#include "DxLib.h"
#include"prototype.h"
#include "variable.h"
#include "define.h"
#include "player.h"

extern mode gGameMode;
extern struct PLAYER gPlayer;

//extern int gGameTime;
void GameInit(void) {


	gPlayer.flg = true;
	gPlayer.x = 0;
	gPlayer.y = 400;
	gPlayer.w = 64;
	gPlayer.h = 90;
	gPlayer.speed = 0;
	CoolTime = 0;

	gGameTime = GAMETIME;

	for (int i = 0; i < 4; i++) {
		gAppleCount[i] = 0;
	}
	gGameMode = MAIN;
}