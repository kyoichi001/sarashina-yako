
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
	//BGM���[���p
	Font01 = CreateFontToHandle("HGS�n�p�p�޼��UB", 20, 1, DX_FONTTYPE_ANTIALIASING, -1, 2);
	//�^�C�g�����j���[�I��p
	Font02 = CreateFontToHandle("HGS����E", 35, 2, DX_FONTTYPE_ANTIALIASING, -1, 1);
	//�^�C�g�����j���[��I��p
	//�N�������ӏ����p
	//Presented by�`�p
	Font03 = CreateFontToHandle("HG�n�p��ھ�ݽEB", 20, 1, DX_FONTTYPE_ANTIALIASING, -1, 2);
	Font04 = CreateFontToHandle("HG�n�p��ھ�ݽEB", 23, 1, DX_FONTTYPE_ANTIALIASING);
	//�^�C�g���p�Q
	Font05 = CreateFontToHandle("Meiryo UI", 35, 3, DX_FONTTYPE_ANTIALIASING, -1, 2);
	//��Փx�I��p�Q
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
