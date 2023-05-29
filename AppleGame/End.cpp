#include"DxLib.h"
#include"variable.h"
#include"prototype.h"
#include"define.h"
#include"end.h"

void DrawEnd(void) {
    //ƒGƒ“ƒh‰æ‘œ•\Ž¦
    DrawGraph(0, 0, gEndImg, FALSE);

    StopSoundMem(gTitleBGM);

    //ƒ^ƒCƒ€‰ÁŽZˆ—•I—¹(‚R•b)
    if (++WaitTime > 300) {

    gGameMode = CLOSE;

    }

}