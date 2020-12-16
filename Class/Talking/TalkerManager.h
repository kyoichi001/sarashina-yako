#pragma once

#include "../../Library/Primitive/Primitive.h"
#include "TalkData.h"

//�l�̉�b�𐧌�
//���W
//�A�N�e�B�u�ɂȂ��Ă��邩
//�N���b���Ă���̂�
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

	//activeFlag : �ŏ��ɃA�N�e�B�u�ɂȂ��Ă��邩�ǂ���
	void setTalker(Talker* talker, bool activeFlag,const Point& cood);
	void setCurrentTalk(TalkData* currentTalk) { mCurrentTalk = currentTalk; }

};