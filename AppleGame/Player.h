#ifndef PLAYER_H
#define PLAYER_H
#define PI    3.1415926535897932384626433832795f

//�\����
struct PLAYER {
	int flg;
	float x=300.0f, y=448.0f;
	int w, h;
	int speed;
};
//�ϐ��錾
struct PLAYER gPlayer;

#endif