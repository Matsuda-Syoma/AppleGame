#pragma once

#include "define.h"
/*�񋓌^�̐錾*/
enum mode {
	TITLE,
	INIT,
	MAIN,
	RANKING,
	HELP,
	INPUTNAME,
	GAMEOVER,
	END,
	CLOSE,
};

//�����S�̍\����

struct APPLE {
	int flg;		//�g�p�t���O
	int type;		//�^�C�v
	int img;		//�摜
	float x, y, w, h;	//���W�A���A����
	float speed;		//�ړ����x
	int score;		//�X�R�A
};


extern mode gGameMode;

extern struct PLAYER gPlayer;
extern struct APPLE gApple[APPLE_MAX];
extern struct RankingData gRanking[RANKING_DATA];

extern int gScore;		//�X�R�A
extern int gGameTime;	//�Q�[�����ԕ\��
extern int gAppleCount[4];
extern int gAppleScore[4];

extern int gTitleImg; //�^�C�g����
extern int gAppleImg[4];
extern int gStageImg;
extern int gHelpImg;
extern int gRankingImg;
extern int gEndImg;

extern int gOldKey;		//�O��̓��̓L�[
extern int gNowKey;		//����̓��̓L�[
extern int gKeyFlg;		//���̓L�[���

extern 	int CoolTime;
extern int OldAppleSpawn;
extern int NewAppleSpawn;

extern int gTitleBGM;				//�^�C�g��BGM
extern int gStageBGM;				//�X�e�[�WBGM
extern int gGameOverSE;			//�Q�[���I�[�o�[SE
extern int gSEmenu1[4];				//���ʉ�1(���j���[�J�[�\���ړ�)
extern int gSEmenu2;				//���ʉ�2(���j���[����)
extern int gSEapple1;				//���ʉ����1(�ʏ���)
extern int gSEapple2;				//���ʉ����2(�ł��)

extern int rnd;

extern char MoziFrame[11];
extern int RWaitTime;