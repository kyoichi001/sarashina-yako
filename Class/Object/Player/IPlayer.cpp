
#include "IPlayer.h"
#include "../../../Data/Resource.h"
#include "../../../Library/Func.h"
#include "../../../Library/Color/ColorData.h"

#include "../../../Library/GUI/GUI.h"
#include "../../../Library/GUI/Widget.h"

#include "../../../Library/Math/Constant.h"
#include "../../../Library/Math/Collision.h"
#include "../../MediatorClass/ObjectAdaptor.h"
#include "../Effect/Effects.h"
#include "Bom/Bom.h"

ObjectAdaptor* IPlayer::mObj = nullptr;

IPlayer::IPlayer() noexcept:
Circle(playerDefault, 3), mHP(40), mTime(0), mHitTime(0), mHitFlag(false),
mShoot1Interval(12), mSubWeapon(32), mScore(0), mBuf(this) , mSlowFlag(true){}

bool IPlayer::Update()noexcept {
	++mTime;
	mOptionZ.Update();
	mOptionX.Update();
	if (mHitFlag) {
		++mHitTime;
		if (mHitTime > 100) {
			mHitFlag = false;
			mHitTime = 0;
		}
	}

	//if (p.y < WALL_Y1 + 150) {
	//	mPlayer->gatherItem();
	//}
	mBuf.Update();
	return mHP > 0;
}

void IPlayer::Draw()const noexcept {
	mBuf.Draw();
}
void IPlayer::Shoot1()noexcept {
	if (mTime % mShoot1Interval == 0) {
		for (auto&i : mOptionZ)
			i->Shoot();
	}
}
void IPlayer::Shoot2()noexcept {
	if (mSubWeapon >= 16) {
		for (auto&i : mOptionX)
			i->Shoot();
		mSubWeapon -= 16;
	}
}
void IPlayer::Slow()noexcept {
	mSlowFlag = true;
	mBuf.RegisterPost("core", new PlayerCore(&p, &mSlowFlag));
}
void IPlayer::Fast()noexcept {
	mSlowFlag = false;
}

void IPlayer::Hit()noexcept {
	mObj->ObjBom().SetObject(new PlayerHitBom(p));
	mObj->ObjEff().SetObject(new PlayerHit(p, { Rand(0.0f,PI2 / 3), 5.0f,0 }, 30));
	mObj->ObjEff().SetObject(new PlayerHit(p, { Rand(PI2 / 3, PI4 / 3), 5.0f,0 }, 30));
	mObj->ObjEff().SetObject(new PlayerHit(p, { Rand(PI4 / 3,PI2), 5.0f,0 }, 30));
}

void  IPlayer::setGameScore(GUI& gui)noexcept {
	const WidgetFont scoreFont = { Font01,WHITE ,WHITE };
	gui.Push(new Viewer<int>("Score", scoreFont, &mScore));
	gui.Push(new Gauze<char>("HP", scoreFont, &mHP, 40));
	gui.Push(new Gauze<char>("Sub Weapon", scoreFont, &mSubWeapon, 100));
}

void  IPlayer::Damage(int damage)noexcept {
	if (!mHitFlag) {
		Hit();
		mHP -= damage;
		if (mHP <= 0) {
			gameoverFlag = true;
		}
		if (mSubWeapon <= 30) {
			mSubWeapon = 30;
		}
		mHitFlag = true;
	}
}

void IPlayer::AddSubWeapon(char subWeapon)noexcept {
	mSubWeapon += subWeapon; 
	if (mSubWeapon > 100)mSubWeapon = 100;
}

void IPlayer::SetAdaptor(ObjectAdaptor* Adaptor)noexcept {mObj = Adaptor;}

void IPlayer::Collided( IGhost& obj){
	if (IsHit(*this,obj)) {
		obj.Damage(10);
		Damage(3);
	}
}
void IPlayer::Collided( IBoss& obj){
	if (IsHit(*this, obj)) {
		obj.Damage(10);
		Damage(3);
	}
}
void IPlayer::Collided( IBullet& obj){
	if (IsHit(*this, obj)) {
		obj.Kill();
		Damage(5);
	}
}
void IPlayer::Collided( IItem& obj){
	/*if (IsHit(*this, obj)) {
		Hit();

	}*/
}
void IPlayer::Collided(ILeazer& obj) {
	if (IsHit(*this, obj.getasSegment())&&obj.IsActive()) {
		Damage(5);
	}
}
void IPlayer::Collided(ILeazer2& obj) {
	if (IsHit(*this, obj)) {
		Damage(5);
	}
}
#include "../../../Library/Math/Geometory.h"
#ifdef _DEBUG

class ELine :public IEffect {
	Segment mSeg;
public:
	ELine(const Segment& seg, int Duration)noexcept : IEffect(seg.begin, Duration), mSeg(seg) {

	}
	bool Update(float t)noexcept override {
		++mTime;
		return mTime<mLifeTime;
	}
	void Draw()const noexcept override {
		DxWrp::DrawLine(mSeg.begin,mSeg.end, 0xFFFFFF, 3);
	}
};
#include "DxLib.h"
void IPlayer::DrawDebug(int X, int Y) const noexcept {
	DrawLine(p.x, 0,p.x, 720, GREEN);
	DrawLine(0,p.y, 960, p.y, RED);
	draw(WHITE, false);
//	DrawFormatString(p.x + 40, p.y + 40, WHITE,"HitOK");
	//DrawFormatString(p.x + 120, p.y + 40, WHITE, HitOK ? "true" : "false");
	DxLib::DrawFormatString(p.x + 40, p.y + 60, WHITE,  "Time = %d",mTime);
	//DrawFormatString(p.x + 40, p.y + 80, WHITE, "BomLiveFlag");
	//DrawFormatString(p.x + 180, p.y + 80, WHITE, BomLiveFlag ? "true" : "false");
	Point EnemyB = mObj->FacEmy().GetShortestPoint(p);
	DrawLine(p.x, p.y, EnemyB.x, EnemyB.y, BLUE);
}
void IPlayer::setDebugGUI(GUI& gui)noexcept {
	gui.GetWidget<Tab>("tab1").Push(new Viewer<Circle>("Player", { Font01,WHITE,GREY }, this));
	gui.GetWidget<Tab>("tab1").Push(new Viewer<bool>("HitFlag", {Font01,WHITE,GREY}, &mHitFlag));
}

#endif