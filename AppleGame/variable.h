#ifndef VARIABLE_H
#define VARIABLE_H

/*列挙型の宣言*/
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

//リンゴの構造体

struct APPLE {
	int flg;		//使用フラグ
	int type;		//タイプ
	int img;		//画像
	float x, y, w, h;	//座標、幅、高さ
	float speed;		//移動速度
	int score;		//スコア
};

//プレイヤーの構造体

//struct PLAYER {
//	int flg;		//使用フラグ
//	int type;		//状態
//	int img;		//画像
//	float x, y, w, h;	//座標、幅、高さ
//	float speed;		//移動速度
//};

extern int gScore;		//スコア
extern int gGameTime;	//ゲーム時間表示
extern int gAppleCount[4];

extern int gAppleImg[4];
extern int gStageImg;

extern int gOldKey;		//前回の入力キー
extern int gNowKey;		//今回の入力キー
extern int gKeyFlg;		//入力キー情報

extern int gTitleBGM;				//タイトルBGM
extern int gStageBGM;				//ステージBGM
extern int gGameOverSE;			//ゲームオーバーSE
extern int gSEmenu1;				//効果音1(メニューカーソル移動)
extern int gSEmenu2;				//効果音2(メニュー決定)
extern int gSEapple1;				//効果音りんご1(通常りんご)
extern int gSEapple2;				//効果音りんご2(毒りんご)
#endif