#ifndef PLAYER_H
#define PLAYER_H
#define PI    3.1415926535897932384626433832795f

//�\����
struct PLAYER {
	int flg;
	int x=300, y=480-32;
	int w, h;
	int speed;
};
//�ϐ��錾
struct PLAYER gPlayer;

#endif