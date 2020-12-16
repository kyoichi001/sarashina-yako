

#include "toString.h"
#include "Primitive.h"
#include "Vec3.h"

std::string toString(int p) { return std::to_string(p); }
std::string toString(char p) { return std::to_string(p); }
std::string toString(long p) { return std::to_string(p); }
std::string toString(unsigned long p){ return std::to_string(p); }
std::string toString(float p) { return std::to_string(p); }
std::string toString(std::string& p) { return p; }
std::string toString(Point& p) {
	return "{ " + std::to_string(int(p.x)) + "," + std::to_string(int(p.y)) + " }";
}
std::string toString(Circle& p) {
	return "{ " + std::to_string(int(p.p.x)) + "," + std::to_string(int(p.p.y)) + "," + std::to_string(p.r) + " }";
}
std::string toString(Rect& p) {
	return "{ " + std::to_string(int(p.tl.x)) + "," + std::to_string(int(p.tl.y)) + "," + std::to_string(p.width) + "," + std::to_string(p.height) + " }";
}
std::string toString(Segment& p) {
	return "{ " + std::to_string(int(p.begin.x)) + "," + std::to_string(int(p.begin.y)) + "," + std::to_string(int(p.end.y)) + "," + std::to_string(int(p.end.y)) + " }";
}
std::string toString(Capsule& p) { return ""; }

std::string toString(Vec2& p) {
	return "{ " + std::to_string(int(p.x)) + "," + std::to_string(int(p.y)) + " }";
}
std::string toString(Vec3& p){
	return "{ " + std::to_string(int(p.x)) + "," + std::to_string(int(p.y)) + "," + std::to_string(int(p.z)) + " }";
}