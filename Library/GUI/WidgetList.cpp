
#include "WidgetList.h"
#include "Cursor.h"

WidgetList::WidgetList()noexcept:mBeforeWidget(nullptr){}

IWidget* WidgetList::push(const std::string& key, IWidget* widget, bool selectableFlag) noexcept {
	widget->mUp = mBeforeWidget;
	if (selectableFlag) {
		if (mBeforeWidget)mBeforeWidget->mDown = widget;
		mBeforeWidget = widget;
	}
	mMap.emplace(key,widget);
	return mMap[key].get();
}
IWidget* WidgetList::push(IWidget* widget, bool selectableFlag ) noexcept {
	return push(widget->getName(), widget, selectableFlag);
}
IWidget* WidgetList::push(IWidget* widget, const std::string&  up, const std::string&  down, const std::string&  left, const std::string&  right)noexcept {
	return push(widget->getName(), widget, up, down, left, right);
}
IWidget* WidgetList::push(const std::string& key, IWidget* widget, const std::string&  up, const std::string&  down, const std::string&  left, const std::string&  right)noexcept {
	IWidget* wUp = getWidget(up);
	widget->mUp = wUp;
	if (wUp)wUp->mDown = widget;
	IWidget* wDown = getWidget(down);
	widget->mDown = wDown;
	if (wDown)wDown->mUp = widget;
	IWidget* wLeft = getWidget(left);
	widget->mLeft = wLeft;
	if (wLeft)wLeft->mRight = widget;
	IWidget* wRight = getWidget(right);
	widget->mRight = wRight;
	if (wRight)wRight->mLeft = widget;

	mMap.emplace(key, widget);
	mBeforeWidget = widget;
	return mMap[key].get();
}
void WidgetList::link(const std::string& key, const std::string&  up, const std::string&  down, const std::string&  left, const std::string&  right) noexcept {
	if (!down.empty())mMap[key]->mDown = mMap[down].get();
	if (!up.empty())mMap[key]->mUp = mMap[up].get();
	if (!left.empty())mMap[key]->mLeft = mMap[left].get();
	if (!right.empty())mMap[key]->mRight = mMap[right].get();
}

void WidgetList::update()noexcept {
	for (auto& i : mMap) {
		i.second->Update();
	}
}
void WidgetList::draw()const noexcept {
	for (auto& i : mMap) {
		i.second->Draw();
	}
}

void WidgetList::foreach(void(*func)(IWidget*))noexcept {
	for (auto&i : mMap) {
		func(i.second.get());
	}
}

