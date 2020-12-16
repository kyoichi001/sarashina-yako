#pragma once

#include "IWidget.h"
#include "Cursor.h"
#include "WidgetList.h"

class Point;

class GUI :public IWidget {
	Cursor mCursor;
	Point mBeforeCood;
	Vec2 mVec;
	WidgetList mList;
	bool mActiveCursor;
public:
	GUI(const Point& P,bool activeCursor=true)noexcept;

	void Init(const std::string& activeWidgetID)noexcept;//widgetを登録した後に実行

	void Update()noexcept override;
	void Draw()const noexcept override;
	IWidget* Push(const std::string& key, IWidget* widget, bool selectableFlag = true);
	IWidget* Push(IWidget* widget, bool selectableFlag = true);
	void clearWidget();
	void link(const std::string& key, const std::string&  up, const std::string&  down = "", const std::string&  left = "", const std::string&  right = "")noexcept;

	//基準点の座標をセットする
	void SetCood(const Point& P)noexcept { tl = P; }
	void SetOfset(const Vec2& V)noexcept { mVec = V; }

	template<typename T>
	T& GetWidget(const std::string& key)noexcept {
		return mList.getWidget<T>(key);
	}
	void activate() { mActiveCursor = true; }
	void inactivate() { mActiveCursor = false; }
	void changeActiveWidget(const std::string& key);

	void onSelected(IWidget* before)override;

};
