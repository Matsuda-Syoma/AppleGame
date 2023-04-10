#include "DxLib.h"
#include"prototype.h"
#include "variable.h"

extern int gStageImg;

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {

	//タイトルを設定
	SetMainWindowText("AppleGame");

	//ウィンドウモードで起動
	ChangeWindowMode(true);

	//DXライブラリの初期化処理
	if (DxLib_Init() == -1)return -1;

	//描画先画面を裏にする（ダブルバッファリング）
	SetDrawScreen(DX_SCREEN_BACK);

	//画像読み込み関数の呼び出し
	if (LoadImages() == -1)return -1;

	//ゲームループ
	while (ProcessMessage() == 0) {

		//入力取得

		//画面の初期化
		ClearDrawScreen();

		DrawGraph(0, 0, gStageImg, false);

		AppleControl();

		DrawBox(500, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0x00ffff, true);
		for (int i = 0; i < 4; i++) {
			//DrawRotaGraph(230, 230, 0.3f, M_PI / 2, gApple[i], true, false);
			DrawFormatString(540, 200 + 40 * i, 0x000000, "%6d", gAppleCount[i]);
		}

		//裏画面の内容を表に表示する
		ScreenFlip();
	}

	//DXライブラリの終了処理
	DxLib_End();

	return 0;

}