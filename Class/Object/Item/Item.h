#pragma once

#include "IItem.h"

class SubWeapon : public IItem {
protected:
	void UpdateObj(float t)noexcept override ;
public:
	SubWeapon(const Point& P)noexcept;
	~SubWeapon()noexcept;
	void Draw()const noexcept override;
	void Execute() noexcept override;
};
