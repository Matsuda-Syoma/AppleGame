#ifndef PLAYER_H
#define PLAYER_H

//プレイヤーの構造体

struct PLAYER {
	int flg;		//使用フラグ
	int type;		//状態
	int img;		//画像
	float x, y, w, h;	//座標、幅、高さ
	float speed;		//移動速度
};


#endif