#ifndef PLAYER_H
#define PLAYER_H
#define PI    3.1415926535897932384626433832795f

//構造体
struct PLAYER {
	int flg;
	int x=300, y=480-32;
	int w, h;
	int speed;
};
//変数宣言
struct PLAYER gPlayer;

#endif