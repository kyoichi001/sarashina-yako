
#ifdef _DEBUG

#include "Debug.h"

#include "../../../../Library/Scene/ISceneChanger.h"
#include "../../../../Library/GUI/Widget.h"
#include "../../../../Library/GUI/GUI.h"
#include "../../../../Data/Resource.h"
#include "../../../../Library/Color/ColorData.h"

Debug::Debug() :BaseMenu(), mGUI(Point::Zero) {}

void Debug::Initialize()noexcept {

	//WidgetFont ConfigFont = { Font02, WHITE, GREY };
	mLiveFlag = true;
	/*gui.Push(new Select("enemy   ", MenuFont));
	gui.Push(new Select("boss    ", MenuFont));
	gui.Push(new Select("bullet  ", MenuFont));
	gui.Push(new Select("p bullet", MenuFont));
	gui.Push(new Choice("back    ", MenuFont, [menuScene]() {menuScene->KillScene(); }));
	gui.GetWidget<Select>(0).Push(new Choice("Enemy1_1", MenuFont, [this]() {mObj->FacEmy().CreateEnemy(0, Mouse.p, 0); }));
	gui.GetWidget<Select>(0).Push(new Choice("Enemy1_2", MenuFont, [this]() {mObj->FacEmy().CreateEnemy(1, Mouse.p, 0); }));
	gui.GetWidget<Select>(0).Push(new Choice("Enemy1_3", MenuFont, [this]() {mObj->FacEmy().CreateEnemy(2, Mouse.p, 0); }));
	gui.GetWidget<Select>(0).Push(new Choice("Enemy1_4", MenuFont, [this]() {mObj->FacEmy().CreateEnemy(3, Mouse.p, 0); }));
	gui.GetWidget<Select>(0).Push(new Choice("Enemy1_5", MenuFont, [this]() {mObj->FacEmy().CreateEnemy(4, Mouse.p, 0); }));
	gui.GetWidget<Select>(0).Push(new Choice("Enemy2_1", MenuFont, [this]() {mObj->FacEmy().CreateEnemy(5, Mouse.p, 0); }));
	gui.GetWidget<Select>(0).Push(new Choice("Enemy2_2", MenuFont, [this]() {mObj->FacEmy().CreateEnemy(6, Mouse.p, 0); }));
	gui.GetWidget<Select>(0).Push(new Choice("Enemy2_3", MenuFont, [this]() {mObj->FacEmy().CreateEnemy(7, Mouse.p, 0); }));
	gui.GetWidget<Select>(0).Push(new Choice("Enemy2_4", MenuFont, [this]() {mObj->FacEmy().CreateEnemy(8, Mouse.p, 0); }));
	gui.GetWidget<Select>(0).Push(new Choice("Enemy2_5", MenuFont, [this]() {mObj->FacEmy().CreateEnemy(9, Mouse.p, 0); }));

	gui.GetWidget<Select>(1).Push(new Choice("boss0", MenuFont, [this]() { mObj->FacEmy().CreateBoss(0, Mouse.p, nullptr); }));
	gui.GetWidget<Select>(1).Push(new Choice("boss1", MenuFont, [this]() { mObj->FacEmy().CreateBoss(1, Mouse.p, nullptr); }));
	gui.GetWidget<Select>(1).Push(new Choice("boss2", MenuFont, [this]() { mObj->FacEmy().CreateBoss(2, Mouse.p, nullptr); }));

	gui.GetWidget<Select>(2).Push(new Choice("void  ", MenuFont, [this]() {mObj->FacBul().Bullet(0, Mouse.p, HALF_PI, 3.0f, static_cast<BulletShape>(0), Red); }));
	gui.GetWidget<Select>(2).Push(new Choice("small ", MenuFont, [this]() {mObj->FacBul().Bullet(0, Mouse.p, HALF_PI, 3.0f, static_cast<BulletShape>(1), Red); }));
	gui.GetWidget<Select>(2).Push(new Choice("midium", MenuFont, [this]() {mObj->FacBul().Bullet(0, Mouse.p, HALF_PI, 3.0f, static_cast<BulletShape>(2), Red); }));
	gui.GetWidget<Select>(2).Push(new Choice("big   ", MenuFont, [this]() {mObj->FacBul().Bullet(0, Mouse.p, HALF_PI, 3.0f, static_cast<BulletShape>(3), Red); }));
	gui.GetWidget<Select>(2).Push(new Choice("huge  ", MenuFont, [this]() {mObj->FacBul().Bullet(0, Mouse.p, HALF_PI, 3.0f, static_cast<BulletShape>(4), Red); }));
	gui.GetWidget<Select>(2).Push(new Choice("arrow ", MenuFont, [this]() {mObj->FacBul().Bullet(0, Mouse.p, HALF_PI, 3.0f, static_cast<BulletShape>(5), Red); }));
	gui.GetWidget<Select>(2).Push(new Choice("fuda  ", MenuFont, [this]() {mObj->FacBul().Bullet(0, Mouse.p, HALF_PI, 3.0f, static_cast<BulletShape>(6), Red); }));
	gui.GetWidget<Select>(2).Push(new Choice("water ", MenuFont, [this]() {mObj->FacBul().Bullet(0, Mouse.p, HALF_PI, 3.0f, static_cast<BulletShape>(7), Red); }));
	gui.GetWidget<Select>(2).Push(new Choice("sOval ", MenuFont, [this]() {mObj->FacBul().Bullet(0, Mouse.p, HALF_PI, 3.0f, static_cast<BulletShape>(8), Red); }));
	gui.GetWidget<Select>(2).Push(new Choice("lOval ", MenuFont, [this]() {mObj->FacBul().Bullet(0, Mouse.p, HALF_PI, 3.0f, static_cast<BulletShape>(9), Red); }));

	mObj->Obj3Ds().Draw();
	DrawBox(0, 0, 960, 720, BLACK);
	mMenu.Draw({ 0,0 });

	mObj->GetPlayer().Draw();
	mObj->ObjEmy().Draw();
	mObj->ObjBss().Draw();
	mObj->ObjBul().Draw();
	mObj->ObjLez1().Draw();
	mObj->ObjLez3().Draw();
	mObj->ObjItm().Draw();
	mObj->ObjPBl().Draw();
	mObj->ObjBom().Draw();
	mObj->ObjPOp().Draw();
	mCList->GetEmy().DrawName();
	mObj->ObjEff().Draw();
	gui.setCanselFunc([menuScene]() {if (Key[Data.Key.Button32] == 1)menuScene->BackScene(); });*/

	//mGUI.Init("Stage 1");
}

void Debug::Finalize()noexcept {}

void Debug::Update(float t)noexcept {
	mGUI.Update();
}
void Debug::Draw()const noexcept {
	mGUI.Draw();
}

#endif