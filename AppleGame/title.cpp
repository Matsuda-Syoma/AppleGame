//#include "DxLib.h"
//#include"prototype.h"
//#include "variable.h"
//#include "define.h"
//
//extern int gTitleImg; //タイトル画像
//
//extern mode gGameMode;
//
//void DrawTitle(void) {
//
//	static int menuNo = 0;
//
//	//メニューカーソル移動処理
//	if (gKeyFlg & PAD_INPUT_DOWN) {
//		if (++menuNo > 3)menuNo = 0;
//	}
//	if (gKeyFlg & PAD_INPUT_UP) {
//		if (--menuNo < 0)menuNo = 3;
//	}
//
//	//Zキーでメニュー選択
//	if (gKeyFlg & PAD_INPUT_A) {
//
//		switch (menuNo) {
//
//		case 0:
//			gGameMode = INIT;
//			break;
//		case 1:
//			gGameMode = RANKING;
//			break;
//		case 2:
//			gGameMode = HELP;
//			break;
//		case 3:
//			gGameMode = END;
//			break;
//		}
//	}
//
//	//タイトル、メニュー、カーソル画像の表示
//	DrawGraph(0, 0, gTitleImg, false);
//	DrawRotaGraph(90, 220 + menuNo * 40, 0.7f, 0, gAppleImg[0], true);
//
//}