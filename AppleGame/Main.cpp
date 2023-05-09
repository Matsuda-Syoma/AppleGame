#include "DxLib.h"
#include"prototype.h"
#include "variable.h"
#include "define.h"

#include<stdio.h>
#include <stdlib.h>
#include <time.h>

mode gGameMode = TITLE;

extern int gStageImg;
extern int gAppleImg[4];

int gOldKey;
int gNowKey;
int gKeyFlg;

extern int gPlayerImg[12];

int gAppleCount[4];

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {

	//�^�C�g����ݒ�
	SetMainWindowText("AppleGame");

	//�E�B���h�E���[�h�ŋN��
	ChangeWindowMode(true);

	SetWaitVSyncFlag(FALSE);

	SetWindowSize(1280, 720);

	//DX���C�u�����̏���������
	if (DxLib_Init() == -1)return -1;

	//�`����ʂ𗠂ɂ���i�_�u���o�b�t�@�����O�j
	SetDrawScreen(DX_SCREEN_BACK);

	//�摜�ǂݍ��݊֐��̌Ăяo��
	if (LoadImages() == -1)return -1;
	//if (LoadSound() == -1)return -1;

	srand((unsigned)time(NULL));

	//�Q�[�����[�v
	while (ProcessMessage() == 0) {

		//���͎擾

		gOldKey = gNowKey;
		gNowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		gKeyFlg = gNowKey & ~gOldKey;

		//��ʂ̏�����
		ClearDrawScreen();

		switch (gGameMode) {

		case TITLE:
			DrawTitle();
			break;

		case INIT:
			GameInit();
			break;

		case MAIN:
			DrawGame();
			break;

		case RANKING:
			DrawRanking();
			break;

		case HELP:
			DrawHelp();
			break;

		case INPUTNAME:
			
			break;

		case GAMEOVER:
			DrawGameOver();
			break;

		case END:
			
			break;

		}

		WaitTimer(16);

		//����ʂ̓��e��\�ɕ\������
		ScreenFlip();
	}

	//DX���C�u�����̏I������
	DxLib_End();

	return 0;

}