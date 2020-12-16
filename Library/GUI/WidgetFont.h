#pragma once

#include <string>
class Point;

class WidgetFont {
	int mActiveColor, mInActiveColor;
	int mFont;
public:
	WidgetFont()noexcept;
	WidgetFont(int Font,int ActiveColor,int InActiveColor)noexcept;
	void Draw(const std::string& Text,const Point& P,bool ActiveFlag)const noexcept;
	int GetSize(const std::string& Text )const noexcept;
	int GetWidth(const std::string& Text)const noexcept;
	int GetFont()const noexcept { return mFont; }
};