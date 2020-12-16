
#include "Config.h"

#include "../../../../Library/Scene/ISceneChanger.h"
#include "../../../../Library/GUI/Widget.h"
#include "../../../../Library/GUI/GUI.h"
#include "../../../../Data/Resource.h"
#include "../../../../Library/Color/ColorData.h"
#include "../../../../Library/Font/FontFunc.h"

int configFont;

Config::Config() :BaseMenu(), mGUI({ 50,150 }) {

	configFont = DxWrp::CreateFontToHandle("HGS����E", 35, 2, FONTTYPE_ANTIALIASING, -1, 1);

	const WidgetFont ConfigFont = { configFont, WHITE, GREY };

	mGUI.Push(new VolumeBar<uchar>("BGM", ConfigFont, &Data.BGMVol, 6));
	mGUI.Push(new VolumeBar<uchar>("SE", ConfigFont, &Data.SEVol, 6));
	mGUI.Push(new Select("�`��ݒ�", ConfigFont, "�w�i�̕\���ݒ�"));
	mGUI.Push(new Choice("�f�[�^���Z�b�g", ConfigFont));
	mGUI.Push(new Choice("�߂�", ConfigFont, [this]() {mSceneChanger->BackScene(); }));

	//mGUI.GetWidget<Select>("�`��ݒ�").Push(new VolumeBar<int>("�Փ˔���̕p�x", ConfigFont, &CollisionUpdate, 4));
	mGUI.GetWidget<Select>("�`��ݒ�").Push(new Trriger("�w�i�̕\���ݒ�", ConfigFont, &Draw3DFlag));
	mGUI.GetWidget<Select>("�`��ݒ�").Push(new Choice("�߂�", ConfigFont));
	mGUI.link("BGM", "�߂�", "SE");
	mGUI.link("SE", "BGM", "�`��ݒ�");
	mGUI.link("�f�[�^���Z�b�g", "SE", "�߂�");
	mGUI.link("�߂�", "�f�[�^���Z�b�g", "BGM");
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