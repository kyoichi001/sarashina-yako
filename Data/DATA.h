
#pragma once

#include "../Library/Typedef.h"

#define WALL_X1 36
#define WALL_Y1 28
#define WALL_X2 642
#define WALL_Y2 692

class Rect;
class Point;
class Circle;

//�v���C���[��������͈�
extern const Rect GameWindow;
//�e�̗L���͈�
extern const Rect BulletRect;
constexpr int gameWidth = WALL_X2 - WALL_X1;
constexpr int gameHeight = WALL_Y2 - WALL_Y1;
//�v���C���[�̃Q�[���J�n�����W
extern const Point playerDefault;

extern bool clearFlag,gameoverFlag;

extern int gameOriginX, gameOriginY;

//�e�̃A�b�v�f�[�g�̎��ԍ���
extern float bulletDeltaTime;

int gpUpdateKey()noexcept;
extern int Key[256];
void InitKeyData()noexcept;

int gpUpdateMouse()noexcept;
extern int MouseKey[3];
extern int MouseWheel;
extern Circle Mouse;

struct Button{
	//01: ��   02: ��  04: �� 08: �E  16: Z  32: X  64: SHIFT 128: D 256: Space 512 Esc
	int Button01, Button02, Button04, Button08;
	int Button16, Button32, Button64, Button128,Button256,Button512;
};

extern char difficulty;
extern char p_weapon;
extern bool pauseflag;
extern bool Draw3DFlag;
extern bool programEndFlag;
extern bool eventFlag;
extern int CollisionUpdate;
#ifdef _DEBUG
extern bool debugflag, scriptreadflag, fogflag;
extern int Direct3DVersion, Valid3DVersion;
extern float timeSpeed;
#endif

struct GameSaveDATA{
	ulong HighScore;
	bool ClearFlag[4][5];
	uchar BGMVol, SEVol;
	Button Key;
};

extern GameSaveDATA Data;

enum BulletState:char { Absolute, Aiming, Sequence };

enum BulletColor :char { Red, Orange, Yerrow, Lime, Green, Cyan, Blue, Purple, White, Black, RandomColor, NoColor };
enum BulletShape :char { Void, Small, Midium, Big, Huge, Arrow, Fuda, Water, Leaf, SOval, LOval,Fire,Trump,Gem, NoShape };
enum LeazerShape :char{ Null, Thin, Normal, Large, VeryLarge, NoLeazer };

template<typename T>
T dif(T Easy, T Normal, T Hard, T Torture) noexcept {
	switch (difficulty) {
	case 0: return Easy;
	case 1:return Normal;
	case 2:return  Hard;
	case 3:return  Torture;
	}
	return Easy;
}

template<typename T>
T dif(T EasyNormal, T HardTorture)noexcept {
	switch (difficulty) {
	case 0:
	case 1:return EasyNormal;
	case 2:
	case 3:return  HardTorture;
	}
	return EasyNormal;
}