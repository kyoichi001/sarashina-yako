
#pragma once

#include "../../../Library/Typedef.h"
#include "LeazerData.h"

class ILeazer;
class ILeazer2;

class Point;

enum BulletColor:char;
enum LeazerShape :char;
enum BulletState :char;

class ObjectAdaptor;

void SetLeazerAngleState(char LeazerAngleState)noexcept;

class LeazerFactory{
	ObjectAdaptor* mObj;
	static BulletState mLeazerAngleState;
	LeazerDatabase mDataBase;
public:

	LeazerFactory(ObjectAdaptor* Adaptor)noexcept;
	~LeazerFactory()noexcept;

	void Leazer01(uchar ID,uchar renewID, Point* parent, float angle,uchar FanMany, float open = 0.0f, uchar radius = 0)noexcept;

	void Leazer02 (uchar ID,uchar renewID,const Point& XY, uchar FanMany, float Angle, float Speed,float open = 0.0f, uchar radius = 0)noexcept;

	float GetLeazertoPlayerAngle(const Point& XY)noexcept;

	void setLeazerData(uchar ID, int cirMany, BulletColor color, LeazerShape shape, int till , int length=0,char AngleState = 0, char drawBlend = 0)noexcept;
	void clearLeazerData()noexcept;

	friend void SetLeazerAngleState(BulletState State)noexcept { LeazerFactory::mLeazerAngleState = State; }

};