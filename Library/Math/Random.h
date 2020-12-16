#pragma once

class Point;
class Vec2;
class Segment;
class Capsule;
class Circle;
class Rect;

Point Rand(const Point& Obj)noexcept;
Point Rand(const Circle& Obj)noexcept;
Point Rand(const Rect& Obj)noexcept;
Point Rand(const Segment& Obj)noexcept;
Point Rand(const Capsule& Obj)noexcept;
Point Rand(const Point& P, int xr, int yr)noexcept;

//[-num,num]
int Rand(int num)noexcept;
//[0,num]
int Rand_NoMinus(int num)noexcept;
//[Value1,Value2]
int Rand(int Value1, int Value2);

//[-num,num]
float Rand(float num)noexcept;
//[0.0f,num]
float Rand_NoMinus(float num)noexcept;
//[Value1,Value2]
float Rand(float Value1, float Value2);

bool Rand_TF(float parsentage)noexcept;