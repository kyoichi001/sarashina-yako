
#include "Geometory.h"
#include "../Primitive/Vec3.h"
#include "../Primitive/Primitive.h"
#include "Constant.h"
#include "../Func.h"//clamp

#include <cmath>

Vec2 Rotation(const Vec2& P, float ang)noexcept {
	float c = cos(ang), s = sin(ang);
	return { P.x*c - P.y*s , P.x*s + P.y*c };
}
Vec2 RotationSpeed(const Vec2& P, float ang)noexcept {
	float s = sin(ang), c = cos(ang);
	return { -P.x*s - P.y*c, P.x*c - P.y*s };
}
Point Rotation(const Point& P, const  Point& O, float ang)noexcept {
	return O + Rotation({ O,P }, ang);
}
Point RotationSpeed(const Point& P, const  Point& O, float ang)noexcept {
	return O + RotationSpeed({ O,P }, ang);
}

Vec2 RotationOval(const Point& P, float ratio, float theta, float ang)noexcept {
	float rx = cos(theta), ry = sin(theta);
	float c = cos(ang), s = sin(ang);
	float r_ratio = 1 / ratio;
	return{
		P.x*(c + (ratio - r_ratio) * rx * ry * s) + P.y*(-s * (ratio * ry * ry + r_ratio * rx * rx)),
		P.x*(ratio * rx * rx + r_ratio * ry*ry)*s + P.y*(c + (r_ratio - ratio) * rx * ry * s)
	};
}

Vec3 RotationX(const Vec3& P, const Vec3& O, float ang) noexcept {
	Vec3 DisV = P - O;
	return Vec3{ DisV.x, DisV.y*cos(ang) - DisV.z*sin(ang), DisV.y*sin(ang) + DisV.z*cos(ang) }+O;
}
Vec3 RotationY(const Vec3& P, const  Vec3& O, float ang)noexcept {
	Vec3 DisV = P - O;
	return Vec3{ DisV.x*cos(ang) + DisV.z*sin(ang), DisV.y , -DisV.x*sin(ang) + DisV.z*cos(ang) }+O;
}
Vec3 RotationZ(const Vec3& P, const  Vec3& O, float ang)noexcept {
	Vec3 DisV = P - O;
	return Vec3{ DisV.x*cos(ang) - DisV.y*sin(ang), DisV.x*sin(ang) + DisV.y*cos(ang) , DisV.z }+O;
}

Vec3 RodriguesRotation(const Vec3& P, const  Vec3& O, const  Vec3& V, float ang)noexcept {

	Vec3 DisV = P - O, Ans;
	float c = cos(ang), s = sin(ang);

	Ans.x = DisV.x*(c + V.x*V.x*(1 - c)) +
		DisV.y*(V.x*V.y*(1 - c) - V.z*s) +
		DisV.z*(V.x*V.z*(1 - c) + V.y*s);

	Ans.y = DisV.x*(V.y*V.x*(1 - c) + V.z*s) +
		DisV.y*(c + V.y*V.y*(1 - c)) +
		DisV.z*(V.y*V.z*(1 - c) - V.x*s);

	Ans.z = DisV.z*(V.z*V.x*(1 - c) - V.y*s) +
		DisV.y*(V.z*V.y*(1 - c) + V.x*s) +
		DisV.z*(c + V.z*V.z*(1 - c));

	return Ans + O;

}

Point inner_point(const Point& p1, const  Point& p2, float m, float n)noexcept {
	return { (p1.x*n + p2.x*m) / (m + n),(p1.y*n + p2.y*m) / (m + n) };
}


