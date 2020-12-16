
#include "BulletFactory.h"
#include "IBullet.h"
#include "../../../Library/Func.h"
#include "../../../Library/Renderer.h"
#include "../../../Library/Math/Constant.h"
#include "../../../Library/Easing/InterpolationMethod.h"
#include "../../MediatorClass/ObjectAdaptor.h"
#include "RenewManager.h"

#include <cmath>

inline float getCirAngle(int num, int many) noexcept {return float(num) * PI2 / float(many);}
inline float getFanAngle(int num, float open, int many)noexcept {
	return open * (float(num) - float(many - 1) / 2.0f);//-open * (float(many - 1) / 2.0f) + num * open;
}
inline float getFanAngleOpen(int num, float open, int many) noexcept {
	return  -(open *0.5f) + open * num / (many - 1);
}
inline float getCirFanAngle(int num, float open, int cirmany, int fanmany) noexcept {
	return getCirAngle(num / fanmany, cirmany) + getFanAngle(num%fanmany, open, fanmany);
}
inline float getCirFanAngle(int cirnum,int fannum, float open, int cirmany, int fanmany) noexcept {
	return getCirAngle(cirnum, cirmany) + getFanAngle(fannum, open, fanmany);
}
inline float getPolygonRadiusRv(int VartexMany, float Angle)noexcept {
	return cosf(fmodf(Angle, PI2 / float(VartexMany)) - PI / float(VartexMany));
}
inline float getPolygonStarRadiusRv(int VartexMany, float Angle) noexcept {
	return cosf(fmodf(Angle, PI4 / VartexMany) - PI2 / VartexMany);
}

int SmallBHdl[10], MidiumBHdl[10], BigBHdl[10], ArrowBHdl[10], FudaBHdl[10], VeryBigBHdl[10];
int PetalHdl[10], WaterHdl[10];
int SmallOvalHdl[10], BigOvalHdl[10], LeafHdl[10],TrumpHdl[10];
int FireHdl[4],GemHdl[10];

BulletData BVoid   { [](const Point& XY,const Vec2& Speed, BulletColor Color,int t) {},-1,-1 };
BulletData BSmall  { [](const Point& XY,const Vec2& Speed, BulletColor Color,int t) {DxWrp::DrawGraph(XY.x - 6, XY.y - 6, SmallBHdl[Color]); },1,4 };
BulletData BMidium { [](const Point& XY,const Vec2& Speed, BulletColor Color,int t) {DxWrp::DrawGraph(XY.x - 8, XY.y - 8, MidiumBHdl[Color]); },2,8 };
BulletData BBig    { [](const Point& XY,const Vec2& Speed, BulletColor Color,int t) {DxWrp::DrawGraph(XY.x - 16,XY.y - 16, BigBHdl[Color]); },8,14 };
BulletData BArrow  { [](const Point& XY,const Vec2& Speed, BulletColor Color,int t) {DxWrp::DrawRotaGraph(XY ,1.0f, Speed.Angle() + HALF_PI, ArrowBHdl[Color]); },4,10 };
BulletData BFuda   { [](const Point& XY,const Vec2& Speed, BulletColor Color,int t) {DxWrp::DrawRotaGraph(XY ,1.0f, Speed.Angle() - HALF_PI, FudaBHdl[Color]); },2,10 };
BulletData BHuge   { [](const Point& XY,const Vec2& Speed, BulletColor Color,int t) {DxWrp::DrawRotaGraph(XY ,lerp(0.0f,1.0f,0,5,t,Ease<Liner>::In),IBullet::getTurnAngle() , VeryBigBHdl[Color]); },18,30 };
BulletData BWater  { [](const Point& XY,const Vec2& Speed, BulletColor Color,int t) {DxWrp::DrawRotaGraph(XY ,1.0f, Speed.Angle() +HALF_PI, WaterHdl[Color]); },3,10 };
BulletData BLeaf   { [](const Point& XY,const Vec2& Speed, BulletColor Color,int t) {DxWrp::DrawRotaGraph(XY ,1.0f, Speed.Angle() +HALF_PI, LeafHdl[Color]); },3 ,10};
BulletData BSOval  { [](const Point& XY,const Vec2& Speed, BulletColor Color,int t) {DxWrp::DrawRotaGraph(XY ,1.0f, Speed.Angle() +HALF_PI, SmallOvalHdl[Color]); },4,6 };
BulletData BLOval  { [](const Point& XY,const Vec2& Speed, BulletColor Color,int t) {DxWrp::DrawRotaGraph(XY ,1.8f, Speed.Angle() +HALF_PI, SmallOvalHdl[Color]); },4,6 };
BulletData BFire   { [](const Point& XY,const Vec2& Speed, BulletColor Color,int t) {
	DxWrp::SetDrawBlendMode(BLEND_ADD,255);
	DxWrp::DrawRotaGraph(XY- Speed.normed()*37.0f,lerp(0.0f,1.0f,0,10,t,Ease<Liner>::In), Speed.Angle() - HALF_PI, FireHdl[(t / 6) % 3 + 1]);
	DxWrp::ResetBlendModeAdd();
	DxWrp::DrawRotaGraph(XY - Speed.normed()*37.0f, lerp(0.0f, 1.0f, 0, 10, t, Ease<Liner>::In), Speed.Angle() - HALF_PI, FireHdl[0]);
},50,64 };
BulletData BTrump{ [](const Point& XY,const Vec2& Speed, BulletColor Color,int t) {DxWrp::DrawRotaGraph(XY ,1.0f, Speed.Angle() + HALF_PI, TrumpHdl[Color]); },2,6 };
BulletData BGem{ [](const Point& XY,const Vec2& Speed, BulletColor Color,int t) {DxWrp::DrawRotaGraph(XY ,1.0f,IBullet::getTurnAngle(), GemHdl[Color]); },50,80 };

