#pragma once

#include "../../Library/Primitive/Primitive.h"
#include "TalkData.h"

//個人の会話を制御
//座標
//アクティブになっているか
//誰が話しているのか
class TalkerManager {
	Point mCood;
	bool mActiveFlag,mChanges;
	Talker* mTalker;
	TalkData* mCurrentTalk;
	int mTime;

public:
	TalkerManager();
	void update(float t=1.0f);
	void draw()const;
	
	void activate();
	void inactivate();

	//activeFlag : 最初にアクティブになっているかどうか
	void setTalker(Talker* talker, bool activeFlag,const Point& cood);
	void setCurrentTalk(TalkData* currentTalk) { mCurrentTalk = currentTalk; }

};