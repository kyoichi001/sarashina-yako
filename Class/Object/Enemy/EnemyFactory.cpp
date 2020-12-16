
#include "EnemyFactory.h"
#include "IGhost.h"
#include "IBoss.h"
#include "EnemyData\Enemy1.h"
#include "EnemyData\Enemy2.h"
#include "EnemyData\Enemy3.h"
#include "EnemyData.h"

#include "../../../Data/DATA.h"
#include "../../../Data/Resource.h"
#include "../../../Library/ObjectEmitter.h"
#include "../../../Library/ObjectList/ObjectListClass.h"

#include "../../MediatorClass/ObjectAdaptor.h"

EnemyFactory::EnemyFactory(ObjectAdaptor* ListPtr)noexcept :mObjListPtr(ListPtr),mEmi(ListPtr->ObjEmi()){
	LoadEnemyResource();
}
EnemyFactory:: ~EnemyFactory()noexcept {}

void EnemyFactory::CreateEnemy(int ID, const Point& P,  float Value)noexcept {
	mObjListPtr->ObjEmy().Emplace(P, &mGhostData[ID], Value);
}
IBoss* EnemyFactory::CreateBoss(int BossNum, const Point& P, StageChapter* Stage) noexcept {
	return mObjListPtr->ObjBss().Emplace(P, BossNum >= mBossData.size() ? &mBossData[0] : &mBossData[BossNum], Stage);
}

void EnemyFactory::RemoveAllEnemy()noexcept {
	RemoveNomalEnemy();
	RemoveBossEnemy();
}

void EnemyFactory::RemoveNomalEnemy()noexcept {mObjListPtr->ObjEmy().Kill();}
void EnemyFactory::RemoveBossEnemy()noexcept {mObjListPtr->ObjBss().Kill();}

void EnemyFactory::pushData(enemy_func func,enemy_endfunc endfunc, Animation* anim, int hp, int r)noexcept {
	mGhostData.emplace_back(func,endfunc,anim,hp,r);
}
void EnemyFactory::pushData(const std::string& bossName, int backHdl, int hp, int r, int Hdl, bool escapeFlag, const std::vector<boss_func>& func)noexcept {
	mBossData.emplace_back(bossName, backHdl, hp, r,Hdl,escapeFlag, func);
}
void EnemyFactory::clearData()noexcept {
	mGhostData.clear();
	mBossData.clear();
}

Point EnemyFactory::GetShortestPoint(const Point& Obj)const noexcept {
	float LengthMinSqu = INFINITY;
	Point Ans= Obj;

	for (auto &Emy : mObjListPtr->ObjEmy()) {
		float lengthsqu = Emy.p.lengthSqu(Obj);
		if (LengthMinSqu > lengthsqu) {
			LengthMinSqu = lengthsqu;
			Ans = Emy.p;
		}
	}
	for (auto &Bss : mObjListPtr->ObjBss()) {
		float lengthsqu = Bss.p.lengthSqu(Obj);
		if (LengthMinSqu > lengthsqu) {
			LengthMinSqu = lengthsqu;
			Ans = Bss.p;
		}
	}
	return Ans;
}


