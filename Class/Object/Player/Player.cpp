
#include "Player.h"
#include "../../../Library/Renderer.h"
#include "Option/OptionData.h"
#include "Pbullet/PlayerBullet.h"

int PlayerAnim[4];

void InitPlayerResource()noexcept {
	DxWrp::LoadDivGraph("Picture/Chara/Player/Player3.png", 4, 4, 1, 32, 64, PlayerAnim);
	InitOptionResource();
	InitPBulletResource();
}

Hirochi1::Hirochi1() noexcept:
IPlayer(){
	mOptionZ.SetObject(new OptionInvisible(&p, Vec2{ 6.0f, -10.0f }));
	mOptionZ.SetObject(new OptionInvisible(&p, Vec2{ -6.0f, -10.0f }));
	mOptionZ.SetObject(new OptionHorming(&p, Vec2{ -30.0f, 50.0f }));
	mOptionZ.SetObject(new OptionHorming(&p, Vec2{ 30.0f, 50.0f }));
	mOptionX.SetObject(new OptionBom(&p, Vec2::Zero));
}

void Hirochi1::drawPlane()const noexcept {
	DxWrp::DrawRotaGraph(p, 1.0f, 0.0f, PlayerAnim[(mTime / 4) % 4]);
#ifdef _DEBUG
	mOptionZ.Draw_noDebug();
	mOptionX.Draw_noDebug();
#else
	mOptionZ.Draw();
	mOptionX.Draw();
#endif
}

Hirochi2::Hirochi2()noexcept{
	/*mOptionZ.SetObject(new OptionInvisible(&p, Vec2{ -20.0f, 0.0f }));
	mOptionZ.SetObject(new OptionInvisible(&p, Vec2{ 20.0f, 0.0f }));*/
	mOptionZ.SetObject(new OptionWind(&p, 0));
	mOptionZ.SetObject(new OptionWind(&p, 1));
	mOptionZ.SetObject(new OptionWind(&p, 2));
	mOptionZ.SetObject(new OptionWind(&p, 3));
	mOptionX.SetObject(new OptionBom2(&p, Vec2::Zero));
	mShoot1Interval = 6;
}
void Hirochi2::drawPlane()const noexcept {
	DxWrp::DrawRotaGraph(p, 1.0f, 0.0f, PlayerAnim[(mTime / 4) % 4]);
#ifdef _DEBUG
	mOptionZ.Draw_noDebug();
	mOptionX.Draw_noDebug();
#else
	mOptionZ.Draw();
	mOptionX.Draw();
#endif
}