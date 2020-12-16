
#pragma once

#include "../../../Library/Primitive/Primitive.h"
#include "../../../Library/Typedef.h"

enum BulletColor:char;
enum LeazerShape :char;

class ObjectAdaptor;

struct LeazerData {
	//begin , end ,widthRate , color , time
	void(*Draw)(const Point&, const Point&,float, BulletColor, int);
	int radius, graze;
};

class ILeazer {
	static ObjectAdaptor* mList;
	Point* mParent;
	Point mOfs,mEnd;
	float mAngle;
	//0: 予告線 1:発生中 2:起動完了 3:消去中 4:消去完了(終了)
	char mState;
	LeazerData* mData;
	BulletColor mColor;
	int mTime, mTill;
	uchar mID, mRenewID;
public:
	ILeazer(uchar ID, uchar renewID, const Point& ofs, float angle,Point* Parent, BulletColor Color, LeazerData* Data, int till)noexcept;
	~ILeazer()noexcept;
	bool Update(float t)noexcept;
	void Draw()const noexcept;
	bool IsLive()const noexcept { return mState != 4; }
	bool IsActive()const noexcept { return mState ==2||mState==1; }
	void Kill()noexcept{ mState = 3; }
	HalfLine getasHalfLine()const noexcept { return HalfLine{ *mParent + mOfs,mAngle }; }
	Segment getasSegment()const noexcept { return Segment{ *mParent + mOfs,mEnd }; }

	void rotate(float deltaangle)noexcept { mAngle += deltaangle; }
	void setAngle(float angle)noexcept { mAngle = angle; }
	//position : 0.0f レーザーの始点 1.0f レーザーの終点(壁に当たっている場所)
	void splitBullet(uchar ID,uchar renewID,float position, uchar FanMany, float Angle, float Speed, float open = 0.0f);

	static void setAdaptor(ObjectAdaptor* adoptor) noexcept { mList = adoptor; }
};

class ILeazer2 :public Segment {
	static ObjectAdaptor* mList;
	Vec2 mSpeed;
	bool mLiveFlag;
	LeazerData* mData;
	BulletColor mColor;
	int mTime, mTill;
	uchar mID, mRenewID;
	float mLength;
public:
	ILeazer2(uchar ID, uchar renewID, const Point& p,const Vec2& speed, float length, BulletColor Color, LeazerData* Data, int till = 0)noexcept;
	ILeazer2()noexcept;
	~ILeazer2()noexcept;
	bool Update(float t)noexcept;
	void Draw()const noexcept;
	bool IsLive()const noexcept { return mLiveFlag; }
	void Kill()noexcept { mLiveFlag = false; }
	static void setAdaptor(ObjectAdaptor* adoptor) noexcept { mList = adoptor; }

};