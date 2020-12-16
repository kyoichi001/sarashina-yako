#include "Morton.h"
#include "../Primitive/Primitive.h"

int bitSeparate(int n) {
	n = (n | (n << 8)) & 0x00ff00ff;
	n = (n | (n << 4)) & 0x0f0f0f0f;
	n = (n | (n << 2)) & 0x33333333;
	return (n | (n << 1)) & 0x55555555;
}

int morton(float x,float y)noexcept {
	return bitSeparate(x) | (bitSeparate(y) << 1);
}

int getMorton(const Point& p, const Point& O, int cellX, int cellY)noexcept {
	int X = (p.x - O.x) / cellX, Y = (p.y - O.y) / cellY;
	return morton(X,Y);
}
int getMorton(const Circle& p, const Point& O, int cellX, int cellY)noexcept {
	const Point tl = { p.p.x - p.r,p.p.y - p.r };
	const Point br = { p.p.x + p.r,p.p.y + p.r };
	int mtn = getMorton(tl, O, cellX, cellY) ^ getMorton(br, O, cellX, cellY);
	int level = 0;
	int i = mtn; i >>= 2;
	for (; i != 0; i >>= 2, level++);
	return mtn >> (level * 2);
}
int getMorton(const Vec3& p, const Point& O, int cellX, int cellY)noexcept {
	return 0;
}

int getMorton(const Point* p, const Point& O, int cellX, int cellY)noexcept { return  getMorton(*p,  O,  cellX,  cellY); }
int getMorton(const Circle* p, const Point& O, int cellX, int cellY)noexcept { return  getMorton(*p, O, cellX, cellY); }
int getMorton(const Vec3* p, const Point& O, int cellX, int cellY)noexcept { return  getMorton(*p, O, cellX, cellY); }
int getMorton(const Emitter* p, const Point& O, int cellX, int cellY)noexcept { return 0; }