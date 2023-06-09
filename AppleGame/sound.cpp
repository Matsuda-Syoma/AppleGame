#include "prototype.h"
#include "variable.h"
#include "DxLib.h"

int gTitleBGM;				//タイトルBGM
int gStageBGM;				//ステージBGM
int gGameOverSE;			//ゲームオーバーSE
int gSEmenu1[4];			//効果音1(メニューカーソル移動)
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
	for(int i = 0;i < 4;i++){
		SetCreateSoundPitchRate(100.0f * i);
		gSEmenu1[i] = LoadSoundMem("sounds/cursor_idou.wav");
	}
	SetCreateSoundPitchRate(0.0f);
	//効果音２(メニュー決定)の読込
	if ((gSEmenu2 = LoadSoundMem("sounds/kettei.wav")) == -1) return -1;
	//効果音りんご１(通常りんご)の読込
	if ((gSEapple1 = LoadSoundMem("sounds/ringo_get.wav")) == -1) return -1;
	//効果音りんご２(毒りんご)の読込
	if ((gSEapple2 = LoadSoundMem("sounds/dokuringo_get2.wav")) == -1) return -1;

	ChangeVolumeSoundMem(MUSIC_VOLUME,gTitleBGM);
	ChangeVolumeSoundMem(MUSIC_VOLUME, gStageBGM);
	ChangeVolumeSoundMem(MUSIC_VOLUME, gGameOverSE);
	for (int i = 0; i < 4; i++) {
		ChangeVolumeSoundMem(SOUND_VOLUME, gSEmenu1[i]);
	}
	ChangeVolumeSoundMem(SOUND_VOLUME, gSEmenu2);
	ChangeVolumeSoundMem(SOUND_VOLUME, gSEapple1);
	ChangeVolumeSoundMem(SOUND_VOLUME, gSEapple2);

	return 0;
}