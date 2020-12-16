
#include "Difficulty.h"

#include "../../../../Library/Scene/ISceneChanger.h"
#include "../../../../Library/GUI/Widget.h"
#include "../../../../Library/GUI/GUI.h"
#include "../../../../Library/Func.h"
#include "../../../../Data/Resource.h"
#include "../../../../Library/Color/ColorData.h"

class WDifficulty :public IWidget {
	char mDifficulty;
	int mHdl;
	bool* mSceneLiveFlag;
public:
	WDifficulty(const std::string& name, char difficulty, int hdl,bool* sceneLiveFlag)noexcept
		: IWidget(name), mDifficulty(difficulty), mHdl(hdl), mSceneLiveFlag(sceneLiveFlag){
		width = 215; height = 553;
	}
	void Update()noexcept override {
	}
	void Draw()const noexcept override {
		const Point Cood = GetCood();
		if (mState == 0) {
			DxWrp::DrawGraph(Cood , mHdl);
		}
		else {
			DxWrp::SetDrawBright(100, 100, 100);
			DxWrp::DrawGraph(Cood , mHdl);
			DxWrp::SetDrawBright(255, 255, 255);
		}
	}
	void goUp(Cursor* cursor)noexcept override {}
	void goDown(Cursor* cursor)noexcept override {}
	void goLeft(Cursor* cursor)noexcept override {
		if (mLeft)cursor->SetWidget(mLeft);
	}
	void goRight(Cursor* cursor)noexcept override {
		if (mRight)cursor->SetWidget(mRight);
	}

	void Execute(Cursor* cursor)noexcept override { difficulty = mDifficulty; *mSceneLiveFlag = false; }
	void Cansel(Cursor* cursor) noexcept override {}

};

int easyHdl, normalHdl, hardHdl, tortureHdl;

Difficulty::Difficulty() :BaseMenu(), mGUI({ 20,150 }) {
	easyHdl = DxWrp::LoadGraph("Picture/Scene/Menu/easy.png");
	normalHdl = DxWrp::LoadGraph("Picture/Scene/Menu/normal.png");
	hardHdl = DxWrp::LoadGraph("Picture/Scene/Menu/hard.png");
	tortureHdl = DxWrp::LoadGraph("Picture/Scene/Menu/torture.png");
	mGUI.SetOfset({ 220.0f,0.0f });
	mGUI.Push(new WDifficulty("Easy", 0, easyHdl, &mLiveFlag));
	mGUI.Push(new WDifficulty("Normal", 1, normalHdl, &mLiveFlag));
	mGUI.Push(new WDifficulty("Hard", 2, hardHdl, &mLiveFlag));
	mGUI.Push(new WDifficulty("Torture", 3, tortureHdl, &mLiveFlag));
	mGUI.link("Easy", "", "", "Torture", "Normal");
	mGUI.link("Normal", "", "", "Easy", "Hard");
	mGUI.link("Hard", "", "", "Normal", "Torture");
	mGUI.link("Torture", "", "", "Hard", "Easy");
}

void Difficulty::Initialize()noexcept {
	mLiveFlag = true;
	mGUI.Init(dif("Easy","Normal","Hard","Torture"));
}

void Difficulty::Finalize()noexcept {}

void Difficulty::Update(float t)noexcept {
	mGUI.Update();
	if (Key[Data.Key.Button32] == 1) {
		mSceneChanger->UndoScene();
	}
}
void Difficulty::Draw()const noexcept {
	DxWrp::DrawStringToHandle(30, 30, "“ïˆÕ“x‚ð‘I‘ð", 0xCC00FF, Font05, WHITE);
	mGUI.Draw();
}