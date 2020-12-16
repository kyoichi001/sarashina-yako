
#include "Item.h"
#include "../Player/IPlayer.h"
#include "../../../Library/Renderer.h"

 int ExtendHdl, BonusHdl, PowerHdl;
/* ExtendHdl = LoadGraph("Picture/Item/1upPic.png");
 BonusHdl = LoadGraph("Picture/Item/1upPic.png");
 PowerHdl = LoadGraph("Picture/Item/1upPic.png");*/

/*void(*ItemFunc[])(IPlayer&) = {
	[](IPlayer& Player) {},
	[](IPlayer& Player) {},
	[](IPlayer& Player) {},
	//[](Player& Player) {Player.AddLife(1); },
	//[](Player& Player) {Player.AddPower(1); },
	//[](Player& Player) {Player.AddPower(1); },
};
void(*ItemDraw[])(const Point&) = {
	[](const Point& p) {DxWrp::DrawGraph(p, ExtendHdl); },
	[](const Point& p) {DxWrp::DrawGraph(p, PowerHdl); },
	[](const Point& p) {DxWrp::DrawGraph(p, BonusHdl); },
};*/

SubWeapon::SubWeapon(const Point& P)noexcept:IItem(P){}
SubWeapon::~SubWeapon()noexcept{}

void SubWeapon::UpdateObj(float t)noexcept {
	mState = 2;
}
void SubWeapon::Draw()const noexcept {
	draw(0xFFFFFF);
}
void SubWeapon::Execute() noexcept {
	mPlayerPtr->AddSubWeapon(1);
}