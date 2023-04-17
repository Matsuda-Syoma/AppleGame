
#include "DxLib.h"

//�@�T�E���h�p�ϐ�
int gTitleBGM;				//�^�C�g��BGM
int gStageBGM;				//�X�e�[�WBGM
int gGameOverSE;			//�Q�[���I�[�o�[SE
int gSEmenu1;				//���ʉ�1(���j���[�J�[�\���ړ�)
int gSEmenu2;				//���ʉ�2(���j���[����)
int gSEapple1;				//���ʉ����1(�ʏ���)
int gSEapple2;				//���ʉ����2(�ł��)


int LoadSound(void) 
{
	//�^�C�g��BGM�̓Ǎ�
	if ((gTitleBGM = LoadSoundMem("")) == -1) return -1;
	//�X�e�[�WBGM�̓Ǎ�
	if ((gStageBGM = LoadSoundMem("")) == -1) return -1;
	//�Q�[���I�[�o�[SE�̓Ǎ�
	if ((gGameOverSE = LoadSoundMem("")) == -1) return -1;
	//���ʉ��P�̓Ǎ�
	if ((gSEmenu1 = LoadSoundMem("")) == -1) return -1;
	//���ʉ��Q�̓Ǎ�
	if ((gSEmenu2 = LoadSoundMem("")) == -1) return -1;
	//���ʉ���񂲂P�̓Ǎ�
	if ((gSEapple1 = LoadSoundMem("")) == -1) return -1;
	//���ʉ���񂲂Q�̓Ǎ�
	if ((gSEapple2 = LoadSoundMem("")) == -1) return -1;

	return 0;
}