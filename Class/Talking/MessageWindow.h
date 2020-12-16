#pragma once

#include "../../Library/Primitive/Primitive.h"
#include <string>

struct TalkData;

//�C�x���g����b��\������E�B���h�E
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