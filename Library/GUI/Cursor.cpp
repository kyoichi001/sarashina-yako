
#include "Cursor.h"
#include "IWidget.h"
#include "../../Data/DATA.h"
#include "../Renderer.h"

Cursor::Cursor()noexcept:mWidget(nullptr){}

void Cursor::Update()noexcept{
	if (Key[Data.Key.Button16] == 1) {
		mWidget->Execute(this);
	}
	if (Key[Data.Key.Button32] == 1) {
		mWidget->Cansel(this);
	}

	if (Key[Data.Key.Button02] == 1) mWidget->goDown(this);
	if (Key[Data.Key.Button01] == 1)  mWidget->goUp(this);
	if (Key[Data.Key.Button08] == 1)  mWidget->goRight(this);
	if (Key[Data.Key.Button04] == 1)  mWidget->goLeft(this);
}

void Cursor::Draw()const noexcept {
	Point cood = mWidget->GetCood();
	DxWrp::DrawBox(cood, mWidget->height, mWidget->width, 0xFFFFFF, false);
	//mWidget->draw(0xFFFFFF, false);
}
void Cursor::SetWidget(IWidget* Widget)noexcept {
	IWidget* before = mWidget;
	if (before) {
		mWidget->InActivate();
	}
	mWidget = Widget;
	mWidget->Activate();
	Widget->onSelected(before);
}
