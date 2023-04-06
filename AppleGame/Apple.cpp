#include "DxLib.h"

//リンゴの構造体

struct APPLE {
	int flg;		//使用フラグ
	int type;		//タイプ
	int img;		//画像
	int x, y, w, h;	//座標、幅、高さ
	int speed;		//移動速度
	int score;		//スコア
};

struct APPLE gApple00 = { true,0,0,0,10,63,63,0,1 };