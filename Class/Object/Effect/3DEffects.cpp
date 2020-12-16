
#include "3DEffects.h"
#include "../../../Library/Math/Constant.h"
#include "../../../Library/Math/Random.h"
#include "../../../Data/Camera.h"
#include "../../../Data/Resource.h"

#include "DxLib.h"
#include <cmath>

Camera* I3DEffect::mCamera = nullptr;

I3DEffect::I3DEffect(const Vec3& p, int lifeTime)noexcept : Vec3(p), mLifeTime(lifeTime), mTime(0), mLiveFlag(true) {}
I3DEffect::~I3DEffect()noexcept {}

CGhost::CGhost(const Vec3& p, int lifeTime, Vec3* parent)noexcept
	: I3DEffect(p, lifeTime), mParent(parent), mExRate(120.0f), mRand(Rand(0.0f, PI2)) {}
bool CGhost::Update(float t) noexcept {
	y += 5 * cos(float(mTime) / 70.0f + mRand);
	mExRate = 25.0f*cos(float(mTime) / 15.0f + mRand)+110.0f;
	++mTime;
	return mLiveFlag;
}

void CGhost::Draw()const noexcept {
	float fogAlpha = mCamera->getFogAlpha({ x + mParent->x, y + mParent->y, z + mParent->z });
	SetDrawBlendMode(DX_BLENDMODE_ADD_X4, fogAlpha);
	DrawBillboard3D({ x + mParent->x, y + mParent->y, z + mParent->z }, 0.5f, 0.5f, mExRate, 0.0f, Ghost3DHdl, TRUE);
	SetDrawBlendMode(0, 0);
}

CCrowd::CCrowd(const Vec3& p, int lifeTime, Vec3* parent)noexcept
	: I3DEffect(p, lifeTime), mParent(parent), mExRate(Rand(700.0f,1500.0f)) {}

bool CCrowd::Update(float t)noexcept{
	++mTime;
	return mLiveFlag;
}

void CCrowd::Draw()const noexcept {
	float fogAlpha = mCamera->getFogAlpha({ x + mParent->x, y + mParent->y, z + mParent->z });
	SetDrawBlendMode(DX_BLENDMODE_ADD, fogAlpha/3);
	//SetDrawBright(fogAlpha, fogAlpha, fogAlpha);
	DrawBillboard3D({ x + mParent->x, y + mParent->y, z + mParent->z }, 0.5f, 0.5f, mExRate, 0.0f, Clowd3DHdl, TRUE);
	//	DrawBillboard3D({ x + mParent->x, y + mParent->y, z + mParent->z }, 0.5f, 0.5f, mExRate / 2.0f, 0.0f, Ghost3DHdl, TRUE);
	//	DrawBillboard3D({ x + mParent->x, y + mParent->y, z + mParent->z }, 0.5f, 0.5f, mExRate / 3.0f, 0.0f, Ghost3DHdl, TRUE);
	SetDrawBlendMode(0, 0);
	//SetDrawBright(255, 255, 255);
}

CSnow::CSnow(const Vec3& p, int lifeTime, Vec3* parent)noexcept
	: I3DEffect(p, lifeTime), mParent(parent), mExRate(Rand(20.0f, 100.0f)) {}

bool CSnow::Update(float t)noexcept {
	y -= 3;
	if (y <-100)y += 2400;
	++mTime;
	return mLiveFlag;
}

void CSnow:: Draw()const noexcept{
	float fogAlpha = mCamera->getFogAlpha({ x + mParent->x, y + mParent->y, z + mParent->z });
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, fogAlpha);
	//SetDrawBright(fogAlpha, fogAlpha, fogAlpha);
	DrawBillboard3D({ x + mParent->x, y + mParent->y, z + mParent->z }, 0.5f, 0.5f, mExRate, float(mTime)/100.0f, Snow3DHdl, TRUE);
	SetDrawBlendMode(0, 0);
	//SetDrawBright(255, 255, 255);

}