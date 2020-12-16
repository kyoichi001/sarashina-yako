
#include "Config.h"

#include "../../../../Library/Scene/ISceneChanger.h"
#include "../../../../Library/GUI/Widget.h"
#include "../../../../Library/GUI/GUI.h"
#include "../../../../Data/Resource.h"
#include "../../../../Library/Color/ColorData.h"
#include "../../../../Library/Font/FontFunc.h"

int configFont;

Config::Config() :BaseMenu(), mGUI({ 50,150 }) {

	configFont = DxWrp::CreateFontToHandle("HGS明朝E", 35, 2, FONTTYPE_ANTIALIASING, -1, 1);

	const WidgetFont ConfigFont = { configFont, WHITE, GREY };

	mGUI.Push(new VolumeBar<uchar>("BGM", ConfigFont, &Data.BGMVol, 6));
	mGUI.Push(new VolumeBar<uchar>("SE", ConfigFont, &Data.SEVol, 6));
	mGUI.Push(new Select("描画設定", ConfigFont, "背景の表示設定"));
	mGUI.Push(new Choice("データリセット", ConfigFont));
	mGUI.Push(new Choice("戻る", ConfigFont, [this]() {mSceneChanger->BackScene(); }));

	//mGUI.GetWidget<Select>("描画設定").Push(new VolumeBar<int>("衝突判定の頻度", ConfigFont, &CollisionUpdate, 4));
	mGUI.GetWidget<Select>("描画設定").Push(new Trriger("背景の表示設定", ConfigFont, &Draw3DFlag));
	mGUI.GetWidget<Select>("描画設定").Push(new Choice("戻る", ConfigFont));
	mGUI.link("BGM", "戻る", "SE");
	mGUI.link("SE", "BGM", "描画設定");
	mGUI.link("データリセット", "SE", "戻る");
	mGUI.link("戻る", "データリセット", "BGM");
}

void Config::Initialize()noexcept {
	mLiveFlag = true;
	mGUI.Init("BGM");
}

void Config::Finalize()noexcept {}

void Config::Update(float t)noexcept {
	mGUI.Update();
	if (Key[Data.Key.Button32]==1) {
		mSceneChanger->BackScene();
	}
}
void Config::Draw()const noexcept {
	mGUI.Draw();
}