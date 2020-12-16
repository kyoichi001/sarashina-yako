
#include "Stage4.h"

#include "../StageChapter.h"

#include "../../../../../Library/3DFunc.h"
#include "../../../../MediatorClass/ObjectAdaptor.h"
#include "../../../../Object/3D/3DObjects.h"
#include "../../../../Object/Effect/Effects.h"

#include "../../../../Object/Enemy/EnemyData/Enemy4.h"

using namespace DxWrp;

void Stage4Init(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept {
	Obj.Obj3Ds().Kill();
	Obj.Obj3Ef().Kill();
	SetFogColor(0, 0, 0);
	SetFogStartEnd(700, 3800);
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
	setBulletData4(Obj.ObjBRen(), Obj);
	Obj.getAudio().playBGM(7);
	TalkingManager& talk = Obj.getTalkManager();
	talk.Init();
	talk.pushLeftTalker(0);
	talk.pushRightTalker(4);
	talk.pushTalk(false, "ちょっと、いつまで同じとこ回ってんの");
	talk.pushTalk(true, "あ、さっき見かけた人");
	talk.pushTalk(false, "方向音痴にもほどがあるでしょ");
	talk.pushTalk(true, "この研究所なんかどこ行っても");
	talk.pushTalk(true, "同じ景色だから…");
	talk.pushTalk(false, "もう待ちくたびれたからこっちから来てやったよ");
	talk.pushTalk(true, "それはありがたい");
	talk.pushTalk(false, "あの人にデータを取るように言われてるから");
	talk.pushTalk(false, "案内する前に実力を見させてもらうよ");
	talk.pushTalk(true, "えーなんかそればっかり");
	talk.pushTalk(true, "さっきの白い人にもそんなこと言われた");
	talk.pushTalk(false, "…君、あのお方と話したの？");
	talk.pushTalk(false, "普段客に姿見せないはずなのに…");
	talk.pushTalk(true, "えーと？");
	talk.pushTalk(false, "とにかく、さっさとやる！");
	talk.pushTalk(false, "いくよ！");
	Chapter->Next();
}

void Stage40(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept {
	if (t == 120) {
		Obj.FacEmy().CreateEnemyEmi(30, 10, 0, Point{ 150.0f,0.0f });
		Obj.FacEmy().CreateEnemyEmi(30,10,0, Point{ 220.0f,0.0f });
	}
	if (t == 470) {
		Obj.FacEmy().CreateEnemyEmi(30, 10, 0, Point{ 400.0f,0.0f });
		Obj.FacEmy().CreateEnemyEmi(30, 10, 0, Point{ 480.0f,0.0f });
	}
	if (t == 820) {
		Chapter->Next();
	}
}

void Stage41(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept {
	if (t == 100) {
		Obj.FacEmy().CreateEnemy(1, { 90.0f,0.0f });
		Obj.FacEmy().CreateEnemy(1, { 470.0f,0.0f });
	}
	if (t == 400) {
		Obj.FacEmy().CreateEnemy(1, { 280.0f,0.0f });
		Obj.FacEmy().CreateEnemy(1, { 500.0f,0.0f });
	}
	if(t==700){
		Obj.FacEmy().CreateEnemy(1, { 470.0f,0.0f });
		Obj.FacEmy().CreateEnemy(1, { 170.0f,0.0f });
	}
	if (t == 1250) {
		Obj.FacEmy().CreateEnemy(2, { 280.0f,0.0f });
		Obj.FacEmy().CreateEnemy(2, { 470.0f,0.0f });
	}
	if (t == 1400) {
		Chapter->Next();
	}
}

void Stage42(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept {
	for (int i = 0; i < 5; ++i) {
		if (t == 5 + 180 * i) {
			Obj.FacEmy().CreateEnemy(3, { Rand(80.0f,520.0f),0.0f });
			Obj.FacEmy().CreateEnemy(3, { Rand(80.0f,520.0f),0.0f });
		}
	}
	for (int i = 0; i < 5; ++i) {
		if (t == 905 + 180 * i) {
			Obj.FacEmy().CreateEnemy(4, { Rand(80.0f,520.0f),0.0f });
			Obj.FacEmy().CreateEnemy(4, { Rand(80.0f,520.0f),0.0f });
		}
	}
	if (t == 2080) {
		Chapter->Next();
	}
}

void Stage43(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept {
	for (int i = 0; i < 100; ++i) {
		if (t == 5 + 17 * i) {
			Obj.FacEmy().CreateEnemy(5, { Rand(35.0f,60.0f),Rand(15.0f,680.0f) });
			Obj.FacEmy().CreateEnemy(5, { Rand(35.0f,60.0f),Rand(15.0f,680.0f) });
			Obj.FacEmy().CreateEnemy(5, { Rand(580.0f,620.0f),Rand(20.0f,685.0f) });
			Obj.FacEmy().CreateEnemy(5, { Rand(580.0f,620.0f),Rand(20.0f,685.0f) });
		}
	}
	for (int i = 0; i < 80; ++i) {
		if (t == 1780 + 22 * i) {
			Obj.FacEmy().CreateEnemy(6, { Rand(30.0f,620.0f),Rand(15.0f,40.0f) });
			Obj.FacEmy().CreateEnemy(6, { Rand(30.0f,620.0f),Rand(15.0f,40.0f) });
			Obj.FacEmy().CreateEnemy(6, { Rand(30.0f,620.0f),Rand(650.0f,685.0f) });
			Obj.FacEmy().CreateEnemy(6, { Rand(30.0f,620.0f),Rand(650.0f,685.0f) });
		}
	}
	if (t == 3750) {
		Chapter->Next();
	}
}

void Stage4Talk(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept {
	if (t == 5) {
		Obj.getTalkManager().setCallBack([Chapter]() {Chapter->Next(); });
		Obj.getTalkManager().startTalkEvent();
	}
}
void Stage4Boss(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept {
	if (t == 5) {
		Obj.getAudio().playBGM(8);
		Obj.FacEmy().CreateBoss(0, Point(-20, 300), Chapter)->SetFinishFunc(
			[](StageChapter& Stage, ObjectAdaptor& CList) {Stage.Next(); }
		);
	}
}

void Stage4Clear(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept {
	if (t == 30) {
		Obj.ObjEff().SetObject(new StageClear(240));
	}
	if (t == 320) {
		Chapter->Next();
		Obj.getAudio().stopBGM();
	}
}
