
#pragma once

#include "ISceneChanger.h"

#include <vector>
#include <memory>

#ifdef _DEBUG
#include <string>
#endif

class Task;
class GUI;
class WidgetFont;

enum SceneChange { NoEffect, Fade, Clear };

using scene_func = Task*(*)(ISceneChanger* Interface, int Value);

//シーンチェンジを管理するクラス
class CSceneMgr : public ISceneChanger{
	//シーン管理変数リスト
	std::vector<std::unique_ptr<Task>> mSceneList;
	//今のシーンの管理リストの添え字
	int mNowSceneIndex;
	// -1 未実行 0 実行中 3 終了中 4 終了
	int mState;
	void SceneRenew()noexcept;
public:
	CSceneMgr()noexcept;
	~CSceneMgr()noexcept;
	void Start(Task* Scene)noexcept;//今保持されているSceneを削除し、登録したシーンを始める
	void Start()noexcept;//最初に登録したシーンから始める
	void Resume()noexcept;//最後に実行したシーンから始める
	void Finalize()noexcept;//今実行しているシーンを終了し、シーンマネージャーを停止させる
	void Update(float t = 1.0f)noexcept;
	void Draw()const noexcept;

	bool IsEnd() const noexcept { return mState == 4; }
	bool IsRunning() const noexcept { return (mState != -1 && mState != 4); }

	//次のシーンに移動する
	//nullptrだった場合SceneManagerを終了する
	Task* PushScene(Task* Scene)noexcept override;
	//シーンを切り替える
	//nullptrだった場合SceneManagerを終了する
	Task* GotoScene(Task* Scene)noexcept override;
	//シーンを予約する
	//nullptrだった場合そのシーンに移動したときSceneManagerを終了する
	Task* ReserveScene(Task* Scene)noexcept override;
	void Restart(Task* Scene)noexcept override;
	//前のシーンに戻る
	//保有するシーンが一つのときは実行されない
	//戻ったとき、以前のシーンから予約したシーンまでを消去する
	 void BackScene()noexcept override;
	 //前のシーンに戻る
	 //保有するシーンが一つのときは実行されない
	 //こちらは戻ったとき、以前のシーンから予約したシーンまでを消去しない
	 void UndoScene()noexcept override;
	 void EndSceneManager()noexcept override;
	 void KillScene()noexcept override;

	void ClearReservedScene()noexcept override;

	Task* GetNowInstance()const noexcept;
	template<typename T>
	T* GetNowInstance()const noexcept { return dynamic_cast<T*>(mSceneList[mNowSceneIndex].get()); }

#ifdef _DEBUG
	int GetNowIndex()const noexcept;
	int GetSceneSize()const noexcept;
	void setDebugInfo(GUI& gui, int tabIndex,const std::string& mgrName,const WidgetFont& font);
private:
	int mSize;
	std::vector<std::string> mSceneName;
#endif
};
