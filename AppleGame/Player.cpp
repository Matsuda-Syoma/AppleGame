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
int CoolTime
;
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

		DrawRotaGraph(gPlayer.x, gPlayer.y, 3.0f, 0, gPlayerImg[gh], TRUE, FALSE);

		gPlayer.x += gPlayer.speed;

		//‰E
		if (gNowKey & PAD_INPUT_RIGHT && gPlayer.speed < 1.5f) {

			gPlayer.speed += 0.02f;

		}
		else if (gPlayer.speed > 0.0f) {
			gPlayer.speed -= 0.01f;
		}

		//¶
		if (gNowKey & PAD_INPUT_LEFT && gPlayer.speed > -1.5f) {
			gPlayer.speed -= 0.02f;
		}
		else if (gPlayer.speed < 0.0f) {
			gPlayer.speed += 0.01f;
		}

		//animation

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

	}


	//‰æ–Ê‚ğ‚Í‚İo‚³‚È‚¢‚æ‚¤‚É‚·‚é
	if (gPlayer.x < 32)gPlayer.x = 32;
	if (gPlayer.x > 468)gPlayer.x = 468;


	//•`‰æ
	if (gPlayer.flg == false) {

		if (++CoolTime < 120) {
			if (CoolTime % 40 < 20) {
				DrawRotaGraph(gPlayer.x, gPlayer.y, 3.0f, 0, gPlayerImg[gh], TRUE, FALSE);
			}
		}
		else {
			CoolTime = 0;
			gPlayer.flg = true;
		}
	}
}