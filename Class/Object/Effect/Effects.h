
#pragma once

#include "IEffect.h"

void LoadEffectResource()noexcept;

//===========================================================================================================================
//
//bullet
//
//===========================================================================================================================

enum BulletColor :char;

class BulletEffect :public IEffect {
	float mExRate;
	BulletColor mColor;
public:
	BulletEffect(const Point& XY,  BulletColor Color)noexcept;
	bool Update(float t)noexcept override;
	void Draw()const noexcept override;
};
class BulletBreak :public IEffect {
	float mExRate;
	BulletColor mColor;
public:
	BulletBreak(const Point& XY, float ExRate, int LifeTime, BulletColor Color)noexcept;
	bool Update(float t)noexcept override;
	void Draw()const noexcept override;
};

//===========================================================================================================================
//
//enemy
//
//===========================================================================================================================

class EnemyBreak :public IEffect {
	Vec2 mSpeed;
	float mHdlAngle, mExRate;
public:
	EnemyBreak(const Point& XY, const Vec2& Speed,int LifeTime)noexcept;
	bool Update(float t)noexcept override;
	void Draw()const noexcept override;
};

class BossBreak :public IEffect {
	Vec2 mSpeed, mAccel;
	float mHdlAngle, mExRate;
public:
	BossBreak(const Point& XY, const Vec2& Speed, float ExRate, int LifeTime, const Vec2& Accel = {})noexcept;
	bool Update(float t)noexcept override;
	void Draw()const noexcept override;
};

class EnemyBack :public IEffect {
	Point* mParent;
	float Angle, ExRate;
	int mHandle;
public:
	EnemyBack(Point* XY, int Handle)noexcept;
	bool Update(float t)noexcept override;
	void Draw()const noexcept override;
};

class EnemyName :public IEffect {
	char* mName;
public:
	EnemyName(char* Name)noexcept;
	bool Update(float t)noexcept override { return true; }
	void Draw()const noexcept override;
};

class EnemyHP :public IEffect {
	Point* mParent;
	int* mHP;
	int mHPBef, mHPAf;
	int mDispHP, mMaxHP;
	bool mEaseFlag;
public:
	EnemyHP(Point* XY, int* HP, int MaxHP)noexcept;
	bool Update(float t)noexcept override;
	void Draw()const noexcept override;
};

class EnemyMarker :public IEffect {
	Point* mParent;
public:
	EnemyMarker(Point* XY)noexcept;
	bool Update(float t)noexcept override;
	void Draw()const noexcept override;
};

class EnemyDamage :public IEffect {
	int mDamage, mAlpha;
public:
	EnemyDamage(const Point& XY, int Damage)noexcept;
	bool Update(float t)noexcept override;
	void Draw()const noexcept override;
};

class BattleStart :public IEffect {
	int mAlpha;
public:
	BattleStart(int duration)noexcept;
	bool Update(float t)noexcept override;
	void Draw()const noexcept override;
};

//===========================================================================================================================
//
//player
//
//===========================================================================================================================

class PlayerBulletHit :public IEffect {
	Vec2 mSpeed;
	float mExRate;
public:
	PlayerBulletHit(const Point& XY, const Vec2& Speed, int LifeTime)noexcept;
	bool Update(float t)noexcept override;
	void Draw()const noexcept override;
};
class PlayerHit :public IEffect {
	Vec2 mSpeed;
	float mExRate;
	float mHdlAngle;
public:
	PlayerHit(const Point& XY, const Vec2& Speed, int LifeTime)noexcept;
	bool Update(float t)noexcept override;
	void Draw()const noexcept override;
};
class PlayerCore :public IEffect {
	Point* mParent;
	bool* mObserver;
	float Angle;
public:
	PlayerCore(Point* XY, bool* Observer)noexcept;
	bool Update(float t)noexcept override;
	void Draw()const noexcept override;
};

//===========================================================================================================================
//
//stage 
//
//===========================================================================================================================

class StageTitle :public IEffect {
	int mAlpha;
	int mStageNum;
public:
	StageTitle(const Point& XY,int StageNum)noexcept;
	bool Update(float t)noexcept override;
	void Draw()const noexcept override;
};

class StageBack :public IEffect {
	int mAlpha,mAlphaMax,mDarkTime;
public:
	StageBack(int Alpha,int Duration,int DarkTime)noexcept;
	bool Update(float t)noexcept override;
	void Draw()const noexcept override;
};

class StageClear :public IEffect {
	int mAlpha;
public:
	StageClear(int Duration)noexcept;
	bool Update(float t)noexcept override;
	void Draw()const noexcept override;
};

class ItemBorder :public IEffect {

public:
	ItemBorder(int Duration)noexcept;
	bool Update(float t)noexcept override;
	void Draw()const noexcept override;
};

//===========================================================================================================================
//
//window effect
//
//===========================================================================================================================

class FadeOut :public IEffect {
	int mColor;
	int mFadeOutFlame;
public:
	FadeOut(int color,int fadeOutFlame, int Duration)noexcept;
	bool Update(float t)noexcept override;
	void Draw()const noexcept override;
};

class FadeIn :public IEffect {
	int mColor;
public:
	FadeIn(int color, int Duration)noexcept;
	bool Update(float t)noexcept override;
	void Draw()const noexcept override;
};
//===========================================================================================================================
//
//common
//
//===========================================================================================================================

class Message :public IEffect {
	const char* mMessage;
public:
	Message(const Point& p,const char* massage,int Duration)noexcept;
	bool Update(float t)noexcept override;
	void Draw()const noexcept override;
};