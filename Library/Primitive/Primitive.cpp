#include "Primitive.h"
#include <cmath>
#include "DxLib.h"
#include "../Func.h"

Point::Point() noexcept:x(0.0f), y(0.0f) {}
Point::Point(float X, float Y) noexcept : x(X), y(Y) {}
Point::Point(float Angle, float Length, int)noexcept : x(Length*cos(Angle)), y(Length*sin(Angle)) {}
float Point::length(const Point& Obj)const noexcept { return sqrt(lengthSqu(Obj)); }
float Point::Angle(const Point& Obj)const noexcept { return atan2(Obj.y - y, Obj.x - x); }
Vec2  Point::toVec2()const noexcept { return { x,y }; }

void Point::Rotate(float Angle)noexcept {
	float c = cos(Angle), s = sin(Angle);
	float X = x * c - y * s;
	float Y = x * s + y * c;
	x = X; y = Y;
}
Point Point::Rotated(float Angle)const noexcept {
	float c = cos(Angle), s = sin(Angle);
	return { x * c - y * s,x * s + y * c };
}
void Point::ease(const Point& P, int t_min, int t_max, int t) noexcept {

}
void Point::draw(int Color) const noexcept {
	DrawPixel(x, y, Color);
}
void Point::clamp(const Rect& rect)noexcept {
	x=Clamp(rect.tl.x, x, rect.tl.x + rect.width);
	y=Clamp(rect.tl.y, y, rect.tl.y + rect.height);
}
Point Point::getClamp(const Rect& rect)const noexcept {
	float X = Clamp(rect.tl.x, x, rect.tl.x + rect.width);
	float Y = Clamp(rect.tl.y, y, rect.tl.y + rect.height);
	return { X,Y };
}

 const  Point Point::Zero{ 0.0f,0.0f };

Vec2::Vec2()noexcept:x(0.0f), y(0.0f) {}
Vec2::Vec2(const Point& p)noexcept : x(p.x), y(p.y) {}
Vec2::Vec2(float X, float Y) noexcept : x(X), y(Y) {}
Vec2::Vec2(float Angle, float Length, int)noexcept : x(Length*cos(Angle)), y(Length*sin(Angle)) {}
Vec2::Vec2(const Point& Begin, const Point& End)noexcept : x(End.x - Begin.x), y(End.y - Begin.y) {}
float Vec2::Angle()const noexcept { return atan2(y, x); }
float Vec2::length()const noexcept { return sqrt(lengthSqu()); }
void Vec2::Rotate(float Angle)noexcept {
	float c = cos(Angle), s = sin(Angle);
	float X = x*c - y*s;
	float Y = x*s + y*c;
	x = X; y = Y;
}
Vec2 Vec2::Rotated(float Angle)const noexcept {
	float c = cos(Angle), s = sin(Angle);
	return { x * c - y * s,x * s + y * c };
}

const  Vec2 Vec2::Zero{ 0.0f,0.0f };

Circle::Circle()noexcept : p(0.0f, 0.0f), r(0) {}
Circle::Circle(float X, float Y, int R) noexcept : p(X, Y), r(R) {}
Circle::Circle(const Point& P, int R) noexcept : p(P), r(R) {}
void Circle::draw(int Color, bool FillFlag , int Thickness ) const noexcept {
	DrawCircle(p.x, p.y, r, Color, FillFlag, Thickness);
}

Rect::Rect()noexcept {}
Rect::Rect(const Point& LeftUp, const  Point& RightDown)noexcept : tl(LeftUp),width(RightDown.x- LeftUp.x), height(RightDown.y - LeftUp.y) {}
Rect::Rect(const Point& LeftUp, int Height, int Width)noexcept : tl(LeftUp),width(Width),height(Height) {}
Rect::Rect(float X1, float Y1, float X2, float Y2) noexcept : tl( X1,Y1 ),width( X2-X1 ),height(Y2-Y1){}
void Rect::draw(int Color, bool FillFlag , int Thickness ) const noexcept {
	DrawBox(tl.x, tl.y, tl.x + width, tl.y + height, Color, FillFlag);
}

Segment::Segment(float X1, float Y1, float X2, float Y2) noexcept : begin(X1, Y1), end(X2, Y2){}
Segment::Segment(const Point& Begin, const  Point &End)noexcept : begin(Begin), end(End){}
Segment::Segment(const Point &Begin, float Length, float Angle) noexcept : begin(Begin), end(Begin + Vec2{Angle,Length,1}) {}
void Segment::draw(int Color, int Thickness ) const noexcept {
	DrawLine(begin.x,begin.y,end.x,end.y,Color,Thickness);
}

#include <iostream>
void Segment::reverse() noexcept {std::swap(begin,end);}
Segment::Segment(const Point& Begin, const Vec2& v)noexcept:begin(Begin), end(begin + v) {}

Capsule::Capsule(float X1, float Y1, float X2, float Y2, int R)noexcept :segment(X1,Y1,X2,Y2),r(R){}
Capsule::Capsule(const Point &Begin, const Point &End, int R) noexcept : segment(Begin,End),r(R){}
Capsule::Capsule(const Point &Begin, float Length, float Angle, int R) noexcept : segment(Begin, Length,Angle), r(R){}

HalfLine::HalfLine(float x, float y, float Angle)noexcept:p(x,y),angle(Angle){}
HalfLine::HalfLine(const Point& P, float Angle)noexcept:p(P),angle(Angle){}
HalfLine::HalfLine(const Point& P, const Vec2& v)noexcept:p(P),angle(v.Angle()){}