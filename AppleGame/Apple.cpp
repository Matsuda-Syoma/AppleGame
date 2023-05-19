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

			//‚è‚ñ‚²‚Ì•\Ž¦
			DrawRotaGraph(gApple[i].x, gApple[i].y, 0.5f, 0, gApple[i].img, true, false);

			if (gApple[i].flg == false) continue;

			//‚Ü‚Á‚·‚®‰º‚ÉˆÚ“®
			gApple[i].y += gApple[i].speed;

			//‰æ–Ê‚ð‚Í‚Ýo‚µ‚½‚çÁ‹Ž
			if (gApple[i].y > 1000) {
				ALane.type[gApple[i].lane][gApple[i].type] = 0;
				gApple[i].flg = false;
			}

			////“–‚½‚è”»’è
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
				ALane.type[gApple[i].lane][gApple[i].type] = 0;
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

	NewAppleSpawn = GetRand(6);

	for (int i = 0; i < APPLE_MAX; i++) {
		if (gApple[i].flg == false) {
			gApple[i] = gApple00;
			gApple[i].type = Random();
			rndap = gApple[i].type;
			if (ALane.type[NewAppleSpawn][gApple[i].type] == 1) {
				gApple[i].flg = false;
				break;
				return false;
			}

			gApple[i].img = gAppleImg[gApple[i].type];
			gApple[i].x = NewAppleSpawn * 140 + 80;
			gApple[i].speed = gAppleSpeed[gApple[i].type];
			gApple[i].score = gAppleScore[gApple[i].type];
			gApple[i].lane = NewAppleSpawn;
			ALane.type[NewAppleSpawn][gApple[i].type] = 1;
			//“Å‚è‚ñ‚²‚ÌŽž‚Í”»’è‚ð0.9”{‚É‚·‚é
			if (gApple[i].type == 3) {
				gApple[i].w = gApple[i].w * 0.9f;
				gApple[i].h = gApple[i].h * 0.9f;
			} else {
				gApple[i].w = gApple[i].w * 1.1f;
				gApple[i].h = gApple[i].h * 1.1f;
			}

			//¬Œ÷
			return true;
		}
	}
	//Ž¸”s
	return false;
}

int Random(void) {

	rnd = rand() % 100;
	if (rnd < 60) {	//Ô
		return 0;
	}else
	if (rnd < 85) {	//Â
		return 1;
	}else
	if (rnd < 95) {	//‹à
		return 2;
	}else
	if (rnd < 100) {//“Å
		return 3;
	}
	return -1;
}