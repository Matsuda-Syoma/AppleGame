#include "DxLib.h"
#include"prototype.h"
#include "variable.h"
#include "define.h"
#include "ranking.h"

extern mode gGameMode;

void DrawGameOver(void) {

	PlaySoundMem(gGameOverSE, DX_PLAYTYPE_BACK, false);

	DrawGraph(0, 0, gStageImg, false);

	DrawBox(150, 120, SCREEN_WIDTH - 150, SCREEN_HEIGHT - 160, 0x000000, true);
	DrawBox(150 + 5, 120 + 5, SCREEN_WIDTH - 150 - 5, SCREEN_HEIGHT - 160 - 5, 0xffffff, true);

	for (int i = 0; i < 4; i++) {
		DrawRotaGraph(400, 185 + 70 * i, 1.2f, 0, gAppleImg[i], true, false);
		SetFontSize(40);
		DrawFormatString(500, 180 + 70 * i, 0x000000, "x%3d", gAppleCount[i]);
	}
	DrawFormatString(250, 480, 0x000000, "Score : %-6d", gScore);
	if (gKeyFlg & PAD_INPUT_A) {
		if (gRanking[RANKING_DATA - 1].score > gScore) {
			gGameMode = RANKING; 
		}
		else
		{
		gGameMode = INPUTNAME;
		}


	}
}