
#pragma once;

#include "../../../Library/ObjectEmitter.h"
#include "../../../Library/ObjectList/ObjectListClass.h"
#include "../../../Library/Math/Random.h"
#include "GhostData.h"
#include "BossData.h"

class ObjectAdaptor;
class Point;
class StageChapter;

class EnemyFactory {
	ObjectAdaptor* mObjListPtr;
	ObjectList<Emitter>& mEmi;
	std::vector<GhostData> mGhostData;
	std::vector<BossData> mBossData;
public:
	EnemyFactory(ObjectAdaptor* ListPtr)noexcept;
	~EnemyFactory()noexcept;

	//LiveFlag はこの敵が死んだときに、falseになる
	void CreateEnemy(int ID, const Point& P, float Value = 0.0f)noexcept;
	IBoss* CreateBoss(int BossNum, const Point& P, StageChapter* Stage)noexcept;
	template<typename T>
	void CreateEnemyEmi(int Interval, int MakeTime, int ID, const T& Obj, float Value = 0.0f)noexcept {
		mEmi.SetObject(new Emitter(
			[this, ID, Value, Obj]() {
			CreateEnemy(ID, Rand(Obj), Value);
		}
		, Interval, MakeTime));
	}

	void RemoveAllEnemy()noexcept;
	void RemoveNomalEnemy()noexcept;
	void RemoveBossEnemy()noexcept;
	
	//雑魚敵用(関数名をわかりやすく)
	void pushData(enemy_func func, enemy_endfunc endfunc, Animation* anim, int hp, int r)noexcept;
	//ボス用(関数名をわかりやすく)
	void pushData(const std::string& bossName,int backHdl,int hp,int r,int Hdl,bool escapeFlag,const std::vector<boss_func>& func)noexcept;
	void clearData()noexcept;

	Point GetShortestPoint(const Point& Obj)const noexcept;

};
