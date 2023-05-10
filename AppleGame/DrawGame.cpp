#include "DxLib.h"
#include"prototype.h"
#include "variable.h"
#include "define.h"

int gGameFlameCount;
int gGameTime;
int gScore;
extern mode gGameMode;
bool Pause;

void DrawGame(void) {

	PlaySoundMem(gStageBGM, DX_PLAYTYPE_LOOP, false);

	DrawGraph(0, 0, gStageImg, false);

	DrawBox(SCREEN_WIDTH - (140 * 2), 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0x00ff80, true);

	DrawFormatString(SCREEN_WIDTH - (120 * 2), 80, 0x000000, "Time:%-3d", gGameTime);

	DrawFormatString(SCREEN_WIDTH - (120 * 2), 160, 0x000000, "Score:%-6d", gScore);


	SetFontSize(48);
	DrawString(SCREEN_WIDTH - (120 * 2), (160 * 2), "個数", 0x000000);
	SetFontSize(32);
	for (int i = 0; i < 4; i++) {
		DrawRotaGraph(SCREEN_WIDTH - (100 * 2), 410 + 70 * i, 1.2f, 0, gAppleImg[i], true, false);
		DrawFormatString(SCREEN_WIDTH - (60 * 2), 400 + 70 * i, 0x000000, "x%3d", gAppleCount[i]);
	}

	if (gKeyFlg & PAD_INPUT_8) {

		Pause = !Pause;

	}
	if (Pause) {

		SetFontSize(64);
		DrawString(100, 200, "--ポーズ中--", 0x0f0f0f);
		SetFontSize(16);

	}
	else if (!Pause) {

		if (gGameTime < 1) {
			StopSoundMem(gStageBGM);
			gGameMode = GAMEOVER;
		}

		AppleControl();

		//プレイヤー制御
		PlayerControl();

		if (++gGameFlameCount > 28) {
			gGameTime--;
			gGameFlameCount = 0;
		}
	}
}