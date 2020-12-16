#pragma once

#include "IWidget.h"
#include "../Renderer.h"
#include "../../Data/Data.h"
#include "WidgetFont.h"
#include "Cursor.h"

template<typename T>
class VolumeBar :public IWidget {
	T mMany, mValue;
	T* mValuePtr;
	WidgetFont mFont;
	void drawBar(Point& Cood)const noexcept  {
		const Point P = Cood + Point(150.0f, 50.0f);
		const Point Unit = Point(350.0f, 0.0f) / mMany;
		DxWrp::DrawLine(P, P + Unit * (mMany - 1), 0xFFFFFF, 2);
		for (int i = 0; i < mMany; ++i) {
			DxWrp::DrawCircle(P + Unit * i, 10, 0xFFFFFF);
		}
		const Point Current = P + Unit * mValue;
		DxWrp::DrawCircle(Current, 7, 0x5555FF);
		DxWrp::DrawFormatStringToHandle(Current + Point(0.0f, 30.0f), 0xFFFFFF, mFont.GetFont(), "%d", mValue);
	}
public:
	VolumeBar(const std::string& name, const WidgetFont& Font, T* Value, T Many)noexcept
		: IWidget(name), mFont(Font), mValuePtr(Value), mValue(0), mMany(Many) {
		width = mFont.GetWidth(name);
		height = mFont.GetSize(name);
	}

	void Update()noexcept override {}
	void Draw()const noexcept override {
		Point Cood = GetCood();
		mFont.Draw(mName,Cood, mState != 1);
		if (mState == 2) {
			drawBar(Cood);
		}
	}
	void goUp(Cursor* cursor)noexcept override { if (mState == 0&&mUp)cursor->SetWidget(mUp); }
	void goDown(Cursor* cursor)noexcept override { if (mState == 0 && mUp)cursor->SetWidget(mDown); }
	void goLeft(Cursor* cursor)noexcept override {
		switch (mState) {
		case 0:
			if (mLeft)cursor->SetWidget(mLeft);
			break;
		case 2:
			mValue = (mValue + mMany - 1) % mMany;
			break;
		}
	}
	void goRight(Cursor* cursor)noexcept override {
		switch (mState) {
		case 0:
			if (mLeft)cursor->SetWidget(mRight);
			break;
		case 2:
			mValue = (mValue + 1) % mMany;
			break;
		}
	}
	void Execute(Cursor* cursor)noexcept override {
		if (mState == 0) {
			mState = 2;
		}
		else if (mState == 2) *mValuePtr = mValue;
	};
	void  Cansel(Cursor* cursor) noexcept override {
		if (mState == 2) mState = 0;
	}
};

#include "../Primitive/toString.h"

//変数
template<typename T>
class Viewer :public IWidget {
	WidgetFont mFont;
	T* mVariable;
public:
	Viewer(const std::string& name, const WidgetFont& Font, T* Variable)noexcept 
		: IWidget(name),mFont(Font),mVariable(Variable) {
		width = mFont.GetWidth(name);
		height = mFont.GetSize(name);
	}

	void Update()noexcept override {}
	void Draw()const noexcept override {
		Point Cood = GetCood();
		mFont.Draw(mName + ": " + toString(*mVariable), Cood, mState != 1);
	}
	void goUp(Cursor* cursor)noexcept override {if(mUp) cursor->SetWidget(mUp); }
	void goDown(Cursor* cursor)noexcept override { if (mDown)cursor->SetWidget(mDown); }
	void goLeft(Cursor* cursor)noexcept override { if (mLeft)cursor->SetWidget(mLeft); }
	void goRight(Cursor* cursor)noexcept override { if (mRight)cursor->SetWidget(mRight); }
	void Execute(Cursor* cursor)noexcept override{}
	void Cansel(Cursor* cursor) noexcept override {}
};

template<typename T>
class Gauze :public IWidget {
	WidgetFont mFont;
	T* mVariable;
	T mMaxValue;
public:
	Gauze(const std::string& name, const WidgetFont& Font, T* Variable,T maxValue)noexcept
		: IWidget(name), mFont(Font), mVariable(Variable) , mMaxValue(maxValue){
		width = mFont.GetWidth(name);
		height = mFont.GetSize(name);
	}

	void Update()noexcept override {}
	void Draw()const noexcept override {
		const Point Cood = GetCood();
		mFont.Draw(mName, Cood, mState != 1);
		int boxX = Cood.x + width + 20;
		DxWrp::DrawBox(boxX, Cood.y, boxX + 100*float(*mVariable) / float(mMaxValue), Cood.y + height, 0xFF0000, true);
		DxWrp::DrawBox(boxX, Cood.y, boxX + 100, Cood.y + height, 0xFFFFFF, false);
		std::string gauze = toString(*mVariable) + "/" + toString(mMaxValue);
		DxWrp::DrawFormatString(boxX + 50, Cood.y, 0xFFFFFF, gauze.c_str(), 0.0f);
	}
	void goUp(Cursor* cursor)noexcept override { if (mUp) cursor->SetWidget(mUp); }
	void goDown(Cursor* cursor)noexcept override { if (mDown)cursor->SetWidget(mDown); }
	void goLeft(Cursor* cursor)noexcept override { if (mLeft)cursor->SetWidget(mLeft); }
	void goRight(Cursor* cursor)noexcept override { if (mRight)cursor->SetWidget(mRight); }

