#ifndef VARIABLE_H
#define VARIABLE_H

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
	CLOSE
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

//�v���C���[�̍\����

struct PLAYER {
	int flg;		//�g�p�t���O
	int type;		//���
	int img;		//�摜
	float x, y, w, h;	//���W�A���A����
	float speed;		//�ړ����x
};

extern int gScore;		//�X�R�A
extern int gGameTime;	//�Q�[�����ԕ\��
extern int gAppleCount[4];

extern int gAppleImg[4];
extern int gStageImg;

extern int gOldKey;		//�O��̓��̓L�[
extern int gNowKey;		//����̓��̓L�[
extern int gKeyFlg;		//���̓L�[���

#endif