#include "DxLib.h"
#include"prototype.h"
#include "variable.h"
#include "define.h"

#include<stdio.h>
#include <stdlib.h>
#include <time.h>

mode gGameMode = TITLE;//title

int gOldKey;
int gNowKey;
int gKeyFlg;

extern int gPlayerImg[12];

int gAppleCount[4];

//強制終了用変数
int Back = 0;

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {

	/*LONGLONG nowTime = GetNowHiPerformanceCount();
	LONGLONG oldTime = nowTime;
	LONGLONG fpsCheckTime;
	int fpsCounter = 0;
	int fps = 0;*/

	//タイトルを設定
	SetMainWindowText("AppleGame");

	//ウィンドウモードで起動
	ChangeWindowMode(true);

	SetWaitVSyncFlag(FALSE);

	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32);
	SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);

	//DXライブラリの初期化処理
	if (DxLib_Init() == -1)return -1;

	//描画先画面を裏にする（ダブルバッファリング）
	SetDrawScreen(DX_SCREEN_BACK);

	//画像読み込み関数の呼び出し
	if (LoadImages() == -1)return -1;
	if (LoadSound() == -1)return 0;

	//ランキングデータの読込
	if (ReadRanking() == -1) return -1;

	srand((unsigned)time(NULL));

	/*//ループ前にFPS計測を初期化
	fpsCheckTime = GetNowHiPerformanceCount();
	fps = 0;
	fpsCounter = 0;*/

	//ゲームループ
	while (ProcessMessage() == 0 && gGameMode != CLOSE && Back!=1) {

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
			InputName();
			break;

		case GAMEOVER:
			DrawGameOver();
			break;

		case END:
			DrawEnd();
			break;
		}

		WaitTimer(16);

		/*SetFontSize(24);
		DrawFormatString(390, 5, 0xffffff, "FPS:%3d", fps);*/

		//裏画面の内容を表に表示する
		ScreenFlip();

		/*//1ループ時点のシステム時間を取得
		oldTime = nowTime;
		nowTime = GetNowHiPerformanceCount();

		//1ループの時間経過を求める

		fpsCounter++;
		if (nowTime - fpsCheckTime > 1000000) {
			fps = fpsCounter;
			fpsCounter = 0;
			fpsCheckTime = nowTime;
		}*/

		//強制終
		if (gNowKey == PAD_INPUT_L) {
			Back = 1;
		}
	}

	//DXライブラリの終了処理
	DxLib_End();

	return 0;

}