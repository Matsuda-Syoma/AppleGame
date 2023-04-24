#include "DxLib.h"
#include "apple.h"
#include "prototype.h"
#include "variable.h"
#include "Player.h"

#include<stdio.h>
#include <stdlib.h>
#include <time.h>

extern int gAppleImg[4];
extern struct PLAYER gPlayer;

struct APPLE gApple[APPLE_MAX];
struct APPLE gApple00 = { true,0,0,0,10,55,55,0,1 };
float gAppleSpeed[4] = { 1.0f,2.0f,3.5f,0.5f };
int gAppleScore[4] = { 100,200,500,-750 };

int AppleTime;		//りんごの生成タイミング

int rnd;


int Random(void);

void AppleControl(void) {

	for (int i = 0; i < APPLE_MAX; i++) {
		if (gApple[i].flg == true) {

			//敵の表示
			DrawRotaGraph(gApple[i].x, gApple[i].y, 1.0f, 0, gApple[i].img, true, false);

			if (gApple[i].flg == false) continue;

			//まっすぐ下に移動
			gApple[i].y += gApple[i].speed;

			//画面をはみ出したら消去
			if (gApple[i].y > 1000) {
				gApple[i].flg = false;
			}

			////当たり判定
			if (HitBoxPlayer(&gPlayer, &gApple[i]) == true &&gPlayer.flg==true) {
				if (gApple[i].type == 3) {
					PlaySoundMem(gSEapple2, DX_PLAYTYPE_BACK, true);
					gPlayer.flg = false;
				}
				else {
					PlaySoundMem(gSEapple1, DX_PLAYTYPE_BACK, true);
				}
				gAppleCount[gApple[i].type] ++;
				gScore += gAppleScore[gApple[i].type];
				gApple[i].flg = false;
				if (gScore < 0) {
					gScore = 0;
				}
			}


		}
	}
	if (++AppleTime > 25) {
		CreateApple();
		AppleTime = 0;
	}

}

int CreateApple(void) {

	for (int i = 0; i < APPLE_MAX; i++) {
		if (gApple[i].flg == false) {
			gApple[i] = gApple00;
			gApple[i].type = Random();
			gApple[i].img = gAppleImg[gApple[i].type];
			//gApple[i].img = gAppleImg;
			gApple[i].x = GetRand(6) * 70 + 40;//最大420 + 40
			gApple[i].speed = gAppleSpeed[gApple[i].type];
			gApple[i].score = gAppleScore[gApple[i].type];
			if (gApple[i].type == 3) {
				gApple[i].w = gApple[i].w * 0.9f;
				gApple[i].h = gApple[i].h * 0.9f;
			} else {
				gApple[i].w = gApple[i].w * 1.1f;
				gApple[i].h = gApple[i].h * 1.1f;
			}

			//成功
			return true;
		}
	}
	//失敗
	return false;
}

int Random(void) {

	rnd = rand() % 100;

	if (rnd < 60) {	//赤
		return 0;
	}else
	if (rnd < 85) {	//青
		return 1;
	}else
	if (rnd < 95) {	//金
		return 2;
	}else
	if (rnd < 100) {//毒
		return 3;
	}
	return -1;
}