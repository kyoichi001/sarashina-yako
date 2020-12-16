#pragma once

class Point;

class Texture {
	static int Many;
	int mHandle;
public:
	Texture()noexcept{}
	Texture(char* filename)noexcept;
	Texture(int Handle)noexcept;
	void set(int Handle)noexcept;
	void load(char* filename)noexcept;
	void draw(const Point& P)noexcept;
	void drawCenter(const Point& P)noexcept;
	void draw(const Point& P, float ExRate, float Angle,bool turnflag=false)noexcept;
	void filter(int FilterType,int value,int value2)noexcept;
	int getXSize()noexcept;
	int getYSize()noexcept;
	Point getSize()noexcept;
};
