
#include "MessageWindow.h"
#include "TalkData.h"

#include "DxLib.h"

MessageWindow::MessageWindow():mColor(0), mRect(50.0f,600.0f,580.0f,690.0f), mText("undefineded"){}

void MessageWindow::update(float t ){

}

void MessageWindow::draw()const {
	mRect.draw(0x000000);
	DrawString(mRect.tl.x, mRect.tl.y, mText.c_str(), mColor);
}