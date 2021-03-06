
#pragma once

#include "../../../Library/Primitive/Primitive.h"

class IPlayer;

class IItem : public Circle{
protected:
	//0 生成された 1 動作中 2 自動回収 3 削除してよし
	char mState;
	static IPlayer* mPlayerPtr;
	Vec2 mSpeed;
	void virtual UpdateObj(float t)noexcept {  }
public:
	IItem(const Point& P)noexcept;
	~IItem()noexcept;
	bool  Update(float t)noexcept;
	void virtual Draw()const noexcept{}
	void Kill()noexcept;
	bool IsLive()const noexcept { return mState != 3; }
	void virtual Execute() noexcept=0;
	void Gather()noexcept;

	static void SetPlayerPtr(IPlayer* ptr)noexcept { mPlayerPtr = ptr; }
};
