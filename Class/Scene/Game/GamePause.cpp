
#include "GamePause.h"
#include "Game.h"
#include "../../../Library/Func.h"
#include "../../../Library/Renderer.h"
#include "../../../Library/Color/ColorData.h"
#include "../../../Library/GUI/Widget.h"
#include "../../../Data/Resource.h"
#include "../../../Data/DATA.h"

GamePause::GamePause(Game* GamePtr)noexcept:mGamePtr(GamePtr), mState(-1), mMessage(0),
mMenu({ -50, 400 }) {
	WidgetFont MenuFont = { Font02, WHITE, GREY };
	WidgetFont DisabledMenuFont = { Font02, GREY, BLACK };

	mMenu.Push(new Choice("�Q�[���ĊJ", MenuFont, [this]() {
		Key[Data.Key.Button16] = 0;
		mPauseEasing.InitReverce();
		mMenuEasing.InitReverce();
		mState = 2;
	}));
	//mMenu.Push(new Choice("���v���C��ۑ����ďI��", DisabledMenuFont),false);
	mMenu.Push(new Choice( "�ŏ������蒼��", MenuFont, [this]() {mMessage = 1;}));
	mMenu.Push(new Choice("�}�j���A��", DisabledMenuFont),false);
	mMenu.Push(new Choice("�I�v�V����", DisabledMenuFont),false);
	mMenu.Push(new Choice( "�Q�[�����I������", MenuFont, [this]() {mMessage = 2;}));

	PauseAlpha = 0;
}
void GamePause::Init() noexcept {
	mPauseEasing.Init(&PauseAlpha, 0, 180, 20, Ease<Cubic>::Out);
	mMenuEasing.Init(&mMenu.tl, Point(-50, 400), Point(90, 400), 15, Ease<Cubic>::Out);

	mMenu.Init("�Q�[���ĊJ");
	mMenu.link("�Q�[���ĊJ", "�Q�[�����I������");
	mMenu.link("�Q�[�����I������", "","�Q�[���ĊJ");
	mState = -1;
	mMessage = 0;
}
bool GamePause::Update(float t)noexcept {
	switch (mState) {
	case -1:
		if (pauseflag)mState = 1;
		break;
	case 0:
		if (Key[Data.Key.Button512] == 1) {
			mState = 2;
			Key[Data.Key.Button512] = 0;
			mPauseEasing.InitReverce();
			mMenuEasing.InitReverce();
		}
		break;
	case 1:
		mMenuEasing.Update();
		mPauseEasing.Update();
		if (mPauseEasing.IsFinished())mState = 0;
		break;
	case 2:
		mMenuEasing.Update();
		mPauseEasing.Update();
		if (mPauseEasing.IsFinished()) {
			mState = 3;
			pauseflag = false;
		}
		break;
	case 3:
		break;
	}
	mMenu.Update();//����͈�ԍŌ�ɂ��Ȃ��ƃ������A�N�Z�X?
	return true;
}
void GamePause::Draw()const noexcept {
	DxWrp::SetBlendModeAlpha(PauseAlpha);
	DxWrp::DrawBox(0, 0, 960, 720, BLACK, true);
	DxWrp::ResetBlendMode();

	DxWrp::SetBlendModeAlpha(float(PauseAlpha)/180.0f*255.0f);
	mMenu.Draw();
	DxWrp::ResetBlendMode();
}
int GamePause::sendMessage()noexcept {
	return mMessage;
}
