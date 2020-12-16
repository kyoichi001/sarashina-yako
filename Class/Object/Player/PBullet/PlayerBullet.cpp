
#include "PlayerBullet.h"
#include "../Player.h"
#include "../../Effect/Effects.h"
#include "../../../MediatorClass/ObjectAdaptor.h"
#include "../../../../Data/Resource.h"
#include "../../../../Library/Renderer.h"
#include "../../../../Library/Math/Constant.h"
#include "../../../../Library/Math/Collision.h"

int StandardHdl, HormingHdl,WindHdl;

void InitPBulletResource()noexcept {
	StandardHdl = DxWrp::LoadGraph("Picture/Bullet/BasicBullet/BasicArrowBullet.png");
	HormingHdl = DxWrp::LoadGraph("Picture/Chara/Player/Bullet1.png");
	WindHdl = DxWrp::LoadGraph("Picture/Chara/Player/Bullet2.png");
}

BulletNormal::BulletNormal(const Point& P, float Speed) :IPBullet(P), mSpeed(0.0f, -Speed) {}
bool BulletNormal::Update(float t)noexcept {
	p += mSpeed;
	return mLiveFlag;
}
void BulletNormal::Draw()const noexcept{
	DxWrp::DrawRotaGraph(p, 1.0f, mSpeed.Angle() + HALF_PI, StandardHdl);
}
void BulletNormal::Finalize()noexcept {
	mCList->ObjEff().SetObject(new PlayerBulletHit(p, { -HALF_PI, 1.5f }, 30));
	mLiveFlag = false;
}


void BulletNormal::Collided( IGhost& obj) {
	if (IsHit(*this, obj)) {
		obj.Damage(10);
		Kill();
	}
}
void BulletNormal::Collided( IBoss& obj) {
	if (IsHit(*this, obj)) {
		obj.Damage(10);
		Kill();
	}
}

BulletHorming::BulletHorming(const Point& P, float Speed) :IPBullet(P),mSpeed(0.0f,-Speed) {}
bool BulletHorming::Update(float t)noexcept {
	Point P = mCList->FacEmy().GetShortestPoint(p);
	float angle= mSpeed.closs(Vec2{ p, P });
	if (angle > 0.0f)angle = 0.15f;
	else if (angle < 0.0f)angle = -0.15f;
	else angle = 0.0f;
	mSpeed.Rotate(angle);
	p += mSpeed;
	return mLiveFlag;
}
void BulletHorming::Draw()const noexcept {
	DxWrp::DrawRotaGraph(p, 1.0f, mSpeed.Angle() + HALF_PI, HormingHdl);
}
void BulletHorming::Finalize()noexcept {
	mCList->ObjEff().SetObject(new PlayerBulletHit(p, { -HALF_PI, 1.5f }, 30));
	mLiveFlag = false;
}

void BulletHorming::Collided(IGhost& obj) {
	if (IsHit(*this, obj)) {
		obj.Damage(6);
		Kill();
	}
}
void BulletHorming::Collided(IBoss& obj) {
	if (IsHit(*this, obj)) {
		obj.Damage(6);
		Kill();
	}
}

BulletWind::BulletWind(const Point& p, float Speed, float angle) :IPBullet(p), mSpeed(angle,Speed,0) {}
bool BulletWind::Update(float t)noexcept {
	p += mSpeed;
	return mLiveFlag;
}
void BulletWind::Draw()const noexcept{
	DxWrp::DrawRotaGraph(p, 1.0f, mSpeed.Angle() + HALF_PI, WindHdl);
}
void BulletWind::Finalize()noexcept {
	mCList->ObjEff().SetObject(new PlayerBulletHit(p, { -HALF_PI, 1.5f }, 30));
	mLiveFlag = false;
}
void BulletWind::Collided(IGhost& obj){
	if (IsHit(*this, obj)) {
		obj.Damage(15);
		Kill();
	}
}
void BulletWind::Collided(IBoss& obj){
	if (IsHit(*this, obj)) {
		obj.Damage(15);
		Kill();
	}
}
