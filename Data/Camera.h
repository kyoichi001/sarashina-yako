
#pragma once

#include "../Library/Primitive/Vec3.h"

class Camera :public Vec3{
	Vec3 mTarget;
public:
	Camera()noexcept;
	Camera(const Vec3& P)noexcept;
	~Camera()noexcept;
	void Update()noexcept;
	void SetPosi(const Vec3& P)noexcept;
	void SetTarg(const Vec3& P)noexcept;
	void AddPosi(const Vec3& P)noexcept;
	void AddTarg(const Vec3& P)noexcept;
	Vec3& GetTarg()noexcept;
	Vec3 getDirection()const noexcept;//カメラの方向の正規ベクトル
	float getFogAlpha(const Vec3& P)const noexcept;//[0,255]
#ifdef _DEBUG
	void Debug()noexcept;
#endif
};