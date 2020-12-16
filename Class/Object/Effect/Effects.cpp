
#include "Effects.h"

#include <math.h>

#include "../../../Library/Func.h"
#include "../../../Library/Easing/InterpolationMethod.h"
#include "../../../Library/Renderer.h"
#include "../../../Library/Math/Constant.h"
#include "../../../Library/Color/ColorData.h"

#include "../../../Data/DATA.h"
#include "../../../Data/Resource.h"

using namespace DxWrp;

int stageTitleHdl, stageTitleNumHdl[5];
void LoadEffectResource()noexcept {
	stageTitleHdl = LoadGraph("Picture/Scene/Game/StageTitle.png");
	LoadDivGraph("Picture/Scene/Game/StageNum.png",5,5,1,128,128,stageTitleNumHdl);
}

//===========================================================================================================================
//
//bullet 
//
//===========================================================================================================================

BulletEffect::BulletEffect(const Point& XY,  BulletColor Color) noexcept :
IEffect(XY, 7), mExRate(2.0f), mColor(Color){}

bool BulletEffect::Update(float t) noexcept {
	mExRate -= 1.0f / mLifeTime;
	mLiveFlag = mExRate > 0.5f;
	//++mTime;
	return mLiveFlag;
}

void BulletEffect::Draw()const noexcept {
	SetBlendModeAlpha(lerp(200,170,0,mLifeTime,mTime,Ease<Liner>::In));
	{
		DrawRotaGraph(*this, mExRate, 0.0f, BulletEffectHdl[mColor]);
	}
	ResetBlendMode();
}

BulletBreak::BulletBreak(const Point& XY, float ExRate, int LifeTime, BulletColor Color) noexcept:
IEffect(XY, LifeTime), mExRate(ExRate), mColor(Color) {}

bool BulletBreak::Update(float t) noexcept {
	mExRate = lerp(2.0f, 0.5f, 0, mLifeTime, mTime, Ease<Liner>::In);
	++mTime;
	mLiveFlag = mTime <= mLifeTime;
	return mLiveFlag;
}

void BulletBreak::Draw()const  noexcept {
	//	SetDrawBlendMode(DX_BLENDMODE_ADD, lerp(255, 0, 0, mLifeTime, mTime, Ease<Liner>::In));
	SetDrawBlendMode(BLEND_ADD, 255);
	{
		DrawRotaGraph(*this, mExRate, 0.0f, BulletEffectHdl[mColor]);
	}
	ResetBlendModeAdd();
}

//===========================================================================================================================
//
//enemy 
//
//===========================================================================================================================

EnemyBreak::EnemyBreak(const Point& XY, const Vec2& Speed,  int LifeTime) noexcept:
IEffect(XY, LifeTime), mSpeed(Speed), mHdlAngle(0.0f){}

bool EnemyBreak::Update(float t)noexcept {
	*this += mSpeed;
	mHdlAngle += 0.03f;
	mExRate = lerp(0.0f, 2.0f, 0, mLifeTime, mTime, Ease<Liner>::In);
	++mTime;
	mLiveFlag = mTime <= mLifeTime;
	return mLiveFlag;
}

void EnemyBreak::Draw()const  noexcept {
	SetBlendModeAlpha(lerp(255, 0, 0, mLifeTime, mTime, Ease<Liner>::In));
	{
		DrawRotaGraph(*this, mExRate+2.0f, mHdlAngle, EnemyBreakHdl);
	}
	ResetBlendMode();
}

BossBreak::BossBreak(const Point& XY, const Vec2& Speed, float ExRate, int LifeTime, const Vec2& Accel) noexcept:
IEffect(XY, LifeTime), mExRate(ExRate), mSpeed(Speed), mAccel(Accel), mHdlAngle(0.0f) {
}

bool BossBreak::Update(float t) noexcept {
	*this += mSpeed;
	mSpeed += mAccel;
	mHdlAngle += 0.03f;
	mExRate += 1.5f / mLifeTime;
	++mTime;
	mLiveFlag = mTime <= mLifeTime;
	return mLiveFlag;
}

void BossBreak::Draw()const  noexcept {
	//SetBlendModeAlpha(lerp(255, 0, 15, mLifeTime, mTime, Ease<Liner>::In));
	{
		DrawRotaGraph(*this, mExRate, mHdlAngle, BossBreakHdl);
	}
	//ResetBlendMode();
}


