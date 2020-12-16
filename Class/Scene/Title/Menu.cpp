#include "Menu.h"

#include "../../../Library/3DFunc.h"
#include "../../../Library/Renderer.h"
#include "../../MediatorClass/ObjectAdaptor.h"
#include "../../Object/3D/3DObjects.h"

#include "Menu\Home.h"

Menu::Menu(int Value) noexcept: Task(Value) {
	mMenumgr.Start(new Home());
}

//‰Šú‰»
void Menu::Initialize()noexcept {
	BaseMenu::SetMenuptr(this);
	mMenumgr.Resume();
	mLiveFlag = true;

	DxWrp::SetFogEnable(true);
	DxWrp::SetFogColor(0, 0, 0);
	DxWrp::SetFogStartEnd(800, 2500);
	mObj->Obj3Ds().Kill();
	for (int i = 0; i < 5; ++i)
		mObj->Obj3Ds().SetObject(new CChunk1_1( { -200.0f + i * 1500, 0.0f, -700.0f },0));
	mObj->GetCamera().SetPosi({ 663.0f, 971.0f, -623.0f });
	mObj->GetCamera().SetTarg({ 534.0f, 834.0f, -192.0f });

	//MenuBackHdl = LoadGraph("Picture/Back/MenuBack.png");
	backShadowHdl = DxWrp::LoadGraph("Picture/Scene/Menu/BackShadow.png");
	mBackAlpha = 0;
	mChangeFlag = false;
	mTime = 0;
	mObj->getAudio().playBGM(0);
}

void Menu::Finalize()noexcept {
	mMenumgr.Finalize();
	DxWrp::DeleteGraph(backShadowHdl);
	mObj->Obj3Ds().Kill();
	mObj->getAudio().stopBGM();
}

#include "../../Object/Effect/Effects.h"

//XV
void Menu::Update(float t)noexcept {
	if (mMenumgr.IsEnd()) {
		mChangeFlag = true;
		if (mTime == 0) {
			//mObj->ObjEff().SetObject(new FadeOut(0x000000, 30,65));
		}
		if (mTime > 60) {
			mLiveFlag = false;
			return;
		}
		mTime++;
	}
	else {
		mMenumgr.Update(t);
	}
}

//•`‰æ
void Menu::Draw()const noexcept {

	if (Draw3DFlag)
		mObj->Obj3Ds().Draw();

	DxWrp::DrawGraph(0, 0, backShadowHdl);

	DxWrp::SetBlendModeAlpha(150);
	DxWrp::DrawBox(0, 0, 960, 720, 0x000000);
	DxWrp::ResetBlendMode();

	mMenumgr.Draw();

#ifdef _DEBUG
	mObj->ObjEff().Draw_noDebug();
#endif
}