BulletData* DataArray[] = {&BVoid ,&BSmall ,&BMidium ,&BBig ,&BHuge,&BArrow,&BFuda,&BWater, &BLeaf,&BSOval,&BLOval,&BFire,&BTrump,&BGem };

BulletFactory::BulletFactory(ObjectAdaptor* Adaptor) noexcept:mAddFlag(true), mObj(Adaptor), mEmi(Adaptor->ObjEmi()) {
	BEmitter::SetSplitBList(this);
	DxWrp::LoadDivGraph("Picture/Bullet/SmallBullet.png", 10, 10, 1, 12, 12, SmallBHdl);
	DxWrp::LoadDivGraph("Picture/Bullet/MidiumBullet.png", 10, 10, 1, 16, 16, MidiumBHdl);
	DxWrp::LoadDivGraph("Picture/Bullet/BigBullet.png", 10, 10, 1, 32, 32, BigBHdl);
	DxWrp::LoadDivGraph("Picture/Bullet/ArrowBullet.png", 10, 10, 1, 32, 32, ArrowBHdl);
	DxWrp::LoadDivGraph("Picture/Bullet/FudaBullet.png", 10, 10, 1, 32, 32, FudaBHdl);
	DxWrp::LoadDivGraph("Picture/Bullet/VeryBigBullet.png", 10, 10, 1, 96, 96, VeryBigBHdl);
	DxWrp::LoadDivGraph("Picture/Bullet/waterBullet.png", 10, 10, 1, 32, 32, WaterHdl);
	DxWrp::LoadDivGraph("Picture/Bullet/LeafBullet.png", 10, 10, 1, 32, 32, LeafHdl);
	DxWrp::LoadDivGraph("Picture/Bullet/SmallOvalBullet.png", 10, 10, 1, 24, 24, SmallOvalHdl);
	DxWrp::LoadDivGraph("Picture/Bullet/fireBullet.png", 4, 4, 1, 256, 256, FireHdl);
	DxWrp::LoadDivGraph("Picture/Bullet/TrumpBullet.png", 10, 10, 1, 32, 32, TrumpHdl);
	DxWrp::LoadDivGraph("Picture/Bullet/gembullet.png", 10, 10, 1, 128, 128, GemHdl);
}
BulletFactory::~BulletFactory()noexcept{}