EnemyBack::EnemyBack(Point* XY, int Handle)noexcept :
IEffect(Point::Zero, 10), mHandle(Handle), Angle(0.0f), mParent(XY), ExRate(1.5f) {}

bool EnemyBack::Update(float t)noexcept {
	Angle += 0.05f;
	ExRate = 1.5f + 0.2f*sinf(Angle);
	return mLiveFlag;
}

void EnemyBack::Draw()const  noexcept {
	SetBlendModeAlpha(155);
	DrawRotaGraph(*mParent, ExRate, Angle, mHandle);
	ResetBlendMode();
}

EnemyName::EnemyName(char* Name)noexcept:
IEffect({ WALL_X1,WALL_Y1 }, 1), mName(Name) {}
void EnemyName::Draw()const noexcept {
	DrawFormatString(x, y, 0xFFFFFF, mName, 0);
}
EnemyHP::EnemyHP(Point* XY, int* HP, int MaxHP)noexcept :
	IEffect(Point::Zero, 10), mParent(XY), mHP(HP), mHPBef(*HP), mHPAf(*HP), mMaxHP(MaxHP), mDispHP(0), mEaseFlag(false) {}

bool EnemyHP::Update(float t)noexcept {
	/*if (mEaseFlag) {
	mDispHP += lerpS(mHPBef- mHPAf, 0, 10, mTime, D_Ease<D_Liner>::In);
	if (mTime > 60) {
	mEaseFlag = false;
	mHPBef = *mHP;
	}
	++mTime;
	}
	else if (*mHP != mHPBef) {
	mHPAf = *mHP;
	mEaseFlag = true;
	mTime = 0;
	}*/
	mDispHP = *mHP;
	//if (!mHP)return false;
	return mLiveFlag;
}

void EnemyHP::Draw()const noexcept {
	DrawBox(mParent->x - 60.0f, mParent->y - 74.0f, mParent->x + 61.0f, mParent->y - 70.0f, 0xAA8888, false);
	DrawBox(mParent->x - 61.0f, mParent->y - 75.0f, mParent->x + 62.0f, mParent->y - 69.0f, 0xDDAAAA, false);
	DrawBox(mParent->x - 61.0f, mParent->y - 75.0f, mParent->x - 61.0f + 122.0f * float(mDispHP) / float(mMaxHP), mParent->y - 69.0f, 0xFF2222, false);
	DrawBox(mParent->x - 60.0f, mParent->y - 74.0f, mParent->x - 60.0f + 120.0f * float(mDispHP) / float(mMaxHP), mParent->y - 70.0f, 0xFFFFFF, true);
	DrawBox(mParent->x - 60.0f, mParent->y - 74.0f, mParent->x - 60.0f + 120.0f * float(mDispHP) / float(mMaxHP), mParent->y - 70.0f, 0xFFAAAA, false);
}

EnemyDamage::EnemyDamage(const Point& XY, int Damage)noexcept :
IEffect(XY, 30), mDamage(Damage), mAlpha(0) {}
bool EnemyDamage::Update(float t)noexcept {
	y -= 2.0f;
	mAlpha = lerp(255, 0, 0, 30, mTime, Ease<Liner>::In);
	++mTime;
	mLiveFlag = mTime <= mLifeTime;
	return mLiveFlag;
}
void EnemyDamage::Draw()const noexcept {
	SetBlendModeAlpha(mAlpha);
	DrawFormatString(x, y, WHITE, "%d", mDamage);
	ResetBlendMode();
}

EnemyMarker::EnemyMarker(Point* XY) noexcept:IEffect(Point::Zero, 10), mParent(XY) {}

bool EnemyMarker::Update(float t)noexcept {
	return mLiveFlag; 
}

