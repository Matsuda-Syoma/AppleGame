#include "DxLib.h"
#include "prototype.h"
#include "variable.h"
#include "ranking.h"
extern mode gGameMode;

/************************************
*�@�����L���O���
*************************************/
void DrawRanking(void)
{
	// A�{�^���Ń^�C�g���֐���
	if (gKeyFlg & PAD_INPUT_A) gGameMode = TITLE;

	//�摜�\��
	DrawGraph(0, 0, gStageImg, FALSE);

	DrawString(250,200,"---�e�X�g�\��---",0xff0000,0);

	// �����L���O�ꗗ��\��
	//SetFontSize(18);
	//for (int i = 0; i < RANKING_DATA; i++) {
	//	DrawFormatString(50, 170 + i * 25, 0xffffff,
	//		"%2d %-10s %10d",
	//		gRanking[i].no,
	//		gRanking[i].name,
	//		gRanking[i].score);
	//}

	DrawString(160, 450, "--- A�{�^���������ă^�C�g���ɖ߂� ---", 0xff0000, 0);
}

/************************************
*�@�����L���O���͏���
*************************************/
void InputName(void)
{
	DrawGraph(0, 0, gTitleImg, FALSE);

	SetFontSize(20);

	DrawString(150, 240, "�����L���O�ɓo�^���܂�", 0xffffff);
	DrawString(150, 270, "���O���p���œ��͂��Ă�������", 0xffffff);

	//���O�̓���
	DrawString(150, 310, "> ", 0xFFFFFF);
	DrawBox(160, 395, 300, 335, 0x000055, TRUE);
	if (KeyInputSingleCharString(170, 310, 10, gRanking[RANKING_DATA - 1].name, FALSE)
		== 1) {
		gRanking[RANKING_DATA - 1].score = gScore;	//�����L���O�f�[�^�ɃX�R�A��o�^
		//SortRanking();						//�����L���O���בւ�
		//SaveRanking();						//�����L���O�f�[�^�̕ۑ�
		gGameMode = RANKING;				//�Q�[�����[�h�̕ύX
	}
}