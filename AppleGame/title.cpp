#include "DxLib.h"
#include"prototype.h"
#include "variable.h"
#include "define.h"
#include "title.h"

extern mode gGameMode;

void DrawTitle(void) {

	static int menuNo = 0;
	//�^�C�g��BGM�Đ�
	PlaySoundMem(gTitleBGM, DX_PLAYTYPE_LOOP, false);

	//���j���[�J�[�\���ړ�����
	if (gKeyFlg & PAD_INPUT_DOWN) {
		PlaySoundMem(gSEmenu1, DX_PLAYTYPE_BACK, true);
		if (++menuNo > 3)menuNo = 0;
	}
	if (gKeyFlg & PAD_INPUT_UP) {
		PlaySoundMem(gSEmenu1, DX_PLAYTYPE_BACK, true);
		if (--menuNo < 0)menuNo = 3;
	}

	//Z�L�[�Ń��j���[�I��
	if (gKeyFlg & PAD_INPUT_A) {

		StopSoundMem(gTitleBGM);
		PlaySoundMem(gSEmenu2, DX_PLAYTYPE_BACK, true);

		switch (menuNo) {

		case 0:
			gGameMode = INIT;
			break;
		case 1:
			gGameMode = RANKING;
			break;
		case 2:
			gGameMode = HELP;
			break;
		case 3:
			gGameMode = END;
			break;
		}
	}

	//�^�C�g���A���j���[�A�J�[�\���摜�̕\��
	DrawGraph(0, 0, gTitleImg, false);
	DrawRotaGraph((225 * 2), 385 + menuNo * 70, 1.0f, 0, gAppleImg[0], true);

	for (int i = 0; i < 2; i++) {
		if (TAnimApple[i].flg == false || gGameMode != TITLE) {
			TAnimApple[i] = TAnim00;
			TAnimApple[i].x = ++Spawn % 2 * 800 + 240;
			TAnimApple[i].speed = GetRand(5.0f) + 2;

		}
		else {
			DrawRotaGraph(TAnimApple[i].x, TAnimApple[i].y, 0.5f, 0, gAppleImg[0], true, false);
			TAnimApple[i].y += TAnimApple[i].speed;
			if (TAnimApple[i].y > 1000) {
				TAnimApple[i].flg = false;
			}
		}
	}

}