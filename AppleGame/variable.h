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

extern int gScore;		//�X�R�A
extern int gGameTime;	//�Q�[�����ԕ\��
extern int gAppleCount[4];

extern int gAppleImg[4];
extern int gStageImg;


#endif