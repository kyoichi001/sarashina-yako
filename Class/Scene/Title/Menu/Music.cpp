
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

	musicFont = DxWrp::CreateFontToHandle("HGS�n�p��ھ�ݽEB", 32, 5, FONTTYPE_ANTIALIASING, -1, 1);
	const WidgetFont Font = { musicFont, WHITE, GREY };

	std::vector<std::string> musicTitle;

	musicTitle=L.getStringVector("music");


	for (int i = 0; i < musicTitle.size(); i++)
		mGUI.Push(new Choice(musicTitle[i], Font, [=]() {mObj->getAudio().playBGM(i); }));

/*	mGUI.Push(new Choice("02 �ފ݂̌�", Font, []() {mObj->getAudio().playBGM(1); }));
	mGUI.Push(new Choice("03 �H�S����", Font, []() {mObj->getAudio().playBGM(2); }));
	mGUI.Push(new Choice("04 ���𕑂���", Font, []() {mObj->getAudio().playBGM(3); }));
	mGUI.Push(new Choice("05 �A�o���M�����h�}�W�b�N", Font, []() {mObj->getAudio().playBGM(4); }));
	mGUI.Push(new Choice("06 ", Font, []() {mObj->getAudio().playBGM(5); }));
	mGUI.Push(new Choice("07 �₨��낸�̔����A�_�X�̐Ԃ���", Font, []() {mObj->getAudio().playBGM(6); }));
	mGUI.Push(new Choice("08 ���̔��M", Font, []() {mObj->getAudio().playBGM(7); }));
	mGUI.Push(new Choice("09 ���̗��j��", Font, []() {mObj->getAudio().playBGM(8); }));
	mGUI.Push(new Choice("10 �W�F���X�g�[��", Font, []() {mObj->getAudio().playBGM(9); }));
	mGUI.Push(new Choice("11 ��̋P���Ԃ���n", Font, []() {mObj->getAudio().playBGM(10); }));
	mGUI.Push(new Choice("12 �閾�����I���", Font, []() {mObj->getAudio().playBGM(11); }));
	mGUI.Push(new Choice("13 �Q�[���I�[�o�[", Font, []() {mObj->getAudio().playBGM(12); }));
	*/
	mGUI.Push(new Choice("�߂�", Font, [this]() { mSceneChanger->BackScene(); }));

	mGUI.link("�߂�", "", musicTitle[0]);
	mGUI.link(musicTitle[0], "�߂�");

}

void Music::Initialize()noexcept {
	mLiveFlag = true;
	mGUI.Init("01 ��s�D��S");

}

void Music::Finalize()noexcept {}

void Music::Update(float t)noexcept {
	mGUI.Update();
	if (Key[Data.Key.Button32] == 1) {
		mSceneChanger->BackScene();
	}
}
void Music::Draw()const noexcept {
	DxWrp::DrawStringToHandle(5, 5, "�~���[�W�b�N���[��", 0xCC00FF, Font05, WHITE);
	mGUI.Draw();
	DxWrp::DrawStringToHandle(0, 705, "Z : �Đ��E��~�؂�ւ� X : �O�̉�ʂɖ߂�", 0xCC00FF, Font05, WHITE);
}