
#include "Weapon.h"

#include "../../../../Library/Scene/ISceneChanger.h"
#include "../../../../Library/GUI/Widget.h"
#include "../../../../Library/GUI/GUI.h"
#include "../../../../Data/Resource.h"
#include "../../../../Library/Color/ColorData.h"
#include "../../../../Library/Func.h"

class WWeapon :public IWidget {
	WidgetFont mFont;
	char mWeapon;
	int mHdl;
	bool* mLiveFlag;
public:
	WWeapon(const std::string& name, const WidgetFont& Font, char weapon, int hdl,bool* liveFlag)noexcept
		: IWidget(name), mFont(Font), mWeapon(weapon), mHdl(hdl), mLiveFlag(liveFlag){
		width = 153; height = 153;
	}
	void Update()noexcept override {}
	void Draw()const noexcept override {
		const Point Cood = GetCood();
		if (mState == 0) {
			DxWrp::DrawFormatStringToHandle(560,50,0xFFFFFF, mFont.GetFont(),mName.c_str(),0.0f);
			DxWrp::DrawRotaGraph(Cood + Vec2{ 64.0f,64.0f }*1.2f, 1.2f, 0.0f, mHdl);
			//DxWrp::DrawBox(Cood - Vec2{ 64.0f,64.0f }, 128, 128, p_weapon == mWeapon ? 0xFFFF00: 0xFFFFFF);
		}
		else {
			DxWrp::DrawRotaGraph(Cood + Vec2{ 64.0f,64.0f }*1.2f, 0.8f, 0.0f, mHdl);
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

	void Execute(Cursor* cursor)noexcept override { 
		p_weapon = mWeapon; 
		*mLiveFlag = false;
	}
	void Cansel(Cursor* cursor) noexcept override {}

};
int hormingHdl, spreyHdl, leazerHdl;
Weapon::Weapon() :BaseMenu(), mGUI({ 50.0f,100.0f }) {
	const WidgetFont Font = { Font02, WHITE, GREY };
	hormingHdl = DxWrp::LoadGraph("Picture/Chara/Player/PlayerOptionIcon0.png");
	spreyHdl = DxWrp::LoadGraph("Picture/Chara/Player/PlayerOptionIcon1.png");
	leazerHdl = DxWrp::LoadGraph("Picture/Chara/Player/PlayerOptionIcon2.png");
	mGUI.SetOfset({140.0f,0.0f});
	mGUI.Push(new WWeapon("Ž©“®’Ç”öŒ^", Font, 0, hormingHdl, &mLiveFlag));
	mGUI.Push(new WWeapon("ˆê”­‹t“]Œ^", Font, 1, spreyHdl, &mLiveFlag));
	//mGUI.Push(new WWeapon("UŒ‚dŽ‹Œ^", Font, 2, leazerHdl, &mLiveFlag));
	//	mGUI.Push(new Choice("–ß‚é", Font, [this]() {mSceneChanger->UndoScene(); }));
	mGUI.link("Ž©“®’Ç”öŒ^", "", "", "ˆê”­‹t“]Œ^", "ˆê”­‹t“]Œ^");
	mGUI.link("ˆê”­‹t“]Œ^", "", "", "Ž©“®’Ç”öŒ^", "Ž©“®’Ç”öŒ^");
	//mGUI.link("UŒ‚dŽ‹Œ^", "", "", "ˆê”­‹t“]Œ^", "Ž©“®’Ç”öŒ^");
}

void Weapon::Initialize()noexcept {
	mLiveFlag = true;
	mGUI.Init("Ž©“®’Ç”öŒ^");
}

void Weapon::Finalize()noexcept {}

void Weapon::Update(float t)noexcept {
	mGUI.Update();
	if (Key[Data.Key.Button32]==1) {
		mSceneChanger->UndoScene();
	}
}
void Weapon::Draw()const noexcept {
	DxWrp::DrawStringToHandle(15, 0, dif("Easy","Normal","Hard","Torture"), 0xCCCC22, Font05, WHITE);
	mGUI.Draw();
}