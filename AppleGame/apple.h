#ifndef APPLE_H
#define APPLE_H

#define APPLE_MAX 10

//�����S�̍\����

struct APPLE {
	int flg;		//�g�p�t���O
	int type;		//�^�C�v
	int img;		//�摜
	int x, y, w, h;	//���W�A���A����
	int speed;		//�ړ����x
	int score;		//�X�R�A
};

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

#endif