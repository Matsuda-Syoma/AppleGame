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
	gPlayer.y = SCREEN_HEIGHT - 120;
	gPlayer.w = 96;
	gPlayer.h = 190;
	gPlayer.speed = 0;
	CoolTime = 0;
	OldAppleSpawn = 0;

	gGameTime = GAMETIME;

	for (int i = 0; i < 4; i++) {
		gAppleCount[i] = 0;
	}
	gGameMode = MAIN;
}