#pragma once

#include "../../../../Library/Lua/LuaScript.h"

class GUI;
class WidgetFont;

//_bgm
//_se
//_draw3DFlag
//_difficulty
//_pWeapon
//{"volumeBar", "name", font, data, datanum}
//{"select", "name", font, widgetList}
//{"choice", "name", font, selectableFlag = true, callBack = []() {}}
//{"onOff", "name", font, data}
int backScene(lua_State* L);
int killScene(lua_State* L);
int pushScene(lua_State* L);
int reserveScene(lua_State* L);
int reserveGame(lua_State* L);
int startGame(lua_State* L);
int endSceneManager(lua_State* L);

class MenuScript {
	LuaScript mScript;
	void setWidget(const std::string& sceneName, lua_State* L, GUI* gui);
	void setWidgetChoice(const std::string& sceneName, lua_State* L, GUI* gui);
	void setWidgetSelect(const std::string& sceneName, lua_State* L, GUI* gui);
	void setWidgetVolume(const std::string& sceneName, lua_State* L, GUI* gui);
	void setWidgetCommon(lua_State* L,  std::string& name, WidgetFont& font, std::string& id);
	void setWidgetList(const std::string& sceneName, lua_State* L, GUI* gui);
public:
	MenuScript(const std::string& file);
	//スクリプトに定義されているシーンのテーブルからGUIを生成する
	GUI* createGUI(const std::string& scene);
};