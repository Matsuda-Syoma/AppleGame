#include "DxLib.h"
#include "prototype.h"
#include "variable.h"
#include "ranking.h"
extern mode gGameMode;

void DrawRanking(void)
{
	// A�{�^���Ń^�C�g���֐���
	if (gKeyFlg & PAD_INPUT_A) gGameMode = TITLE;

	DrawGraph(0, 0, gTitleImg, FALSE);

	// �����L���O�ꗗ��\��
	SetFontSize(18);
		for (int i = 0; i < RANKING_DATA; i++) {
			
	}

}