
#include "MenuScript.h"
#include "../../../../Library/Scene/ISceneChanger.h"
#include "../Menu/BaseMenu.h"
#include "../Menu/MenuFactory.h"
#include "../../Game/Game.h"

ISceneChanger* menuScene=nullptr;
ISceneChanger* parentScene=nullptr;
LuaScript* script=nullptr;
//ISceneChanger* menuScene;

int backScene(lua_State* L) {
	menuScene->BackScene();
	return 0;
}
int killScene(lua_State* L){
	menuScene->KillScene();
	return 0;
}
int pushScene(lua_State* L) {
	std::string scene = lua_tostring(L,-1);
	if (scene == "null") {
		menuScene->PushScene(nullptr);
	}
	else {
		int enumScene = script->get<int>("scene." + scene);
		//menuScene->PushScene(new BaseMenu(createMenuGUI(static_cast<SceneEnum>(enumScene), menuScene, parentScene)));
	}
	return 0;
}
int reserveScene(lua_State* L) {
	std::string scene = lua_tostring(L, -1);
	if (scene == "null") {
		menuScene->ReserveScene(nullptr);
	}
	else {
		int enumScene = script->get<int>("scene." + scene);
		//menuScene->ReserveScene(new BaseMenu(createMenuGUI(static_cast<SceneEnum>(enumScene), menuScene, parentScene)));
	}
	return 0;
}
int reserveGame(lua_State* L) {
	int num = lua_tonumber(L, -1);
	parentScene->ReserveScene(new Game(num));
	return 0;
}
int startGame(lua_State* L) {
	int num = lua_tonumber(L, -1);
	parentScene->PushScene(new Game(num));
	return 0;
}
int endSceneManager(lua_State* L) {
	menuScene->EndSceneManager();
	return 0;
}

MenuScript::MenuScript(const std::string& file):mScript(file) {

}
GUI* MenuScript::createGUI(const std::string& scene){
	lua_State* L = mScript.getLuaState();
	lua_getglobal(L, scene.c_str());
	GUI* gui = new GUI(Point::Zero);
	setWidget(scene,L,gui);
	return gui;
}
#include "../../../../Library/GUI/Widget.h"
#include "../../../../Library/GUI/WidgetFont.h"
void MenuScript::setWidget(const std::string& sceneName, lua_State* L, GUI* gui) {
	lua_getfield(L, -1, "widget");	
	setWidgetList(sceneName, L, gui);
}
void MenuScript::setWidgetChoice(const std::string& sceneName, lua_State* L, GUI* gui) {

	std::string name;
	WidgetFont font;
	std::string id;

	setWidgetCommon(L, name, font, id);

	if (id.empty()) {
		gui->Push(new Choice(name, font));
	}
	else {
		gui->Push(new Choice(name, font, [L, sceneName, id]() {
			int n = lua_gettop(L);
			lua_pop(L, n);
			lua_getglobal(L, sceneName.c_str());
			lua_getfield(L, -1, "gui");
			lua_getfield(L, -1, "widget");
			lua_getfield(L, -1, "callBack");
			lua_getfield(L, -1, id.c_str());
			lua_pcall(L, 0, 0, 0);
			n = lua_gettop(L);
			lua_pop(L, n);
		}));
	}
}

void MenuScript::setWidgetSelect(const std::string& sceneName, lua_State* L, GUI* gui) {
	std::string name;
	bool selectableFlag;
	WidgetFont font;
	std::string id;
	setWidgetCommon(L, name, font, id);

	lua_getfield(L, -1, "list");
	setWidgetList(sceneName, L, gui);
}

void MenuScript::setWidgetVolume(const std::string& sceneName, lua_State* L, GUI* gui) {
	std::string name;
	WidgetFont font;
	std::string id;
	setWidgetCommon(L, name, font, id);

	lua_getfield(L, -1, "datanum");
	int num = lua_tonumber(L, -1);

}

void MenuScript::setWidgetCommon(lua_State* L, std::string& name, WidgetFont& font, std::string& id) {
	lua_getfield(L, -1, "name");
	name = lua_tostring(L, -1);
	lua_pop(L, -1);

	lua_getfield(L, -1, "font");
	std::vector<int> fontV;
	lua_pushnil(L);
	while (lua_next(L, -2)) {
		fontV.push_back((int)lua_tonumber(L, -1));
		lua_pop(L, 1);
	}
	lua_pop(L, -1);

	/*lua_getfield(L, -1, "selectableFlag");
	if (lua_isnil(L, -1)) {
		selectable = true;
	}
	else {
		selectable = lua_toboolean(L, -1);
	}
	lua_pop(L, -1);*/

	lua_getfield(L, -1, "id");
	if (lua_isnil(L, -1)) {
		id = "";
	}
	else {
		id = lua_tostring(L, -1);
	}
	lua_pop(L, -1);
}


void MenuScript::setWidgetList(const std::string& sceneName, lua_State* L, GUI* gui) {
	lua_pushnil(L);//”Ô•º
	while (lua_next(L, -2)) {
		lua_getfield(L, -1, "type");
		std::string type = lua_tostring(L, -1);
		if (type == "choice") {
			setWidgetChoice(sceneName, L, gui);
			continue;
		}
		if (type == "select") {
			setWidgetSelect(sceneName, L, gui);
			continue;
		}
		lua_pop(L, 1);
	}

}
