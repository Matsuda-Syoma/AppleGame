#include "DxLib.h"
#include"prototype.h"
#include "variable.h"
#include "define.h"

int gGameFlameCount;
int gGameTime;
int gScore;
extern mode gGameMode;

void DrawGame(void) {
	DrawGraph(0, 0, gStageImg, false);

	if (gGameTime < 1) {
		gGameMode = GAMEOVER;
	}

	AppleControl();

	DrawBox(500, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0x00ffff, true);

	if (++gGameFlameCount > 28) {
		gGameTime--;
		gGameFlameCount = 0;
	}
	DrawFormatString(520, 40, 0x000000, "Time:%-3d", gGameTime);

	DrawFormatString(520, 80, 0x000000, "Score:%--6d", gScore);


	SetFontSize(24);
	DrawString(520, 160, "å¬êî", 0x000000);
	SetFontSize(16);
	for (int i = 0; i < 4; i++) {
		DrawRotaGraph(540, 205 + 40 * i, 0.6f, 0, gAppleImg[i], true, false);
		DrawFormatString(580, 200 + 40 * i, 0x000000, "x%3d", gAppleCount[i]);
	}
}