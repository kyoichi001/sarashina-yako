
#include "DATA.h"
#include "DxLib.h"
#include "../Library/Primitive/Primitive.h"

GameSaveDATA Data;
char difficulty;
char p_weapon;
bool pauseflag;
bool Draw3DFlag=true;
bool programEndFlag=false;
bool eventFlag = false;
int CollisionUpdate=2;
const Rect GameWindow = { WALL_X1,WALL_Y1,WALL_X2,WALL_Y2 };
const Rect BulletRect = { WALL_X1 - 100,WALL_Y1 - 100,WALL_X2 + 100,WALL_Y2 + 100 };
const Point playerDefault = { 300, 500 };
int gameOriginX, gameOriginY;
bool clearFlag=false, gameoverFlag=false;
float bulletDeltaTime=1.0f;

int Key[256]; // キーが押されているフレーム数を格納する

int gpUpdateKey()noexcept {
	char tmpKey[256]; // 現在のキーの入力状態を格納する
	GetHitKeyStateAll(tmpKey); // 全てのキーの入力状態を得る
	for (int i = 0; i < 256; ++i) {
		if (tmpKey[i] != 0) // i番のキーコードに対応するキーが押されていたら
			++Key[i];     // 加算
		else               // 押されていなければ
			Key[i] = 0;   // 0にする
	}
	return 0;
}

void InitKeyData()noexcept {
	Data.Key.Button01 = KEY_INPUT_UP;
	Data.Key.Button02 = KEY_INPUT_DOWN;
	Data.Key.Button04 = KEY_INPUT_LEFT;
	Data.Key.Button08 = KEY_INPUT_RIGHT;
	Data.Key.Button16 = KEY_INPUT_Z;
	Data.Key.Button32 = KEY_INPUT_X;
	Data.Key.Button64 = KEY_INPUT_LSHIFT;
	Data.Key.Button128 = KEY_INPUT_D;
	Data.Key.Button256 = KEY_INPUT_SPACE;
	Data.Key.Button512 = KEY_INPUT_ESCAPE;
}

int MouseKey[3];
int MouseWheel;
Circle Mouse;

int gpUpdateMouse()noexcept {

	MouseWheel = GetMouseWheelRotVol();
	int MouseX, MouseY;
	GetMousePoint(&MouseX, &MouseY);
	Mouse.p.x = MouseX;
	Mouse.p.y = MouseY;
	Mouse.r = 10;

	int tmpKey; // 現在のキーの入力状態を格納する

	tmpKey = GetMouseInput();
	tmpKey&MOUSE_INPUT_LEFT ? ++MouseKey[0] : MouseKey[0] = 0;
	tmpKey&MOUSE_INPUT_RIGHT ? ++MouseKey[1] : MouseKey[1] = 0;
	tmpKey&MOUSE_INPUT_MIDDLE ? ++MouseKey[2] : MouseKey[2] = 0;

	return 0;
}

#ifdef _DEBUG
bool debugflag, scriptreadflag, fogflag;
int Direct3DVersion, Valid3DVersion;
float timeSpeed=1.0f;
#endif