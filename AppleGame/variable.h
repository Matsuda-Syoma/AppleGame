#ifndef VARIABLE_H
#define VARIABLE_H

/*�񋓌^�̐錾*/
extern enum mode {
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
extern int gDrawScore;		//�X�R�A�\��
extern int gDrawGameTime;	//�Q�[�����ԕ\��
extern int gAppleCount[4];

extern int gAppleImg[4];
extern int gStageImg;


#endif