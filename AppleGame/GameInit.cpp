#include "DxLib.h"
#include"prototype.h"
#include "variable.h"
#include "define.h"

extern mode gGameMode;
//extern int gGameTime;
void GameInit(void) {

	gGameTime = GAMETIME;

	for (int i = 0; i < 4; i++) {
		gAppleCount[i] = 0;
	}
	gGameMode = MAIN;
}