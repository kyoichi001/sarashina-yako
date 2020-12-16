
#include "LeazerFactory.h"
#include "ILeazer.h"
#include "../Player/Player.h"
#include "../../../Library/Func.h"
#include "../../../Library/Renderer.h"
#include "../../../Library/Math/Constant.h"
#include "../../../Data/Data.h"
#include "../../MediatorClass/ObjectAdaptor.h"

inline float getCirAngle(int num, int many) noexcept { return num * PI2 / many; }
inline float getFanAngle(int num, float open, int many)noexcept {
	return open * (num - float(many - 1) / 2.0f);//-open * (float(many - 1) / 2.0f) + num * open;
}
inline float getFanAngleOpen(int num, float open, int many) noexcept {
	return  -(open *0.5f) + open * num / (many - 1);
}
inline float getCirFanAngle(int num, float open, int cirmany, int fanmany) noexcept {
	return getCirAngle(num / fanmany, cirmany) + getFanAngle(num%fanmany, open, fanmany);
}
inline float getCirFanAngle(int cirnum, int fannum, float open, int cirmany, int fanmany) noexcept {
	return getCirAngle(cirnum, cirmany) + getFanAngle(fannum, open, fanmany);
}
inline float getPolygonRadiusRv(int VartexMany, float Angle)noexcept {
	return cosf(fmodf(Angle, PI2 / VartexMany) - PI / VartexMany);
}
inline float getPolygonStarRadiusRv(int VartexMany, float Angle) noexcept {
	return cosf(fmodf(Angle, PI4 / VartexMany) - PI2 / VartexMany);
}

int SmallLHdl[10], MidiumLHdl[10], BigLHdl[10], HugeLHdl[10];

LeazerData BVoid  { [](const Point& begin,const Point& end,float widthRate, BulletColor Color,int t) {},-1,-1 };
LeazerData BSmall { [](const Point& begin,const Point& end,float widthRate, BulletColor Color,int t) {DxWrp::DrawModiGraph(begin, end,4.0f*widthRate, SmallLHdl[Color]); },1,4 };
LeazerData BMidium{ [](const Point& begin,const Point& end,float widthRate, BulletColor Color,int t) {DxWrp::DrawModiGraph(begin, end,8.0f*widthRate,  MidiumLHdl[Color]); },2,8 };
LeazerData BBig   { [](const Point& begin,const Point& end,float widthRate, BulletColor Color,int t) {DxWrp::DrawModiGraph(begin, end,16.0f*widthRate,  BigLHdl[Color]); },8,14 };
LeazerData BHuge  { [](const Point& begin,const Point& end,float widthRate, BulletColor Color,int t) {DxWrp::DrawModiGraph(begin, end,32.0f*widthRate,  HugeLHdl[Color]); },18,30 };

LeazerData* DataArray[] = { &BVoid ,&BSmall ,&BMidium ,&BBig ,&BHuge};

BulletState LeazerFactory::mLeazerAngleState= Absolute;

LeazerFactory::LeazerFactory(ObjectAdaptor* Adaptor) noexcept: mObj(Adaptor){
	//BEmitter::SetSplitBList(this);
	DxWrp::LoadDivGraph("Picture/Bullet/SmallBullet.png", 10, 10, 1, 12, 12, SmallLHdl);
	DxWrp::LoadDivGraph("Picture/Bullet/MidiumBullet.png", 10, 10, 1, 16, 16, MidiumLHdl);
	DxWrp::LoadDivGraph("Picture/Bullet/BigBullet.png", 10, 10, 1, 32, 32, BigLHdl);
	DxWrp::LoadDivGraph("Picture/Bullet/VeryBigBullet.png", 10, 10, 1, 96, 96, HugeLHdl);

}
LeazerFactory::~LeazerFactory()noexcept {}

float  LeazerFactory::GetLeazertoPlayerAngle(const Point& XY)noexcept { return mLeazerAngleState ==Aiming ? XY.Angle(mObj->GetPlayer()->p) : 0.0f; }

void LeazerFactory::Leazer01(uchar ID, uchar renewID, Point* parent,  float angle,uchar FanMany,float open, uchar radius)noexcept {
	LeazerDammakuData data = mDataBase.mLeazer[ID];
	auto& lList = mObj->ObjLez1();
	angle += data.mAngleState == Aiming ? parent->Angle(mObj->GetPlayer()->p) : 0.0f;
	for (int i = 0; i < data.mCirMany; ++i) {
		for (int j = 0; j < FanMany; ++j) {
			float ang = getCirFanAngle(i, j, open, data.mCirMany, FanMany) + angle;
			lList.Emplace(ID, renewID, Point{ ang ,float(radius),0 }, ang, parent, data.mColor, DataArray[data.mShape], data.mTill);
		}
	}
}
void  LeazerFactory::Leazer02(uchar ID, uchar renewID, const Point& XY, uchar FanMany, float angle, float Speed, float open, uchar radius)noexcept {
	LeazerDammakuData data = mDataBase.mLeazer[ID];
	auto& lList = mObj->ObjLez2();
	angle += data.mAngleState == Aiming ? XY.Angle(mObj->GetPlayer()->p) : 0.0f;
	for (int i = 0; i < data.mCirMany; ++i) {
		for (int j = 0; j < FanMany; ++j) {
			Vec2 a = { getCirFanAngle(i, j, open, data.mCirMany, FanMany) + angle,1.0f,0 };
			lList.Emplace(ID, renewID, XY + a * radius, a*Speed, data.mLength, data.mColor, DataArray[data.mShape], data.mTill);
		}
	}
}

void LeazerFactory::setLeazerData(uchar ID, int cirMany, BulletColor color, LeazerShape shape, int till, int length,char AngleState , char drawBlend)noexcept {
	mDataBase.set(ID, cirMany, color, shape, till,length, AngleState, drawBlend);
}

void LeazerFactory::clearLeazerData()noexcept {
	mDataBase.clear();
}