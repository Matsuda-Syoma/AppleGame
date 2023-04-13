#include "DxLib.h"
#include "player.h"
#include "prototype.h"
#include "variable.h"

extern int gOldKey;
extern int gNowKey;
extern int gKeyFlg;

struct PLAYER gPlayer;

void PlayerControl(void) {

	//è„â∫ç∂âEÇÃà⁄ìÆ
	if (gPlayer.flg == true) {
		if (gNowKey & PAD_INPUT_LEFT)gPlayer.x -= gPlayer.speed;
		if (gNowKey & PAD_INPUT_RIGHT)gPlayer.x += gPlayer.speed;
	}
}