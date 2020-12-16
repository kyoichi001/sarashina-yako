#pragma once

#include "../../../Library/Primitive/Vec3.h"

class Camera;

//エフェクトを1個表示するプログラム
class I3DEffect :public Vec3 {
protected:
	int mTime, mLifeTime;
	bool mLiveFlag;
	static Camera* mCamera;
public:
	I3DEffect(const Vec3& p, int lifeTime)noexcept;
	~I3DEffect()noexcept;
	void virtual Draw()const noexcept {}
	bool virtual Update(float t)noexcept { return false; }
	bool IsLive()const noexcept { return mLiveFlag; }
	void Kill()noexcept { mLiveFlag = false; }
	void static setCamera(Camera* camera) { mCamera = camera; }
};

class CGhost :public I3DEffect {
	Vec3* mParent;
	float mExRate;
	float mRand;
public:
	CGhost(const Vec3& p, int lifeTime,Vec3* parent)noexcept;
	bool Update(float t)noexcept override;
	void Draw()const noexcept override;
};

class CCrowd :public I3DEffect {
	Vec3* mParent;
	float mExRate;
public:
	CCrowd(const Vec3& p, int lifeTime, Vec3* parent)noexcept;
	bool Update(float t)noexcept override;
	void Draw()const noexcept override;
};

class CSnow :public I3DEffect {
	Vec3* mParent;
	float mExRate;
public:
	CSnow(const Vec3& p, int lifeTime, Vec3* parent)noexcept;
	bool Update(float t)noexcept override;
	void Draw()const noexcept override;
};