
#include "EnemyData.h"
#include "../../../Library/Renderer.h"
#include "../../../Library/Sprite/Animation.h"

using namespace DxWrp;

int GhostNullHdl=-1,Ghost1Hdl, Ghost1Anim[4], Ghost2Anim[4], Ghost3Anim[4],GhostSkullHdl;
int Boss[6];
int EnemyBack1Hdl, EnemyBack2Hdl;

Animation EnemyAnim[5];

void LoadEnemyResource()noexcept {
	Ghost1Hdl =LoadGraph("Picture/Chara/Enemy/Ghost/Ghost4.png");
	LoadDivGraph("Picture/Chara/Enemy/Ghost/Ghost41.png", 4, 4, 1, 32, 64, Ghost1Anim);
	LoadDivGraph("Picture/Chara/Enemy/Ghost/Ghost42.png", 4, 4, 1, 32, 64, Ghost2Anim);
	LoadDivGraph("Picture/Chara/Enemy/Ghost/fire2.png", 4, 4, 1, 32, 32, Ghost3Anim);
	GhostSkullHdl = LoadGraph("Picture/Chara/Enemy/Ghost/skull.png");
	Boss[0] = LoadGraph("Picture/Chara/Enemy/Boss/BOSS1.png");
	Boss[1] = LoadGraph("Picture/Chara/Enemy/Boss/BOSS2.png");
	Boss[2] = LoadGraph("Picture/Chara/Enemy/Boss/BOSS3.png");
	Boss[3] = LoadGraph("Picture/Chara/Enemy/Boss/BOSS4.png");
	Boss[4] = LoadGraph("Picture/Chara/Enemy/Boss/BOSS5.png");
	Boss[5] = LoadGraph("Picture/Chara/Enemy/Boss/BOSS6.png");
	EnemyBack1Hdl = EnemyBack2Hdl = LoadGraph("Picture/Effect/EnemyEffect01.png");
	EnemyAnim[0].Set(30, &GhostNullHdl, 1);
	EnemyAnim[1].Set(30, Ghost1Anim, 4);
	EnemyAnim[2].Set(30, Ghost2Anim, 4);
	EnemyAnim[3].Set(30, Ghost3Anim, 4);
	EnemyAnim[4].Set(30, &GhostSkullHdl , 1);
}

#include "IGhost.h"
#include "../../MediatorClass/ObjectAdaptor.h"
#include "../Effect/Effects.h"
#include "../../../Library/Math/Constant.h"

void NormalEnemyEnd(IGhost* Obj, ObjectAdaptor& List) {
	List.ObjEff().SetObject(new EnemyBreak(Obj->p, { Rand(PI), 0.1f ,0 }, 30));
	List.GetPlayer()->addScore(100);
	List.GetPlayer()->AddSubWeapon(1);
}