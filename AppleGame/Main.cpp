#include "DxLib.h"
#include"prototype.h"
#include "variable.h"
#include "define.h"

mode gGameMode = INIT;

extern int gStageImg;
extern int gAppleImg[4];
extern int gPlayerImg[12];

int gAppleCount[4];

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

		switch (gGameMode) {

		case TITLE:

			break;

		case INIT:
			GameInit();
			break;

		case MAIN:
			DrawGame();
			break;

		case RANKING:
			
			break;

		case HELP:
			
			break;

		case INPUTNAME:
			
			break;

		case GAMEOVER:
			
			break;

		case END:
			
			break;

		}

		//����ʂ̓��e��\�ɕ\������
		ScreenFlip();
	}

	//DX���C�u�����̏I������
	DxLib_End();

	return 0;

}