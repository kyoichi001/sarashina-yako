
#include "Stage.h"
#include "StageChapter.h"
#include "../../../../Data/Resource.h"
#include "../../../../Library/Func.h"
#include "../../../../Library/3DFunc.h"
#include "../../../MediatorClass/ObjectAdaptor.h"
#include "../../../Object/Enemy/IGhost.h"
#include "../../../Object/Enemy/IBoss.h"
#include "../../../Object/3D/3DObjects.h"
#include "../../../Object/Enemy/EnemyData.h"
#include "../../../Object/Effect/Effects.h"

using namespace DxWrp;

void StageEInit(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept {
	SetFogColor(56, 0, 76);
	SetFogStartEnd(0, 3000);
	Obj.Obj3Ds().Kill();
	Obj.Obj3Ef().Kill();
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 4; ++j) {
			Vec3* p = Obj.Obj3Ds().SetObject(new CChunk1_1({ -800.0f + j * 1500, 0.0f, -2200.0f + i * 1500 }, 0));
			for (int i = 0; i < 4; ++i) {
				Obj.Obj3Ef().SetObject(new CCrowd({ Rand(0.0f,1500.0f),Rand(150.0f,2500.0f), Rand(0.0f,1500.0f) }, 10, p));
				Obj.Obj3Ef().SetObject(new CSnow({ Rand(0.0f,1500.0f),Rand(2000.0f,3500.0f), Rand(0.0f,1500.0f) }, 10, p));
			}
		}
	}
	Obj.GetCamera().SetPosi({ 1708.0f, 1419.0f, 600.0 });
	Obj.GetCamera().SetTarg({ 681.0f, 1262.0f, 800.0 });
	Chapter->Next();
}

void StageE0(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept {
	if (t % 60 == 0)Obj.ObjEff().SetObject(new Message(Point(25.0f, 200.0f), "メッセージはでないはずです。\n開発者にお知らせください。", 30));
}

