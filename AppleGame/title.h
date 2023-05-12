#pragma once

struct TitleAnim {
	int flg;
	float x, y;
	float speed;
};
struct TitleAnim TAnim00 = { true,0,0,0};
TitleAnim TAnimApple[12];
int Spawn = 0;