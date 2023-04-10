#include "DxLib.h"
#include"prototype.h"
#include "variable.h"
#include "define.h"

extern mode gGameMode;

void GameInit(void) {

	for (int i = 0; i < 4; i++) {
		gAppleCount[i] = 0;
	}
	gGameMode = MAIN;
}