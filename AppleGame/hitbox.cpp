#include "DxLib.h"
#include "prototype.h"
#include "variable.h"
#include "player.h"
//自機と敵機の当たり判定(短形)
int HitBoxPlayer(PLAYER* p, APPLE*e) {

	//x,yは中心座標とする
	float sx1 = p->x - (p->w / 2);
	float sy1 = p->y - (p->h / 2);
	float sx2 = sx1 + p->w;
	float sy2 = sy1 + p->h;

	float dx1 = e->x - (e->w / 2);
	float dy1 = e->y - (e->h / 2);
	float dx2 = dx1 + e->w;
	float dy2 = dy1 + e->h;

	//デバッグ用処理
	//DrawBox(dx1, dy1, dx2, dy2, 0x000000, false);
	//DrawBox(sx1, sy1, sx2, sy2, 0xffffff, true);

	if (sx1 < dx2 && dx1 < sx2 && sy1 < dy2 && dy1 < sy2) {
		return true;
	}
	return false;
}
