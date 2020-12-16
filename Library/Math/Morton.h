#pragma once

class Point;
class Circle;
class Rect;
class Vec3;

class Emitter;

int getMorton(const Point& P, const Point& O, int cellX, int cellY)noexcept;
int getMorton(const Circle& p, const Point& O, int cellX, int cellY)noexcept;
int getMorton(const Vec3& p, const Point& O, int cellX, int cellY)noexcept;

int getMorton(const Point* P, const Point& O, int cellX, int cellY)noexcept;
int getMorton(const Circle* p, const Point& O, int cellX, int cellY)noexcept;
int getMorton(const Vec3* p, const Point& O, int cellX, int cellY)noexcept;

int getMorton(const Emitter* p, const Point& O, int cellX, int cellY)noexcept;
