#ifndef APPLE_H
#define APPLE_H

#define APPLE_MAX 10

//リンゴの構造体

struct APPLE {
	int flg;		//使用フラグ
	int type;		//タイプ
	int img;		//画像
	int x, y, w, h;	//座標、幅、高さ
	int speed;		//移動速度
	int score;		//スコア
};

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

#endif