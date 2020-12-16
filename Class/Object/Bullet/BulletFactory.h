
#pragma once

#include "../../../Library/Typedef.h"
//#include "../../MediatorClass/ObjectAdaptor.h"
#include "../../../Library/ObjectList/ObjectListClass.h"
#include "BulletEmitter.h"
#include "RenewManager.h"
#include "DammakuData.h"

class Point;
class ObjectAdaptor;
class IBullet;
struct BulletData;

enum BulletColor:char;
enum BulletShape :char;
enum BulletState :char;

class BulletFactory{
	ObjectAdaptor* mObj;
	ObjectList<Emitter>& mEmi;
	BulletDatabase mDataBase;
	bool mAddFlag;//íeÇê∂ê¨Ç≥ÇπÇÈÇ©Ç«Ç§Ç©

	using func = void(*)(IBullet&, int, ObjectAdaptor&);

public:
	BulletFactory(ObjectAdaptor* Adaptor)noexcept;
	~BulletFactory()noexcept;

	void Bullet(uchar ID,uchar renewID, const Point& XY, uchar fanMany, float Angle, float Speed, float open=0.0f, short radius = 0)noexcept;

	template<typename T>
	BEmitter* BulletEmitter(uchar ID, uchar renewID, T* Cood, uchar fanMany,uchar Interval, unsigned ShotTime, float Angle, float Speed, float open = 0.0f,  short Radius = 0)noexcept {
		return static_cast<BEmitter*>(mEmi.SetObject(new BEmitter(ID, renewID,Cood, fanMany, Interval, ShotTime, Angle, Speed, open,Radius)));
	}

	void BulletForeach(int ID, func Func)noexcept;

	void setDammakuData(uchar ID, int cirMany, BulletColor color, BulletShape shape, int till = 0, char AngleState = 0, char drawBlend = 0,char polygon=0)noexcept;
	void clearDammakuData()noexcept;

	void clear_emi()noexcept;

	float GetBullettoPlayerAngle(const Point& XY)const noexcept;
	BulletDatabase& getData()noexcept { return mDataBase; }
	static BulletData* getBulletData(BulletShape shape)noexcept;

};