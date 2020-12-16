#pragma once

#include <vector>
#include <functional>

#include "TalkData.h"
#include "MessageWindow.h"
#include "TalkerManager.h"

//会話イベント全体を管理するクラス
//会話データのリスト
//現在の会話
class TalkingManager {
	Talker mTalker[6];
	std::vector<TalkData> mData;
	std::vector<bool> mLeftFlag;
	MessageWindow mWindow;
	TalkerManager mLeft, mRight;
	std::function<void(void)> mCallBack;
	int mCurrentIndex, mLeftFirstIndex, mRightFirstIndex;
	int mLeftTalker, mRightTalker;
	bool mEndFlag;
public:
	TalkingManager();
	void update(float t=1.0f);
	void draw() const;

	bool IsEnd()const;

	void Init();

	//0 : 主人公 1: 1面ボス 2: 2面ボス 3: 3面ボス 4: 4面ボス 5: 5面ボス 
	void pushLeftTalker(int TalkerID);
	void pushRightTalker(int TalkerID);
	//face 0: 普通 1:笑顔 2:怒り 3:呆れ
	void pushTalk(bool leftFlag,const std::string& text);
	void setCallBack(const std::function<void()>& callback);

	void startTalkEvent();

};