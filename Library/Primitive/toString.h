
#pragma once
#include <string>

class Point;
class Circle;
class Rect;
class Segment;
class Capsule;
class Vec2;
class Vec3;

std::string toString(int p);
std::string toString(char p);
std::string toString(long p);
std::string toString(unsigned long p);
std::string toString(float p);

std::string toString(std::string& p);

std::string toString(Point& p);
std::string toString(Circle& p);
std::string toString(Rect& p);
std::string toString(Segment& p);
std::string toString(Capsule& p);

std::string toString(Vec2& p);
std::string toString(Vec3& p);
