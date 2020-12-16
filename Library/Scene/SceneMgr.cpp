
#include "SceneMgr.h"
//#include "../../Library/InterpolationMethod.h"
#include "../../Library/Func.h"
#include "Task.h"

CSceneMgr::CSceneMgr() noexcept :mState(-1), mNowSceneIndex(0) {}
CSceneMgr::~CSceneMgr()noexcept {}

void CSceneMgr::Start(Task* Scene)noexcept {
	mSceneList.clear();
	mSceneList.emplace_back(Scene);
	Start();
}
void CSceneMgr::Start()noexcept {
	mState = 0;
	mNowSceneIndex = 0;
	mSceneList[mNowSceneIndex]->SetSceneChanger(this);
	mSceneList[mNowSceneIndex]->Initialize();
}

void CSceneMgr::Finalize() noexcept {
	if (!IsRunning()) return;
	mSceneList[mNowSceneIndex]->Finalize();
	mState = 4;
}

void CSceneMgr::Update(float t)noexcept {
	if (!IsRunning()) return;
	mSceneList[mNowSceneIndex]->Update(t);
	if (!mSceneList[mNowSceneIndex]->IsLive()) {
		mSceneList[mNowSceneIndex]->Finalize();
		++mNowSceneIndex;
		SceneRenew();
	}
#ifdef _DEBUG
	mSize = mSceneList.size();
#endif
}
void CSceneMgr::Draw()const noexcept {
	if (!IsRunning()) return;
	mSceneList[mNowSceneIndex]->Draw();
}

Task* CSceneMgr::PushScene(Task* Scene)noexcept {
	if (!IsRunning()) return nullptr;
	mSceneList[mNowSceneIndex]->Finalize();
	++mNowSceneIndex;
	if (!Scene) {
		mState = 4;
		return nullptr;
	}
	mSceneList.emplace(mSceneList.begin() + mNowSceneIndex, Scene);
	SceneRenew();
	return mSceneList[mNowSceneIndex].get();
}
Task* CSceneMgr::GotoScene(Task* Scene)noexcept {
	if (!IsRunning()) return nullptr;
	mSceneList[mNowSceneIndex]->Finalize();
	mSceneList[mNowSceneIndex].reset(Scene);
	SceneRenew();
	return mSceneList[mNowSceneIndex].get();
}
Task* CSceneMgr::ReserveScene(Task* Scene)noexcept {
	mSceneList.emplace_back(Scene);
	return mSceneList.back().get();
}
void CSceneMgr::Restart(Task* Scene)noexcept {
	if (!mSceneList.empty())mSceneList[mNowSceneIndex]->Finalize();//シーンが残っていたら終了処理を行う
	if (!Scene)return;
	mSceneList.clear();
	mState = 0;
	mNowSceneIndex = 0;
	mSceneList.emplace_back(Scene);
	mSceneList[mNowSceneIndex]->SetSceneChanger(this);
	mSceneList[mNowSceneIndex]->Initialize();
}
void CSceneMgr::Resume()noexcept {
	mState = 0;
	mSceneList[mNowSceneIndex]->Initialize();
}

void CSceneMgr::ClearReservedScene() noexcept {
	if (!mSceneList.empty())
		mSceneList.erase(mSceneList.begin() + mNowSceneIndex + 1, mSceneList.end());
}
void CSceneMgr::BackScene()noexcept {
	if (!IsRunning() || mSceneList.size() <= 1) return;
	mSceneList[mNowSceneIndex]->Finalize();
	mSceneList.erase(mSceneList.begin() + mNowSceneIndex, mSceneList.end());
	--mNowSceneIndex;
	mSceneList[mNowSceneIndex]->Initialize();
	mState = 0;
}
void CSceneMgr::UndoScene()noexcept {
	if (!IsRunning() || mSceneList.size() <= 1) return;
	mSceneList[mNowSceneIndex]->Finalize();
	--mNowSceneIndex;
	mSceneList[mNowSceneIndex]->Initialize();
	mState = 0;
}

void CSceneMgr::SceneRenew()noexcept {
	if (mNowSceneIndex < 0 || mSceneList.empty()) { mState = 4; return; }
	if (mNowSceneIndex >= mSceneList.size()) {
		if (mSceneList.size() ==1) {//シーンが変わる処理があってもシーンが一つしかない場合
			mNowSceneIndex = 0;
			return;
		}
		mSceneList.pop_back();
		mNowSceneIndex = mSceneList.size() - 1;//現在更新していたシーンより前のシーンにする
	}
	if (!mSceneList[mNowSceneIndex]) {//Scene == nullptr
		mState = 4;
		mSceneList.clear();
		return;
	}
	mSceneList[mNowSceneIndex]->SetSceneChanger(this);
	mSceneList[mNowSceneIndex]->Initialize();//シーンを初期化
	mState = 0;
}
void CSceneMgr::EndSceneManager()noexcept {
	mSceneList.clear();
	mNowSceneIndex = 0;
	mState = 4;
}
void CSceneMgr::KillScene()noexcept {
	if (!IsRunning())return;
	mSceneList[mNowSceneIndex]->Kill();//現在のシーンの終了処理を実行
}
Task* CSceneMgr::GetNowInstance()const noexcept {
	return mSceneList[mNowSceneIndex].get();
}

#ifdef _DEBUG
#include "../GUI/GUI.h"
#include "../GUI/Widget.h"
int CSceneMgr::GetNowIndex()const noexcept { return mNowSceneIndex; }
int CSceneMgr::GetSceneSize()const noexcept { return mSceneList.size(); }
void CSceneMgr::setDebugInfo(GUI& gui, int tabIndex,const std::string& mgrName,const WidgetFont& font) {
	gui.GetWidget<Tab>("tab0").Push(new Viewer<int>(mgrName+" Scene Size",font, &mSize));
	gui.GetWidget<Tab>("tab0").Push(new Viewer<int>(mgrName+ " NowIndex", font, &mNowSceneIndex));
	//gui.GetWidget<Tab>(0).Push(tabIndex, new Viewer<int>(mgrName+" EndIndex", font, &mEndIndex));
}
#endif

