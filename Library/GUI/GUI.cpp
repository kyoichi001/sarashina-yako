
#include "GUI.h"
#include "../../Data/DATA.h"

GUI::GUI(const Point& P, bool activeCursor)noexcept:IWidget(""), mBeforeCood(Point::Zero), mVec(0.0f,50.0f),mActiveCursor(activeCursor) {
	tl = P;
	mState = 1;
}

void GUI::Init(const std::string& activeWidgetID)noexcept {
	if (mList.empty()) return;
	IWidget* wid = mList.getWidget(activeWidgetID);
	wid->Activate();
	mCursor.SetWidget(wid);
	mState = 0;
}

void GUI::Update()noexcept {
	if (mList.empty())return;
	if (mState != 2) {
		mList.update();
		if (mActiveCursor) {
			mCursor.Update();
		}
	}
}
void GUI::Draw()const noexcept {
	if (mList.empty())return;
	mList.draw();
	if (mActiveCursor) {
		mCursor.Draw();
	}
}

IWidget* GUI::Push(IWidget* widget, bool selectableFlag) {
	return Push(widget->getName(), widget, selectableFlag);
}

IWidget* GUI::Push(const std::string& key, IWidget* widget, bool selectableFlag ) {
	IWidget* w = mList.push(key, widget, selectableFlag);
	w->SetParent(this);
	if (mList.size()==1) {//‰‚ß‚Äpush‚³‚ê‚½‚Æ‚«
		mBeforeCood = Point::Zero;
		w->SetCood(Point::Zero);
	}
	else {
		mBeforeCood += mVec;
		w->SetCood(mBeforeCood);
	}
	return w;
}
void GUI::clearWidget() {
	mList.clear();
}

void GUI::link(const std::string& key, const std::string&  up, const std::string&  down, const std::string&  left, const std::string&  right)noexcept {
	mList.link(key, up, down, left, right);
}

void GUI::changeActiveWidget(const std::string& key) {
	mCursor.SetWidget(mList.getWidget(key));
}

void GUI::onSelected(IWidget* before){
	mCursor.SetWidget(before);
}
