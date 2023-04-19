#include "DxLib.h"
#include "loadimages.h"
#include"prototype.h"
#include "variable.h"

int gAppleImg[4];
int gStageImg;
int gTitleImg;

int LoadImages(void) {
	if (LoadDivGraph("Images/Apple.png", 4, 4, 1, 60, 60, gAppleImg) == -1)return -1;
	if ((gStageImg = LoadGraph("Images/bg_mori.png")) == -1)return -1;
}
