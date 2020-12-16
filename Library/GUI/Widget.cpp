#include "Widget.h"

int Loop(int cursor, int num)noexcept { return (cursor + 1) % num; }
int LoopBack(int cursor, int num)noexcept { return (cursor + num - 1) % num; }

Choice::Choice(const std::string& name, const WidgetFont& Font, std::function<void()> CallBack)noexcept:
IWidget(name),mFont(Font),mCallBack(CallBack){
	width = mFont.GetWidth(name);
	height = mFont.GetSize(name);
}

void Choice::Draw()const noexcept {
	mFont.Draw(mName,GetCood(), mState == 0);
}
void Choice::Execute(Cursor* cursor)noexcept {
	mCallBack();
}
void Choice::Cansel(Cursor* cursor) noexcept {
	cursor->SetWidget(mParent);
}

Trriger::Trriger(const std::string& name, const WidgetFont& Font, bool* Flag)noexcept :
IWidget(name),mFont(Font), mFlag(Flag){

}

void Trriger::Draw()const noexcept {
	Point p = GetCood();
	mFont.Draw(mName,p, mState == 0);
	DxWrp::DrawCircle(p+ Point{ 30.0f, 0.0f }, 15, 0xFFFFFF);
}

void Trriger::Execute(Cursor* cursor)noexcept {
	*mFlag = !*mFlag;
}
void Trriger::Cansel(Cursor* cursor) noexcept {
	cursor->SetWidget(mParent);
}

Select::Select(const std::string& name, const WidgetFont& Font, const  std::string& activeWidget, char Mode, std::function<void(int)> callback)noexcept :
IWidget(name), mFont(Font),mMode(Mode),mCallback(callback), mWidgetOfs(0.0f,50.0f),mActiveWidget(activeWidget), mSelected(false){
	width = mFont.GetWidth(name);
	height = mFont.GetSize(name);
}

void Select::Update()noexcept {
	if (mState == 2) {//‘I‘ð‚³‚ê‚½‚Æ‚«
		mList.update();
	}
}

void  Select::Draw()const noexcept {
	Point a = GetCood();
	mFont.Draw(mName,a, mState == 0);
	if (mSelected) {//‘I‘ð‚³‚ê‚½‚Æ‚«
		if (mMode == 0) {
			mList.draw();
		}
		else {
			mList.draw();
			//mList.getActiveWidget()->Draw();
		}
	}
}

void Select::goUp(Cursor* cursor)noexcept { if (mUp) cursor->SetWidget(mUp); }
void Select::goDown(Cursor* cursor)noexcept { if (mDown) cursor->SetWidget(mDown); }
void Select::goLeft(Cursor* cursor)noexcept { if (mLeft) cursor->SetWidget(mLeft); }
void Select::goRight(Cursor* cursor)noexcept { if (mRight) cursor->SetWidget(mRight); }

void Select::Execute(Cursor* cursor)noexcept {
	if (mState == 0) {
		mSelected = true;
		cursor->SetWidget(mList.getWidget(mActiveWidget));
	}
	else if (mState == 2) {
	}
}
void Select::Cansel(Cursor* cursor)noexcept {
	//mState = 0;
	cursor->SetWidget(mParent);
	mSelected = false;
}

void  Select::Push( IWidget* Widget, bool selectableFlag )noexcept {
	Push(Widget->getName(), Widget);
}
void  Select::Push(const std::string& key, IWidget* Widget, bool selectableFlag )noexcept {
	mList.push(key, Widget,selectableFlag)->SetParent(this);
	if (mList.size()==1) {
		Widget->SetCood({ 100.0f,20.0f });
	}
	else {
		Widget->SetCood(Widget->mUp->tl + mWidgetOfs);
	}
}

Tab::Tab(const std::string& name, IWidget* parent)noexcept:IWidget(name), mParent(parent) {
	mWidgetOfs = { 0.0f,50.0f };
	width = 80;//mFont.GetWidth(name);
	height = 30;//mFont.GetSize(name);
}
void Tab::Update()noexcept {
}
void Tab::Draw()const noexcept {
	//DxWrp::DrawStringToHandle(tl,mName.c_str(),0xFFFFFF);
	const Point Cood = GetCood();
	switch (mState) {
	case 0:
		DxWrp::DrawBox(Cood,height,width,0xFFFFFF);
		mList.draw();
		break;
	case 1:
		DxWrp::DrawBox(Cood, height, width, 0x555555);
		break;
	case 2:
		DxWrp::DrawBox(Cood, height, width, 0xFFFFFF);
		mList.draw();
		break;
	case 3:
	default:
		DxWrp::DrawBox(Cood, height, width, 0x99999);
		mList.draw();
		break;
	}
}
void Tab::goUp(Cursor* cursor)noexcept   {
	switch(mState) {
	case 0:
		if (mUp)cursor->SetWidget(mUp);
		break;
	case 2:
		break;
	}
}
void Tab::goDown(Cursor* cursor)noexcept {
	switch (mState) {
	case 0:
		if (mDown)cursor->SetWidget(mDown);
		break;
	case 2:
		break;
	}
}

void Tab::goLeft(Cursor* cursor)noexcept {
	switch (mState) {
	case 0:
		if (mLeft)cursor->SetWidget(mLeft);
		break;
	}

}
void Tab::goRight(Cursor* cursor)noexcept {
	switch (mState) {
	case 0:
		if (mRight)cursor->SetWidget(mRight);
		break;
	}
}

void Tab::Execute(Cursor* cursor)noexcept {
	switch (mState) {
	case 0:
		mState = 2;
		break;
	case 2:
		break;
	}
}
void Tab::Cansel(Cursor* cursor) noexcept {
	switch (mState) {
	case 0:		
		cursor->SetWidget(mParent);
		break;
	case 2:
		mState = 0;
		break;
	}
}
void Tab::Push(IWidget* Widget)noexcept {
	Push( Widget->getName(), Widget);
}

void Tab::Push(const std::string& key, IWidget* Widget)noexcept {
	IWidget* w = mList.push(key, Widget);
	w->SetParent(this);
	Point parentCood = -tl + Vec2{0.0f,80.0f};
	if (mList.size() == 1) {//‰‚ß‚Äpush‚³‚ê‚½‚Æ‚«
		w->SetCood(parentCood);
		mBeforeCood = parentCood;
	}
	else {
		mBeforeCood += mWidgetOfs;
		w->SetCood(mBeforeCood);
	}
}
