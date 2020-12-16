
#include "Home.h"

#include "../../../../Library/Scene/ISceneChanger.h"
#include "../../../../Library/GUI/Widget.h"
#include "../../../../Library/GUI/GUI.h"

#include "Config.h"
#include "Music.h"
//#include "Ready.h"
#include "Config.h"
#include "StagePractice.h"
#include "Trophy.h"
#include "../Menu.h"
#include "../../Game/Game.h"

#include "../../../../Library/Font/FontFunc.h"

#include "../../../Object/Effect/IEffect.h"
#include "Difficulty.h"
#include "Weapon.h"

#ifdef _DEBUG
#include "../../Ending/Ending.h"
#include "../../GameOver/GameOver.h"
#include "Debug.h"
#include "ChapterSelect.h"
#endif

int menuFont,startFont;
int backHdl,backMaskHdl,backFireHdl,backFireBlightHdl;

Home::Home() :BaseMenu(), mGUI({20.0f,50.0f}) {

	menuFont = DxWrp::CreateFontToHandle("HGS創英ﾌﾟﾚｾﾞﾝｽEB", 32, 5, FONTTYPE_ANTIALIASING, -1, 1);
	startFont = DxWrp::CreateFontToHandle("HGS創英ﾌﾟﾚｾﾞﾝｽEB", 40, 5, FONTTYPE_ANTIALIASING, -1, 1);
	mGUI.SetOfset({ 2.5f,80.0f });
	const WidgetFont StartFont = { startFont, 0x0066FF, 0x003377 };
	const WidgetFont ExitFont = { menuFont, 0xFF5500, 0x772200 };
	const WidgetFont Font = { menuFont, 0xFFFFFF, 0x777777 };
	const WidgetFont DisabledFont = { menuFont, 0xFFFFFF, 0x444444 };

	mGUI.Push(new Choice("ゲームスタート", StartFont, [this]() {
		mSceneChanger->ClearReservedScene();
		mSceneChanger->PushScene(new Difficulty());
		mSceneChanger->ReserveScene(new Weapon());
		mSceneChanger->ReserveScene(new StagePractice());
	}));
	//mGUI.Push(new Choice("Replay", DisabledFont), false);
	mGUI.Push(new Choice("音楽", Font, [this]() {mSceneChanger->PushScene(new Music()); }));
	//mGUI.Push(new Choice("設定", Font, [this]() {mSceneChanger->PushScene(new Config()); }));
	//mGUI.Push(new Choice("実績", Font, [this]() {mSceneChanger->PushScene(new Trophy()); }));
#ifdef _DEBUG
	mGUI.Push(new Choice("debug", Font, [this]() {mSceneChanger->PushScene(new Debug()); }));
	mGUI.Push(new Choice("Chapter Select", Font, [this]() {
		mSceneChanger->ClearReservedScene();
		mSceneChanger->PushScene(new Difficulty());
		mSceneChanger->ReserveScene(new Weapon());
		mSceneChanger->ReserveScene(new ChapterSelect());
	}));
	mGUI.Push(new Choice("Ending", Font, [this]() {mMenuptr->GetSceneChanger()->PushScene(new Ending()); }));
	mGUI.Push(new Choice("Game Over", Font, [this]() {
		mMenuptr->GetSceneChanger()->PushScene(new GameOver()); 
	}));
#endif
	mGUI.Push(new Choice("終了する", ExitFont, [&]() {programEndFlag = true; }));
	mGUI.link("終了する", "", "ゲームスタート");
	mGUI.link("ゲームスタート", "終了する");
}

void Home::Initialize()noexcept {
	mTime = 0;
	mLiveFlag = true;
	mGUI.Init("ゲームスタート");
	DxWrp::CreateMaskScreen();
	backMaskHdl = DxWrp::LoadMask("Picture/Scene/Menu/title2mask.png");
	backHdl = DxWrp::LoadGraph("Picture/Scene/Menu/title.png");
	backFireHdl = DxWrp::LoadGraph("Picture/Scene/Menu/fire.png");
	backFireBlightHdl = DxWrp::LoadGraph("Picture/Scene/Menu/fireblight.png");
	DxWrp::DrawMask(0, 0, backMaskHdl, MASKTRANS_BLACK);
}

void Home::Finalize()noexcept {
	DxWrp::DeleteMask(backHdl);
	DxWrp::DeleteMask(backMaskHdl);
	DxWrp::DeleteGraph(backFireHdl);
	DxWrp::DeleteGraph(backFireBlightHdl);
}

void Home::Update(float t)noexcept {
	mGUI.Update();
	++mTime;
}
void Home::Draw()const noexcept {
	mGUI.Draw();
	DxWrp::DrawGraph(0, 0, backHdl);
	DxWrp::SetUseMaskScreenFlag(true);
	DxWrp::DrawRotaGraph(528 + 128, 292 + 128, 1.2f, 0.0f, backFireHdl);
	if (0 <= mTime % 60 && mTime % 60 <= 8)
		DxWrp::DrawRotaGraph(528 + 128, 292 + 128, 1.2f, 0.0f, backFireBlightHdl);
	DxWrp::SetUseMaskScreenFlag(false);
}