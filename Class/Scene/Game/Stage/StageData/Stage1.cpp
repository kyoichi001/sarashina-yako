
#include "Stage1.h"
#include "../StageChapter.h"

#include "../../../../../Library/3DFunc.h"
#include "../../../../../Library/Renderer.h"
#include "../../../../MediatorClass/ObjectAdaptor.h"
#include "../../../../Object/3D/3DObjects.h"
#include "../../../../Object/Effect/Effects.h"

#include "../../../../Object/Enemy/EnemyData/Enemy1.h"

using namespace DxWrp;

void Stage1Init(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept {
	SetFogColor(0, 0, 0);
	SetFogStartEnd(0, 3000);
	Obj.Obj3Ds().Kill();
	Obj.Obj3Ef().Kill();
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 4; ++j) {
			Vec3* p = nullptr;
			if (i != 1) {
				p = Obj.Obj3Ds().SetObject(new CChunk1_1({ -800.0f + j * 1500, 0.0f, -2200.0f + i * 1500 }, 0));
			}
			else {
				p = Obj.Obj3Ds().SetObject(new CChunk1_2({ -800.0f + j * 1500, 0.0f, -2200.0f + i * 1500 }, 0));
			}
			for (int k = 0; k < 4; ++k) {
				Obj.Obj3Ef().SetObject(new CGhost({ Rand(0.0f,1500.0f),Rand(0.0f,1500.0f), Rand(0.0f,1500.0f) }, 10, p));
				//Obj.Obj3Ef().SetObject(new CSnow({ Rand(0.0f,1500.0f),Rand(2000.0f,3500.0f), Rand(0.0f,1500.0f) }, 10, p));
			}
			for (int k = 0; k < 2; ++k) {
				Obj.Obj3Ef().SetObject(new CCrowd({ Rand(0.0f,1500.0f),Rand(1650.0f,2500.0f), Rand(0.0f,1500.0f) }, 10, p));
			}
		}
	}
	Obj.GetCamera().SetPosi({ 1708.0f, 1419.0f, 600.0 });
	Obj.GetCamera().SetTarg({ 681.0f, 1262.0f, 800.0 });
	//Obj.FacEff().create(new StageBack(150,30,1600));
	setBulletData1(Obj.ObjBRen(), Obj);
	Chapter->setBack(LoadGraph("Picture/Scene/Game/sky.png"));

	TalkingManager& talk = Obj.getTalkManager();
	talk.Init();
	talk.pushLeftTalker(0);
	talk.pushRightTalker(1);
	talk.pushTalk(false, "‚â‚Á‚Ù[");
	talk.pushTalk(false, "‚·‚²‚¢‚ËŒNB‚ ‚Ì—H—ì‚½‚¿‚ðö‚è”²‚¯‚Ä‚­‚é‚È‚ñ‚Ä");
	talk.pushTalk(true,  "‚¿‚å‚Á‚©‚¢‚È‚ñ‚©‚©‚¯‚Ä‚Ç‚¤‚¢‚¤‚Â‚à‚è‚¾");
	talk.pushTalk(false,  "‰É‚Â‚Ô‚µ‚É‚¯‚µ‚©‚¯‚½‚¾‚¯‚¾‚æ");
	talk.pushTalk(false,  "“~‚Í‚È‚É‚à‚â‚é‚±‚Æ‚ª–³‚­‚Ä‰É‚Å‚³[");
	talk.pushTalk(true,  "‚¨‘O‚ª—H—ì‚ðo‚µ‚Ä‚¢‚é”ÆlH");
	talk.pushTalk(true,  "Œãˆ—‚Æ‚©–Ê“|‚¾‚©‚ç‚»‚Ì‚­‚ç‚¢‚É‚µ‚Ä‚Ù‚µ‚¢‚à‚ñ‚¾‚¯‚Ç");
	talk.pushTalk(false, "¶‚Ýo‚µ‚Ä‚È‚¢‚æ[B‘€‚Á‚Ä‚é‚¾‚¯");
	talk.pushTalk(true,  "æ‚ð‚¢‚»‚¢‚Å‚¢‚é‚ñ‚Å‚Ë");
	talk.pushTalk(true,  "‚â‚ß‚È‚¢‚È‚çŽÀ—ÍsŽg‚Å‚¢‚±‚¤‚©");
	talk.pushTalk(false, "—V‚ñ‚Å‚­‚ê‚é‚È‚ç‘åŠ½Œ}‚¾‚æ");
	Obj.getAudio().playBGM(1);
	Chapter->Next();
}
void Stage10(ObjectAdaptor& Obj, StageChapter* Chapter, int t) noexcept {
	if (t == 150) {
		Obj.FacEmy().CreateEnemyEmi(20, 10, 0, Point(100, 30));
		Obj.FacEmy().CreateEnemyEmi(20, 10, 0, Point(50, 30));
	}
	if (t == 700) {
		Obj.FacEmy().CreateEnemyEmi(20, 20, 0, Point(600, 30));
		Obj.FacEmy().CreateEnemyEmi(20, 20, 0, Point(550, 30));
	}
	if (t == 1250) {
		Obj.FacEmy().CreateEnemy(1, Point(100, 30), 100);
		Obj.FacEmy().CreateEnemy(2, Point(550, 30));
	}
	if (t == 1380) {
		Obj.FacEmy().CreateEnemy(1, Point(100, 30), 100);
		Obj.FacEmy().CreateEnemy(2, Point(550, 30));
	}
	if (t == 1650) {
		Chapter->Next();
	}
}
void Stage11(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept {
	//Time==0 Title
	if (t == 10)Obj.ObjEff().SetObject(new StageTitle(Point(5.0f, 200.0f), 0));
	if (t == 300) {
		Obj.FacEmy().CreateEnemyEmi(20, 20, 0, Point(100, 30));
		Obj.FacEmy().CreateEnemyEmi(20, 20, 0, Point(50, 30));
	}
	if (t == 350) {
		Obj.FacEmy().CreateEnemy(5, Point(580, 30));
	}
	if (t == 950) {
		Obj.FacEmy().CreateEnemyEmi(20, 20, 0, Point(600, 30));
		Obj.FacEmy().CreateEnemyEmi(20, 20, 0, Point(550, 30));
	}
	if (t == 1000) {
		Obj.FacEmy().CreateEnemy(5, Point(100, 30));
	}
	if (t == 1500) {
		Chapter->Next();
	}
}
void Stage1MidBoss(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept {
	if (t == 60)
		Obj.FacEmy().CreateBoss(0, Point(-20, 300), Chapter)->SetFinishFunc(
			[](StageChapter& Stage, ObjectAdaptor& CList) {Stage.Next(); }
	);
}
void Stage12(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept {
	if (t == 50) Obj.FacEmy().CreateEnemyEmi(20, 20, 6, Point(100, 30));
	if (t == 400) Obj.FacEmy().CreateEnemyEmi(20, 20, 6, Point(550, 30));
	if (t == 800) {
		Obj.FacEmy().CreateEnemyEmi(25, 15, 4, Point(-20, Rand(70, 250)));
		Obj.FacEmy().CreateEnemyEmi(25, 15, 4, Point(670, Rand(70, 250)));
	}
	if (t == 1250) {
		Obj.FacEmy().CreateEnemy(3, Point(580, 30));
		Obj.FacEmy().CreateEnemy(3, Point(100, 30));
	}
	if (t == 1400) {
		Obj.FacEmy().CreateEnemy(3, Point(610, 30));
		Obj.FacEmy().CreateEnemy(3, Point(80, 30));
	}
	if (t == 2000) {
		Chapter->Next();
	}
}
void Stage1Talk(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept {
	if (t == 5) {
		Obj.getTalkManager().setCallBack([Chapter]() {Chapter->Next(); });
		Obj.getTalkManager().startTalkEvent();
	}
}

void Stage1Boss(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept {
	if (t == 5) {
		Obj.getAudio().stopBGM();
		Obj.getAudio().playBGM(2);

		Obj.FacEmy().CreateBoss(1, Point(-20, 300), Chapter)->SetFinishFunc(
			[](StageChapter& Stage, ObjectAdaptor& CList) {Stage.Next(); }
		);
	}
}
void Stage1Clear(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept {
	if (t == 30) {
		Obj.ObjEff().SetObject(new StageClear(240));
	}
	if (t == 320) {
		Obj.getAudio().stopBGM();
		Chapter->Next();
	}
}