Point Besier2(const Point& P0, Point& P1, Point& C, int min, int max, int Time)noexcept {
	if (Time<min)return P0;
	else if (Time>max)return P1;
	float t = float(Time - min) / float(max - min);
	return Point(
		(1 - t)*(1 - t)*P0.x + 2 * (1 - t)*t*C.x + t*t*P1.x,
		(1 - t)*(1 - t)*P0.y + 2 * (1 - t)*t*C.y + t*t*P1.y);
}
Point Curve2(const Point& P0, const  Point& P1, const  Point& A, int min, int max, int Time)noexcept {
	Point C = {
		4.0f*A.x - P0.x - P1.x,
		4.0f*A.y - P0.y - P1.y };
	return {};//Besier2(P0, P1, C, min, max, Time);
}
Point Besier3(const Point& P0, const  Point& P1, const  Point& C0, const  Point& C1, int min, int max, int Time)noexcept {
	if (Time<min)return P0;
	else if (Time>max)return P1;
	float t = float(Time - min) / float(max - min);
	return Point(
		(1 - t)*(1 - t)*(1 - t)*P0.x + 3 * (1 - t)*(1 - t)*t*C0.x + 3 * (1 - t)*t*t*C1.x + t*t*t*P1.x,
		(1 - t)*(1 - t)*(1 - t)*P0.y + 3 * (1 - t)*(1 - t)*t*C0.y + 3 * (1 - t)*t*t*C1.x + t*t*t*P1.y);
}
Vec2 D_Besier2(const Vec2& P1, const  Vec2& C, int min, int max, int Time)noexcept {
	float t = float(Time - min) / float(max - min);
	if (t < 0.0f || t > 1.0f)return Vec2();
	return Vec2(
		2 * (1 - 2 * t)*C.x + 2 * t*P1.x,
		2 * (1 - 2 * t)*C.y + 2 * t*P1.y) / float(max - min);
}
Vec2 D_Curve2(const Vec2& P1, const  Vec2& A, int min, int max, int Time)noexcept {
	Vec2 C = {
		(4.0f*A.x - P1.x),
		(4.0f*A.y - P1.y) };
	return D_Besier2(P1, C, min, max, Time);
}
Vec2 D_Besier3(const Vec2& P1, const  Vec2& C0, const  Vec2& C1, int min, int max, int Time)noexcept {
	return {};
}

float distanceSqu(const Point& Obj1, const Point& Obj2)noexcept {
	return Obj1.lengthSqu(Obj2);
}
float distanceSqu(const Point& Obj1, const Circle& Obj2)noexcept {
	return 0.0f;
}
float distanceSqu(const Point& Obj1, const Segment& Obj2)noexcept {
	Vec2 bp = { Obj2.begin ,Obj1 };
	float t = Obj2.vector().dot(bp);
	if (t <= 0.0f) {
		return bp.lengthSqu();//点が線分の始点より外側にあるとき
	}
	float sgLengthSqu = Obj2.lengthSqu();
	if (t >= sgLengthSqu) {//|BP|cos >= |BE| , |BP||BE|cos >= |BE||BE|
		return Obj1.lengthSqu(Obj2.end);//始点から点へのばしたベクトルの、線分への射影が線分よりも長いとき
	}
	return bp.lengthSqu() - t * t / sgLengthSqu;//3平方の定理 |BP|^2 - (|BP|cos)^2  , |BP|^2 - (|BP||BE|cos)^2/|BE|^2
}
float distanceSqu(const Point& Obj1, const Rect& Obj2)noexcept {
	Point p = Obj1.getClamp(Obj2);
	return Obj1.lengthSqu(p);
}

float distanceSqu(const Segment& Obj1, const Segment& Obj2)noexcept { return 0.0f; }
float distanceSqu(const Point& Obj1, const Capsule& Obj2)noexcept { return 0.0f; }

float distanceSqu(const Rect& Obj1, const Rect& Obj2)noexcept { return 0.0f; }

Point getClosestPoint(const Point& p, Segment seg, float& t)noexcept {
	Vec2 segV = seg.vector();
	t = segV.dot(p - seg.begin) / segV.lengthSqu();
	t = Clamp(0.0f, t, 1.0f);
	return seg.begin + segV * t;
}