#include "GameScore.h"
#include "../../../Library/GUI/Widget.h"
#include "../../../Library/Renderer.h"
#include "../../../Data/Resource.h"//font
#include "../../../Library/Func.h"//dif

#include "../../MediatorClass/ObjectAdaptor.h"

 using namespace DxWrp;

 GameScore::GameScore(ObjectAdaptor* Adaptor) :mAdaptor(Adaptor), mScore({ 675,70 },false) {


	mScoreHdl = LoadGraph("Picture/Scene/Game/GameBackre.png");
	mLogoHdl = LoadGraph("Picture/Scene/Game/TitleLogo3.png");
	//GameBlackBack = LoadGraph("Picture/Back/GameDefaultBack.png");
#ifdef _DEBUG
	//StageMgr.setDebugInfo(mObj->DbgInfo().getGUI(),8,"Stage", scoreFont);
#endif
}

void GameScore::initialize()noexcept {
	static const WidgetFont scoreFont = { Font01,0xFFFFFF ,0xFFFFFF };
	mScore.clearWidget();
	mScore.Push("difficulty", new Choice(dif("Easy", "Normal", "Hard", "Torture"), scoreFont));
	mScore.Push(new Viewer<ulong>("Hiscore", scoreFont, &Data.HighScore));
	mAdaptor->GetPlayer()->setGameScore(mScore);
	mScore.Init("difficulty");
}
void GameScore::finalize()noexcept {
	DeleteGraph(mScoreHdl);
	DeleteGraph(mLogoHdl);
}

void GameScore::update()noexcept{
	mScore.Update();
}
void GameScore::draw()const noexcept{

	DrawGraph(960 - 280, 0, mScoreHdl);

	mScore.Draw();
	DrawRotaGraph(780, 500, 1.0f, 0, mLogoHdl);
}