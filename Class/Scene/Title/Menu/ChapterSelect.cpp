
#include "ChapterSelect.h"

#include "../../../../Library/Scene/ISceneChanger.h"
#include "../../../../Library/GUI/Widget.h"
#include "../../../../Library/GUI/GUI.h"
#include "../../../../Data/Resource.h"
#include "../../../../Library/Color/ColorData.h"
#include "../../../../Library/Func.h"

#include "../Menu.h"
#include "../../Game/Game.h"

ChapterSelect::ChapterSelect() :BaseMenu(), mGUI({0.0f,100.0f}) {
	const WidgetFont Font = { Font02, WHITE, GREY };

	mGUI.Push(new Select("Stage 1", Font,"Chapter0"));
	mGUI.Push(new Select("Stage 2", Font,"Chapter0"));
	mGUI.Push(new Select("Stage 3", Font,"Chapter0"));
	mGUI.Push(new Select("Stage 4", Font,"Chapter0"));
	mGUI.Push(new Select("Stage 5", Font,"Chapter0"));
	mGUI.Push(new Choice("Back", Font, [this]() {mSceneChanger->UndoScene(); }));

	mGUI.GetWidget<Select>("Stage 1").Push(new Choice("Chapter0", Font, [this]() {mMenuptr->GetSceneChanger()->PushScene(new Game(14)); }));
	mGUI.GetWidget<Select>("Stage 1").Push(new Choice("Chapter1", Font, [this]() {mMenuptr->GetSceneChanger()->PushScene(new Game(15)); }));
	mGUI.GetWidget<Select>("Stage 1").Push(new Choice("MidBoss ", Font, [this]() {mMenuptr->GetSceneChanger()->PushScene(new Game(16)); }));
	mGUI.GetWidget<Select>("Stage 1").Push(new Choice("Chapter2", Font, [this]() {mMenuptr->GetSceneChanger()->PushScene(new Game(17)); }));
	mGUI.GetWidget<Select>("Stage 1").Push(new Choice("Talk    ", Font, [this]() {mMenuptr->GetSceneChanger()->PushScene(new Game(18)); }));
	mGUI.GetWidget<Select>("Stage 1").Push(new Choice("Boss    ", Font, [this]() {mMenuptr->GetSceneChanger()->PushScene(new Game(19)); }));

	mGUI.GetWidget<Select>("Stage 2").Push(new Choice("Chapter0", Font, [this]() {mMenuptr->GetSceneChanger()->PushScene(new Game(20)); }));
	mGUI.GetWidget<Select>("Stage 2").Push(new Choice("Chapter1", Font, [this]() {mMenuptr->GetSceneChanger()->PushScene(new Game(21)); }));
	mGUI.GetWidget<Select>("Stage 2").Push(new Choice("MidBoss ", Font, [this]() {mMenuptr->GetSceneChanger()->PushScene(new Game(22)); }));
	mGUI.GetWidget<Select>("Stage 2").Push(new Choice("Chapter2", Font, [this]() {mMenuptr->GetSceneChanger()->PushScene(new Game(23)); }));
	mGUI.GetWidget<Select>("Stage 2").Push(new Choice("Talk    ", Font, [this]() {mMenuptr->GetSceneChanger()->PushScene(new Game(24)); }));
	mGUI.GetWidget<Select>("Stage 2").Push(new Choice("Boss    ", Font, [this]() {mMenuptr->GetSceneChanger()->PushScene(new Game(25)); }));

	mGUI.GetWidget<Select>("Stage 3").Push(new Choice("Chapter0", Font, [this]() {mMenuptr->GetSceneChanger()->PushScene(new Game(26)); }));
	mGUI.GetWidget<Select>("Stage 3").Push(new Choice("Chapter1", Font, [this]() {mMenuptr->GetSceneChanger()->PushScene(new Game(27)); }));
	mGUI.GetWidget<Select>("Stage 3").Push(new Choice("MidBoss ", Font, [this]() {mMenuptr->GetSceneChanger()->PushScene(new Game(28)); }));
	mGUI.GetWidget<Select>("Stage 3").Push(new Choice("Chapter2", Font, [this]() {mMenuptr->GetSceneChanger()->PushScene(new Game(29)); }));
	mGUI.GetWidget<Select>("Stage 3").Push(new Choice("Talk    ", Font, [this]() {mMenuptr->GetSceneChanger()->PushScene(new Game(30)); }));
	mGUI.GetWidget<Select>("Stage 3").Push(new Choice("Boss    ", Font, [this]() {mMenuptr->GetSceneChanger()->PushScene(new Game(31)); }));

	mGUI.GetWidget<Select>("Stage 4").Push(new Choice("Chapter0", Font, [this]() {mMenuptr->GetSceneChanger()->PushScene(new Game(32)); }));
	mGUI.GetWidget<Select>("Stage 4").Push(new Choice("Chapter1", Font, [this]() {mMenuptr->GetSceneChanger()->PushScene(new Game(33)); }));
	mGUI.GetWidget<Select>("Stage 4").Push(new Choice("Chapter2", Font, [this]() {mMenuptr->GetSceneChanger()->PushScene(new Game(34)); }));
	mGUI.GetWidget<Select>("Stage 4").Push(new Choice("Chapter3", Font, [this]() {mMenuptr->GetSceneChanger()->PushScene(new Game(35)); }));
	mGUI.GetWidget<Select>("Stage 4").Push(new Choice("Talk    ", Font, [this]() {mMenuptr->GetSceneChanger()->PushScene(new Game(36)); }));
	mGUI.GetWidget<Select>("Stage 4").Push(new Choice("Boss", Font, [this]() {mMenuptr->GetSceneChanger()->PushScene(new Game(37)); }));

	mGUI.GetWidget<Select>("Stage 5").Push(new Choice("Chapter0", Font, [this]() {mMenuptr->GetSceneChanger()->PushScene(new Game(38)); }));
	mGUI.GetWidget<Select>("Stage 5").Push(new Choice("Chapter1", Font, [this]() {mMenuptr->GetSceneChanger()->PushScene(new Game(39)); }));
	mGUI.GetWidget<Select>("Stage 5").Push(new Choice("ChapterMidBoss", Font, [this]() {mMenuptr->GetSceneChanger()->PushScene(new Game(40)); }));
	mGUI.GetWidget<Select>("Stage 5").Push(new Choice("Chapter2", Font, [this]() {mMenuptr->GetSceneChanger()->PushScene(new Game(41)); }));
	mGUI.GetWidget<Select>("Stage 5").Push(new Choice("Talk", Font, [this]() {mMenuptr->GetSceneChanger()->PushScene(new Game(42)); }));
	mGUI.GetWidget<Select>("Stage 5").Push(new Choice("Boss", Font, [this]() {mMenuptr->GetSceneChanger()->PushScene(new Game(43)); }));

}

void ChapterSelect::Initialize()noexcept {
	mLiveFlag = true;

	mGUI.Init("Stage 1");

}

void ChapterSelect::Finalize()noexcept {}

void ChapterSelect::Update(float t)noexcept {
	mGUI.Update();
	
	if (Key[Data.Key.Button32]==1) {
		mSceneChanger->UndoScene();
	}
}
void ChapterSelect::Draw()const noexcept {
	DxWrp::DrawStringToHandle(15, 0, dif("Easy", "Normal", "Hard", "Torture"), 0xCCCC22, Font05, WHITE);
	DxWrp::DrawStringToHandle(15, 30, &p_weapon, 0xCCCC22, Font05, WHITE);
	mGUI.Draw();
}