#ifdef _DEBUG
#include "DxLib.h"
#include "DebugInfo.h"
#include "../../Library/Func.h"
#include "../../Library/Renderer.h"
#include "../../Library/Color/ColorData.h"
#include "../../Library/Scene/Task.h"
#include "../../Data/Data.h"
#include "../../Data/Resource.h"
#include "../MediatorClass/ObjectAdaptor.h"
#include "../MediatorClass/CollisionMediator.h"
#include "../../Library/GUI/Widget.h"

template<typename T>
void updateObjectListInfo(ListInfo& info, const ObjectList<T>& List)noexcept {
	info.mSize = List.size();
	info.mUpdateTime = List.GetUpdateTime();
	info.mDrawTime = List.GetDrawTime();
	info.mMakeTime = List.GetMakeTime();
}
template<typename T>
void updateObjectListInfo(ListInfo& info, const FixedObjectList<T>& List)noexcept {
	info.mSize = List.size();
	info.mUpdateTime = List.GetUpdateTime();
	info.mDrawTime = List.GetDrawTime();
	info.mMakeTime = List.GetMakeTime();
}
/*template<typename T>
void updateObjectListInfo(ListInfo& info, const FixedObjectListMorton<T>& List)noexcept {
	info.mSize = List.size();
	info.mUpdateTime = List.GetUpdateTime();
	info.mDrawTime = List.GetDrawTime();
	info.mMakeTime = List.GetMakeTime();
}*/

DebugInfo::DebugInfo(ObjectAdaptor* Adaptor) noexcept:mAdaptor(Adaptor),mWindow({950.0f,0.0f}) {
	//_GetSystemInfo(&Dxlibver, &DirectXver, NULL);
	mFont = { Font01, WHITE, GREY };
	mWindow.SetOfset({ 80.0f,0.0f });
	mWindow.Push(new Tab("tab0",&mWindow));
	mWindow.Push(new Tab("tab1",&mWindow));
	mWindow.Push(new Tab("tab2",&mWindow));
	mWindow.Push(new Tab("tab3",&mWindow));
	mWindow.Push(new Tab("tab4",&mWindow));
	mWindow.Push(new Tab("tab5",&mWindow));
	mWindow.Push(new Tab("tab6",&mWindow));
	mWindow.Push(new Tab("tab7",&mWindow));
	mWindow.Push(new Tab("tab8",&mWindow));
	mWindow.Push(new Tab("tab9",&mWindow));
	initBase();
	initPlayer();
	initBullet();
	initLeazer();
	initEnemy();
	init3D();
	initEffect();
	initEmitter();
	initCollision();
	mWindow.link("tab0", "", "", "tab9", "tab1");
	mWindow.link("tab1", "", "", "tab0", "tab2");
	mWindow.link("tab2", "", "", "tab1", "tab3");
	mWindow.link("tab3", "", "", "tab2", "tab4");
	mWindow.link("tab4", "", "", "tab3", "tab5");
	mWindow.link("tab5", "", "", "tab4", "tab6");
	mWindow.link("tab6", "", "", "tab5", "tab7");
	mWindow.link("tab7", "", "", "tab6", "tab8");
	mWindow.link("tab8", "", "", "tab7", "tab9");
	mWindow.link("tab9", "", "", "tab8", "tab0");
	mWindow.Init("tab0");
	//mWindow.GetWidget<Tab>("debugtab").setOfs({ 0.0f,25.0f });
}

void DebugInfo::setListGUI(const std::string& name, ListInfo& info, const std::string& listName) {
	mWindow.GetWidget<Tab>(name).Push(new Viewer<int>(listName+"Size", mFont, &info.mSize));
	mWindow.GetWidget<Tab>(name).Push(new Viewer<int>(listName+"Update Time", mFont, &info.mUpdateTime));
	mWindow.GetWidget<Tab>(name).Push(new Viewer<int>(listName+"Draw Time", mFont, &info.mDrawTime));
	mWindow.GetWidget<Tab>(name).Push(new Viewer<int>(listName+"Make Time", mFont, &info.mMakeTime));

}
void DebugInfo::Update()noexcept {
	//if (Key[KEY_INPUT_R] == 1)difficulty = (difficulty + 1) % 4;
	updateObjectListInfo<IPBullet>(mListInfo[0], mAdaptor->ObjPBl());
	updateObjectListInfo<IBullet>(mListInfo[1], mAdaptor->ObjBul());
	updateObjectListInfo<IGhost>(mListInfo[2], mAdaptor->ObjEmy());
	updateObjectListInfo<IBoss>(mListInfo[3], mAdaptor->ObjBss());
	updateObjectListInfo<I3D>(mListInfo[4], mAdaptor->Obj3Ds());
	updateObjectListInfo<IEffect>(mListInfo[5], mAdaptor->ObjEff());
	updateObjectListInfo<I3DEffect>(mListInfo[6], mAdaptor->Obj3Ef());
	updateObjectListInfo<Emitter>(mListInfo[7], mAdaptor->ObjEmi());
	mWindow.Update();
	//mAdaptor->GetCamera().Debug();
}

