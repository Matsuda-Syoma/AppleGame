#include "DxLib.h"
#include "define.h"
#include "variable.h"
#include"prototype.h"
#include "player.h"

void GameInit(void) {

	//アイテムの初期設定
	for (int i = 0; i < 4; i++) {
		gAppleCount[i] = 0;
	}

	for (int i = 0; i < APPLE_MAX; i++) {
		gApple[i].flg = false;
	}

	//プレイヤーの初期設定
	gPlayer.flg = true;
	gPlayer.x = 0;
	gPlayer.y = SCREEN_HEIGHT - 120;
	gPlayer.w = 96;
	gPlayer.h = 190;
	gPlayer.speed = 0;
	CoolTime = 0;
	OldAppleSpawn = 0;
	gScore = 0;

	RWaitTime = 0;
	MoziSelectW = 0;
	MoziSelectH = 0;

	strcpy_s(MoziFrame, "");

	SetSoundCurrentTime(0, gStageBGM);
	SetSoundCurrentTime(0, gGameOverSE);

	gGameTime = GAMETIME;

	for (int i = 0; i < 4; i++) {
		gAppleCount[i] = 0;
	}
	gGameMode = MAIN;
}