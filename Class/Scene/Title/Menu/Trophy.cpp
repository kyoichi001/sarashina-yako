
#include "Trophy.h"

#include "../../../../Library/Scene/ISceneChanger.h"
#include "../../../../Library/GUI/Widget.h"
#include "../../../../Library/GUI/GUI.h"
#include "../../../../Data/Resource.h"
#include "../../../../Library/Color/ColorData.h"

Trophy::Trophy() :BaseMenu(), mGUI(Point::Zero) {

	const WidgetFont Font = { Font02, WHITE, GREY };

	mGUI.Push(new Choice("Stage 3をクリアする", Font, []() {}));//折り返し
	mGUI.Push(new Choice("Stage 5をクリアする", Font, []() {}));//おわり
	mGUI.Push(new Choice("Stage 5をノーミスでクリア", Font, []() {}));//
	mGUI.Push(new Choice("すべてのステージをノーミスでクリア", Font, []() {}));//
	mGUI.Push(new Choice("すべてのステージを最高難易度でノーミスノーボムでクリア", Font, []() {}));//
	mGUI.Push(new Choice("ボスバトルをクリア", Font, []() {}));//
	mGUI.Push(new Choice("サブウェポンを1ステージで10回使う", Font, []() {}));//大胆不敵
	mGUI.Push(new Choice("戻る", Font, [this]() { mSceneChanger->BackScene(); }));
	//mGUI.setCanselFunc([this]() {mSceneChanger->BackScene(); });
}

void Trophy::Initialize()noexcept {
	mLiveFlag = true;
	mGUI.Init("Stage 3をクリアする");
}

void Trophy::Finalize()noexcept {}

void Trophy::Update(float t)noexcept {
	mGUI.Update();
}
void Trophy::Draw()const noexcept {
	DxWrp::DrawStringToHandle(15, 0, "トロフィー", 0xCCCC22, Font05, WHITE);
	mGUI.Draw();
}