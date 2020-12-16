#pragma once

#include <vector>
#include <functional>

#include "TalkData.h"
#include "MessageWindow.h"
#include "TalkerManager.h"

//��b�C�x���g�S�̂��Ǘ�����N���X
//��b�f�[�^�̃��X�g
//���݂̉�b
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

	//0 : ��l�� 1: 1�ʃ{�X 2: 2�ʃ{�X 3: 3�ʃ{�X 4: 4�ʃ{�X 5: 5�ʃ{�X 
	void pushLeftTalker(int TalkerID);
	void pushRightTalker(int TalkerID);
	//face 0: ���� 1:�Ί� 2:�{�� 3:����
	void pushTalk(bool leftFlag,const std::string& text);
	void setCallBack(const std::function<void()>& callback);

	void startTalkEvent();

};