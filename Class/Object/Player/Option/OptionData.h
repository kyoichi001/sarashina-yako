
#pragma once

#include "IOption.h"

void InitOptionResource()noexcept;

class OptionInvisible :public IOption {
public:
	OptionInvisible(Point* XY, const Vec2& dif)noexcept;
	void Shoot()noexcept override;
};
class OptionHorming :public IOption{
public:
	OptionHorming(Point* XY, const Vec2& dif)noexcept;
	void Draw()const noexcept override;
	void Shoot()noexcept override;
};
class OptionWind :public IOption{
	float mAngle,mLength;
	bool mMoveSign;
public:
	OptionWind(Point* XY, char typeNum)noexcept;
	bool  Update(float t)noexcept override;
	void Shoot()noexcept override;
	void Draw()const noexcept override;
};
class OptionBom :public IOption {
public:
	OptionBom(Point* XY, const Vec2& dif)noexcept;
	void Shoot()noexcept override;
};
class OptionBom2 :public IOption {
	bool mShootFlag;
	int mShotCount;
public:
	OptionBom2(Point* XY, const Vec2& dif)noexcept;
	bool  Update(float t)noexcept override;
	void Shoot()noexcept override;
};

