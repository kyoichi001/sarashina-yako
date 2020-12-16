
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
	talk.pushTalk(false, "����ف[");
	talk.pushTalk(false, "�������ˌN�B���̗H�삽������蔲���Ă���Ȃ��");
	talk.pushTalk(true,  "����������Ȃ񂩂����Ăǂ��������肾");
	talk.pushTalk(false,  "�ɂԂ��ɂ�����������������");
	talk.pushTalk(false,  "�~�͂Ȃɂ���邱�Ƃ������ĉɂł��[");
	talk.pushTalk(true,  "���O���H����o���Ă���Ɛl�H");
	talk.pushTalk(true,  "�㏈���Ƃ��ʓ|�����炻�̂��炢�ɂ��Ăق������񂾂���");
	talk.pushTalk(false, "���ݏo���ĂȂ���[�B�����Ă邾��");
	talk.pushTalk(true,  "����������ł����ł�");
	talk.pushTalk(true,  "��߂Ȃ��Ȃ���͍s�g�ł�������");
	talk.pushTalk(false, "�V��ł����Ȃ�劽�}����");
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