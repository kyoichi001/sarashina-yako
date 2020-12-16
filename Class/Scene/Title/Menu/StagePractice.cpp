
#include "StagePractice.h"

#include "../../../../Library/Scene/ISceneChanger.h"
#include "../../../../Library/GUI/Widget.h"
#include "../../../../Library/GUI/GUI.h"
#include "../../../../Data/Resource.h"
#include "../../../../Library/Color/ColorData.h"
#include "../../../../Library/Func.h"

#include "../Menu.h"
#include "../../Game/Game.h"

class WStage :public IWidget {
	int mHdl;
	std::function<void()> mFunc;
	std::string mPrevKey;
public:
	WStage(const std::string& name, int hdl, const std::function<void()>& func, const std::string& prev)noexcept
		: IWidget(name), mHdl(hdl), mFunc(func), mPrevKey(prev) {
		width = 512; height = 64;
	}
	void Update()noexcept override {}
	void Draw()const noexcept override {
		const Point Cood = GetCood();
		if (mState == 0) {
			DxWrp::DrawRotaGraph(Cood, 1.0f, 0.0f, mHdl);
			DxWrp::DrawBox(Cood, 64, 512, 0xFFFFFF);
		}
		else {
			DxWrp::DrawRotaGraph(Cood, 2.0f, 0.0f, mHdl);
			DxWrp::DrawBox(Cood, 64, 512, 0x888888);
		}
	}
	void goUp(Cursor* cursor)noexcept override {
		if (mUp)cursor->SetWidget(mUp);
	}
	void goDown(Cursor* cursor)noexcept override {
		if (mDown)cursor->SetWidget(mDown);
	}
	void goLeft(Cursor* cursor)noexcept override {}
	void goRight(Cursor* cursor)noexcept override {}

	void Execute(Cursor* cursor)noexcept override {
		if (mState == 0) {
			mFunc();
		}
	}
	void Cansel(Cursor* cursor) noexcept override {
		dynamic_cast<GUI*>(mParent)->changeActiveWidget(mPrevKey);
	}

};
StagePractice::StagePractice() :BaseMenu(), mGUI({50.0f,100.0f}) {
	const WidgetFont Font = { Font02, WHITE, GREY };

	mGUI.Push(new Choice("Stage1", Font, [this]() {mMenuptr->GetSceneChanger()->PushScene(new Game(1)); }));
	mGUI.Push(new Choice("Stage2", Font, [this]() {mMenuptr->GetSceneChanger()->PushScene(new Game(2)); }));
	mGUI.Push(new Choice("Stage3", Font, [this]() {mMenuptr->GetSceneChanger()->PushScene(new Game(3)); }));
	mGUI.Push(new Choice("Stage4", Font, [this]() {mMenuptr->GetSceneChanger()->PushScene(new Game(4)); }));
	mGUI.Push(new Choice("Stage5", Font, [this]() {mMenuptr->GetSceneChanger()->PushScene(new Game(5)); }));
	mGUI.Push(new Choice("ボスラッシュ", Font, [this]() {
		mMenuptr->GetSceneChanger()->PushScene(new Game(6)); }));
	mGUI.Push(new Choice("戻る", Font, [this]() { mSceneChanger->UndoScene(); }));
}

void StagePractice::Initialize()noexcept {
	mLiveFlag = true;

	mGUI.Init("Stage1");

}

void StagePractice::Finalize()noexcept {}

void StagePractice::Update(float t)noexcept {
	mGUI.Update();
	if (Key[Data.Key.Button32]==1) {
		mSceneChanger->UndoScene();
	}
}
void StagePractice::Draw()const noexcept {
	DxWrp::DrawStringToHandle(15, 15, dif("Easy", "Normal", "Hard", "Torture"), 0xCCCC22, Font05, WHITE);
	DxWrp::DrawStringToHandle(15, 45, "ステージを選択", 0xCC00FF, Font05, WHITE);
	mGUI.Draw();
}