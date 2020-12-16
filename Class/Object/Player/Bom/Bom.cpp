
#include "Bom.h"
#include "../Player.h"
#include "../../Effect/Effects.h"
#include "../../../MediatorClass/ObjectAdaptor.h"
#include "../../../../Data/Resource.h"
#include "../../../../Library/Renderer.h"
#include "../../../../Library/Math/Constant.h"
#include "../../../../Library/Math/Collision.h"
#include "../../../../Library/Easing/InterpolationMethod.h"

int Bom1_1Hdl,Bom1_2Hdl;
void InitBomResource()noexcept {
	Bom1_1Hdl = DxWrp::LoadGraph("Picture/Chara/Player/BomEffect0_0.png");
	Bom1_2Hdl = DxWrp::LoadGraph("Picture/Chara/Player/BomEffect0_1.png");
}

EnemyEnd::EnemyEnd(const Point& XY)noexcept :IBom(XY) {
	r = 0;
	mAttack = 0;
}

bool EnemyEnd::Update(float t)noexcept {
	if (r<800)r += 15;
	else {
		mLiveFlag = false;
	}
	return mLiveFlag;
}
void EnemyEnd::Collided(IBullet& obj) {
	if (IsHit(*this, obj)) {
		obj.Kill();
	}
}

EnemyNext::EnemyNext(const Point& XY)noexcept :IBom(XY) {
}
bool EnemyNext::Update(float t)noexcept {
	if (r<800)r += 15;
	else {
		mLiveFlag = false;
	}
	return mLiveFlag;
}
void EnemyNext::Collided(IBullet& obj) {
	if (IsHit(*this, obj)) {
		obj.Kill();
	}
}

PlayerHitBom::PlayerHitBom(const Point& XY)noexcept:IBom(XY) {
	mAttack = 5;
}
bool PlayerHitBom::Update(float t)noexcept {
	if (r<800)r += 20;
	else {
		mLiveFlag = false;
	}
	return mLiveFlag;
}
void PlayerHitBom::Collided(IBullet& obj) {
	if (IsHit(*this, obj)) {
		obj.Kill();
	}
}


PlayerBom::PlayerBom(const Point& XY)noexcept :IBom(XY), mAlpha(255),mAngle(0.0f) {
}

bool PlayerBom::Update(float t)noexcept {
	if (mTime < 60) {
		r = lerp(0, 500, 0, 60, mTime, Ease<Quart>::In);
		mAngle += D_lerp(PI, 0, 60, mTime, D_Ease<D_Quad>::In);
	}
	else if (mTime < 140) {
		mAngle += 0.02f;
	}
	else  if (mTime < 240) {
		//r = lerp(600, 500, 180, 200, mTime, Ease<Quad>::Out);
		mAlpha = lerp(255, 0, 140, 170, mTime, Ease<Liner>::In);
		mAngle += D_lerp(PI, 140, 170, mTime, D_Ease<D_Liner>::In);
	}
	else {
		mLiveFlag = false;
	}
	++mTime;
	return mLiveFlag;
}
void PlayerBom::Draw()const noexcept {
	DxWrp::SetBlendModeAlpha(mAlpha );
	draw(0xFFFFFF,false,10);
	DxWrp::SetDrawBlendMode(BLEND_ADD, mAlpha);
	DxWrp::DrawRotaGraph(p, float(r) / 190.0f, mAngle, Bom1_1Hdl);
	DxWrp::DrawRotaGraph(p, float(r) / 190.0f, mAngle, Bom1_1Hdl);
	DxWrp::SetDrawBlendMode(BLEND_ADD, mAlpha/3);
	DxWrp::DrawRotaGraph(p, float(r) / 300.0f, -mAngle, Bom1_2Hdl);
	DxWrp::ResetBlendMode();
}
void PlayerBom::Collided(IBullet& obj) {
	if (IsHit(*this, obj)) {
		obj.Kill();
	}
}

PlayerBom2::PlayerBom2(const Point& XY)noexcept :IBom(XY), mAlpha(255) {}
bool PlayerBom2::Update(float t)noexcept {
	if (mTime < 10) {
		r = lerp(0, 100, 0, 10, mTime, Ease<Liner>::In);
	}
	else  if (mTime < 90) {
		r = lerp(100, 20, 60, 90, mTime, Ease<Quad>::Out);
		mAlpha = lerp(255, 0, 60, 90, mTime, Ease<Liner>::In);
	}
	else {
		mLiveFlag = false;
	}
	++mTime;
	return mLiveFlag;
}
void PlayerBom2::Draw()const noexcept {
	DxWrp::SetBlendModeAlpha(mAlpha);
	draw(0xFFFFFF, false, 10);
	DxWrp::ResetBlendMode();
}
void PlayerBom2::Collided(IBullet& obj) {
	if (IsHit(*this, obj)) {
		obj.Kill();
	}
}