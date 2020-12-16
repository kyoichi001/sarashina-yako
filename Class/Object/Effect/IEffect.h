#pragma once

#include "../../../Library/Primitive/Primitive.h"

//�G�t�F�N�g��1�\������v���O����
class IEffect :public Point {
protected:
	int mTime, mLifeTime;
	bool mLiveFlag;
public:
	IEffect(const Point& XY, int LifeTime)noexcept;
	~IEffect()noexcept;
	void virtual Draw()const noexcept {}
	bool virtual Update(float t)noexcept { return false; }
	bool IsLive()const noexcept { return mLiveFlag; }
	void Kill()noexcept { mLiveFlag = false; }
};
