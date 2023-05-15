#include "DxLib.h"
#include "define.h"
#include "variable.h"
#include "prototype.h"
#include "result.h"

void DrawGameOver(void) {


	if(!playSE) {
		PlaySoundMem(gGameOverSE, DX_PLAYTYPE_BACK, false);
		playSE = 1;
	}
	DrawGraph(0, 0, gStageImg, false);

	DrawBox(150, 120, SCREEN_WIDTH - 150, SCREEN_HEIGHT - 160, 0x000000, true);
	DrawBox(150 + 5, 120 + 5, SCREEN_WIDTH - 150 - 5, SCREEN_HEIGHT - 160 - 5, 0xffffff, true);

	for (int i = 0; i < 4; i++) {
		DrawRotaGraph(450, 185 + 70 * i, 1.2f, 0, gAppleImg[i], true, false);
		SetFontSize(40);
		DrawFormatString(550, 180 + 70 * i, 0x000000, "x%3d = %5d", gAppleCount[i],gAppleCount[i]*gAppleScore[i]);
	}
	DrawFormatString(500, 480, 0x000000, "Score : %-6d", gScore);
	if (++RWaitTime > 180) {
		PlaySoundMem(gSEmenu2, DX_PLAYTYPE_BACK, true);

		if (gRanking[RANKING_DATA - 1].score > gScore) {
			gGameMode = RANKING; 
		}
		else
		{
		gGameMode = INPUTNAME;
		}

		playSE = 0;
	}
}