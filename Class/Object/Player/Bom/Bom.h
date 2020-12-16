#pragma once

#include "IBom.h"

void InitBomResource()noexcept;

class PlayerHitBom :public IBom {
public:
	PlayerHitBom(const Point& XY)noexcept;
	bool Update(float t)noexcept override;
	void virtual Collided(IBullet& obj)override;
};
class PlayerBom :public IBom {
	int mAlpha;
	float mAngle;
public:
	PlayerBom(const Point& XY)noexcept;
	bool Update(float t)noexcept override;
	void Draw()const noexcept override;
	void virtual Collided(IBullet& obj)override;
};
class PlayerBom2 :public IBom {
	int mAlpha;
public:
	PlayerBom2(const Point& XY)noexcept;
	bool Update(float t)noexcept override;
	void Draw()const noexcept override;
	void virtual Collided(IBullet& obj)override;
};

class EnemyNext :public IBom {
public:
	EnemyNext(const Point& XY)noexcept;
	bool Update(float t)noexcept override;
	void virtual Collided(IBullet& obj)override;
};
class EnemyEnd :public IBom {
public:
	EnemyEnd(const Point& XY)noexcept;
	bool Update(float t)noexcept override;
	void virtual Collided(IBullet& obj)override;
};