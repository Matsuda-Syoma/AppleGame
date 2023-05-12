#include "DxLib.h"
#include"prototype.h"
#include "variable.h"
#include "define.h"
#include "title.h"

void DrawTitle(void) {

	static int menuNo = 0;
	//タイトルBGM再生
	PlaySoundMem(gTitleBGM, DX_PLAYTYPE_LOOP, false);
	//メニューカーソル移動処理
	if (gKeyFlg & PAD_INPUT_DOWN) {

		if (++menuNo > 3)menuNo = 0;
		PlaySoundMem(gSEmenu1[menuNo], DX_PLAYTYPE_BACK, true);
	}
	if (gKeyFlg & PAD_INPUT_UP) {

		if (--menuNo < 0)menuNo = 3;
		PlaySoundMem(gSEmenu1[menuNo], DX_PLAYTYPE_BACK, true);
	}

	//Zキーでメニュー選択
	if (gKeyFlg & PAD_INPUT_A) {

		StopSoundMem(gTitleBGM);
		SetSoundCurrentTime(0, gTitleBGM);
		PlaySoundMem(gSEmenu2, DX_PLAYTYPE_BACK, true);

		switch (menuNo) {

		case 0:
			gGameMode = INIT;
			break;
		case 1:
			gGameMode = RANKING;
			break;
		case 2:
			gGameMode = HELP;
			break;
		case 3:
			gGameMode = END;
			break;
		}
	}

	//タイトル、メニュー、カーソル画像の表示
	DrawGraph(0, 0, gTitleImg, false);
	DrawRotaGraph((225 * 2), 385 + menuNo * 70, 1.0f, 0, gAppleImg[0], true);

	for (int i = 0; i < 12; i++) {
		if (TAnimApple[i].flg == false || gGameMode != TITLE) {
			TAnimApple[i] = TAnim00;
			TAnimApple[i].x = GetRand(300)+ ++Spawn % 2 * 900 + 100;
			TAnimApple[i].speed = GetRand(5.0f) + 2;

		}
		else {
			DrawRotaGraph(TAnimApple[i].x, TAnimApple[i].y, 0.5f, 0, gAppleImg[0], true, false);
			TAnimApple[i].y += TAnimApple[i].speed;
			if (TAnimApple[i].y > 1000) {
				TAnimApple[i].flg = false;
			}
		}
	}

}