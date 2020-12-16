#pragma once

enum StageEnum:char{
	GamePlay,
	Stage1,Stage2,Stage3,Stage4,Stage5,StageEX,
	OD1,OD2,OD3,OD4,OD5,OD6,OD7,
	NoStage
};

class CSceneMgr;
class ObjectAdaptor;

class StageFactory {
	ObjectAdaptor* mOList;
public:
	StageFactory(ObjectAdaptor* List)noexcept;
	~StageFactory()noexcept;
	//return PracticeFlag
	bool GetStage(StageEnum StageID, CSceneMgr& StageMgr)noexcept;
};