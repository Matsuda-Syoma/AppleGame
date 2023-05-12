#include "DxLib.h"
#include"prototype.h"
#include "variable.h"
#include "loadimages.h"

int LoadImages(void) {
	if (LoadDivGraph("Images/Apple.png", 4, 4, 1, 60, 60, gAppleImg) == -1)return -1;
	if ((gStageImg = LoadGraph("Images/bg_mori.png")) == -1)return -1;
	if ((gTitleImg = LoadGraph("Images/bg_title.png")) == -1)return -1;
	if ((gHelpImg = LoadGraph("Images/help.png")) == -1)return -1;
	if (LoadDivGraph("Images/t12.png", 12, 3, 4, 32, 64, gPlayerImg) == -1)return -1;
	if ((gRankingImg = LoadGraph("Images/RANKING.png")) == -1)return -1;
	if ((gEndImg = LoadGraph("Images/bg_end.png")) == -1)return -1;

	return 0;
}
