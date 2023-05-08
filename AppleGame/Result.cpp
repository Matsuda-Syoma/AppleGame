#include "DxLib.h"
#include"prototype.h"
#include "variable.h"
#include "define.h"

extern mode gGameMode;

void DrawGameOver(void) {

	PlaySoundMem(gGameOverSE, DX_PLAYTYPE_BACK, false);

	DrawGraph(0, 0, gStageImg, false);

	DrawBox(150, 120, SCREEN_WIDTH - 150, 320, 0x000000, true);
	DrawBox(150 + 5, 120 + 5, SCREEN_WIDTH - 150 - 5, 320 - 5, 0xffffff, true);

	for (int i = 0; i < 4; i++) {
		DrawRotaGraph(260, 155 + 30 * i, 0.6f, 0, gAppleImg[i], true, false);
		SetFontSize(20);
		DrawFormatString(300, 150 + 30 * i, 0x000000, "x%3d", gAppleCount[i]);
	}
	DrawFormatString(250, 280, 0x000000, "Score : %-6d", gScore);
	if (gKeyFlg & PAD_INPUT_A) {
		gGameMode = INPUTNAME;
	}
}