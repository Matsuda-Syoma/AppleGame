#include "DxLib.h"
#include"prototype.h"
#include "variable.h"
#include "define.h"

extern mode gGameMode;

void DrawTitle(void) {

	static int menuNo = 0;

	//���j���[�J�[�\���ړ�����
	if (gKeyFlg & PAD_INPUT_DOWN) {
		if (++menuNo > 3)menuNo = 0;
	}
	if (gKeyFlg & PAD_INPUT_UP) {
		if (--menuNo < 0)menuNo = 3;
	}

	//Z�L�[�Ń��j���[�I��
	if (gKeyFlg & PAD_INPUT_A) {

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
	DrawRotaGraph(215, 257 + menuNo * 35, 0.5f, 0, gAppleImg[0], true);

}