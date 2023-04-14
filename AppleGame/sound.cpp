
#include "DxLib.h"

//　サウンド用変数
int gTitleBGM;				//タイトルBGM
int gStageBGM;				//ステージBGM
int gGameOverSE;			//ゲームオーバーSE
int gSEmenu1;				//効果音1(メニューカーソル移動)
int gSEmenu2;				//効果音2(メニュー決定)
int gSEapple1;				//効果音りんご1(通常りんご)
int gSEapple2;				//効果音りんご2(毒りんご)


int LoadSound(void) 
{
	//タイトルBGMの読込
	if ((gTitleBGM = LoadSoundMem("")) == -1) return -1;
	//ステージBGMの読込
	if ((gStageBGM = LoadSoundMem("")) == -1) return -1;
	//ゲームオーバーSEの読込
	if ((gGameOverSE = LoadSoundMem("")) == -1) return -1;
	//効果音１の読込
	if ((gSEmenu1 = LoadSoundMem("")) == -1) return -1;
	//効果音２の読込
	if ((gSEmenu2 = LoadSoundMem("")) == -1) return -1;
	//効果音りんご１の読込
	if ((gSEapple1 = LoadSoundMem("")) == -1) return -1;
	//効果音りんご２の読込
	if ((gSEapple2 = LoadSoundMem("")) == -1) return -1;

	return 0;
}