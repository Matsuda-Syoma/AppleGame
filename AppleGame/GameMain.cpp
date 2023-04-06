#include "DxLib.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {

	//タイトルを設定
	SetMainWindowText("AppleGame");

	//ウィンドウモードで起動
	ChangeWindowMode(true);

	//DXライブラリの初期化処理
	if (DxLib_Init() == -1)return -1;

	//描画先画面を裏にする（ダブルバッファリング）
	SetDrawScreen(DX_SCREEN_BACK);

	//ゲームループ
	while (ProcessMessage() == 0) {

		//入力取得



		//画面の初期化
		ClearDrawScreen();

		//テスト表示
		DrawString(250, 200, "AppleGame", 0xffffff, 0x000000);

		//裏画面の内容を表に表示する
		ScreenFlip();
	}

	//DXライブラリの終了処理
	DxLib_End();

	return 0;

}