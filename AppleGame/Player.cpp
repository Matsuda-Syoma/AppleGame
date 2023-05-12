#include"DxLib.h"
#include"prototype.h"
#include"variable.h"
#include"Player.h"

//変数宣言

int count;
int Acount;
int key[256];
int PlayerImg = 1;
int CoolTime;

struct PLAYER gPlayer;

void PlayerControl(void)
{
	extern int gPlayerImg[12];

	gPlayer.x += gPlayer.speed;

	//右
	if (gNowKey & PAD_INPUT_RIGHT && gPlayer.speed < 5.6f) {

		gPlayer.speed += 0.1f;

	}
	else if (gPlayer.speed > 0.0f) {
		gPlayer.speed -= 0.2f;
	}

	//左
	if (gNowKey & PAD_INPUT_LEFT && gPlayer.speed > -5.6f) {
		gPlayer.speed -= 0.1f;
	}
	else if (gPlayer.speed < 0.0f) {
		gPlayer.speed += 0.2f;
	}



	if (gPlayer.speed > -0.2f && gPlayer.speed < 0.2f) {

		if (~gNowKey & PAD_INPUT_LEFT && ~gNowKey & PAD_INPUT_RIGHT) {

			gPlayer.speed = 0.0f;
		}
	}

	//animation

	//右
	if (gPlayer.speed > 0.2f) {
		PlayerImg = count % 3 + 6;
		if (++Acount > 24 / gPlayer.speed) {
			++count;
			Acount = 0;
		}

		//左
	}
	else if (gPlayer.speed < -0.2f) {
		PlayerImg = count % 3 + 5;
		if (++Acount > 24 / (gPlayer.speed * -1)) {
			-- count;
			Acount = 0;
		}
	}
	else if (gPlayer.speed > -0.2f && gPlayer.speed < 0.2f) {
		count = 0;
		Acount = 0;
		PlayerImg = 1;
	}



	//画面をはみ出さないようにする
	if (gPlayer.x < 48)gPlayer.x = 48;
	if (gPlayer.x > SCREEN_WIDTH - 280 - 48)gPlayer.x = SCREEN_WIDTH - 280 - 48;

	//描画
	if (gPlayer.flg == true) {

		DrawRotaGraph(gPlayer.x, gPlayer.y, 4.0f, 0, gPlayerImg[PlayerImg], TRUE, FALSE);

	}else{

		if (++CoolTime < 120) {
			if (CoolTime % 40 < 20) {
				DrawRotaGraph(gPlayer.x, gPlayer.y, 4.0f, 0, gPlayerImg[PlayerImg], TRUE, FALSE);
			}
		}
		else {
			CoolTime = 0;
			gPlayer.flg = true;
		}
	}
}