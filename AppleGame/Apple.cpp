#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include "DxLib.h"
#include "prototype.h"
#include "variable.h"
#include "define.h"
#include "apple.h"
#include "player.h"


void AppleControl(void) {

	for (int i = 0; i < APPLE_MAX; i++) {
		if (gApple[i].flg == true) {

			//りんごの表示
			DrawRotaGraph(gApple[i].x, gApple[i].y, 2.0f, 0, gApple[i].img, true, false);

			if (gApple[i].flg == false) continue;

			//まっすぐ下に移動
			gApple[i].y += gApple[i].speed;

			//画面をはみ出したら消去
			if (gApple[i].y > 1000) {
				gApple[i].flg = false;
			}

			////当たり判定
			if (HitBoxPlayer(&gPlayer, &gApple[i]) == true &&gPlayer.flg == true) {
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

		NewAppleSpawn = GetRand(6);

		if (OldAppleSpawn != NewAppleSpawn) {

			CreateApple();
			OldAppleSpawn = NewAppleSpawn;

		}
			AppleTime = 0;
	}
}

int CreateApple(void) {

	for (int i = 0; i < APPLE_MAX; i++) {
		if (gApple[i].flg == false) {
			gApple[i] = gApple00;
			gApple[i].type = Random();
			gApple[i].img = gAppleImg[gApple[i].type];
			gApple[i].x = NewAppleSpawn * 140 + 80;
			gApple[i].speed = gAppleSpeed[gApple[i].type];
			gApple[i].score = gAppleScore[gApple[i].type];
			//毒りんごの時は判定を0.9倍にする
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