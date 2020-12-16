
#include "../Renderer.h"
#include "WidgetFont.h"

WidgetFont::WidgetFont()noexcept :mFont(0), mActiveColor(0x000000), mInActiveColor(0x000000) {}
WidgetFont::WidgetFont(int Font, int ActiveColor, int InActiveColor)noexcept:mFont(Font),mActiveColor(ActiveColor),mInActiveColor(InActiveColor){}
void WidgetFont::Draw(const std::string& Text,const Point& P, bool ActiveFlag)const noexcept {
	DxWrp::DrawStringToHandle(P, Text.c_str(), ActiveFlag ? mActiveColor : mInActiveColor, mFont);
}
int WidgetFont::GetSize(const std::string& Text)const noexcept{
	return DxWrp::GetFontSize(mFont);
}
int WidgetFont::GetWidth(const std::string& Text)const noexcept{
	return DxWrp::GetDrawStringWidthToHandle(Text.c_str(), Text.size(), mFont);
}