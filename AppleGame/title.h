#ifndef TITLE_H
#define TITLE_H

struct TitleAnim {
	int flg;
	float x, y;
	float speed;
};
struct TitleAnim TAnim00 = { true,0,0,0};
TitleAnim TAnimApple[2];

#endif