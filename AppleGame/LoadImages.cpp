#include "DxLib.h"
#include "loadimages.h"
#include"prototype.h"
#include "variable.h"

int gAppleImg[4];
int gStageImg;
int gTitleImg;
int gHelpImg;
int gPlayerImg[12];

int LoadImages(void) {
	if (LoadDivGraph("Images/Apple.png", 4, 4, 1, 60, 60, gAppleImg) == -1)return -1;
	if ((gStageImg = LoadGraph("Images/bg_mori.png")) == -1)return -1;
	if ((gTitleImg = LoadGraph("Images/bg_title.png")) == -1)return -1;
	if ((gHelpImg = LoadGraph("Images/help.png")) == -1)return -1;
	if (LoadDivGraph("Images/Player.png", 12, 3, 4, 32, 32, gPlayerImg) == -1)return -1;

	return 0;
}
