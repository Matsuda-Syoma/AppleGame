#include "DxLib.h"
#include"prototype.h"
#include "variable.h"
#include "define.h"

#include<stdio.h>
#include <stdlib.h>
#include <time.h>

mode gGameMode = TITLE;

extern int gStageImg;
extern int gAppleImg[4];

int gOldKey;
int gNowKey;
int gKeyFlg;

extern int gPlayerImg[12];

int gAppleCount[4];

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {

	//タイトルを設定
	SetMainWindowText("AppleGame");

	//ウィンドウモードで起動
	ChangeWindowMode(true);

	SetWaitVSyncFlag(FALSE);

	SetWindowSize(1280, 720);

	//DXライブラリの初期化処理
	if (DxLib_Init() == -1)return -1;

	//描画先画面を裏にする（ダブルバッファリング）
	SetDrawScreen(DX_SCREEN_BACK);

	//画像読み込み関数の呼び出し
	if (LoadImages() == -1)return -1;
	//if (LoadSound() == -1)return -1;

	srand((unsigned)time(NULL));

	//ゲームループ
	while (ProcessMessage() == 0) {

		//入力取得

		gOldKey = gNowKey;
		gNowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		gKeyFlg = gNowKey & ~gOldKey;

		//画面の初期化
		ClearDrawScreen();

		switch (gGameMode) {

		case TITLE:
			DrawTitle();
			break;

		case INIT:
			GameInit();
			break;

		case MAIN:
			DrawGame();
			break;

		case RANKING:
			DrawRanking();
			break;

		case HELP:
			DrawHelp();
			break;

		case INPUTNAME:
			
			break;

		case GAMEOVER:
			DrawGameOver();
			break;

		case END:
			
			break;

		}

		WaitTimer(16);

		//裏画面の内容を表に表示する
		ScreenFlip();
	}

	//DXライブラリの終了処理
	DxLib_End();

	return 0;

}