void BulletFactory::Bullet(uchar ID, uchar renewID, const Point& XY, uchar FanMany, float Angle, float Speed, float open, short radius) noexcept {
	DammakuData& data = mDataBase.mBullet[ID];
	auto& bList = mObj->ObjBul();
	Angle += data.mAngleState == Aiming ? XY.Angle(mObj->GetPlayer()->p) : 0.0f;

	if (data.mPolygon == 0) {
		for (int i = 0; i < data.mCirMany; ++i) {
			for (int j = 0; j < FanMany; ++j) {
				Vec2 p{ getCirFanAngle(i, j,open, data.mCirMany, FanMany) + Angle ,1.0f,0 };
				bList.Emplace(ID, renewID, XY + p * radius, p*Speed, data.mColor, nullptr, DataArray[data.mShape]);
			}
		}
	}else{
		for (int i = 0; i < data.mCirMany; ++i) {
			for (int j = 0; j < FanMany; ++j) {
				float an = getCirFanAngle(i, j, open, data.mCirMany, FanMany)  ;
				Vec2 p{ an+ Angle ,1.0f/getPolygonRadiusRv(data.mPolygon,an),0 };
				bList.Emplace(ID, renewID, XY + p * radius, p*Speed, data.mColor, nullptr, DataArray[data.mShape]);
			}
		}
	}
	//PLAY_SE(2);
}

/*void BulletFactory::Bullet(uchar ID, const Point& XY, uchar fanMany, float Angle, float Speed, float open, BulletShape shape, BulletColor color, short radius = 0)noexcept {
	DammakuData& data = mDataBase.mBullet[ID];
	auto& bList = mObj->ObjBul();
	Angle += data.mAngleState == Aiming ? XY.Angle(mObj->GetPlayer().p) : 0.0f;

	for (int i = 0; i < data.mCirMany*fanMany; ++i) {
		Vec2 p{ Decide_CirFan_Angle(i, open, data.mCirMany, fanMany) + Angle ,1.0f,0 };
		bList.Emplace(ID, XY + p * radius, p*Speed, color, data.mTill, nullptr, DataArray[shape], data.mDrawBlend);
	}
	//PLAY_SE(2);
}*/

/*void  BulletFactory::Bullet(uchar ID, const Point& XY, uchar FanMany, float Angle, float Speed, float open, float(*f)(float), short radius)noexcept {
	DammakuData& data = mDataBase.mBullet[ID];
	auto& bList = mObj->ObjBul();
	Angle += data.mAngleState == Aiming ? XY.Angle(mObj->GetPlayer().p) : 0.0f;

	for (int i = 0; i < data.mCirMany*FanMany; ++i) {
		float angle = Decide_CirFan_Angle(i, open, data.mCirMany, FanMany) + Angle;
		Vec2 p{ angle ,f(angle),0 };
		bList.Emplace(ID, XY + p * radius, p*Speed, data.mColor, data.mTill, nullptr, DataArray[data.mShape], data.mDrawBlend);
	}
	//PLAY_SE(2);
}

void BulletFactory::Bullet(uchar ID, const Point& XY, uchar Many, float Angle, float Speed, float(*f)(int, int), short radius  )noexcept {
		Angle += mBulletAngleState == Player ? XY.Angle(mObj->GetPlayer().p) : 0.0f;
		auto bList = mObj->ObjBul();
		for (int i = 0; i <Many; ++i) {
			float angle = Decide_CirFan_Angle(i, open, CirMany, FanMany) + Angle;
			Vec2 p{ angle ,f(angle),0 };
			bList.Emplace(ID, XY + p*radius, p*Speed, Color, Till, nullptr, DataArray[Shape], mBulletDrawType);
		}
		PLAY_SE(2);
}*/

float BulletFactory::GetBullettoPlayerAngle(const Point& XY)const noexcept { return XY.Angle(mObj->GetPlayer()->p); }

void BulletFactory::clear_emi() noexcept { mObj->ObjEmi().Kill(); }
void BulletFactory::setDammakuData(uchar ID, int cirMany, BulletColor color, BulletShape shape, int till, char AngleState, char drawBlend,char polygon) noexcept {
	mDataBase.set(ID, cirMany, color, shape, till, AngleState, drawBlend,polygon);
}
void  BulletFactory::clearDammakuData()noexcept {
	mDataBase.clear();
}

void BulletFactory::BulletForeach(int ID, func Func)noexcept {
	for (auto& Bul : mObj->ObjBul()) {
		if (Bul.GetID() == ID)Func(Bul, Bul.GetTime(), *mObj);
	}
}
BulletData* BulletFactory::getBulletData(BulletShape shape)noexcept {
	return DataArray[shape];
}
