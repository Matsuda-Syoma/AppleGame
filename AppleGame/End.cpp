#include"DxLib.h"
#include"variable.h"
#include"prototype.h"
#include"define.h"

extern mode gGameMode;
extern int gStageImg;

int WaitTime = 0;


void DrawEnd(void) {
    //�G���h�摜�\��
    DrawGraph(0, 0, gStageImg, FALSE);

    StopSoundMem(gTitleBGM);

    SetFontSize(24);
    DrawString(360, 480 - 24, "Thank you for playing", 0xffffff, 0);

    //�^�C�����Z�������I��(�R�b)
    if (++WaitTime > 300)gGameMode=CLOSE;

}