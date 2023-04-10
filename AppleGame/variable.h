#ifndef VARIABLE_H
#define VARIABLE_H

/*列挙型の宣言*/
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

extern int gScore;		//スコア
extern int gDrawScore;		//スコア表示
extern int gDrawGameTime;	//ゲーム時間表示
extern int gAppleCount[4];

extern int gAppleImg[4];
extern int gStageImg;


#endif