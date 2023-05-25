#include "DxLib.h"
#include"prototype.h"
#include "variable.h"
#include "define.h"

#include<stdio.h>
#include <stdlib.h>
#include <time.h>

mode gGameMode = TITLE;//title

int gOldKey;
int gNowKey;
int gKeyFlg;

extern int gPlayerImg[12];

int gAppleCount[4];

//�����I���p�ϐ�
int Back = 0;

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {

	/*LONGLONG nowTime = GetNowHiPerformanceCount();
	LONGLONG oldTime = nowTime;
	LONGLONG fpsCheckTime;
	int fpsCounter = 0;
	int fps = 0;*/

	//�^�C�g����ݒ�
	SetMainWindowText("AppleGame");

	//�E�B���h�E���[�h�ŋN��
	ChangeWindowMode(true);

	SetWaitVSyncFlag(FALSE);

	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32);
	SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);

	//DX���C�u�����̏���������
	if (DxLib_Init() == -1)return -1;

	//�`����ʂ𗠂ɂ���i�_�u���o�b�t�@�����O�j
	SetDrawScreen(DX_SCREEN_BACK);

	//�摜�ǂݍ��݊֐��̌Ăяo��
	if (LoadImages() == -1)return -1;
	if (LoadSound() == -1)return 0;

	//�����L���O�f�[�^�̓Ǎ�
	if (ReadRanking() == -1) return -1;

	srand((unsigned)time(NULL));

	/*//���[�v�O��FPS�v����������
	fpsCheckTime = GetNowHiPerformanceCount();
	fps = 0;
	fpsCounter = 0;*/

	//�Q�[�����[�v
	while (ProcessMessage() == 0 && gGameMode != CLOSE && Back!=1) {

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
			InputName();
			break;

		case GAMEOVER:
			DrawGameOver();
			break;

		case END:
			DrawEnd();
			break;
		}

		WaitTimer(16);

		/*SetFontSize(24);
		DrawFormatString(390, 5, 0xffffff, "FPS:%3d", fps);*/

		//����ʂ̓��e��\�ɕ\������
		ScreenFlip();

		/*//1���[�v���_�̃V�X�e�����Ԃ��擾
		oldTime = nowTime;
		nowTime = GetNowHiPerformanceCount();

		//1���[�v�̎��Ԍo�߂����߂�

		fpsCounter++;
		if (nowTime - fpsCheckTime > 1000000) {
			fps = fpsCounter;
			fpsCounter = 0;
			fpsCheckTime = nowTime;
		}*/

		//�����I
		if (gNowKey == PAD_INPUT_L) {
			Back = 1;
		}
	}

	//DX���C�u�����̏I������
	DxLib_End();

	return 0;

}