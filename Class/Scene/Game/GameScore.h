#pragma once
#include "../../../Library/GUI/GUI.h"

class ObjectAdaptor;

class GameScore {
	GUI mScore;
	int mScoreHdl, mLogoHdl;
	 ObjectAdaptor* mAdaptor;
public:
	GameScore(ObjectAdaptor* obj);
	void initialize()noexcept;
	void finalize()noexcept;
	void update()noexcept;
	void draw()const noexcept;
};