#include "Random.h"


#include <random>
#include <algorithm>
#include "../Primitive/Primitive.h"
#include "Constant.h"

using namespace std;

mt19937 Random;

Point Rand(const Point& Obj)noexcept { return Obj; }
Point Rand(const Circle& Obj)noexcept {
	float theta = Rand(0.0f, PI2), radi = Rand(0.0f, float(Obj.r));
	float X = Obj.p.x + radi * cos(theta);
	float Y = Obj.p.y + radi * sin(theta);
	return { X,Y };
}
Point Rand(const Rect& Obj) noexcept {
	return {
		Obj.tl.x + Rand(0, Obj.width),
		Obj.tl.y + Rand(0, Obj.height)
	};
}
Point Rand(const Segment& Obj)noexcept {
	float t = Rand(0.0f, 1.0f);
	return Obj.begin*t + Obj.end*(1.0f - t);
}
Point Rand(const Capsule& Obj) noexcept {
	return {};
}
Point Rand(const Point& P, int xr, int yr) noexcept {
	return {};
}


//uniform_int_distribution<int> dist_i(0,0);
//uniform_int_distribution<float> dist_f(0.0f, 0.0f);
//bernoulli_distribution dist(0.0f);

int Rand(int num)noexcept {
	//uniform_int<int>::param_type prm(-num, num);
	//dist_i.param(prm);
	uniform_int_distribution<int> dist(-num, num);
	return dist(Random);
}
int Rand_NoMinus(int num) noexcept {
	uniform_int_distribution<int> dist(0, num);
	return dist(Random);
}
int Rand(int Value1, int Value2) {
	//uniform_int<int>::param_type prm(Value1, Value2);
	//dist_i.param(prm);
	uniform_int_distribution<int> dist(Value1, Value2);
	return dist(Random);
}
float Rand(float num)noexcept {
	uniform_real_distribution<float> dist(-num, num);
	return dist(Random);
}
float Rand_NoMinus(float num)noexcept {
	uniform_real_distribution<float> dist(0.0f, num);
	return dist(Random);
}
float Rand(float Value1, float Value2) {
	uniform_real_distribution<float> dist(Value1, Value2);
	return dist(Random);
}
bool Rand_TF(float parsentage)noexcept {
	bernoulli_distribution dist(parsentage);
	return dist(Random);
}