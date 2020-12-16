#pragma once

#include "../../../Library/Primitive/Vec3.h"

class Camera;

class I3D :public Vec3 {
protected:
	int mHandle;
	int mTime;
	int mValue;
	void virtual UpdateObj() noexcept {}
	Vec3* mParent;
	bool mLiveFlag;
	static Camera* mCamera;
public:
	I3D()noexcept;
	I3D(const Vec3& P, int Value)noexcept;
	~I3D()noexcept{}
	bool Update(float t)noexcept;
	void virtual Draw()const noexcept;
	void SetRotate(const Vec3& Obj)noexcept;
	int GetTime()const noexcept { return mTime; }
	bool IsLive()const noexcept { return mLiveFlag; }
	void Kill()noexcept { mLiveFlag = false; }
	void SetParent(Vec3* P) noexcept;
	static void setCamera(Camera* camera) { mCamera = camera; }
#ifdef _DEBUG
	void virtual DrawDebug()const noexcept {}
#endif
};