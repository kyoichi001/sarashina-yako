
#include "IBoss.h"
#include "../Player/Bom/Bom.h"
//#include "../Item/ItemData.h"
#include "../../MediatorClass/ObjectAdaptor.h"
#include "../../../Library/Func.h"
#include "../../../Library/Renderer.h"
#include "../../../Library/Math/Geometory.h"
#include "../../../Library/Math/Constant.h"
#include "../Effect/Effects.h"
#include "BossData.h"

using namespace DxWrp;
ObjectAdaptor* IBoss::mCList = nullptr;

IBoss:: ~IBoss()noexcept {}
IBoss::IBoss(const Point& P, BossData* Data, StageChapter* Stage) noexcept
	: Circle(P, Data->radius), mHP(Data->MaxHP), mData(Data), mStage(Stage), DefencePer(1.0f), mChapter(Data->Func), mTime(0), mState(0),mDrawer(this) {
	mCList->FacEmy().RemoveNomalEnemy();
	mCList->FacBul().clear_emi();
	mDrawer.RegisterPost("Back",new EnemyBack(&p, mData->BackHdl));
	mDrawer.RegisterPost("HP",new EnemyHP(&p, &mHP, mData->MaxHP));
	mDrawer.RegisterPost("Marker",new EnemyMarker(&p));
	if (!mData->EscapeFlag) {
		mDrawer.RegisterPre("Name",new EnemyName(&mData->Name[0]));
		mCList->ObjEff().SetObject(new BattleStart(60));
	}
}

void IBoss::Finalize()noexcept {
	mState = 4;
	mFunc(*mStage, *mCList);
	if (!mData->EscapeFlag) {
		mCList->FacBul().clear_emi();
		Point Cood = p;
		mCList->ObjEmi().SetObject(new Emitter(
			[Cood]() {
			mCList->ObjEff().SetObject(new EnemyBreak(Cood, { Rand(PI), 6.0f ,0 }, 10));
			mCList->ObjEff().SetObject(new EnemyBreak(Cood, { Rand(PI), 6.0f ,0 }, 10));
		}, 2, 6));
	}
	mCList->GetPlayer()->addScore(2000);
}

void IBoss::Draw()const noexcept {
	mDrawer.Draw();
}

bool IBoss::Update(float t)noexcept {
	if (mState == 4) return false;
	if (mChapter.IsFinished()) {
		Finalize();
		return false;
	}
	mDrawer.Update();
	mChapter.Update(this, *mCList, t);
	mMoveEase.Update();
	++mTime;
	return true;
}
void IBoss::MoveNext()noexcept {
	Next();
}

void IBoss::pushMoveFunc(boss_func Obj)noexcept { mChapter.PushMoveFunc(Obj); }

void  IBoss::drawPlane()const noexcept {
	DrawRotaGraph(p, 1.0, 0.0, mData->Hdl);
}
void IBoss::Damage(int damage)noexcept {
	if (mState != 1) return;
	int d_HP = float(damage)*(1.0f - DefencePer);
	mHP -= d_HP;
	mCList->ObjEff().SetObject(new EnemyDamage(p, d_HP));
	if (mHP <= 0) {
		Next();
	}
}
void IBoss::SetMovePoint(const Point& P, int Time, EasingFunc Easing)noexcept {
	mMoveEase.Init(&p, p, P, Time, Easing);
}
void IBoss::Next()noexcept {
	mState = 1;
	mHP = mData->MaxHP;
	mChapter.Next();
	mCList->ObjBom().SetObject(new EnemyNext(p));
	mCList->FacEmy().RemoveNomalEnemy();
	mCList->FacBul().clear_emi();
}
void IBoss::Start()noexcept {
	mState = 1;
	DefencePer = 0.0f;
	Next();
}

void MoveAppear(IBoss* Obj, ObjectAdaptor& List, int t)noexcept {//mState==0
	if (t < 60) {
		Obj->p.x = lerp(800.0f, 350.0f, 0, 60, t, Ease<Liner>::In);
		Obj->p.y = lerp(-100.0f, 250.0f, 0, 60, t, Ease<Liner>::In);
	}
	else {
		Obj->mState = Obj->mData->EscapeFlag ? 1 : 7;
		Obj->Start();
	}
}
void MoveEscape(IBoss* Obj, ObjectAdaptor& List, int t) noexcept {//mState==5
	if (t == 5) {
		Obj->mCList->FacBul().clear_emi();
		Obj->mCList->ObjEmi().SetObject(new Emitter(
			[Obj]() {
			float Ang = Rand(PI);
			Obj->mCList->ObjEff().SetObject(new EnemyBreak(Obj->p, { Rand(PI), 6.0f ,0 }, 30));
			Obj->mCList->ObjEff().SetObject(new EnemyBreak(Obj->p, { Rand(PI), 6.0f ,0 }, 30));
		}, 2, 6));
		Obj->mState = 5;
	}
	else if (t > 130) {
		Obj->p.x += 15;
		Obj->p.y -= 15;
	}
	if (t > 150) {
		Obj->mChapter.Next();
	}
}

#ifdef _DEBUG
#include "DxLib.h"
#include "../../../Library/Color/ColorData.h"

void IBoss::DrawDebug()const noexcept {
	DxLib::DrawFormatString(p.x + 50, p.y + 70, WHITE, "time %f", mTime);
	DxLib::DrawFormatString(p.x + 50, p.y + 85, WHITE, "chaptermany %d", mChapter.GetChapterMany());
	DxLib::DrawFormatString(p.x + 50, p.y + 100, WHITE, "chapter %d", mChapter.GetNowChapter());
	DxLib::DrawFormatString(p.x + 50, p.y + 115, WHITE, "chapter time %f", mChapter.GetTime());
	DxLib::DrawFormatString(p.x + 50, p.y + 130, WHITE, "state %d", mState);
	DxLib::DrawFormatString(p.x + 50, p.y + 145, WHITE, "HP %d", mHP);
	DxLib::DrawFormatString(p.x + 50, p.y + 160, WHITE, "MaxHP %d", mData->MaxHP);
	DxLib::DrawFormatString(p.x + 50, p.y + 175, WHITE, "DEF %3.2f", DefencePer);
	DxLib::DrawFormatString(p.x + 50, p.y + 190, WHITE, "EscapeFlag");
	DxLib::DrawFormatString(p.x + 150, p.y + 190, WHITE, mData->EscapeFlag ? "true" : "false");
}
#endif