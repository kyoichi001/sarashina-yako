
#include "Stage2.h"

#include "../StageChapter.h"

#include "../../../../../Library/3DFunc.h"
#include "../../../../MediatorClass/ObjectAdaptor.h"
#include "../../../../Object/3D/3DObjects.h"
#include "../../../../Object/Effect/Effects.h"

#include "../../../../Object/Enemy/EnemyData/Enemy2.h"

using namespace DxWrp;

void Stage2Init(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept {
	Obj.Obj3Ds().Kill();
	Obj.Obj3Ef().Kill();
	SetFogColor(0, 0, 0);
	SetFogStartEnd(700, 3800);
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 4; ++j) {
			Vec3 chunkCood = { -800.0f + j * 1500, 0.0f, -2200.0f + i * 1500 };
			Vec3* p = Obj.Obj3Ds().SetObject(i == 1 ? (I3D*)new CChunk1_2(chunkCood, 0) : (I3D*)new CChunk2(chunkCood, 0));
			for (int k = 0; k < 4; ++k) {
				Obj.Obj3Ef().SetObject(new CSnow({ Rand(0.0f,1500.0f),Rand(2000.0f,3500.0f), Rand(0.0f,1500.0f) }, 10, p));
			}
			for (int k = 0; k < 2; ++k) {
				Obj.Obj3Ef().SetObject(new CCrowd({ Rand(0.0f,1500.0f),Rand(1650.0f,2500.0f), Rand(0.0f,1500.0f) }, 10, p));
			}
		}
	}
	//for (int i = 0; i < 5; ++i)Obj.Obj3Ds().SetObject(new CChunk2( { -200.0f + i * 1500, 0.0f, -700.0f },0));
	Obj.GetCamera().SetPosi({ 1108.0f, 1119.0f, 600.0 });
	Obj.GetCamera().SetTarg({ 81.0f, 962.0f, 800.0 });
	setBulletData2(Obj.ObjBRen(), Obj);
	Obj.getAudio().playBGM(3);
	TalkingManager& talk = Obj.getTalkManager();
	talk.Init();
	talk.pushLeftTalker(0);
	talk.pushRightTalker(2);
	talk.pushTalk(true, "���[��A�܂����");
	talk.pushTalk(true, "�ړI�n�͋߂��͂��Ȃ񂾂��ǂ�");
	talk.pushTalk(false, "������Ƃ�����");
	talk.pushTalk(false, "�ڂ̑O��������イ���؂���Ǝ�i�̎ז�����");
	talk.pushTalk(false, "���Ă����Ȃ��Ȃ痧�������Ă��炤��");
	talk.pushTalk(true, "���ɂ܂����������");
	talk.pushTalk(true, "������ւ�̌������ɍs�������񂾂���");
	talk.pushTalk(false, "����Ȃ炠�����̕�����");
	talk.pushTalk(true, "�����A�ǂ���");
	talk.pushTalk(true, "���ꂶ��");
	talk.pushTalk(false, "������Ƒ҂���");
	talk.pushTalk(false, "�U�X�ז����ꂽ�񂾁B�����͎x�����Ă����Ȃ��Ƃ�");
	talk.pushTalk(true, "����");
	Chapter->Next();
}

