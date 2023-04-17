#include "DxLib.h"
#include "player.h"
#include "prototype.h"
#include "variable.h"

extern int gOldKey;
extern int gNowKey;
extern int gKeyFlg;

struct PLAYER gPlayer;

void PlayerControl(void) {

	//ç∂âEÇÃà⁄ìÆ
	if (gPlayer.flg == true) {

		gPlayer.x += gPlayer.speed;

		if (gNowKey & PAD_INPUT_RIGHT && gPlayer.speed < 1.0f){

			gPlayer.speed += 0.01f;

		}
		else if(gPlayer.speed > 0.01f) {
			gPlayer.speed -= 0.01f;
		}
		DrawFormatString(100, 100, 0x000000, "x%d", gPlayer.speed);

		if (gNowKey & PAD_INPUT_LEFT && gPlayer.speed > -1.0f) {
			gPlayer.speed -= 0.01f;
		}
		else if (gPlayer.speed < -0.01f) {
			gPlayer.speed += 0.01f;
		}
	}
}