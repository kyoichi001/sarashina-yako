
#include "TalkingManager.h"
#include "../../Data/DATA.h"

#include "../../Library/Renderer.h"

int hirochiHdl, azamiHdl, heigoHdl, uhgonHdl, hirakoHdl, akiHdl;

TalkingManager::TalkingManager()
	:mCurrentIndex(0), mLeftFirstIndex(-1), mRightFirstIndex(-1), mLeftTalker(0), mRightTalker(0), mEndFlag(false){
	hirochiHdl = DxWrp::LoadGraph("Picture/Chara/Talking/hirochi.png");
	azamiHdl = DxWrp::LoadGraph("Picture/Chara/Talking/azami.png");
	heigoHdl = DxWrp::LoadGraph("Picture/Chara/Talking/heigo.png");
	uhgonHdl = DxWrp::LoadGraph("Picture/Chara/Talking/uh-gohn.png");
	hirakoHdl = DxWrp::LoadGraph("Picture/Chara/Talking/hirako.png");
	akiHdl = DxWrp::LoadGraph("Picture/Chara/Talking/aki.png");
	mTalker[0] = { 0x0000FF,hirochiHdl};
	mTalker[1] = { 0xFF00FF,azamiHdl };
	mTalker[2] = { 0xFF0000,heigoHdl };
	mTalker[3] = { 0xFFFF00,uhgonHdl };
	mTalker[4] = { 0x00FF,hirakoHdl };
	mTalker[5] = { 0xFF0000,akiHdl };
}

void TalkingManager::update(float t) {
	if (!eventFlag) return;
	if (Key[Data.Key.Button16] == 1) {
		++mCurrentIndex;
		if (mCurrentIndex >= mData.size()) {
			mEndFlag = true;
			mCurrentIndex = 0;
			eventFlag = false;
			mCallBack();
			return;
		}
		if (mLeftFlag[mCurrentIndex]) {
			mWindow.setdata(mTalker[mLeftTalker ].FontColor, mData[mCurrentIndex].mText);
			mLeft.setCurrentTalk(&mData[mCurrentIndex]);
			mLeft.activate();
			mRight.inactivate();
		}
		else {
			mWindow.setdata(mTalker[mRightTalker].FontColor, mData[mCurrentIndex].mText);
			mRight.setCurrentTalk(&mData[mCurrentIndex]);
			mLeft.inactivate();
			mRight.activate();
		}
	}
	mLeft.update();
	mRight.update();
}

void TalkingManager::draw() const{
	if (!eventFlag) return;
	mWindow.draw();
	mLeft.draw();
	mRight.draw();
}

void TalkingManager::Init() {
	mEndFlag = false;
	mCurrentIndex = mLeftTalker = mRightTalker = 0;
	mLeftFlag.clear();
	mData.clear();
}

void TalkingManager::pushLeftTalker(int TalkerID) { 
	mLeftTalker = TalkerID; 
	mLeft.setTalker(&mTalker[TalkerID], true, {180.0f,350.0f});
}
void TalkingManager::pushRightTalker(int TalkerID) {
	mRightTalker = TalkerID; 
	mRight.setTalker(&mTalker[TalkerID], false, {530.0f,350.0f});
}

void TalkingManager::pushTalk(bool leftFlag, const std::string& text) {
	mLeftFlag.push_back(leftFlag);
	mData.push_back({ text });
	if (leftFlag) {
		if (mLeftFirstIndex == -1) {
			mLeftFirstIndex = mData.size() - 1;
			mLeft.setCurrentTalk(&mData[mLeftFirstIndex]);
		}
		if (mData.size() == 1) {
			mWindow.setdata(mTalker[mLeftTalker].FontColor, mData[mCurrentIndex].mText);
		}
	}
	else {
		if (mRightFirstIndex == -1) {
			mRightFirstIndex = mData.size() - 1;
			mRight.setCurrentTalk(&mData[mRightFirstIndex]);
		}
		if (mData.size() == 1) {
			mWindow.setdata(mTalker[mRightTalker].FontColor, mData[mCurrentIndex].mText);
		}
	}
}

bool TalkingManager::IsEnd()const {
	return mEndFlag;
}

void TalkingManager::startTalkEvent() {
	eventFlag = true;
}

void TalkingManager::setCallBack(const std::function<void()>& callback) {
	mCallBack = callback;
}
