
#pragma once

#include "../../../Library/Primitive/Primitive.h"
#include "../../../Library/Typedef.h"
#include "../../../Data/Data.h"

enum BulletColor :char;
class ObjectAdaptor;
class BulletRenewManager;
struct DammakuData;

struct BulletData {
	void(*Draw)(const Point&,const Vec2&, BulletColor, int);
	int radius,graze;
};

class IBullet :public Circle{
	static ObjectAdaptor* mCList;
	static DammakuData* mBul;
	static float TurnAngle;
	uchar mRenewID,mID;
	bool mLiveFlag;
	Vec2 mSpeed;
	BulletColor mColor;
	float mTime;
	Point* mParent;
	BulletData* mData;
public:
	IBullet()noexcept;
	IBullet(uchar ID, uchar renewID,const Point& XY, const Vec2& Speed, BulletColor Color, Point* Parent, BulletData* Data)noexcept;
	void Init(uchar ID, uchar renewID, const Point& XY, const Vec2& Speed, BulletColor Color, Point* Parent, BulletData* Data)noexcept;
	~IBullet()noexcept{}
	bool Update(float t = 1.0f)noexcept;
	void Draw()const noexcept;
	bool IsLive()const noexcept { return mLiveFlag; }
	int GetTime()const noexcept { return mTime; }
	uchar GetID()const noexcept { return mID; }
	Vec2 GetSpeed()const noexcept { return mSpeed; }
	void Kill()noexcept;
	void Erace() noexcept { mLiveFlag = false; }
	bool IsOver()const noexcept;

	static void UpdateTurnAngle()noexcept { TurnAngle += 0.01f; }
	static float getTurnAngle() noexcept { return TurnAngle; }
	void static SetClassList(ObjectAdaptor* ClassListPtr)noexcept;

	void Turn(float Angle)noexcept;
	void Accel(float Speed)noexcept;
	void SetSpeed(const Vec2& Speed)noexcept;
	void Remake(BulletColor Color, BulletShape obj = NoShape)noexcept;
	void Renew(float Angle,float Speed,BulletState AngleState=Absolute, BulletState SpeedState = Absolute)noexcept;
	void Split(uchar ID,uchar renewID,  uchar FanMany, float Angle, float Speed, float open = 0.0f,  bool LiveFlag = false)noexcept;
	void Rotate(const Point& P, float Angle)noexcept;
	bool isReflected(uchar reflectflag, Point& Cood, Vec2& Speed)noexcept;
	void Force(const Vec2&& Accel)noexcept;
	void Link(Point* Parent)noexcept { mParent = Parent; }

#ifdef _DEBUG
public:
	void DrawHit()noexcept;
	void DrawGraze()noexcept;
	void DrawSpeed()noexcept;
	void DrawValue()noexcept;
#endif
};
