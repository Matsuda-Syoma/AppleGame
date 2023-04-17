#include "DxLib.h"
#include"prototype.h"
#include "variable.h"
#include "define.h"

int gGameFlameCount;
int gGameTime;

void DrawGame(void) {
	DrawGraph(0, 0, gStageImg, false);

	AppleControl();
	PlayerControl();

	DrawBox(500, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0x00ffff, true);

	if (++gGameFlameCount > 28) {
		gGameTime--;
		gGameFlameCount = 0;
	}
	DrawFormatString(560, 100, 0x000000, "%3d", gGameTime);


	SetFontSize(24);
	DrawString(520, 160, "å¬êî", 0x000000);
	SetFontSize(16);
	for (int i = 0; i < 4; i++) {
		DrawRotaGraph(540, 205 + 40 * i, 0.6f, 0, gAppleImg[i], true, false);
		DrawFormatString(580, 200 + 40 * i, 0x000000, "x%3d", gAppleCount[i]);
	}
}