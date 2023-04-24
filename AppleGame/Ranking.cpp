#include "DxLib.h"
#include "prototype.h"
#include "variable.h"
#include "ranking.h"
extern mode gGameMode;

void DrawRanking(void)
{
	// Aボタンでタイトルへ推移
	if (gKeyFlg & PAD_INPUT_A) gGameMode = TITLE;

	DrawGraph(0, 0, gTitleImg, FALSE);

	// ランキング一覧を表示
	SetFontSize(18);
		for (int i = 0; i < RANKING_DATA; i++) {
			
	}

}