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
	DrawGraph(0, 0, gRankingImg, FALSE);

	// �����L���O�ꗗ��\��
	SetFontSize(36);
	for (int i = 0; i < RANKING_DATA; i++) {
		DrawFormatString(80, 140 + i * 40, 0x000000,
			"%2d %-10s %10d",
			gRanking[i].no,
			gRanking[i].name,
			gRanking[i].score);
	}
}


void InputName(void)
{
	DrawGraph(0, 0, gStageImg, FALSE);

	SetFontSize(20);

	DrawString(150, 200, "�����L���O�ɓo�^���܂�", 0xffffff);
	DrawString(150, 230, "���O���p���œ��͂��Ă�������", 0xffffff);

	//���O�̓���
	DrawString(150, 310, "> ", 0xFFFFFF);
	DrawBox(160, 335, 295, 305, 0x000055, TRUE);
	if (KeyInputSingleCharString(170, 310, 10, gRanking[RANKING_DATA - 1].name, FALSE)
		== 1) {
		gRanking[RANKING_DATA - 1].score = gScore;	//�����L���O�f�[�^�ɃX�R�A��o�^
		SortRanking();						//�����L���O���בւ�
		SaveRanking();						//�����L���O�f�[�^�̕ۑ�
		gGameMode = RANKING;				//�Q�[�����[�h�̕ύX
	}
}


void SortRanking(void)
{
	int i, j;
	RankingData work;

	// �I��@�\�[�g
	for (i = 0; i < RANKING_DATA - 1; i++) {
		for (j = i + 1; j < RANKING_DATA; j++) {
			if (gRanking[i].score <= gRanking[j].score) {
				work = gRanking[i];
				gRanking[i] = gRanking[j];
				gRanking[j] = work;
			}
		}
	}

	// ���ʕt��
	for (i = 0; i < RANKING_DATA; i++) {
		gRanking[i].no = 1;
	}
	// ���_�������ꍇ�́A�������ʂƂ���
	// �����ʂ��������ꍇ�̎��̏��ʂ̓f�[�^�������Z���ꂽ���ʂƂ���
	for (i = 0; i < RANKING_DATA - 1; i++) {
		for (j = i + 1; j < RANKING_DATA; j++) {
			if (gRanking[i].score > gRanking[j].score) {
				gRanking[j].no++;
			}
		}
	}
}

int  SaveRanking(void)
{
	FILE* fp;
#pragma warning(disable:4996)

	// �t�@�C���I�[�v��
	if ((fp = fopen("data/rankingdata.txt", "w")) == NULL) {
		/* �G���[���� */
		printf("Ranking Data Error\n");
		return -1;
	}

	// �����L���O�f�[�^���z��f�[�^����������
	for (int i = 0; i < RANKING_DATA; i++) {
		fprintf(fp, "%2d %10s %10d\n", gRanking[i].no, gRanking[i].name, gRanking[i].score);
	}

	//�t�@�C���N���[�Y
	fclose(fp);
	return 0;

}

int ReadRanking(void)
{
	FILE* fp;
#pragma warning(disable:4996)

	//�t�@�C���I�[�v��
	if ((fp = fopen("data/rankingdata.txt", "r")) == NULL) {
		//�G���[����
		printf("Ranking Data Error\n");
		return -1;
	}

	//�����L���O�f�[�^�z����f�[�^��ǂݍ���
	for (int i = 0; i < RANKING_DATA; i++) {
		int dammy = fscanf(fp, "%2d %10s %10d", &gRanking[i].no, gRanking[i].name, &gRanking[i].score);
	}

	//�t�@�C���N���[�Y
	fclose(fp);

	return 0;
}