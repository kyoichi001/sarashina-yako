
#include "I3DObject.h"
#include "DxLib.h"

Camera* I3D::mCamera=nullptr;

I3D::I3D()noexcept: mTime(0), mParent(nullptr), mLiveFlag(true) {}
I3D::I3D(const Vec3& P, int Value)noexcept : Vec3(P), mValue(Value), mTime(0), mParent(nullptr), mLiveFlag(true) {
	MV1SetUseZBuffer(mHandle, TRUE);
	MV1SetPosition(mHandle, { x, y, z });
}
bool I3D::Update(float t) noexcept {
	UpdateObj();
	if (mParent)
		MV1SetPosition(mHandle, { x + mParent->x, y + mParent->y, z + mParent->z });
	else
		MV1SetPosition(mHandle, { x, y, z });
	++mTime;
	return IsLive();
}
void I3D::Draw()const noexcept {
	MV1DrawModel(mHandle);
}

void I3D::SetRotate(const Vec3& Obj)noexcept {
	MV1SetRotationXYZ(mHandle, { Obj.x, Obj.y, Obj.z });
}

void I3D::SetParent(Vec3* P) noexcept { mParent = P; }
