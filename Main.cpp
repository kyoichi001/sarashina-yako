#define _CRT_SECURE_NO_WARNINGS
//#define _SCL_SECURE_NO_WARNINGS

#include "DxLib.h"
#include "./Library/Fps.h"
#include "./Library/Color/ColorData.h"
#include "./Library/Renderer.h"
#include "./Data/Resource.h"
#include "MainProcess.h"

void WhindowInit();

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int){

	WhindowInit();
	Init3D();
	InitKeyData();
	DxWrp::InitBlend();

	LoadAllData();

	Fps mFps;

	Main Process;

	Process.Initialize();

	//SnapShotフォルダを作る
	LPSECURITY_ATTRIBUTES IpSecurity=NULL;
	CreateDirectory("SnapShot", IpSecurity);

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && 
		gpUpdateKey() == 0 && !Process.IsEnd()&& !programEndFlag){

#ifdef _DEBUG
		gpUpdateMouse();
#endif

		mFps.Update();

		Process.Update();
		Process.Draw();

		DrawFormatString(868, 700, WHITE, "%6.4f Fps", mFps.GetFps());

		if (Key[KEY_INPUT_P] == 1){
			char str[50];
			DATEDATA data;
			GetDateTime(&data);
			sprintf(str, "SnapShot/%d-%d-%d_%d_%d_%d.bmp", data.Year,data.Mon,data.Day,data.Hour,data.Min,data.Sec);
			SaveDrawScreen(0, 0, 960, 720, str);
		}
	}

	Process.Finalize();
	
	DxLib_End();

	return 0;

}

#include "Library\Lua\LuaScript.h"

void WhindowInit(){
	LuaScript L("Script/config.lua");
	SetOutApplicationLogValidFlag(L.get<bool>("logFlag"));
	SetUseDivGraphFlag(FALSE);//画像分割
	ChangeWindowMode(TRUE);
	SetMainWindowText(L.get<std::string>("window.title").c_str());//タイトル指定
	int width = L.get<int>("window.width");
	int height = L.get<int>("window.height");

#ifdef _DEBUG
	SetGraphMode(width+400, height, 32);//画面の大きさ指定
#else
	SetGraphMode(width, height, 32);//画面の大きさ指定
#endif
	//SetFullScreenResolutionMode(DX_FSRESOLUTIONMODE_NATIVE);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK); //ウィンドウモード変更と初期化と裏画面設定
	SetAlwaysRunFlag(TRUE);//非アクティブ時でも実行
	programEndFlag = false;
}