
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
	if ((gTitleBGM = LoadSoundMem("sounds/hinatabokko.wav")) == -1) return -1;
	//ステージBGMの読込
	if ((gStageBGM = LoadSoundMem("sounds/MusMus-BGM-087.wav")) == -1) return -1;
	//ゲームオーバーSEの読込
	if ((gGameOverSE = LoadSoundMem("sounds/MusMus-JGL-010b.wav")) == -1) return -1;
	//効果音１(メニューカーソル移動)の読込
	if ((gSEmenu1 = LoadSoundMem("sounds/cursor_idou.wav")) == -1) return -1;
	//効果音２(メニュー決定)の読込
	if ((gSEmenu2 = LoadSoundMem("sounds/kettei.wav")) == -1) return -1;
	//効果音りんご１(通常りんご)の読込
	if ((gSEapple1 = LoadSoundMem("sounds/ringo_get.wav")) == -1) return -1;
	//効果音りんご２(毒りんご)の読込
	if ((gSEapple2 = LoadSoundMem("sounds/dokuringo_get2.wav")) == -1) return -1;

	return 0;
}