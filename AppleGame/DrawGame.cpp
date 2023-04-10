#include "DxLib.h"
#include"prototype.h"
#include "variable.h"
#include "define.h"

void DrawGame(void) {
	DrawGraph(0, 0, gStageImg, false);

	AppleControl();

	DrawBox(500, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0x00ffff, true);
	SetFontSize(24);
	DrawString(520, 160, "å¬êî", 0x000000);
	SetFontSize(16);
	for (int i = 0; i < 4; i++) {
		DrawRotaGraph(540, 205 + 40 * i, 0.6f, 0, gAppleImg[i], true, false);
		DrawFormatString(580, 200 + 40 * i, 0x000000, "x%3d", gAppleCount[i]);
	}
}