	void Execute(Cursor* cursor)noexcept override {}
	void Cansel(Cursor* cursor) noexcept override {
		cursor->SetWidget(mParent);
	}
};

#include <functional>

//選択肢
class Choice :public IWidget {
	WidgetFont mFont;
	std::function<void(void)> mCallBack;
public:
	Choice(const std::string& name, const WidgetFont& Font, std::function<void(void)> CallBack = []() {})noexcept;
	void Update()noexcept override{}
	void Draw()const noexcept override;
	void goUp(Cursor* cursor)noexcept override { if (mUp) cursor->SetWidget(mUp); }
	void goDown(Cursor* cursor)noexcept override { if (mDown)cursor->SetWidget(mDown); }
	void goLeft(Cursor* cursor)noexcept override { if (mLeft)cursor->SetWidget(mLeft); }
	void goRight(Cursor* cursor)noexcept override { if (mRight)cursor->SetWidget(mRight); }

	void Execute(Cursor* cursor)noexcept override;
	void Cansel(Cursor* cursor) noexcept override;
};

class Trriger :public IWidget {
	WidgetFont mFont;
	bool* mFlag;
public:
	Trriger(const std::string& name, const WidgetFont& Font, bool* Flag)noexcept;
	void Update()noexcept override {}
	void Draw()const noexcept override;
	void goUp(Cursor* cursor)noexcept override { if (mUp) cursor->SetWidget(mUp); }
	void goDown(Cursor* cursor)noexcept override { if (mDown)cursor->SetWidget(mDown); }
	void goLeft(Cursor* cursor)noexcept override { if (mLeft)cursor->SetWidget(mLeft); }
	void goRight(Cursor* cursor)noexcept override { if (mRight)cursor->SetWidget(mRight); }
	void Execute(Cursor* cursor)noexcept override;
	void Cansel(Cursor* cursor) noexcept override;
};


#include <vector>
#include <memory>
#include "WidgetList.h"

class Select :public IWidget {
	WidgetFont mFont;
	Vec2 mWidgetOfs;
	bool mSelected;
	//0: 選択肢を全部表示 1: アクティブな選択肢だけ表示 
	char mMode;
	WidgetList mList;
	std::string mActiveWidget;//選択されたとき最初にくるWidget
	std::function<void(int)> mCallback;//クラス内のWidgetが選択されたとき
public:
	Select(const std::string& name, const WidgetFont& Font, const  std::string& activeWidget, char Mode = 0, std::function<void(int)> callback = [](int index) {})noexcept;

	void Update()noexcept override;
	void Draw()const noexcept override;

	void goUp(Cursor* cursor)noexcept override;
	void goDown(Cursor* cursor)noexcept override;
	void goLeft(Cursor* cursor)noexcept override;
	void goRight(Cursor* cursor)noexcept override;
	void Execute(Cursor* cursor)noexcept override;
	void Cansel(Cursor* cursor)noexcept override;

	//基準点の座標をセットする
	void SetCood(const Point& P)noexcept { tl = P; }
	void SetWidgetOfs(const Vec2& V)noexcept { mWidgetOfs = V; }
	void Push(IWidget* Widget,bool selectableFlag=true)noexcept;
	void Push(const std::string& key, IWidget* Widget, bool selectableFlag = true)noexcept;
	IWidget& GetWidget(const std::string& key)noexcept { return *mList.getWidget(key); }
	template<typename T>
	T& GetWidget(const std::string& key)noexcept {
		return mList.getWidget<T>(key);
	}
};

class Tab :public IWidget {//state 0:タブを開いていない 2: タブを選択中 3:選択したタブのWidgetを表示宙
	WidgetList mList;
	Vec2 mWidgetOfs;
	Point mBeforeCood;
	IWidget* mParent;
public:
	Tab(const std::string& name,IWidget* parent=nullptr)noexcept;
	void Update()noexcept override;
	void Draw()const noexcept override;
	void goUp(Cursor* cursor)noexcept override;
	void goDown(Cursor* cursor)noexcept override;
	void goLeft(Cursor* cursor)noexcept override;
	void goRight(Cursor* cursor)noexcept override;
	void Execute(Cursor* cursor)noexcept override;
	void Cansel(Cursor* cursor) noexcept override;
	void Push(IWidget* Widget)noexcept;
	void Push(const std::string& key,IWidget* Widget)noexcept;
	void setOfs(Vec2& ofs) { mWidgetOfs = ofs; }
};

class TabContainer :public IWidget {
public:

};