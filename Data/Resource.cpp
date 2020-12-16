
#include "Resource.h"
#include "dxlib.h"

int Font01, Font02, Font03, Font04, Font05, Font06;
int TrainHdl, TreeHdl, BuildingHdl, RailHdl;
int EnemyMarkerHdl;
int  PlayerCoreHdl, HitEffectHdl, SlowEffectHdl;
int BulletEffectHdl[10], SnowHdl, PBuletBreakHdl, BossBreakHdl, EnemyBreakHdl, PlayerBreakHdl;
int StageBackShadowHdl, Stage1Hdl;
int MenuBackHdl, MenuBackShadowHdl;
int Ghost3DHdl,Clowd3DHdl, Snow3DHdl;

void LoadFont()noexcept;
void Load3D()noexcept;
void LoadPData()noexcept;
void LoadEffectHdl()noexcept;
void LoadStageHdl()noexcept;

#ifdef _DEBUG
#include "DATA.h"
#endif

void Init3D()noexcept {
#ifdef _DEBUG
	Direct3DVersion = GetUseDirect3DVersion();
	Valid3DVersion = GetValidShaderVersion();
#endif
	//SetFogEnable(TRUE);
	SetUseZBuffer3D(TRUE);
	SetWriteZBuffer3D(TRUE);
	SetFogColor(0, 0, 255);
	//SetFogStartEnd(100.0f, 5000.0f);
}

void LoadAllData()noexcept {
	LoadFont();
	Load3D();
	LoadPData();
	LoadEffectHdl();
	LoadStageHdl();
}

void LoadFont()noexcept {
	//BGMルーム用
	Font01 = CreateFontToHandle("HGS創英角ｺﾞｼｯｸUB", 20, 1, DX_FONTTYPE_ANTIALIASING, -1, 2);
	//タイトルメニュー選択用
	Font02 = CreateFontToHandle("HGS明朝E", 35, 2, DX_FONTTYPE_ANTIALIASING, -1, 1);
	//タイトルメニュー非選択用
	//起動時注意書き用
	//Presented by～用
	Font03 = CreateFontToHandle("HG創英ﾌﾟﾚｾﾞﾝｽEB", 20, 1, DX_FONTTYPE_ANTIALIASING, -1, 2);
	Font04 = CreateFontToHandle("HG創英ﾌﾟﾚｾﾞﾝｽEB", 23, 1, DX_FONTTYPE_ANTIALIASING);
	//タイトル用２
	Font05 = CreateFontToHandle("Meiryo UI", 35, 3, DX_FONTTYPE_ANTIALIASING, -1, 2);
	//難易度選択用２
	Font06 = CreateFontToHandle("Meiryo UI", 65, 10, DX_FONTTYPE_ANTIALIASING, -1, 2);
}

void Load3D()noexcept {
	RailHdl = MV1LoadModel("3D/Rail2.x");
	TrainHdl = MV1LoadModel("3D/train_re4.mv1");
	BuildingHdl = MV1LoadModel("3D/Buildings.mv1");
	TreeHdl = LoadGraph("Picture/tree2.png");
	Ghost3DHdl = LoadGraph("Picture/ghost3D.png");
	Clowd3DHdl = LoadGraph("Picture/clowd3.png");
	Snow3DHdl= LoadGraph("Picture/snow3D.png");
}

void LoadPData()noexcept {
	// PlayerHdl = LoadGraph("Picture/Chara/Player/Player.png");
	PlayerCoreHdl = LoadGraph("Picture/Chara/Player/PlayerCore.png");
	HitEffectHdl = LoadGraph("Picture/Effect/BossBreak.png");
	SlowEffectHdl = LoadGraph("Picture/Chara/Player/PlayerSlow.png");
}

void LoadEffectHdl()noexcept {
	SnowHdl = LoadGraph("Picture/Effect/StarEffect.png");
	BossBreakHdl = LoadGraph("Picture/Effect/EnemyEffect02.png");
	EnemyBreakHdl = LoadGraph("Picture/Effect/BreakEffect.png");
	LoadDivGraph("Picture/Bullet/MidiumBullet.png", 10, 10, 1, 16, 16, BulletEffectHdl);
	PBuletBreakHdl = LoadGraph("Picture/Bullet/BasicBullet/BasicFudaBullet.png");
	PlayerBreakHdl = LoadGraph("Picture/Effect/PlayerBreak.png");
	EnemyMarkerHdl = LoadGraph("Picture/Bullet/BasicBullet/BasicArrowBullet.png");
	//LoadDivGraph("Picture/Effect/bulletBreakEffect.png", 10, 10, 1, 32, 32, BreakEffectHdl);
}

void LoadStageHdl() noexcept {
	StageBackShadowHdl= LoadGraph("Picture/Back/BackShadow.png");
	Stage1Hdl = LoadGraph("Picture/StageTitle.png");
}
