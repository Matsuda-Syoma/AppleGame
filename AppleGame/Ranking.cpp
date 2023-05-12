#include<string.h>
#include "DxLib.h"
#include "prototype.h"
#include "variable.h"
#include "ranking.h"


RankingData gRanking[RANKING_DATA];

				  //12345678901234567890123456
char MoziSmall[] = "abcdefghijklmnopqrstuvwxyz";
char MoziBig[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char MoziNumber[] = "0123456789";

int MoziSelectW;
int MoziSelectH;
char MoziFrame[11];
char MoziWork[2];

void DrawRanking(void)
{
	// Aボタンでタイトルへ推移
	if (gKeyFlg & PAD_INPUT_A) {
		PlaySoundMem(gSEmenu2, DX_PLAYTYPE_BACK, true);
		StopSoundMem(gGameOverSE);
		gGameMode = TITLE;
	}

	//画像表示
	DrawGraph(0, 0, gRankingImg, FALSE);

	// ランキング一覧を表示
	SetFontSize(48);
	for (int i = 0; i < RANKING_DATA; i++) {
		DrawFormatString(240, 300 + i * 50, 0x000000,
			"%2d %-10s %10d",
			gRanking[i].no,
			gRanking[i].name,
			gRanking[i].score);
	}
}


void InputName(void)
{

	DrawGraph(0, 0, gStageImg, FALSE);

	SetFontSize(40);

	DrawString(150, 200, "ランキングに登録します", 0xffffff);

	for (int i = 0; i < sizeof(MoziSmall); i++) {
		DrawFormatString(150 + i * 40, 300, 0x000000, "%c", MoziSmall[i]);
	}
	for (int i = 0; i < sizeof(MoziBig); i++) {
		DrawFormatString(150 + i * 40, 350, 0x000000, "%c", MoziBig[i]);
	}
	for (int i = 0; i < sizeof(MoziNumber); i++) {
		DrawFormatString(150 + i * 40, 400, 0x000000, "%c", MoziNumber[i]);

	}

	DrawString(750, 555, "End", 0x000000);
	DrawBox(460, 535, 690, 600, 0x000055, TRUE);
	DrawFormatString(470, 545, 0xffffff, "%s", MoziFrame);

	//右
	if (gKeyFlg & PAD_INPUT_RIGHT) {
		if (++MoziSelectW > sizeof(MoziSmall) - 2) {
			MoziSelectW = 0;
		}
		if (MoziSelectH == 2 && MoziSelectW > sizeof(MoziNumber) - 2) {
			MoziSelectW = 0;
		}
	}
	//左
	if (gKeyFlg & PAD_INPUT_LEFT) {
		if (--MoziSelectW < 0) {
			MoziSelectW = sizeof(MoziSmall) - 2;
		}
		if (MoziSelectH == 2 && MoziSelectW > sizeof(MoziNumber) - 2) {
			MoziSelectW = sizeof(MoziNumber) - 2;
		}
	}
	//上
	if (gKeyFlg & PAD_INPUT_UP) {
		if (--MoziSelectH < 0) {
			MoziSelectH = 3;
		}
		if (MoziSelectH == 2 && MoziSelectW > sizeof(MoziNumber) - 2) {
			MoziSelectW = sizeof(MoziNumber) - 2;
		}
	}
	//下
	if (gKeyFlg & PAD_INPUT_DOWN) {
		if (++MoziSelectH > 3) {
			MoziSelectH = 0;
			}
		if (MoziSelectH == 2 && MoziSelectW > sizeof(MoziNumber) - 2) {
			MoziSelectW = sizeof(MoziNumber) - 2;
		}
	}

	switch (MoziSelectH)
	{
	case 3:
		DrawString(720, 555, ">", 0x000000);

		if (gKeyFlg & PAD_INPUT_A) {
			strcpy_s(gRanking[RANKING_DATA - 1].name , MoziFrame);
			PlaySoundMem(gSEmenu2, DX_PLAYTYPE_BACK, true);
			gRanking[RANKING_DATA - 1].score = gScore;	//ランキングデータにスコアを登録
			SortRanking();						//ランキング並べ替え
			SaveRanking();						//ランキングデータの保存
			gGameMode = RANKING;				//ゲームモードの変更
		}
		break;
	default:

		SetFontSize(32);
		DrawString(130 + MoziSelectW * 40, 305 + MoziSelectH * 50, ">", 0x000000);
		if (gKeyFlg & PAD_INPUT_A && strlen(MoziFrame) < 10) {
			if (MoziSelectH == 0) {
				strncpy_s(MoziWork, &MoziSmall[MoziSelectW], 1);
				strcat_s(MoziFrame, MoziWork);
			}
			if (MoziSelectH == 1) {
				strncpy_s(MoziWork, &MoziBig[MoziSelectW], 1);
				strcat_s(MoziFrame, MoziWork);
			}
			if (MoziSelectH == 2) {
				strncpy_s(MoziWork, &MoziNumber[MoziSelectW], 1);
				strcat_s(MoziFrame, MoziWork);
			}
		}
		break;
	}

	if (gKeyFlg & PAD_INPUT_B) {
		strncpy_s(MoziFrame, MoziFrame, strlen(MoziFrame) - 1);
	}

	//名前の入力
	//if (KeyInputSingleCharString(170, 350, 10, gRanking[RANKING_DATA - 1].name, FALSE)
	//	== 1) {

	//}
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