#include "DxLib.h"
#include"prototype.h"
#include "variable.h"
#include "define.h"

extern mode gGameMode;

void DrawHelp(void) {
	
	if (gKeyFlg & PAD_INPUT_A) gGameMode = TITLE;
	if (gKeyFlg & PAD_INPUT_B) gGameMode = INIT;
	DrawGraph(0, 0, gHelpImg, false);
}
