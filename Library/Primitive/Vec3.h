#pragma once

class Vec3 {
public:
	float x, y, z;
	Vec3()noexcept;
	Vec3(float X, float Y, float Z)noexcept;
	~Vec3()noexcept;

	inline float lengthSqu()const noexcept { return x*x + y*y + z*z; }
	 float length()const noexcept;
	inline float dot(const Vec3& Obj)const  noexcept { return x*Obj.x + y + Obj.y + z*Obj.z; }
	inline Vec3 closs(const Vec3& Obj)const  noexcept { return { y*Obj.z - z*Obj.y, z*Obj.x - x*Obj.z, x*Obj.y - y*Obj.z }; }
	Vec3 GetNorm()const noexcept { return *this / length(); }
	void norm()noexcept { *this = GetNorm(); }

	bool operator ==(const Vec3 &Obj)const noexcept { return  x == Obj.x&& y == Obj.y&& z == Obj.z; }
	bool operator !=(const Vec3 &Obj)const  noexcept { return x != Obj.x || y != Obj.y || z != Obj.z; }
	Vec3 operator +(const Vec3 &Obj)const  noexcept { return { x + Obj.x, y + Obj.y, z + Obj.z }; }
	Vec3 operator -(const Vec3 &Obj)const  noexcept { return { x - Obj.x, y - Obj.y, z - Obj.z }; }
	Vec3 operator *(float Length)const noexcept { return { x * Length, y * Length, z * Length }; }
	Vec3 operator /(float Length)const noexcept { return { x / Length, y / Length, z / Length }; }
	void operator +=(const Vec3 &Obj) noexcept { x += Obj.x; y += Obj.y; z += Obj.z; }
	void operator -=(const Vec3 &Obj) noexcept { x -= Obj.x; y -= Obj.y; z -= Obj.z; }

	const static Vec3 Zero;
};

