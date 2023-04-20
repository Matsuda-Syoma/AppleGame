#include "prototype.h"
#include "variable.h"
#include "DxLib.h"


int LoadSound(void)
{
	//�^�C�g��BGM�̓Ǎ�
	if ((gTitleBGM = LoadSoundMem("sounds/hinatabokko.wav")) == -1) return -1;
	//�X�e�[�WBGM�̓Ǎ�
	if ((gStageBGM = LoadSoundMem("sounds/MusMus-BGM-087.wav")) == -1) return -1;
	//�Q�[���I�[�o�[SE�̓Ǎ�
	if ((gGameOverSE = LoadSoundMem("sounds/MusMus-JGL-010b.wav")) == -1) return -1;
	//���ʉ��P(���j���[�J�[�\���ړ�)�̓Ǎ�
	if ((gSEmenu1 = LoadSoundMem("sounds/cursor_idou.wav")) == -1) return -1;
	//���ʉ��Q(���j���[����)�̓Ǎ�
	if ((gSEmenu2 = LoadSoundMem("sounds/kettei.wav")) == -1) return -1;
	//���ʉ���񂲂P(�ʏ���)�̓Ǎ�
	if ((gSEapple1 = LoadSoundMem("sounds/ringo_get.wav")) == -1) return -1;
	//���ʉ���񂲂Q(�ł��)�̓Ǎ�
	if ((gSEapple2 = LoadSoundMem("sounds/dokuringo_get2.wav")) == -1) return -1;

	return 0;
}