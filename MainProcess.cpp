
#include "MainProcess.h"
#include "Class\Object\Effect\Effects.h"

//#include "Class\Scene\Title\Title.h"
#include "Class\Scene\Title\Menu.h"
#ifdef _DEBUG
#include "Data/DATA.h"
#include "DxLib.h"
#endif

Main::Main() noexcept:mCollision(&mAdaptor)
{
	Task::SetAdaptor(&mAdaptor);
	LoadEffectResource();
}
Main::~Main()noexcept {}

void Main::Initialize()noexcept {
	Scene.Start(new Menu(0));
	mTime = 0;
#ifdef _DEBUG
	fogflag = true;
	//Scene.setDebugInfo(mAdaptor.DbgInfo().getGUI(), 8, "Scene", { Font01,0xFFFFFF ,0x999999 });
#endif
}

void Main::Update() noexcept {
#ifdef _DEBUG
	if (Key[KEY_INPUT_D] == 1)debugflag = !debugflag;
	if (Key[KEY_INPUT_U] == 1) {
		fogflag = !fogflag;
		SetFogEnable(fogflag);
	}
#endif
	Scene.Update(1.0f);
	mAdaptor.ObjectListUpdate();
	mAdaptor.ObjectUpdate();

	if (mTime % 2 == 0) {
		mCollision.Update();
		if (mTime % 10 == 0)
			mCollision.EraceOverObject();
	}
	++mTime;
}

void Main::Draw() noexcept {
	Scene.Draw();
#ifdef _DEBUG
	if (debugflag){
		mAdaptor.DbgInfo().Draw();
	}
#endif
}

void Main::Finalize()noexcept {
	Scene.Finalize();
}

bool Main::IsEnd()const noexcept {return Scene.IsEnd();}
