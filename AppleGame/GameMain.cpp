#include "DxLib.h"
#include"prototype.h"
#include "variable.h"

extern int gStageImg;

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {

	//�^�C�g����ݒ�
	SetMainWindowText("AppleGame");

	//�E�B���h�E���[�h�ŋN��
	ChangeWindowMode(true);

	//DX���C�u�����̏���������
	if (DxLib_Init() == -1)return -1;

	//�`����ʂ𗠂ɂ���i�_�u���o�b�t�@�����O�j
	SetDrawScreen(DX_SCREEN_BACK);

	//�摜�ǂݍ��݊֐��̌Ăяo��
	if (LoadImages() == -1)return -1;

	//�Q�[�����[�v
	while (ProcessMessage() == 0) {

		//���͎擾

		//��ʂ̏�����
		ClearDrawScreen();

		DrawGraph(0, 0, gStageImg, false);

		AppleControl();

		DrawBox(500, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0x00ffff, true);
		for (int i = 0; i < 4; i++) {
			//DrawRotaGraph(230, 230, 0.3f, M_PI / 2, gApple[i], true, false);
			DrawFormatString(540, 200 + 40 * i, 0x000000, "%6d", gAppleCount[i]);
		}

		//����ʂ̓��e��\�ɕ\������
		ScreenFlip();
	}

	//DX���C�u�����̏I������
	DxLib_End();

	return 0;

}