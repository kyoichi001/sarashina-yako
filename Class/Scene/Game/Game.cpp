#include "Game.h"
#include "../../../Library/Func.h"
#include "../../../Library/Renderer.h"
#include "../../MediatorClass/ObjectAdaptor.h"
#include "../../Object/Player/PlayerFactory.h"

#include "../Ending/Ending.h"
#include "../GameOver/GameOver.h"

#include "Stage\StageChapter.h"

using namespace DxWrp;
int back;
Game::Game(int stageID ) noexcept: Task(stageID), mScore(mObj),mPause(this),  mStageID(stageID){
	StageChapter::SetAdaptor(mObj);
}
Game::~Game()noexcept {}

//‰Šú‰»
void Game::Initialize()noexcept {
	Key[Data.Key.Button16] = 0;
	pauseflag = false;
	gameoverFlag = false;
	mLiveFlag = true;
	mObj->setPlayer(mObj->FacPly().getPlayer(p_weapon));
	StagePracticeFlag = mObj->FacStg().GetStage(static_cast<StageEnum>(mStageID), StageMgr);
	mScore.initialize();
}

//XV
void Game::Update(float t)noexcept {
	if (!pauseflag) {
		if (Key[Data.Key.Button512] == 1) {
			pauseflag = true;
			mPause.Init();
		}
		if (StageMgr.IsEnd()) {
			mLiveFlag = false;
			if (clearFlag) {
				mSceneChanger->GotoScene(new Ending());
			}
			return;
		}
		if (gameoverFlag) {
			mSceneChanger->GotoScene(new GameOver());
			return;
		}
		StageMgr.Update(t);
		mScore.update();
		mObj->GetPlayerController().UpdateMove();
		mObj->GetPlayerController().UpdateShot();
	}
	else{
		mPause.Update(t);
		switch (mPause.sendMessage()){
		case 0:break;
		case 1:
			Reset();
			pauseflag = false;
			return;
		case 2:
			mSceneChanger->BackScene();
			pauseflag = false;
			return;
		}
	}
}

#include "DxLib.h"
void ObjectDraw(ObjectAdaptor* obj) {
	if (Draw3DFlag) {
		obj->Obj3Ds().Draw();
		SetUseZBuffer3D(FALSE);
		//SetWriteZBuffer3D(TRUE);
		obj->Obj3Ef().Draw();
		SetUseZBuffer3D(TRUE);
	}
	SetBlendModeAlpha(230);
	{
		obj->ObjPBl().Draw();
	}
	ResetBlendMode();
	obj->GetPlayer()->Draw();
	obj->ObjEmy().Draw();
	obj->ObjBss().Draw();
	obj->ObjBul().Draw();
	obj->ObjBom().Draw();
	obj->ObjLez1().Draw();
	obj->ObjLez2().Draw();
	//obj->ObjItm().Draw();
	obj->ObjEff().Draw();
	obj->getTalkManager().draw();
}

//•`‰æ
void Game::Draw()const noexcept {

	StageMgr.Draw();
	if (mStageID == 6) {
		DxWrp::SetBlendModeAlpha(120);
		DxWrp::DrawBox(0, 0, 960, 720, 0xFFFFFF);
		DxWrp::ResetBlendMode();
	}
	ObjectDraw(mObj);
	GameWindow.draw(0xFFFFFF, false, 2);
	mScore.draw();
	if (pauseflag){
		mPause.Draw();
	}
#ifdef _DEBUG
	if (debugflag) {
		DrawDebugWindow(480, 300);
	}
#endif

}

void Game::Finalize()noexcept {
	StageMgr.Finalize();
	mObj->ObjEmy() .Kill();
	mObj->ObjBss() .Kill();
	mObj->ObjBul().Kill();
	mObj->ObjPBl().Kill();
	mObj->ObjBom() .Kill();
	mObj->ObjLez1().Kill();
	mObj->ObjLez2().Kill();
	mObj->ObjItm() .Kill();
	mObj->ObjEff() .Kill();
	mObj->ObjEmi().Kill();
	mObj->Obj3Ds().Kill();
	mObj->Obj3Ef() .Kill();
	eventFlag = false;
}

void Game::Reset() {
	Finalize();
	Initialize();
}

#ifdef _DEBUG
#include "Stage\BaseStage.h"
#include "DxLib.h"
#include "../../../Library/Color/ColorData.h"
void Game::DrawDebugWindow(int X, int Y)const noexcept {
	SetBlendModeAlpha(150);
	{
		DxLib::DrawBox(X, Y, X+400, Y+50, GREY, TRUE);
		DxLib::DrawBox(X, Y, X + 400, Y + 50, WHITE, FALSE);
	}
	ResetBlendMode();
	DxLib::DrawFormatString(X + 5, Y + 5, WHITE, "Game Scene Debug");
	DxLib::DrawFormatString(X+5, Y+25, WHITE, "Difficulty %d", difficulty);
	//DxLib::DrawFormatString(X+5, Y+45, WHITE, "Time %d", mTime);
	DxLib::DrawBox(WALL_X1, WALL_Y1, WALL_X2, WALL_Y2, WHITE, FALSE);
	dynamic_cast<BaseStage*>(StageMgr.GetNowInstance())->DrawDebug(730, 400);
}
#endif