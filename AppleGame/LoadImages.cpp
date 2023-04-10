#include "DxLib.h"
#include "loadimages.h"
#include"prototype.h"

int LoadImages(void) {
	//if ((gAppleImg = LoadGraph("Images/Apple.png")) == -1)return -1;
	if (LoadDivGraph("Images/Apple.png", 4, 4, 1, 60, 60, gAppleImg) == -1)return -1;
	//if (LoadDivGraph("Images/Car.bmp", 3, 3, 1, 63, 120, gAppleImg) == -1)return -1;
	return 0;
}
