#include "DxLib.h"
#include "apple.h"
#include "prototype.h"

extern int gAppleImg[4];

struct APPLE gApple[APPLE_MAX];
struct APPLE gApple00 = { true,0,0,0,10,63,63,0,1 };
int gAppleSpeed[4] = { 1,2,2,1 };
int gAppleScore[4] = { 10,20,40,-20 };

void AppleControl(void) {

	for (int i = 0; i < APPLE_MAX; i++) {
		if (gApple[i].flg == true) {

			//�G�̕\��
			DrawRotaGraph(gApple[i].x, gApple[i].y, 1.0f, 0, gApple[i].img, true, false);

			if (gApple[i].flg == false) continue;

			//�܂��������Ɉړ�
			gApple[i].y += gApple[i].speed;

			//��ʂ��͂ݏo���������
			if (gApple[i].y > SCREEN_HEIGHT + gApple[i].h)gApple[i].flg = false;

			////�����蔻��
			//if (HitBoxPlayer(&gPlayer, &gEnemy[i]) == true && gPlayer.baricnt <= 0) {
			//	gPlayer.flg = false;
			//	gPlayer.count = 0;
			//	gPlayer.hp -= 100;
			//	gEnemy[i].flg = false;
			//	if (gPlayer.hp <= 0)gGameMode = GAMEOVER;
			//}
		}
	}

	////���s�������ƂɓG�o���p�^�[���𐧌䂷��
	//if (gMileage / 10 % 50 == 0) {
	//	CreateApple();
	//}

	CreateApple();

}

int CreateApple(void) {

	for (int i = 0; i < APPLE_MAX; i++) {
		if (gApple[i].flg == false) {
			gApple[i] = gApple00;
			gApple[i].type = GetRand(3);
			gApple[i].img = gAppleImg[gApple[i].type];
			//gApple[i].img = gAppleImg;
			gApple[i].x = GetRand(6) * 70 + 40;//�ő�420 + 40
			gApple[i].speed = 0;// gAppleSpeed[gApple[i].type];
			gApple[i].score = gAppleScore[gApple[i].type];

			//����
			return true;
		}
	}
	//���s
	return false;
}