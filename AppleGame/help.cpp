#include "DxLib.h"
#include"prototype.h"
#include "variable.h"
#include "define.h"

void DrawHelp(void) {
	
	if (gKeyFlg & PAD_INPUT_A) {
		PlaySoundMem(gSEmenu2, DX_PLAYTYPE_BACK, true);
		gGameMode = TITLE;
	}
	if (gKeyFlg & PAD_INPUT_B) {
		PlaySoundMem(gSEmenu2, DX_PLAYTYPE_BACK, true);
		gGameMode = INIT;
	}
	DrawGraph(0, 0, gHelpImg, false);
}
