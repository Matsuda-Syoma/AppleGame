#include"DxLib.h"
#include"Player.h"
#include"prototype.h"
#include"variable.h"

int gOldKey;
int gNowKey;
int gKeyFlg;



void PlayerControl(void)
{
	extern int gPlayerImg[12];
	
	int count=0;
	int key[256];
	int ix = 0, gh = 0;

	 gOldKey = gNowKey;
	 gNowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	 gKeyFlg = gNowKey & ~gOldKey;

	 float move =2;
	 gPlayer.speed = move;

	 //�ړ�
	if (gPlayer.flg == true) {
		if (gNowKey & PAD_INPUT_LEFT)gPlayer.x -= gPlayer.speed;
		if (gNowKey & PAD_INPUT_LEFT) {
			if (count > 0)
				count = 0;
				--count;
		}
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
		//���ړ�
		if (gNowKey & PAD_INPUT_LEFT) {
			DrawRotaGraph(gPlayer.x, gPlayer.y, 3.0f, 0, gPlayerImg[gh], TRUE, FALSE);
		}
		//�E�ړ�
		else if (gNowKey & PAD_INPUT_RIGHT) {
		DrawRotaGraph(gPlayer.x, gPlayer.y, 3.0f, 0, gPlayerImg[gh], TRUE, FALSE);
		}
		else {
			DrawRotaGraph(gPlayer.x, gPlayer.y, 3.0f, 0, gPlayerImg[1], TRUE, FALSE);
		}
		if (key[PAD_INPUT_LEFT] != 1 && key[PAD_INPUT_RIGHT] != 1) {
			count = 0;
		}
	}
}