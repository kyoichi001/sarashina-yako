
#pragma once

#include "Class\MediatorClass\ObjectAdaptor.h"
#include "Class\MediatorClass\CollisionMediator.h"
#include "Library\Scene\SceneMgr.h"

class Main{
	ObjectAdaptor mAdaptor;
	CollisionMediator mCollision;
	CSceneMgr Scene;
	int mTime;
public:	

	Main()noexcept;
	~Main()noexcept;
	void Initialize()noexcept;
	void Update()noexcept;
	void Draw() noexcept;
	void Finalize()noexcept;
	bool IsEnd()const noexcept;
};