
#pragma once

#include "IPBullet.h"

void InitPBulletResource()noexcept;

class BulletNormal :public IPBullet {
	Vec2 mSpeed;
public:
	BulletNormal(const Point& p, float Speed);
	bool virtual Update(float t)noexcept override;
	void virtual Draw()const noexcept;
	void virtual Finalize()noexcept override;
	void virtual Collided(IGhost& obj)override;
	void virtual Collided(IBoss& obj)override;
};
class BulletHorming :public IPBullet {
	Vec2 mSpeed;
public:
	BulletHorming(const Point& p, float Speed);
	bool virtual Update(float t)noexcept override;
	void virtual Draw()const noexcept;
	void virtual Finalize()noexcept override;
	void virtual Collided(IGhost& obj)override;
	void virtual Collided(IBoss& obj)override;
};
class BulletWind :public IPBullet {
	Vec2 mSpeed;
public:
	BulletWind(const Point& p, float Speed,float angle);
	bool virtual Update(float t)noexcept override;
	void virtual Draw()const noexcept;
	void virtual Finalize()noexcept override;
	void virtual Collided(IGhost& obj)override;
	void virtual Collided(IBoss& obj)override;
};