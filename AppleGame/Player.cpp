#include"DxLib.h"
#include"Player.h"
#include"prototype.h"
#include"variable.h"

extern int gOldKey;
extern int gNowKey;
extern int gKeyFlg;

int count = 0;
int key[256];
int ix = 0, gh = 0;
float move = 2;
int i;
float fsin[360], fcos[360], mv = 0.1f;

//�ϐ��錾
struct PLAYER gPlayer;

//for (i = 0; i < 360; i++) {
//	fsin[i] = (float)sin(i * 3.1415926535 / 180);
//	fcos[i] = (float)cos(i * 3.1415926535 / 180);
//}

void PlayerControl(void)
{
	extern int gPlayerImg[12];

	gOldKey = gNowKey;
	gNowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	gKeyFlg = gNowKey & ~gOldKey;

	gPlayer.speed = move;

	//�ړ�
	if (gPlayer.flg == true) {
		//���ړ�
		if (gNowKey & PAD_INPUT_LEFT)gPlayer.x -= gPlayer.speed;
		if (gNowKey & PAD_INPUT_LEFT) {
			if (count > 0)
				count = 0;
			--count;
		}
		//�E�ړ�
		if (gNowKey & PAD_INPUT_RIGHT)gPlayer.x += gPlayer.speed;
		if (gNowKey & PAD_INPUT_RIGHT) {
			if (count < 0)
				count = 0;
			++count;
		}
	}

	//��ʂ��͂ݏo���Ȃ��悤�ɂ���
	if (gPlayer.x < 32)gPlayer.x = 32;
	if (gPlayer.x > SCREEN_WIDTH - 180)gPlayer.x = SCREEN_WIDTH - 180;
	if (gPlayer.y < 60)gPlayer.y = 60;
	if (gPlayer.y > SCREEN_HEIGHT - 60)gPlayer.y = SCREEN_HEIGHT - 60;

	ix = abs(count) % 30 / 10;

	//�E����
	if (count > 0) {
		ix += 6;
		gh = ix;
	}
	else if (count < 0) {
		//������
		ix += 3;
		gh = ix;
	}

	//�`��
	if (gPlayer.flg = true) {
		//���ړ��`��
		if (gNowKey & PAD_INPUT_LEFT) {
			DrawRotaGraph(gPlayer.x, gPlayer.y, 3.0f, 0, gPlayerImg[gh], TRUE, FALSE);
		}
		//�E�ړ��`��
		else if (gNowKey & PAD_INPUT_RIGHT) {
			DrawRotaGraph(gPlayer.x, gPlayer.y, 3.0f, 0, gPlayerImg[gh], TRUE, FALSE);
		}
		else {
			//�����Ă��Ȃ��Ƃ��͐��ʂɌ�����
			DrawRotaGraph(gPlayer.x, gPlayer.y, 3.0f, 0, gPlayerImg[1], TRUE, FALSE);
			count = 0;
		}

	}
}