void Stage20(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept {
	if (t == 150) {
		Obj.FacEmy().CreateEnemyEmi(24, 8, 0, Rect(-20.0f, 28.0f, 25.0f, 160.0f));
		Obj.FacEmy().CreateEnemyEmi(24, 8, 1, Rect(-20.0f, 28.0f, 25.0f, 160.0f));
	}
	if (t == 450) {
		Obj.FacEmy().CreateEnemyEmi(24, 8, 0, Rect(630.0f, 28.0f, 650.0f, 160.0f));
		Obj.FacEmy().CreateEnemyEmi(24, 8, 1, Rect(630.0f, 28.0f, 650.0f, 160.0f));
	}
	if (t == 950) {
		Obj.FacEmy().CreateEnemy(2, Point(70.0f, 80.0f));
		Obj.FacEmy().CreateEnemy(2, Point(580.0f, 80.0f));
	}
	if (t == 1420) {
		Obj.FacEmy().CreateEnemy(2, Point(70.0f, 80.0f));
		Obj.FacEmy().CreateEnemy(2, Point(580.0f, 80.0f));
	}
	if (t == 1530) {
		Chapter->Next();
	}
}
void Stage21(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept {
	//Time==0 Title
	if (t == 10)Obj.ObjEff().SetObject(new StageTitle(Point(5.0f, 200.0f), 1));
	if (t == 270) {
		Obj.FacEmy().CreateEnemyEmi(24, 7, 0, Rect(-20.0f, 28.0f, 25.0f, 160.0f));
		Obj.FacEmy().CreateEnemyEmi(24, 7, 1, Rect(-20.0f, 28.0f, 25.0f, 160.0f));
	}
	if (t == 420) {
		Obj.FacEmy().CreateEnemy(3, Point(580, 30));
	}
	if (t == 570) {
		Obj.FacEmy().CreateEnemyEmi(24, 7, 0, Rect(630.0f, 28.0f, 650.0f, 160.0f));
		Obj.FacEmy().CreateEnemyEmi(24, 7, 1, Rect(630.0f, 28.0f, 650.0f, 160.0f));
	}
	if (t == 720) {
		Obj.FacEmy().CreateEnemy(3, Point(100, 30));
	}
	if (t == 1070) {
		Obj.FacEmy().CreateEnemyEmi(24, 7, 0, Rect(630.0f, 28.0f, 650.0f, 160.0f));
		Obj.FacEmy().CreateEnemyEmi(24, 7, 1, Rect(630.0f, 28.0f, 650.0f, 160.0f));
	}
	if (t == 1170) {
		Obj.FacEmy().CreateEnemy(3, Point(100, 30));
	}
	if (t == 1400) {
		Obj.FacEmy().CreateEnemy(2, Point(70.0f, 80.0f));
		Obj.FacEmy().CreateEnemy(2, Point(580.0f, 80.0f));
	}
	if (t == 1800) {
		Obj.FacEmy().CreateEnemy(2, Point(70.0f, 80.0f));		
		Obj.FacEmy().CreateEnemy(2, Point(620.0f, 80.0f));
		Obj.FacEmy().CreateEnemy(2, Point(580.0f, 80.0f));
	}
	if (t == 2340) {
		Chapter->Next();
	}
}
void Stage2MidBoss(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept {
	if (t == 5) {
		Obj.FacEmy().CreateBoss(0, Point(-20, 300), Chapter)->SetFinishFunc(
			[](StageChapter& Stage, ObjectAdaptor& CList) {Stage.Next(); }
		);
	}
}
void Stage22(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept {
	if (t == 5) {
		Obj.FacEmy().CreateEnemyEmi(24, 7, 4, Rect(630.0f, 28.0f, 650.0f, 160.0f));
		Obj.FacEmy().CreateEnemy(5, { 120.0f,0.0f });
	}
	if (t == 300) {
		Obj.FacEmy().CreateEnemyEmi(24, 7, 4, Rect(-20.0f, 28.0f, 25.0f, 160.0f));
		Obj.FacEmy().CreateEnemy(5, { 480.0f,0.0f });
	}
	if (t == 700) {
		Obj.FacEmy().CreateEnemyEmi(24, 7, 0, Rect(-20.0f, 28.0f, 25.0f, 160.0f));
		Obj.FacEmy().CreateEnemyEmi(24, 7, 1, Rect(-20.0f, 28.0f, 25.0f, 160.0f));
	}
	if (t == 960) {
		Obj.FacEmy().CreateEnemyEmi(24, 7, 0, Rect(630.0f, 28.0f, 650.0f, 160.0f));
		Obj.FacEmy().CreateEnemyEmi(24, 7, 1, Rect(630.0f, 28.0f, 650.0f, 160.0f));
	}
	if (t == 1390) {
		Obj.FacEmy().CreateEnemy(6, { 120.0f,0.0f });
		Obj.FacEmy().CreateEnemy(6, { 480.0f,0.0f });
	}
	if (t == 1600) {
		Obj.FacEmy().CreateEnemy(6, { 150.0f,0.0f });
		Obj.FacEmy().CreateEnemy(6, { 420.0f,0.0f });
	}
	if (t == 2000) {
		Chapter->Next();
	}
}
void Stage2Talk(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept {
	if (t == 5) {
		Obj.getTalkManager().setCallBack([Chapter]() {Chapter->Next(); });
		Obj.getTalkManager().startTalkEvent();
	}
}
void Stage2Boss(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept {
	if (t == 5) {
		Obj.getAudio().stopBGM();
		Obj.getAudio().playBGM(4);
		Obj.FacEmy().CreateBoss(1, Point(-20, 300), Chapter)->SetFinishFunc(
			[](StageChapter& Stage, ObjectAdaptor& CList) {Stage.Next(); }
		);
	}
}
void Stage2Clear(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept {
	if (t == 30) {
		Obj.ObjEff().SetObject(new StageClear(240));
	}
	if (t == 320) {
		Chapter->Next();
		Obj.getAudio().stopBGM();
	}
}