void DebugInfo::Draw()const noexcept {
	DrawLine(Mouse.p.x, 0, Mouse.p.x, 720, ORANGE);
	DrawLine(0, Mouse.p.y, 960, Mouse.p.y, CYAN);
	mWindow.Draw();
	/*DrawLine3D({0.0f, 0.0f, 0.0f}, {9000.0f, 0.0f, 0.0f}, RED);
	DrawLine3D({0.0f, 0.0f, 0.0f}, {0.0f, 9000.0f, 0.0f}, 0x00FF00);
	DrawLine3D({0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 9000.0f}, BLUE);
	DrawSphere3D({ 0.0f, 0.0f, 0.0f }, 20, 10, ORANGE, WHITE, TRUE);*/

	//DxLib::DrawFormatString(X + 5, Y + 145, RED, "X");
	//DxLib::DrawFormatString(X + 45, Y + 145, GREEN, "Y");
	//DxLib::DrawFormatString(X + 85, Y + 145, BLUE, "Z");

	//VECTOR V = ConvScreenPosToWorldPos({ X + 30.0f, Y + 180.0f, 0.0f });
	//DxLib::DrawLine3D(V, VAdd(V, {0.0f, 10.0f, 0.0f}), GREEN);
	//DxLib::DrawLine3D(V, VAdd(V, {0.0f, 0.0f, 10.0f}), BLUE);
	//DxLib::DrawLine3D(V, VAdd(V, {10.0f, 0.0f, 0.0f}), RED);
}

void DebugInfo::initBase() noexcept {
	mWindow.GetWidget<Tab>("tab0").Push(new Viewer<Circle>("Mouse", mFont, &Mouse));
	mWindow.GetWidget<Tab>("tab0").Push(new Viewer<char>("difficulty", mFont, &difficulty));
	mWindow.GetWidget<Tab>("tab0").Push(new Viewer<char>("weapon", mFont, &p_weapon));
}

void DebugInfo::initPlayer() noexcept {
	setListGUI("tab1",mListInfo[0], "Player Bullet");
}
void DebugInfo::initBullet() noexcept {
	setListGUI("tab2", mListInfo[1], "Bullet");

	for (auto& Obj : mAdaptor->ObjBul()) {
		Obj.DrawGraze();
		Obj.DrawHit();
		Obj.DrawSpeed();
	}
}
void DebugInfo::initLeazer() noexcept {
}

void DrawCircleXYLine(const Circle& Obj) {
	DrawLine(Obj.p.x, 0, Obj.p.x, 720, GREEN);
	DrawLine(0, Obj.p.y, 960, Obj.p.y, RED);
	Obj.draw(WHITE,false);
}
void DrawEnemyXYLine(ObjectAdaptor& Adaptor) noexcept {
	for (auto& Obj : Adaptor.ObjEmy()) {
		//DrawCircleXYLine(it);
	}
	for (auto& Obj : Adaptor.ObjBss()) {
		//DrawCircleXYLine(it);
	}
}

void DebugInfo::initEnemy() noexcept {
	setListGUI("tab3", mListInfo[2], "Ghost");
	setListGUI("tab3", mListInfo[3], "Boss");

	DrawEnemyXYLine(*mAdaptor);

	for (auto& Obj : mAdaptor->ObjBss()) {
		Obj.DrawDebug();
	}
}
void DebugInfo::init3D() noexcept {

	for (auto& Obj : mAdaptor->Obj3Ds()) {
		Obj->DrawDebug();
	}

	setListGUI("tab4", mListInfo[4], "3D Obj");

	mWindow.GetWidget<Tab>("tab4").Push(new Viewer<Vec3>("Camera Position", mFont, &mAdaptor->GetCamera()));
	mWindow.GetWidget<Tab>("tab4").Push(new Viewer<Vec3>("Camera Target", mFont, &mAdaptor->GetCamera().GetTarg()));


}
void DebugInfo::initEffect() noexcept {
	setListGUI("tab5", mListInfo[5], "Effect");
	setListGUI("tab5", mListInfo[6], "3DEffect");
}

void DebugInfo::initEmitter() noexcept {
	setListGUI("tab6", mListInfo[7], "Emitter");
}

void DebugInfo::initCollision()noexcept {
	/*
	DxLib::DrawFormatString(X + 5, Y + 5, WHITE, "Collision Bom Bullet          = %d", mCollision->GetBomBulletTime());
	DxLib::DrawFormatString(X + 5, Y + 25, WHITE, "Collision Bom Enemy           = %d", mCollision->GetBomEnemyTime());
	DxLib::DrawFormatString(X + 5, Y + 45, WHITE, "Collision Bullet Player       = %d", mCollision->GetBulletPlayerTime());
	DxLib::DrawFormatString(X + 5, Y + 65, WHITE, "Collision Item  Player        = %d", mCollision->GetItemPlayerTime());
	DxLib::DrawFormatString(X + 5, Y + 85, WHITE, "Collision PBullet Enemy       = %d", mCollision->GetPBulletEnemyTime());
	*/
}
void DebugInfo::initScene() noexcept {
}

void DebugInfo::push(int Tab, IWidget* widget)noexcept{
mWindow.Push(widget);
}

#endif