void EnemyMarker::Draw()const noexcept {
	DrawRotaGraph(mParent->x, 705.0f, 1.0f, 0.0f, EnemyMarkerHdl);
}
BattleStart::BattleStart(int duration)noexcept:IEffect(Point::Zero, duration), mAlpha(0) {}
bool BattleStart::Update(float t)noexcept {
	if (mTime <= mLifeTime >> 1)mAlpha = lerp(0, 255, 0, mLifeTime >> 1, mTime, Ease<Liner>::In);
	else if (mTime <= mLifeTime) {
		mAlpha = lerp(255, 0, mLifeTime >> 1, mLifeTime, mTime, Ease<Liner>::In);
	}
	else {
		mLiveFlag = false;
	}
	++mTime;
	return mLiveFlag;
}
void BattleStart::Draw()const noexcept {
	SetBlendModeAlpha(mAlpha);
	GameWindow.draw(0xFFFFFF);
	//DrawRotaGraph(mParent->x, 705.0f, 1.0f, 0.0f, EnemyMarkerHdl);
	ResetBlendMode();
}

//===========================================================================================================================
//
//player
//
//===========================================================================================================================

PlayerBulletHit::PlayerBulletHit(const Point& XY, const Vec2& Speed, int LifeTime) noexcept:
IEffect(XY, LifeTime), mExRate(1.0f), mSpeed(Speed){}

bool PlayerBulletHit::Update(float t) noexcept {
	*this += mSpeed;
	mExRate = lerp(1.3f, 0.2f, 0, mLifeTime, mTime, Ease<Liner>::In);
	++mTime;
	mLiveFlag = mTime <= mLifeTime;
	return mLiveFlag;
}

void PlayerBulletHit::Draw()const noexcept {
	SetDrawBlendMode(BLEND_ADD, 255);
	//SetBlendModeAlpha(lerp(255, 0, 0, mLifeTime, mTime, Ease<Liner>::In));
	{
		DrawRotaGraph(*this, mExRate, 0.0f, BulletEffectHdl[7]);
	}
	ResetBlendModeAdd();
	//ResetBlendMode();
}

PlayerHit::PlayerHit(const Point& XY, const Vec2& Speed, int LifeTime)noexcept:
IEffect(XY, LifeTime), mExRate(0.0f), mSpeed(Speed) {}

bool PlayerHit::Update(float t)noexcept {
	*this += mSpeed;
	mHdlAngle += 0.03f;
	mExRate = lerp(0.0f, 1.0f, 0, mLifeTime, mTime, Ease<Liner>::In);
	++mTime;
	mLiveFlag = mTime <= mLifeTime;
	return mLiveFlag;
}

void PlayerHit::Draw()const noexcept {
	SetBlendModeAlpha(lerp(255, 0, 0, mLifeTime, mTime, Ease<Liner>::In));
	{
		DrawRotaGraph(*this, mExRate + 2.0f, mHdlAngle, PlayerBreakHdl);
	}
	ResetBlendMode();
}

PlayerCore::PlayerCore(Point* XY, bool* Observer)noexcept :
IEffect(Point::Zero, 10), Angle(0.0f), mParent(XY), mObserver(Observer) {}

bool PlayerCore::Update(float t)noexcept {
	Angle += 0.05f;
	if (!*mObserver) {
		mLiveFlag = false;
	}
	return mLiveFlag;
}

void PlayerCore::Draw()const noexcept {
	DrawRotaGraph(*mParent, 1.0f, Angle, PlayerCoreHdl);
	SetBlendModeAlpha(160);
	DrawRotaGraph(*mParent, 0.6f, Angle, SlowEffectHdl);
	DrawRotaGraph(*mParent, 0.8f, -Angle, SlowEffectHdl);
	ResetBlendMode();
}

//===========================================================================================================================
//
//stage
//
//===========================================================================================================================

StageTitle::StageTitle(const Point& XY, int StageNum) noexcept:IEffect(XY, 10),mStageNum(StageNum), mAlpha(0){}

bool StageTitle::Update(float t)noexcept {
	if (mTime < 150) {
		mAlpha = lerp(0, 255, 0, 150, mTime, Ease<Liner>::In);
		x += D_lerp(300, 0, 150, mTime, D_Ease<D_Quad>::Out);
	}
	else if (mTime < 350) {
		mAlpha = lerp(255, 0, 180, 350, mTime, Ease<Liner>::In);
		x += D_lerp(400, 180, 350, mTime, D_Ease<D_Quad>::In);
	}
	else {
		return false;
	}
	++mTime;
	return mLiveFlag;
}

