
#include "Vec3.h"
#include <cmath>

Vec3::Vec3() noexcept:x(0.0f), y(0.0f), z(0.0f) {}
Vec3::Vec3(float X, float Y, float Z) noexcept : x(X), y(Y), z(Z) {}
Vec3::~Vec3()noexcept {}

float Vec3::length()const noexcept { return sqrt(lengthSqu()); }

const  Vec3 Vec3::Zero{ 0.0f,0.0f,0.0f };
