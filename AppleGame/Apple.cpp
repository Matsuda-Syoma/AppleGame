#include "DxLib.h"

//�����S�̍\����

struct APPLE {
	int flg;		//�g�p�t���O
	int type;		//�^�C�v
	int img;		//�摜
	int x, y, w, h;	//���W�A���A����
	int speed;		//�ړ����x
	int score;		//�X�R�A
};

struct APPLE gApple00 = { true,0,0,0,10,63,63,0,1 };