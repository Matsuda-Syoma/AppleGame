#include"DxLib.h"
#include"Player.h"
#include"prototype.h"
#include"variable.h"

extern int gOldKey;
extern int gNowKey;
extern int gKeyFlg;

int count;
int Acount;
int key[256];
int ix, gh = 1;

//•Ï”éŒ¾
struct PLAYER gPlayer;

//for (i = 0; i < 360; i++) {
//	fsin[i] = (float)sin(i * 3.1415926535 / 180);
//	fcos[i] = (float)cos(i * 3.1415926535 / 180);
//}

void PlayerControl(void)
{
	extern int gPlayerImg[12];

	//ˆÚ“®
	if (gPlayer.flg == true) {

		gPlayer.x += gPlayer.speed;

		//‰E
		if (gNowKey & PAD_INPUT_RIGHT && gPlayer.speed < 1.5f) {

			gPlayer.speed += 0.01f;

		}
		else if (gPlayer.speed > 0.0f) {
			gPlayer.speed -= 0.01f;
		}

		//¶
		if (gNowKey & PAD_INPUT_LEFT && gPlayer.speed > -1.5f) {
			gPlayer.speed -= 0.01f;
		}
		else if (gPlayer.speed < 0.0f) {
			gPlayer.speed += 0.01f;
		}

		//animation

	/*	if (++Acount < 48 && gNowKey & PAD_INPUT_LEFT) {
			if (count > 0) {
				count = 0;
				--count;
			}
		}*/

		if (gPlayer.speed > 0.1f) {
			gh = count % 3 + 6;
			if (++Acount > 24) {
				++count;
				Acount = 0;
			}
		}else if (gPlayer.speed < 0.0f) {
			gh = count % 3 + 3;
			if (++Acount > 24) {
				++count;
				Acount = 0;
			}
		}
		else if(gPlayer.speed <= 0.1f && gPlayer.speed> 0.0f) {
			count = 0;
			Acount = 0;
			gh = 1;
		}

		DrawFormatString(520, 400, 0x000000, "speed %lf", gPlayer.speed);

	}


	//‰æ–Ê‚ğ‚Í‚İo‚³‚È‚¢‚æ‚¤‚É‚·‚é
	if (gPlayer.x < 32)gPlayer.x = 32;
	if (gPlayer.x > SCREEN_WIDTH - 180)gPlayer.x = SCREEN_WIDTH - 180;
	if (gPlayer.y < 60)gPlayer.y = 60;
	if (gPlayer.y > SCREEN_HEIGHT - 60)gPlayer.y = SCREEN_HEIGHT - 60;

	//ix = abs(count) % 30 / 10;

	////‰EŒü‚«
	//if (count > 0) {
	//	ix += 6;
	//	gh = ix;
	//}
	//else if (count < 0) {
	//	//¶Œü‚«
	//	ix += 3;
	//	gh = ix;
	//}

	//•`‰æ
	if (gPlayer.flg = true) {
		////¶ˆÚ“®•`‰æ
		//if (gNowKey & PAD_INPUT_LEFT) {
			DrawRotaGraph(gPlayer.x, gPlayer.y, 3.0f, 0, gPlayerImg[gh], TRUE, FALSE);
		//}
		////‰EˆÚ“®•`‰æ
		//else if (gNowKey & PAD_INPUT_RIGHT) {
		//	DrawRotaGraph(gPlayer.x, gPlayer.y, 3.0f, 0, gPlayerImg[gh], TRUE, FALSE);
		//}
		//else {
		//	//“®‚¢‚Ä‚¢‚È‚¢‚Æ‚«‚Í³–Ê‚ÉŒü‚¯‚é
		//	DrawRotaGraph(gPlayer.x, gPlayer.y, 3.0f, 0, gPlayerImg[1], TRUE, FALSE);
		//	count = 0;
		//}

	}
}