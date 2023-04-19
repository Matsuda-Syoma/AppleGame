#include "DxLib.h"
#include "apple.h"
#include "prototype.h"
#include "variable.h"

extern int gAppleImg[4];
extern struct PLAYER gPlayer;

struct APPLE gApple[APPLE_MAX];
struct APPLE gApple00 = { true,0,0,0,10,55,55,0,1 };
float gAppleSpeed[4] = { 1.0f,2.0f,3.5f,0.5f };
int gAppleScore[4] = { 100,200,500,-750 };

void AppleControl(void) {

	for (int i = 0; i < APPLE_MAX; i++) {
		if (gApple[i].flg == true) {

			//�G�̕\��
			DrawRotaGraph(gApple[i].x, gApple[i].y, 1.0f, 0, gApple[i].img, true, false);

			if (gApple[i].flg == false) continue;

			//�܂��������Ɉړ�
			gApple[i].y += gApple[i].speed;

			//��ʂ��͂ݏo���������
			if (gApple[i].y > 1000) {
				gApple[i].flg = false;
			}

			////�����蔻��
			if (HitBoxPlayer(&gPlayer, &gApple[i]) == true) {
				/*gPlayer.flg = false;*/
				gAppleCount[gApple[i].type] ++;
				gScore += gAppleScore[gApple[i].type];
				gApple[i].flg = false;
			}


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
			gApple[i].speed = gAppleSpeed[gApple[i].type];
			gApple[i].score = gAppleScore[gApple[i].type];
			if (gApple[i].type == 3) {
				gApple[i].w = gApple[i].w * 0.9f;
				gApple[i].h = gApple[i].h * 0.9f;
			} else {
				gApple[i].w = gApple[i].w * 1.1f;
				gApple[i].h = gApple[i].h * 1.1f;
			}

			//����
			return true;
		}
	}
	//���s
	return false;
}