
#include "StageBosslush.h"

#include "../StageChapter.h"

#include "../../../../../Library/3DFunc.h"
#include "../../../../MediatorClass/ObjectAdaptor.h"
#include "../../../../Object/3D/3DObjects.h"
#include "../../../../Object/Effect/Effects.h"

#include "../../../../Object/Enemy/EnemyData/Bosslush.h"

using namespace DxWrp;

void StageEXInit(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept {

	Obj.Obj3Ds().Kill();
	Obj.Obj3Ef().Kill();
	SetFogColor(255, 255, 255);
	SetFogStartEnd(200, 3800);
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 4; ++j) {
			Vec3* p = Obj.Obj3Ds().SetObject(new CChunk4({ -800.0f + j * 1500, 0.0f, -2200.0f + i * 1500 }, 0));
			for (int k = 0; k < 4; ++k) {
				Obj.Obj3Ef().SetObject(new CSnow({ Rand(0.0f,1500.0f),Rand(2000.0f,3500.0f), Rand(0.0f,1500.0f) }, 10, p));
			}
			for (int k = 0; k < 1; ++k) {
				Obj.Obj3Ef().SetObject(new CCrowd({ Rand(0.0f,1500.0f),Rand(1650.0f,2500.0f), Rand(0.0f,1500.0f) }, 10, p));
			}
		}
	}
	Obj.GetCamera().SetPosi({ 1108.0f, 1119.0f, 600.0 });
	Obj.GetCamera().SetTarg({ 81.0f, 962.0f, 800.0 });
	setBulletDataEX(Obj.ObjBRen(), Obj);
	Obj.getAudio().playBGM(9);
	Chapter->Next();
}
void StageEX0(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept {
	if (t == 45) {
		Obj.FacEmy().CreateBoss(0, Point(-20, 300), Chapter)->SetFinishFunc(
			[](StageChapter& Stage, ObjectAdaptor& CList) {Stage.Next(); }
		);
	}
}
void StageEX1(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept{
	if (t == 45) {
		Obj.FacEmy().CreateBoss(1, Point(-20, 300), Chapter)->SetFinishFunc(
			[](StageChapter& Stage, ObjectAdaptor& CList) {Stage.Next(); }
		);
	}
}
void StageEX2(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept{
	if (t == 45) {
		Obj.FacEmy().CreateBoss(2, Point(-20, 300), Chapter)->SetFinishFunc(
			[](StageChapter& Stage, ObjectAdaptor& CList) {Stage.Next(); }
		);
	}
}
void StageEX3(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept{
	if (t == 45) {
		Obj.FacEmy().CreateBoss(3, Point(-20, 300), Chapter)->SetFinishFunc(
			[](StageChapter& Stage, ObjectAdaptor& CList) {Stage.Next(); }
		);
	}
}
void StageEX4(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept{
	if (t == 45) {
		Obj.FacEmy().CreateBoss(4, Point(-20, 300), Chapter)->SetFinishFunc(
			[](StageChapter& Stage, ObjectAdaptor& CList) {Stage.Next(); }
		);
	}
}
void StageEX5(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept{
	if (t == 45) {
		Obj.FacEmy().CreateBoss(5, Point(-20, 300), Chapter)->SetFinishFunc(
			[](StageChapter& Stage, ObjectAdaptor& CList) {Stage.Next(); }
		);
	}
}
void StageEXClear(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept {
	if (t == 30) {
		Obj.ObjEff().SetObject(new StageClear(240));
	}
	if (t == 320) {
		Chapter->Next();
		Obj.getAudio().stopBGM();
	}
}