
/*#include "MenuFactory.h"
#include "BaseMenu.h"
#include "../../../../Library/Color/ColorData.h"
#include "../../../../Library/Scene/ISceneChanger.h"
#include "../../../../Library/GUI/Widget.h"
#include "../../../../Library/GUI/GUI.h"
#include "../../../../Data/Resource.h"
#include "../../Game/Game.h"
#include "../Menu.h"

char* BossName[] = {
	"Azami Yotsuya",
	"Kikyo Yamabuki",
	"Kocho Yanagikawa",
	"Kocho Yanagikawa",
	"Kocho Yanagikawa",
};

WidgetFont ConfigFont;
WidgetFont MenuFont;
WidgetFont DisabledMenuFont;
WidgetFont WeaponFont;
WidgetFont DebugFont ;

void initGUIFont()noexcept {
	ConfigFont = { Font02, WHITE, GREY };
	MenuFont = { Font05, WHITE, GREY };
	DisabledMenuFont = { Font05, DARKGREY, DARKGREY };
	WeaponFont = { Font06, WHITE, GREY };
	DebugFont = { Font03, WHITE, GREY };
}

void setConfigGUI(GUI& gui,ISceneChanger* menuScene, ISceneChanger* parentScene) {
}
void setDifficultyGUI(GUI& gui, ISceneChanger* menuScene, ISceneChanger* parentScene) {
}
void setHomeGUI(GUI& gui, ISceneChanger* menuScene, ISceneChanger* parentScene) {
}
void setMusicGUI(GUI& gui, ISceneChanger* menuScene, ISceneChanger* parentScene) {
}
void setStagePracticeGUI(GUI& gui, ISceneChanger* menuScene, ISceneChanger* parentScene) {
}
void setWeaponGUI(GUI& gui, ISceneChanger* menuScene, ISceneChanger* parentScene) {
}
void setChapterSelectGUI(GUI& gui, ISceneChanger* menuScene, ISceneChanger* parentScene) {

}
void setDebugGUI(GUI& gui, ISceneChanger* menuScene, ISceneChanger* parentScene) {

}

GUI* createMenuGUI(SceneEnum scene, ISceneChanger* menuScene, ISceneChanger* parentScene)noexcept {
	GUI* gui = new GUI(Point::Zero);
	switch (scene) {
	case Config       :setConfigGUI       (*gui, menuScene, parentScene); break;
	case Difficulty   :setDifficultyGUI   (*gui, menuScene, parentScene); break;
	case Home         :setHomeGUI         (*gui, menuScene, parentScene); break;
	case Music        :setMusicGUI        (*gui, menuScene, parentScene); break;
	case StagePractice:setStagePracticeGUI(*gui, menuScene, parentScene); break;
	case Weapon       :setWeaponGUI       (*gui, menuScene, parentScene); break;
	case ChapterSelect:setChapterSelectGUI(*gui, menuScene, parentScene); break;
	//case Debug        :setDebugGUI        (*gui, menuScene, parentScene); break;
	}
	return gui;
}
*/