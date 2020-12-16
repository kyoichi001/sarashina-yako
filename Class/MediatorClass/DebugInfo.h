
#pragma once
#ifdef _DEBUG

#include "../../Library/GUI/GUI.h"
#include "../../Library/GUI/WidgetFont.h"

class ObjectAdaptor;
struct ListInfo {
	int mUpdateTime, mDrawTime, mMakeTime, mSize;
};

class DebugInfo{
	ObjectAdaptor* mAdaptor;
	GUI mWindow;
	ListInfo mListInfo[10];
	void initBase     () noexcept;
	void initPlayer   () noexcept;
	void initBullet   () noexcept;
	void initLeazer   () noexcept;
	void initEnemy    () noexcept;
	void init3D       () noexcept;
	void initEffect   () noexcept;
	void initEmitter  () noexcept;
	void initCollision() noexcept;
	void initScene() noexcept;
	void setListGUI(const std::string& name, ListInfo& info,const std::string& listName);
	WidgetFont mFont;
public:

	DebugInfo()noexcept : mWindow({}){}
	DebugInfo(ObjectAdaptor* Adaptor)noexcept;

	void Update()noexcept;
	void Draw()const noexcept;

	void push(int Tab, IWidget* widget)noexcept;

	GUI& getGUI()noexcept { return mWindow; }

};

#endif