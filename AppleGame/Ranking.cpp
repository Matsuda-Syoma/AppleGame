#include "DxLib.h"
#include "prototype.h"
#include "variable.h"
#include "ranking.h"
extern mode gGameMode;


void DrawRanking(void)
{
	// Aボタンでタイトルへ推移
	if (gKeyFlg & PAD_INPUT_A) gGameMode = TITLE;

	//画像表示
	DrawGraph(0, 0, gRankingImg, FALSE);

	// ランキング一覧を表示
	SetFontSize(36);
	for (int i = 0; i < RANKING_DATA; i++) {
		DrawFormatString(80, 140 + i * 40, 0x000000,
			"%2d %-10s %10d",
			gRanking[i].no,
			gRanking[i].name,
			gRanking[i].score);
	}
}


void InputName(void)
{
	DrawGraph(0, 0, gStageImg, FALSE);

	SetFontSize(20);

	DrawString(150, 200, "ランキングに登録します", 0xffffff);
	DrawString(150, 230, "名前を英字で入力してください", 0xffffff);

	//名前の入力
	DrawString(150, 310, "> ", 0xFFFFFF);
	DrawBox(160, 335, 295, 305, 0x000055, TRUE);
	if (KeyInputSingleCharString(170, 310, 10, gRanking[RANKING_DATA - 1].name, FALSE)
		== 1) {
		gRanking[RANKING_DATA - 1].score = gScore;	//ランキングデータにスコアを登録
		SortRanking();						//ランキング並べ替え
		SaveRanking();						//ランキングデータの保存
		gGameMode = RANKING;				//ゲームモードの変更
	}
}


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

int  SaveRanking(void)
{
	FILE* fp;
#pragma warning(disable:4996)

	// ファイルオープン
	if ((fp = fopen("data/rankingdata.txt", "w")) == NULL) {
		/* エラー処理 */
		printf("Ranking Data Error\n");
		return -1;
	}

	// ランキングデータ分配列データを書き込む
	for (int i = 0; i < RANKING_DATA; i++) {
		fprintf(fp, "%2d %10s %10d\n", gRanking[i].no, gRanking[i].name, gRanking[i].score);
	}

	//ファイルクローズ
	fclose(fp);
	return 0;

}

int ReadRanking(void)
{
	FILE* fp;
#pragma warning(disable:4996)

	//ファイルオープン
	if ((fp = fopen("data/rankingdata.txt", "r")) == NULL) {
		//エラー処理
		printf("Ranking Data Error\n");
		return -1;
	}

	//ランキングデータ配分列データを読み込む
	for (int i = 0; i < RANKING_DATA; i++) {
		int dammy = fscanf(fp, "%2d %10s %10d", &gRanking[i].no, gRanking[i].name, &gRanking[i].score);
	}

	//ファイルクローズ
	fclose(fp);

	return 0;
}