#include"DxLib.h"
#include"variable.h"
#include"prototype.h"
#include"define.h"
#include"end.h"

void DrawEnd(void) {
    //�G���h�摜�\��
    DrawGraph(0, 0, gEndImg, FALSE);

    StopSoundMem(gTitleBGM);

    //�^�C�����Z�������I��(�R�b)
    if (++WaitTime > 300) {

    gGameMode = CLOSE;

    }

}