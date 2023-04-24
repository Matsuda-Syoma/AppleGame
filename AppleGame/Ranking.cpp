#include "DxLib.h"
#include "prototype.h"
#include "variable.h"
#include "ranking.h"
extern mode gGameMode;

void DrawRanking(void)
{
	// A�{�^���Ń^�C�g���֐���
	if (gKeyFlg & PAD_INPUT_A) gGameMode = TITLE;

	//�摜�\��
	DrawGraph(0, 0, gStageImg, FALSE);

	// �����L���O�ꗗ��\��
	SetFontSize(18);
		for (int i = 0; i < RANKING_DATA; i++) {
			DrawFormatString(50, 170 + i * 25, 0xffffff,
				"%2d %-10s %10d",
				gRanking[i].no,
				gRanking[i].name,
				gRanking[i].score);
	}

		DrawString(100, 450, "--- �X�y�[�X�L�[�������ă^�C�g���ɖ߂� ---", 0xff0000, 0);
}