
#include "Stage3.h"

#include "../StageChapter.h"

#include "../../../../../Library/3DFunc.h"
#include "../../../../MediatorClass/ObjectAdaptor.h"
#include "../../../../Object/3D/3DObjects.h"
#include "../../../../Object/Effect/Effects.h"

#include "../../../../Object/Enemy/EnemyData/Enemy3.h"

using namespace DxWrp;

void Stage3Init(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept {
	Obj.Obj3Ds().Kill();
	Obj.Obj3Ef().Kill();
	SetFogColor(0, 0, 0);
	SetFogStartEnd(700, 3800);
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 4; ++j) {
			Vec3* p = Obj.Obj3Ds().SetObject(new CChunk2({ -800.0f + j * 1500, 0.0f, -2200.0f + i * 1500 }, 0));
			for (int k = 0; k < 7; ++k) {
				Obj.Obj3Ef().SetObject(new CSnow({ Rand(0.0f,1500.0f),Rand(2000.0f,3500.0f), Rand(0.0f,1500.0f) }, 10, p));
			}
			for (int k = 0; k < 1; ++k) {
				Obj.Obj3Ef().SetObject(new CCrowd({ Rand(0.0f,1500.0f),Rand(1650.0f,2500.0f), Rand(0.0f,1500.0f) }, 10, p));
			}
		}
	}
	Obj.GetCamera().SetPosi({ 1108.0f, 1119.0f, 600.0 });
	Obj.GetCamera().SetTarg({ 81.0f, 962.0f, 800.0 });
	setBulletData3(Obj.ObjBRen(), Obj);
	Obj.getAudio().playBGM(5);
	TalkingManager& talk = Obj.getTalkManager();
	talk.Init();
	talk.pushLeftTalker(0);
	talk.pushRightTalker(3);
	talk.pushTalk(false, "やあやあ君見慣れない人だね");
	talk.pushTalk(false, "お客さん？");
	talk.pushTalk(true, "ここに来いとある人に招待されたんでね");
	talk.pushTalk(true, "通してもらえないかな");
	talk.pushTalk(false, "うーん、君見たところ少し特殊な人間みたいだねー");
	talk.pushTalk(false, "このままただで通すわけにはいかないかな？");
	talk.pushTalk(true, "うえ、急いでるのに。めんどくさい");
	talk.pushTalk(false, "まあまあいいじゃないか");
	talk.pushTalk(false, "どうせ中にはいっても道に迷いそうだし");
	talk.pushTalk(true, "うー");
	talk.pushTalk(false, "というわけで小手調べだ");
	talk.pushTalk(false, "久しぶりに楽しめそうだよ");
	Chapter->Next();
}
void Stage30(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept {
	if (t == 5) {
		Obj.FacEmy().CreateEnemyEmi(30, 5, 0, Rect(630.0f, 28.0f, 650.0f, 160.0f));
	}
	if (t == 350) {
		Obj.FacEmy().CreateEnemyEmi(60, 3, 1, Rect(80.0f, 0.0f, 120.0f, 0.0f));
		Obj.FacEmy().CreateEnemy(3, { 120.0f,0.0f });
		Obj.FacEmy().CreateEnemy(3, { 220.0f,0.0f });
	}
	if (t == 750) {
		Obj.FacEmy().CreateEnemyEmi(60, 3, 1, Rect(400.0f, 0.0f, 440.0f, 0.0f));
		Obj.FacEmy().CreateEnemy(3, { 530.0f,0.0f });
		Obj.FacEmy().CreateEnemy(2, { 430.0f,0.0f });
	}
	if (t == 1150) {
		Obj.FacEmy().CreateEnemy(2, { 120.0f,0.0f });
		Obj.FacEmy().CreateEnemy(3, { 430.0f,0.0f });
		Obj.FacEmy().CreateEnemy(3, { 530.0f,0.0f });
	}
	if (t == 1550) {
		Obj.FacEmy().CreateEnemy(3, { 120.0f,0.0f });
		Obj.FacEmy().CreateEnemy(3, { 220.0f,0.0f });
		Obj.FacEmy().CreateEnemy(2, { 420.0f,0.0f });
	}
	if (t == 1950) {
		Obj.FacEmy().CreateEnemyEmi(30, 5, 0, Rect(630.0f, 28.0f, 650.0f, 160.0f));
	}
	if (t == 2500) {
		Obj.FacEmy().CreateEnemyEmi(30, 5, 0, Rect(80.0f, 0.0f, 140.0f, 0.0f));
	}
	if (t == 3000) {
		Chapter->Next();
	}

}
void Stage31(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept {
	if (t == 160) {
		Obj.FacEmy().CreateEnemy(5, { 100.0f,0.0f });
		Obj.FacEmy().CreateEnemy(5, { 460.0f,0.0f });
	}
	if (t == 760) {
		Obj.FacEmy().CreateEnemy(4, { 90.0f,0.0f });
		Obj.FacEmy().CreateEnemy(4, { 330.0f,0.0f });
		Obj.FacEmy().CreateEnemy(4, { 530.0f,0.0f });
	}
	if (t == 1360) {
		Obj.FacEmy().CreateEnemy(4, { 140.0f,0.0f });
		Obj.FacEmy().CreateEnemy(4, { 260.0f,0.0f });
		Obj.FacEmy().CreateEnemy(4, { 390.0f,0.0f });
		Obj.FacEmy().CreateEnemy(4, { 520.0f,0.0f });
	}
	if (t == 1960) {
		Obj.FacEmy().CreateEnemy(4, { 80.0f,0.0f });
		Obj.FacEmy().CreateEnemy(4, { 190.0f,0.0f });
		Obj.FacEmy().CreateEnemy(4, { 320.0f,0.0f });
		Obj.FacEmy().CreateEnemy(4, { 430.0f,0.0f });
		Obj.FacEmy().CreateEnemy(4, { 530.0f,0.0f });
	}
	if (t == 2600) {
		Chapter->Next();
	}
}

void Stage3MidBoss(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept {
	if (t == 5) {
		Obj.FacEmy().CreateBoss(0, Point(-20, 300), Chapter)->SetFinishFunc(
			[](StageChapter& Stage, ObjectAdaptor& CList) {Stage.Next(); }
		);
	}
}
void Stage32(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept {
	if (t == 160) {
		Obj.FacEmy().CreateEnemyEmi(60, 3, 1, Rect(400.0f, 0.0f, 440.0f, 0.0f));
		Obj.FacEmy().CreateEnemy(3, { 530.0f,0.0f });
		Obj.FacEmy().CreateEnemy(2, { 430.0f,0.0f });
	}
	if (t == 500) {
		Obj.FacEmy().CreateEnemy(5, { 100.0f,0.0f });
		Obj.FacEmy().CreateEnemy(5, { 460.0f,0.0f });
	}
	if (t == 1000)
		Chapter->Next();
}
void Stage33(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept {
	if (t == 300) {
		Obj.FacEmy().CreateEnemy(4, { 140.0f,0.0f });
		Obj.FacEmy().CreateEnemy(4, { 260.0f,0.0f });
		Obj.FacEmy().CreateEnemy(4, { 390.0f,0.0f });
		Obj.FacEmy().CreateEnemy(4, { 520.0f,0.0f });
	}
	if (t == 750) {
		Obj.FacEmy().CreateEnemyEmi(60, 3, 1, Rect(400.0f, 0.0f, 440.0f, 0.0f));
		Obj.FacEmy().CreateEnemy(3, { 530.0f,0.0f });
		Obj.FacEmy().CreateEnemy(2, { 430.0f,0.0f });
	}
	if (t == 1300) {
		Chapter->Next();
	}
}
void Stage3Talk(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept {
	if (t == 5) {
		Obj.getTalkManager().setCallBack([Chapter]() {Chapter->Next(); });
		Obj.getTalkManager().startTalkEvent();
	}
}
void Stage3Boss(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept {
	if (t == 5) {
		Obj.getAudio().stopBGM();
		Obj.getAudio().playBGM(6);
		Obj.FacEmy().CreateBoss(1, Point(-20, 300), Chapter)->SetFinishFunc(
			[](StageChapter& Stage, ObjectAdaptor& CList) {Stage.Next(); }
		);
	}
}
void Stage3Clear(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept {
	if (t == 30) {
		Obj.ObjEff().SetObject(new StageClear(240));
	}
	if (t == 320) {
		Chapter->Next();
		Obj.getAudio().stopBGM();
	}
}
