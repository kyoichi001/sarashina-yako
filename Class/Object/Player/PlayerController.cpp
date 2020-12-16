
#include "PlayerController.h" 

#include "../../../Library/Func.h"
#include "../../../Data/DATA.h"
#include "../../../Library/Math/Constant.h"
#include "../../../Library/Primitive/Primitive.h"
#include "IPLayer.h"

Vec2 PlayerController::GetSpeedFromKey()noexcept {
	int movespeed = Key[Data.Key.Button64] >= 1?2:4;
	Vec2 Speed;
	if (Key[Data.Key.Button08] >= 1) Speed.x = movespeed;
	if (Key[Data.Key.Button04] >= 1) Speed.x = -movespeed;
	if (Key[Data.Key.Button01] >= 1) Speed.y = -movespeed;
	if (Key[Data.Key.Button02] >= 1) Speed.y = movespeed;
	return Speed;
}

void PlayerController::UpdateMove()noexcept {
	mPlayer->p += GetSpeedFromKey();
	mPlayer->p.clamp(GameWindow);
	if (Key[Data.Key.Button64] >= 1)mPlayer->Slow();
	else mPlayer->Fast();
}
void PlayerController::UpdateShot() noexcept {
	if (Key[Data.Key.Button16] >= 1) mPlayer->Shoot1();
	if (Key[Data.Key.Button32] == 1) mPlayer->Shoot2();

	if (Key[Data.Key.Button256] == 1) {
		//mPlayer->mObj->ObjPBl().Emplace(OneKill,mPlayer->p+Point(6,-10), -HALF_PI);//for the purpose of debuging
	}
}
