
#include "StageFactory.h"
#include "StageChapter.h"
#include "BaseStage.h"
#include "Stage.h"
#include "StageData/Stage1.h"
#include "StageData/Stage2.h"
#include "StageData/Stage3.h"
#include "StageData/Stage4.h"
#include "StageData/Stage5.h"
#include "StageData/StageBosslush.h"

#include "../../../../Library/Scene/SceneMgr.h"
#include "../../../MediatorClass/ObjectAdaptor.h"
#include "../../../../Library/Func.h"

StageFunc StageInit[] = {
	Stage1Init,Stage2Init,Stage3Init,Stage4Init,Stage5Init,StageEXInit
};

std::vector<StageFunc> Chapter[] = {
	{ Stage10,Stage11,Stage1MidBoss,Stage12,Stage1Talk,Stage1Boss ,Stage1Clear },
	{ Stage20,Stage21,Stage2MidBoss ,Stage22,Stage2Talk,Stage2Boss ,Stage2Clear },
	{ Stage30,Stage31 ,Stage3MidBoss ,Stage33,Stage3Talk,Stage3Boss,Stage3Clear },
	{ Stage40,Stage41,Stage42,Stage43,Stage4Talk,Stage4Boss,Stage4Clear},
	{ Stage50,Stage51,Stage5MidBoss,Stage52,Stage5Talk,Stage5Boss ,Stage5Clear },
	{ StageEX0,StageEX1,StageEX2,StageEX3,StageEX4,StageEX5 ,StageEXClear },
	{ StageE0 },
};

std::vector<StageFunc> StageError = {StageEInit,StageE0};

StageFactory::StageFactory(ObjectAdaptor* List)noexcept :mOList(List){}
StageFactory::~StageFactory()noexcept {}

bool StageFactory::GetStage(StageEnum StageID, CSceneMgr& StageMgr)noexcept {
	if (StageID == 0) {
		StageMgr.Start(new BaseStage(StageInit[0], Chapter[0]));
		StageMgr.ReserveScene(new BaseStage(StageInit[1], Chapter[1]));
		StageMgr.ReserveScene(new BaseStage(StageInit[2], Chapter[2]));
		StageMgr.ReserveScene(nullptr);
		return false;
	}
	else if (StageID <= 6) {//プラクティス (1~6)
		StageMgr.Start(new BaseStage(StageInit[StageID - 1], Chapter[StageID - 1]));
		StageMgr.ReserveScene(nullptr);
		return true;
	}
	else if (StageID <= 13) {//オーバードライブ (7 ~ 13)
		return true;
	}
	else {//チャプター選択 (Stage1: 14~19 Stage2: 20~25 Stage3: 26~30 Stage4: 31~35)
		if (StageID <= 19) {//Stage 1
			StageMgr.Start(new BaseStage(StageInit[0], Chapter[0][StageID - 14]));
			StageMgr.ReserveScene(nullptr);
			return true;
		}
		else if (StageID <= 25) {//Stage 2
			StageMgr.Start(new BaseStage(StageInit[1], Chapter[1][StageID - 20]));
			StageMgr.ReserveScene(nullptr);
			return true;
		}
		else if(StageID<=31) {//Stage 3
			StageMgr.Start(new BaseStage(StageInit[2], Chapter[2][StageID - 26]));
			StageMgr.ReserveScene(nullptr);
			return true;
		}
		else if (StageID <= 37) {//Stage 4
			StageMgr.Start(new BaseStage(StageInit[3], Chapter[3][StageID - 32]));
			StageMgr.ReserveScene(nullptr);
			return true;
		}
		else if (StageID <= 43) {//Stage 5
			StageMgr.Start(new BaseStage(StageInit[4], Chapter[4][StageID - 38]));
			StageMgr.ReserveScene(nullptr);
			return true;
		}
		else if (StageID <= 49) {//Stage EX
			StageMgr.Start(new BaseStage(StageInit[5], Chapter[5][StageID - 44]));
			StageMgr.ReserveScene(nullptr);
			return true;
		}
		else {//Stage Error
			StageMgr.Start(new BaseStage(StageError[0], StageError[1]));
			StageMgr.ReserveScene(nullptr);
			return true;
		}
	}
}
