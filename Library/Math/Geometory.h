#pragma once

class Point;
class Vec3;
class Vec2;
class Segment;
class Capsule;
class Circle;
class Rect;

//座標回転
Vec2 Rotation(const Vec2& P, float ang)noexcept;
Vec2 RotationSpeed(const Vec2& P, float ang)noexcept;
Point Rotation(const Point& P, const Point& O, float ang)noexcept;
Point RotationSpeed(const Point& P, const Point& O, float ang)noexcept;

//短長軸の比率がratioでthetaだけ回転した楕円上に回転させる
Vec2 RotationOval(const Point& P,float ratio, float theta,float ang)noexcept;

//座標回転
Vec3 RotationX(const  Vec3& P, const  Vec3& O, float ang)noexcept;
Vec3 RotationY(const  Vec3& P, const  Vec3& O, float ang)noexcept;
Vec3 RotationZ(const  Vec3& P, const  Vec3& O, float ang)noexcept;

//PからOを基準に任意の単位ベクトル(V)にang角回転した角度をkaesu
Vec3 RodriguesRotation(const Vec3& P, const  Vec3& O, const  Vec3& V, float ang)noexcept;

//内分点を返す関数
Point inner_point(const Point& p1, const  Point& p2, float m, float n)noexcept;

//ベジェ曲線
Point Besier2(const Point& P0, const  Point& P1, const  Point& C, int min, int max, int Time)noexcept;
Point Curve2(const Point& P0, const  Point& P1, const  Point& A, int min, int max, int Time)noexcept;//Aを通る版
Point Besier3(const Point& P0, const  Point& P1, const  Point& C0, const  Point& C1, int min, int max, int Time)noexcept;
Vec2 D_Besier2(const  Vec2& P1, const  Vec2& C, int min, int max, int Time)noexcept;
Vec2 D_Curve2(const  Vec2& P1, const  Vec2& A, int min, int max, int Time)noexcept;//Aを通る版
Vec2 D_Besier3(const  Vec2& P1, const  Vec2& C0, const  Vec2& C1, int min, int max, int Time)noexcept;

float distanceSqu(const Point& Obj1, const Point& Obj2)noexcept;
float distanceSqu(const Point& Obj1, const Circle& Obj2)noexcept;
float distanceSqu(const Point& Obj1, const Segment& Obj2)noexcept;
float distanceSqu(const Point& Obj1, const Rect& Obj2)noexcept;
float distanceSqu(const Point& Obj1, const Capsule& Obj2)noexcept;

float distanceSqu(const Segment& Obj1, const Segment& Obj2)noexcept;
float distanceSqu(const Rect& Obj1, const Rect& Obj2)noexcept;

Point getClosestPoint(const Point& p, Segment seg,float& t)noexcept;
