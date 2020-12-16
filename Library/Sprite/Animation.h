#pragma once

class Point;

#include <vector>

class Animation {
	std::vector<int> mHdl;
	int mInterval;
	int mSize;
public:
	Animation(const std::vector<int>& Handle, int Interval)noexcept;
	Animation(const int* Handle, int Size, int Interval)noexcept;
	Animation()noexcept: mHdl(0), mInterval(0) {}
	void Set(int Interval,const int* Handle,int Size)noexcept;
	void Regster(int Handle)noexcept;
	void Regster(const char* Handle)noexcept;
	void Regster(const char* Handle,int AllMany,int xMany,int yMany,int xSize,int ySize)noexcept;
	void Draw(const Point& P, int t, float Angle, float ExRate = 1.0f)const noexcept;
	void Draw(const Point& P, int t)const noexcept;
};