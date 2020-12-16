
#include "Stage5.h"

#include "../StageChapter.h"

#include "../../../../../Library/3DFunc.h"
#include "../../../../MediatorClass/ObjectAdaptor.h"
#include "../../../../Object/3D/3DObjects.h"
#include "../../../../Object/Effect/Effects.h"

#include "../../../../Object/Enemy/EnemyData/Enemy5.h"

using namespace DxWrp;

void Stage5Init(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept{
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
	setBulletData5(Obj.ObjBRen(), Obj);
	Obj.getAudio().playBGM(9);
	TalkingManager& talk = Obj.getTalkManager();
	talk.Init();
	talk.pushLeftTalker(0);
	talk.pushRightTalker(5);
	talk.pushTalk(true, "あー、長かった");
	talk.pushTalk(true, "ここにあの人がいるんだっけ？");
	talk.pushTalk(true, "研究に協力してほしいとは言ってたが…");
	talk.pushTalk(false, "さてさて、やっと来たのね？");
	talk.pushTalk(false, "もう何十分も遅れてるからどうしたのかと思った");
	talk.pushTalk(true, "ちょっと道に迷ってね");
	talk.pushTalk(true, "結局道案内させてもらった");
	talk.pushTalk(false, "(ちょっと…？)");
	talk.pushTalk(true, "それで、結局俺のやる事って？");
	talk.pushTalk(false, "ああ、そうそう");
	talk.pushTalk(false, "私たちが興味を持っているのは君の持つ力なの");
	talk.pushTalk(false, "これまで例を見ない不思議な力…");
	talk.pushTalk(false, "君の体の中に何が眠っているのか見させてほしいの");
	talk.pushTalk(true, "俺の力…");
	talk.pushTalk(true, "俺の力なんて金属をいじくる程度だけど");
	talk.pushTalk(false, "そんなことはない。使い方次第で何でもできる");
	talk.pushTalk(false, "私たちはそう考えたわ");
	talk.pushTalk(true, "俺、実験体にされるのか？");
	talk.pushTalk(false, "いや、ちょっと力を使うところを見せてほしいだけ");
	talk.pushTalk(false, "じゃあいくよ！");
	Chapter->Next();
}

void Stage50(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept{
	for (int i = 0; i < 10; i++) {
		if (t == 30+i*105) {
			Obj.FacEmy().CreateEnemy(0, Point{ Rand(140.0f,500.0f),0.0f });
			Obj.FacEmy().CreateEnemy( 0, Point{ Rand(140.0f,500.0f),0.0f });
		}
	}
	if (t == 1420) {
		Chapter->Next();
	}
}

void Stage51(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept{
	for (int i = 0; i < 3; i++) {
		if (t == 30 + i * 200) {
			Obj.FacEmy().CreateEnemy(1, Point{ Rand(140.0f,500.0f),70.0f });
			Obj.FacEmy().CreateEnemy(1, Point{ Rand(140.0f,500.0f),70.0f });
		}
	}
	if (t ==720) {
		Chapter->Next();
	}
}

void Stage5MidBoss(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept {
	if (t == 5) {
		Obj.FacEmy().CreateBoss(0, Point(-20, 300), Chapter)->SetFinishFunc(
			[](StageChapter& Stage, ObjectAdaptor& CList) {Stage.Next(); }
		);
	}
}

void Stage52(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept{
	if (t == 120) {
		Obj.FacEmy().CreateEnemyEmi(70, 4, 1, Point{ 150.0f,0.0f });
	}
	if (t == 470) {	
		Obj.FacEmy().CreateEnemyEmi(70, 4, 0, Point{ 400.0f,0.0f });
	}
	if (t == 820) {
		Chapter->Next();
	}
}

void Stage5Talk(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept {
	if (t == 5) {
		Obj.ObjBul().Kill();
		Obj.ObjEmy().Kill();
		Obj.getTalkManager().setCallBack([Chapter]() {Chapter->Next(); });
		Obj.getTalkManager().startTalkEvent();
	}
}
void Stage5Boss(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept{
	if (t == 5) {
		Obj.getAudio().stopBGM();
		Obj.getAudio().playBGM(10);
		Obj.FacEmy().CreateBoss(1, Point(-20, 300), Chapter)->SetFinishFunc(
			[](StageChapter& Stage, ObjectAdaptor& CList) {Stage.Next(); }
		);
	}
}

void Stage5Clear(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept {
	if (t == 120) {
		clearFlag = true;
		Chapter->Next();
		Obj.getAudio().stopBGM();
	}
}
