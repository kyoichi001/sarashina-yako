#pragma once

#include "../Primitive/Primitive.h"
#include <string>

class Cursor;
class IWidget :public Rect {
protected:
	std::string mName;
	//0 : �A�N�e�B�u 1:�@��A�N�e�B�u 
	char mState;
	IWidget* mParent;
public:
	IWidget * mUp; IWidget* mDown; IWidget* mLeft; IWidget* mRight;

	IWidget()noexcept;
	IWidget(const std::string& name)noexcept;
	virtual ~IWidget()noexcept{}

	void virtual Update()noexcept {}
	void virtual Draw()const noexcept {}

	void virtual goUp(Cursor* cursor)noexcept {}
	void virtual goDown(Cursor* cursor)noexcept {}
	void virtual goLeft(Cursor* cursor)noexcept {}
	void virtual goRight(Cursor* cursor)noexcept {}

	void Activate()noexcept;
	void InActivate()noexcept;

	void SetParent(IWidget* Parent)noexcept { mParent = Parent; }

	std::string getName()noexcept { return mName; }

	//���M�̑��΍��W���Z�b�g
	void SetCood(const Point& P)noexcept { tl = P; }
	Point GetCood()const noexcept {
		if (!mParent)return tl;
		return mParent->GetCood() +tl;
	}

	void virtual Execute(Cursor* cursor) noexcept { };
	void virtual Cansel(Cursor* cursor) noexcept { };
	void virtual onSelected(IWidget* before) {};


};