
#include "Music.h"

#include "../../../../Library/Scene/ISceneChanger.h"
#include "../../../../Library/GUI/Widget.h"
#include "../../../../Library/GUI/GUI.h"
#include "../../../../Data/Resource.h"
#include "../../../../Library/Color/ColorData.h"
#include "../../../../Library/Font/FontFunc.h"

#include "../../../MediatorClass/ObjectAdaptor.h"

#include "../../../../Library/Lua/LuaScript.h"

int musicFont;

Music::Music() :BaseMenu(), mGUI({10.0f,40.0f}) {
	
	LuaScript L("Script/config.lua");

	musicFont = DxWrp::CreateFontToHandle("HGS創英ﾌﾟﾚｾﾞﾝｽEB", 32, 5, FONTTYPE_ANTIALIASING, -1, 1);
	const WidgetFont Font = { musicFont, WHITE, GREY };

	std::vector<std::string> musicTitle;

	musicTitle=L.getStringVector("music");


	for (int i = 0; i < musicTitle.size(); i++)
		mGUI.Push(new Choice(musicTitle[i], Font, [=]() {mObj->getAudio().playBGM(i); }));

/*	mGUI.Push(new Choice("02 彼岸の光", Font, []() {mObj->getAudio().playBGM(1); }));
	mGUI.Push(new Choice("03 幽鬼少女", Font, []() {mObj->getAudio().playBGM(2); }));
	mGUI.Push(new Choice("04 町を舞う花", Font, []() {mObj->getAudio().playBGM(3); }));
	mGUI.Push(new Choice("05 アバンギャルドマジック", Font, []() {mObj->getAudio().playBGM(4); }));
	mGUI.Push(new Choice("06 ", Font, []() {mObj->getAudio().playBGM(5); }));
	mGUI.Push(new Choice("07 やおよろずの白足、神々の赤い目", Font, []() {mObj->getAudio().playBGM(6); }));
	mGUI.Push(new Choice("08 時の箱舟", Font, []() {mObj->getAudio().playBGM(7); }));
	mGUI.Push(new Choice("09 月の羅針盤", Font, []() {mObj->getAudio().playBGM(8); }));
	mGUI.Push(new Choice("10 ジェムストーン", Font, []() {mObj->getAudio().playBGM(9); }));
	mGUI.Push(new Choice("11 夜の輝く赤い大地", Font, []() {mObj->getAudio().playBGM(10); }));
	mGUI.Push(new Choice("12 夜明けが終わる", Font, []() {mObj->getAudio().playBGM(11); }));
	mGUI.Push(new Choice("13 ゲームオーバー", Font, []() {mObj->getAudio().playBGM(12); }));
	*/
	mGUI.Push(new Choice("戻る", Font, [this]() { mSceneChanger->BackScene(); }));

	mGUI.link("戻る", "", musicTitle[0]);
	mGUI.link(musicTitle[0], "戻る");

}

void Music::Initialize()noexcept {
	mLiveFlag = true;
	mGUI.Init("01 夜行好奇心");

}

void Music::Finalize()noexcept {}

void Music::Update(float t)noexcept {
	mGUI.Update();
	if (Key[Data.Key.Button32] == 1) {
		mSceneChanger->BackScene();
	}
}
void Music::Draw()const noexcept {
	DxWrp::DrawStringToHandle(5, 5, "ミュージックルーム", 0xCC00FF, Font05, WHITE);
	mGUI.Draw();
	DxWrp::DrawStringToHandle(0, 705, "Z : 再生・停止切り替え X : 前の画面に戻る", 0xCC00FF, Font05, WHITE);
}