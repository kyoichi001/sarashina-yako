#pragma once

#include "../../Library/Primitive/Primitive.h"
#include <string>

struct TalkData;

//イベント時会話を表示するウィンドウ
class MessageWindow {
	int mColor;
	std::string mText;
	Rect mRect;
public:
	MessageWindow();
	void update(float t = 1.0f);
	void draw()const;
	void setdata(int color, const std::string& text) { mColor = color; mText = text; }
};