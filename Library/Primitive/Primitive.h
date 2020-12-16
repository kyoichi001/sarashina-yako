
#pragma once

class Vec2;
class Rect;

class Point {
public:
	float x, y;
	Point()noexcept;
	Point(float X, float Y)noexcept;
	Point(float Angle, float Length, int)noexcept;
	~Point()noexcept{}

	void set(float X,float Y) noexcept { x = Y, y = Y; }

	float lengthSqu(const Point& Obj)const noexcept { return (x - Obj.x)*(x - Obj.x) + (y - Obj.y)*(y - Obj.y); }
	float length(const Point& Obj)const noexcept;
	float Angle(const Point& Obj)const noexcept;
	Vec2 toVec2()const noexcept;

	void ease(const Point& P,int t_min,int t_max,int t)noexcept;
	void draw(int Color)const noexcept;

	void Rotate(float Angle)noexcept;
	Point Rotated(float Angle)const noexcept;
	void clamp(const Rect& rect)noexcept;
	Point getClamp(const Rect& rect)const noexcept;
	Point operator -()const noexcept { return { -x,-y }; }
	Point operator +(const Point &Obj)const noexcept { return { x + Obj.x, y + Obj.y }; }
	Point operator -(const Point &Obj)const  noexcept { return { x - Obj.x, y - Obj.y }; }
	Point operator *(float Length)const noexcept { return { x * Length, y * Length }; }
	Point operator /(float Length)const noexcept { return { x / Length, y / Length }; }
	void operator +=(const Point &Obj)noexcept { x+= Obj.x; y += Obj.y; }
	void operator -=(const Point &Obj)noexcept { x -= Obj.x; y -= Obj.y; }
	bool operator ==(const Point &Obj)const noexcept { return x == Obj.x&&y == Obj.y; }
	bool operator !=(const Point &Obj)const noexcept { return x != Obj.x || y != Obj.y; }

	const static Point Zero;
};


class Vec2 {
public:
	float x, y;
	Vec2()noexcept;
	Vec2(const Point& p)noexcept;
	Vec2(float X, float Y)noexcept;
	Vec2(float Angle, float Length, int)noexcept;
	Vec2(const Point& Begin, const Point& End)noexcept;

	void set(float X, float Y) noexcept { x = X; y = Y; }

	float Angle()const noexcept;
	float lengthSqu()const noexcept { return x*x + y*y; }
	float length()const noexcept;
	float dot(const Vec2& Obj)const  noexcept { return x*Obj.x + y * Obj.y; }
	float closs(const Vec2& Obj)const  noexcept { return  x*Obj.y - y*Obj.x; }
	Vec2 normed()const noexcept { return *this / length(); }
	void norm()noexcept { *this /= length(); }
	void Rotate(float Angle)noexcept;
	Vec2 Rotated(float Angle)const noexcept;
	void SetLength(float Length)noexcept { *this *= Length / length(); }

	Point toPoint()const noexcept { return { x, y }; };

	Vec2 operator -()const noexcept { return { -x,-y }; }
	Vec2 operator +(const Vec2 &Obj)const noexcept { return { x + Obj.x, y + Obj.y }; }
	Vec2 operator -(const Vec2 &Obj)const  noexcept { return { x - Obj.x, y - Obj.y }; }
	Vec2 operator *(float Length)const noexcept { return { x * Length, y * Length }; }
	Vec2 operator /(float Length)const noexcept { return { x / Length, y / Length }; }
	void operator *=(float length)noexcept { x *= length; y *= length; }
	void operator /=(float length)noexcept { x /= length; y /= length; }
	void operator +=(const Vec2 &Obj)noexcept { x += Obj.x; y += Obj.y; }
	void operator -=(const Vec2 &Obj)noexcept { x -= Obj.x; y -= Obj.y; }
	bool operator ==(const Vec2 &Obj)const noexcept { return x == Obj.x&&y == Obj.y; }
	bool operator !=(const Vec2 &Obj)const noexcept { return !(*this == Obj); }

	const static Vec2 Zero;

};


inline Point operator +(const Point& P, const Vec2 &Obj) noexcept { return { P.x + Obj.x, P.y + Obj.y }; }
inline Point operator -(const Point& P, const Vec2 &Obj) noexcept { return { P.x - Obj.x, P.y - Obj.y }; }
inline void operator +=(Point& P, const Vec2 &Obj)noexcept { P.x = P.x + Obj.x; P.y = P.y + Obj.y; }
inline void operator -=(Point& P, const Vec2 &Obj)noexcept { P.x = P.x - Obj.x; P.y = P.y - Obj.y; }

class Circle {
public:
	Point p;
	int r;
	Circle()noexcept;
	Circle(float X, float Y, int R)noexcept;
	Circle(const Point& P, int R)noexcept;
	void set(float X, float Y, int R) noexcept { p.x = X; p.y = Y; r = R; }
	void set(const Point& P, int R)noexcept { p = P; r = R; }
	void draw(int Color, bool FillFlag = true, int Thickness=1)const noexcept;
};

class Segment{
public:
	Point begin,end;
	Segment(float X1, float Y1, float X2, float Y2)noexcept;
	Segment(const Point& Begin, const Point& End)noexcept;
	Segment(const Point& Begin, float Length, float Angle)noexcept;
	Segment(const Point& Begin, const Vec2& v)noexcept;
	void draw(int Color,int Thickness=1)const noexcept;
	void reverse()noexcept;
	float lengthSqu()const noexcept { return begin.lengthSqu(end); };
	Vec2 vector()const noexcept { return end - begin; }
	Point center()const noexcept { return (begin + end)*0.5; };
};

class Rect {
public:
	Point tl;
	int height, width;
	Rect()noexcept;
	Rect(const Point& LeftUp, const  Point& RightDown)noexcept;
	Rect(const Point& LeftUp, int height, int width)noexcept;
	Rect(float X1, float Y1, float X2, float Y2)noexcept;
	void draw(int Color, bool FillFlag = true, int Thickness = 1)const noexcept;
	Segment top()const noexcept { return { tl,Vec2{ float(width),0.0f } }; }
	Segment btm()const noexcept { return { tl + Vec2{ 0.0f,float(height) },Vec2{ float(width),0.0f } }; }
	Segment lft()const noexcept { return { tl,Vec2{ 0.0f,float(height) } }; }
	Segment rgt()const noexcept { return { tl + Vec2{ float(width),0.0f } ,Vec2{0.0f,float(height) } }; }
};

class Capsule {
public:
	Segment segment;
	int r;
	Capsule(float X1, float Y1, float X2, float Y2, int R)noexcept;
	Capsule(const Point& Begin, const Point& End, int R)noexcept;
	Capsule(const Point& Begin, float Length, float Angle, int R)noexcept;
};

class HalfLine {
public:
	Point p;
	float angle;
	HalfLine(float x, float y, float angle)noexcept;
	HalfLine(const Point& p, float angle)noexcept;
	HalfLine(const Point& p, const Vec2& v)noexcept;
	void rotate(float deltaAngle)noexcept { angle += deltaAngle; }
	Vec2 getDirection()const noexcept { return Vec2{ angle,1.0f,0 }; }
	//ñ@ê¸
	Vec2 getNormal()const noexcept { return Vec2{ angle + 3.1415926535f*0.5f, 1.0f, 0 }; }
	Point getCood(float t)const noexcept { return p + Vec2{ angle,1.0f,0 }*t; }
};