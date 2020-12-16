
#include "Camera.h"
#include "../Data/DATA.h"
#include "../Library/Func.h"
#include "DxLib.h"

Camera::Camera() noexcept:Vec3(GetCameraPosition().x, GetCameraPosition().y, GetCameraPosition().z){
	mTarget = { GetCameraTarget().x, GetCameraTarget().y, GetCameraTarget().z };
	mTarget.z += 400;
}

Camera::Camera(const Vec3& P)noexcept :Vec3(P){}
Camera::~Camera()noexcept{}

void Camera::Update()noexcept {
	SetCameraPositionAndTarget_UpVecY({ x, y, z }, { mTarget.x, mTarget.y, mTarget.z });
}

void Camera::SetPosi(const Vec3& P)noexcept {*this = P;}
void Camera::SetTarg(const Vec3& P)noexcept {mTarget=P;}
void Camera::AddPosi(const Vec3& P)noexcept {*this += P;}
void Camera::AddTarg(const Vec3& P)noexcept { mTarget += P; }

Vec3& Camera::GetTarg()noexcept {return mTarget;}
float  Camera::getFogAlpha(const Vec3& P)const noexcept {
	float camL = Vec3(P - *this).lengthSqu();
	if (camL >= 20000000) return 0;
	if (camL <= 300000)return  255;
	return (20000000 - camL) / 20000000 * 255;
}
Vec3 Camera::getDirection()const noexcept {
	return (*this - mTarget).GetNorm();
}

#ifdef _DEBUG

Vec3 toVec3(const VECTOR& Obj)noexcept {return { Obj.x, Obj.y, Obj.z };}
VECTOR toVEC(Vec3& Obj) noexcept {return { Obj.x, Obj.y, Obj.z };}

void Camera::Debug()noexcept {

	Vec3 CamFront = toVec3(GetCameraFrontVector());
	Vec3 CamUp = toVec3(GetCameraUpVector());
	Vec3 CamLeft = toVec3(GetCameraLeftVector());

	if (Key[KEY_INPUT_LSHIFT] > 0){
		if (CamFront.lengthSqu() > 25.0f){
			*this += CamFront*MouseWheel*1.5f;
		}
		if (Key[KEY_INPUT_UP   ] > 0)*this += CamUp*1.5f  , mTarget += CamUp*1.5f;
		if (Key[KEY_INPUT_DOWN ] > 0)*this -= CamUp*1.5f  , mTarget -= CamUp*1.5f;
		if (Key[KEY_INPUT_LEFT ] > 0)*this += CamLeft*1.5f, mTarget += CamLeft*1.5f;
		if (Key[KEY_INPUT_RIGHT] > 0)*this -= CamLeft*1.5f, mTarget -= CamLeft*1.5f;
	}
	else if (Key[KEY_INPUT_LCONTROL] > 0){
		if (CamFront.lengthSqu() > 25.0f){
			mTarget += CamFront*MouseWheel*1.5f;
		}
		if (Key[KEY_INPUT_UP   ] > 0)mTarget += CamUp*1.5f;
		if (Key[KEY_INPUT_DOWN ] > 0)mTarget -= CamUp*1.5f;
		if (Key[KEY_INPUT_LEFT ] > 0)mTarget += CamLeft*1.5f;
		if (Key[KEY_INPUT_RIGHT] > 0)mTarget -= CamLeft*1.5f;
	}
	/*else if (Key[KEY_INPUT_LALT] > 0){

	}*/
	else {
		if (CamFront.lengthSqu() > 25.0f) {
			*this += CamFront*MouseWheel*1.5f;
		}
		if (Key[KEY_INPUT_UP   ] > 0) *this += CamUp*1.5f;
		if (Key[KEY_INPUT_DOWN ] > 0) *this -= CamUp*1.5f;
		if (Key[KEY_INPUT_LEFT ] > 0) *this += CamLeft*1.5f;
		if (Key[KEY_INPUT_RIGHT] > 0) *this -= CamLeft*1.5f;
	}

}

#endif