void StageTitle::Draw()const noexcept {
	SetBlendModeAlpha(mAlpha);
	/*DrawCircle(x, 260, 20, WHITE);
	DrawCircle(x + 50, 260 - 20, 10, WHITE);
	DrawCircle(x - 35, 260 + 10, 50, WHITE);*/
	DrawLine(x, y + 150, x + lerp(0, 500, 0, 150, mTime, Ease<Quad>::In),y+150,WHITE, 1);
	DrawGraph(x, y, stageTitleHdl);
	DrawGraph(x+280,y,stageTitleNumHdl[mStageNum]);
	ResetBlendMode();
}

StageBack::StageBack(int Alpha, int Duration, int DarkTime)noexcept:IEffect(Point::Zero, Duration), mAlphaMax(Alpha), mDarkTime(DarkTime),mAlpha(200){}
bool StageBack::Update(float t)noexcept{
	if (mTime < mDarkTime) {
		mAlpha = 200;
	}
	else if (mTime <  mDarkTime + mLifeTime) {
		mAlpha = lerp(200, mAlphaMax, mDarkTime, mDarkTime+ mLifeTime, mTime, Ease<Liner>::In);
	}
	else {
		mLiveFlag = false;
		return false;
	}
	++mTime;
	return mLiveFlag;
}
void StageBack::Draw()const noexcept {
	SetBlendModeAlpha(mAlpha);
	DrawBox(0, 0, 960, 720, BLACK, true);
	ResetBlendMode();
}

StageClear::StageClear(int Duration)noexcept:IEffect({100,200}, Duration) {}
bool StageClear::Update(float t)noexcept {
	if (mTime < mLifeTime/2) {
		mAlpha = lerp(0, 255, 0, mLifeTime / 2-10, mTime, Ease<Liner>::In);
	}
	else if(mTime<mLifeTime){
		mAlpha = lerp(255, 0, mLifeTime / 2+10, mLifeTime-5, mTime, Ease<Liner>::In);
	}
	else {
		return false;
	}
	++mTime;
	return mLiveFlag;
}
void StageClear::Draw()const noexcept {
	SetBlendModeAlpha(mAlpha);
	DrawStringToHandle(x, y,"Stage Clear",WHITE,Font06);
	ResetBlendMode();
}

ItemBorder::ItemBorder(int Duration)noexcept :IEffect(Point::Zero, Duration) {}

bool ItemBorder::Update(float t)noexcept{
	++mTime;
	return mTime<mLifeTime;
}
void ItemBorder::Draw()const noexcept {
	SetBlendModeAlpha(155);
	{
		DrawLine(0, WALL_Y1 + 150, 960, WALL_Y1 + 150, 0xFFAAAA, 3);
	}
	ResetBlendMode();
	DrawLine(0, WALL_Y1 + 150, 960, WALL_Y1 + 150, RED);
}

//===========================================================================================================================
//
//window effect
//
//===========================================================================================================================

FadeOut::FadeOut(int color, int fadeOutFlame,int Duration)noexcept:IEffect(Point::Zero,Duration),mColor(color),mFadeOutFlame(fadeOutFlame){}
bool FadeOut::Update(float t)noexcept {
	++mTime;
	return mTime < mLifeTime;
}
void FadeOut::Draw()const noexcept {
	DxWrp::SetBlendModeAlpha(float(mTime) / float(mFadeOutFlame)*255.0f);
	DxWrp::DrawBox(0,0,960,720,mColor);
	DxWrp::ResetBlendMode();
}

FadeIn::FadeIn(int color, int Duration)noexcept:IEffect(Point::Zero, Duration), mColor(color) {}
bool FadeIn::Update(float t)noexcept {
	++mTime;
	return mTime < mLifeTime;
}
void FadeIn::Draw()const noexcept {
	DxWrp::SetBlendModeAlpha((1.0f - float(mTime) / float(mLifeTime))*255.0f);
	DxWrp::DrawBox(0, 0, 960, 720, mColor);
	DxWrp::ResetBlendMode();
}

//===========================================================================================================================
//
//common
//
//===========================================================================================================================

Message::Message(const Point& p, const char* message, int Duration)noexcept:IEffect(p,Duration),mMessage(message){}
bool Message::Update(float t)noexcept {
	++mTime;
	return mTime<mLifeTime;
}
void Message::Draw()const noexcept {
	DxWrp::DrawFormatString(*this, 0xFFFFFF, mMessage, 1.0f);
}