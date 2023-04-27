#include "DxLib.h"
#include "prototype.h"
#include "variable.h"
#include "ranking.h"
extern mode gGameMode;

/************************************
*　ランキング画面
*************************************/
void DrawRanking(void)
{
	// Aボタンでタイトルへ推移
	if (gKeyFlg & PAD_INPUT_A) gGameMode = TITLE;

	//画像表示
	DrawGraph(0, 0, gStageImg, FALSE);

	DrawString(250,200,"---テスト表示---",0xff0000,0);

	// ランキング一覧を表示
	//SetFontSize(18);
	//for (int i = 0; i < RANKING_DATA; i++) {
	//	DrawFormatString(50, 170 + i * 25, 0xffffff,
	//		"%2d %-10s %10d",
	//		gRanking[i].no,
	//		gRanking[i].name,
	//		gRanking[i].score);
	//}

	DrawString(160, 450, "--- Aボタンを押してタイトルに戻る ---", 0xff0000, 0);
}

/************************************
*　ランキング入力処理
*************************************/
void InputName(void)
{
	DrawGraph(0, 0, gTitleImg, FALSE);

	SetFontSize(20);

	DrawString(150, 240, "ランキングに登録します", 0xffffff);
	DrawString(150, 270, "名前を英字で入力してください", 0xffffff);

	//名前の入力
	DrawString(150, 310, "> ", 0xFFFFFF);
	DrawBox(160, 395, 300, 335, 0x000055, TRUE);
	if (KeyInputSingleCharString(170, 310, 10, gRanking[RANKING_DATA - 1].name, FALSE)
		== 1) {
		gRanking[RANKING_DATA - 1].score = gScore;	//ランキングデータにスコアを登録
		//SortRanking();						//ランキング並べ替え
		//SaveRanking();						//ランキングデータの保存
		gGameMode = RANKING;				//ゲームモードの変更
	}
}

/***********************************************
 * ランキング並べ替え
 ***********************************************/
void SortRanking(void)
{
	int i, j;
	RankingData work;

	// 選択法ソート
	for (i = 0; i < RANKING_DATA - 1; i++) {
		for (j = i + 1; j < RANKING_DATA; j++) {
			if (gRanking[i].score <= gRanking[j].score) {
				work = gRanking[i];
				gRanking[i] = gRanking[j];
				gRanking[j] = work;
			}
		}
	}

	// 順位付け
	for (i = 0; i < RANKING_DATA; i++) {
		gRanking[i].no = 1;
	}
	// 得点が同じ場合は、同じ順位とする
	// 同順位があった場合の次の順位はデータ個数が加算された順位とする
	for (i = 0; i < RANKING_DATA - 1; i++) {
		for (j = i + 1; j < RANKING_DATA; j++) {
			if (gRanking[i].score > gRanking[j].score) {
				gRanking[j].no++;
			}
		}
	}
}
