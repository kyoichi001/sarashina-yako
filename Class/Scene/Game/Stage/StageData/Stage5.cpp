
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
	talk.pushTalk(true, "���[�A��������");
	talk.pushTalk(true, "�����ɂ��̐l������񂾂����H");
	talk.pushTalk(true, "�����ɋ��͂��Ăق����Ƃ͌����Ă����c");
	talk.pushTalk(false, "���Ă��āA����Ɨ����̂ˁH");
	talk.pushTalk(false, "�������\�����x��Ă邩��ǂ������̂��Ǝv����");
	talk.pushTalk(true, "������Ɠ��ɖ����Ă�");
	talk.pushTalk(true, "���Ǔ��ē������Ă������");
	talk.pushTalk(false, "(������Ɓc�H)");
	talk.pushTalk(true, "����ŁA���ǉ��̂�鎖���āH");
	talk.pushTalk(false, "�����A��������");
	talk.pushTalk(false, "�������������������Ă���̂͌N�̎��͂Ȃ�");
	talk.pushTalk(false, "����܂ŗ�����Ȃ��s�v�c�ȗ́c");
	talk.pushTalk(false, "�N�̑̂̒��ɉ��������Ă���̂��������Ăق�����");
	talk.pushTalk(true, "���̗́c");
	talk.pushTalk(true, "���̗͂Ȃ�ċ���������������x������");
	talk.pushTalk(false, "����Ȃ��Ƃ͂Ȃ��B�g��������ŉ��ł��ł���");
	talk.pushTalk(false, "�������͂����l������");
	talk.pushTalk(true, "���A�����̂ɂ����̂��H");
	talk.pushTalk(false, "����A������Ɨ͂��g���Ƃ���������Ăق�������");
	talk.pushTalk(false, "���Ⴀ������I");
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
