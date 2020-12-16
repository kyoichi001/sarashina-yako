
#include "Trophy.h"

#include "../../../../Library/Scene/ISceneChanger.h"
#include "../../../../Library/GUI/Widget.h"
#include "../../../../Library/GUI/GUI.h"
#include "../../../../Data/Resource.h"
#include "../../../../Library/Color/ColorData.h"

Trophy::Trophy() :BaseMenu(), mGUI(Point::Zero) {

	const WidgetFont Font = { Font02, WHITE, GREY };

	mGUI.Push(new Choice("Stage 3���N���A����", Font, []() {}));//�܂�Ԃ�
	mGUI.Push(new Choice("Stage 5���N���A����", Font, []() {}));//�����
	mGUI.Push(new Choice("Stage 5���m�[�~�X�ŃN���A", Font, []() {}));//
	mGUI.Push(new Choice("���ׂẴX�e�[�W���m�[�~�X�ŃN���A", Font, []() {}));//
	mGUI.Push(new Choice("���ׂẴX�e�[�W���ō���Փx�Ńm�[�~�X�m�[�{���ŃN���A", Font, []() {}));//
	mGUI.Push(new Choice("�{�X�o�g�����N���A", Font, []() {}));//
	mGUI.Push(new Choice("�T�u�E�F�|����1�X�e�[�W��10��g��", Font, []() {}));//��_�s�G
	mGUI.Push(new Choice("�߂�", Font, [this]() { mSceneChanger->BackScene(); }));
	//mGUI.setCanselFunc([this]() {mSceneChanger->BackScene(); });
}

void Trophy::Initialize()noexcept {
	mLiveFlag = true;
	mGUI.Init("Stage 3���N���A����");
}

void Trophy::Finalize()noexcept {}

void Trophy::Update(float t)noexcept {
	mGUI.Update();
}
void Trophy::Draw()const noexcept {
	DxWrp::DrawStringToHandle(15, 0, "�g���t�B�[", 0xCCCC22, Font05, WHITE);
	mGUI.Draw();
}