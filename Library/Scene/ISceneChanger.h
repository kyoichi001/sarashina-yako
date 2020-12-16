#pragma once

class Task;

//シーンを変更するためのインターフェイスクラス
class ISceneChanger {
public:
	virtual ~ISceneChanger()noexcept{}
	//指定シーンに移動する
	virtual Task* PushScene(Task* Scene)noexcept = 0;
	;//現在のシーンを指定シーンに変更する
	virtual Task* GotoScene(Task* Scene)noexcept = 0;
	//シーンを予約する
	virtual Task* ReserveScene(Task* Scene)noexcept = 0;
	//リストのシーンを全て削除し、指定シーンからやり直す
	virtual void Restart(Task* Scene)noexcept = 0;
	//前のシーンに変更し、予約していたシーンを削除する(ただしシーンが一つしかない場合動作しない)
	virtual void BackScene()noexcept = 0;
	//前のシーンに変更するが、シーンは削除しない
	virtual void UndoScene()noexcept = 0;
	//シーンマネージャーを終了する
	virtual void EndSceneManager()noexcept = 0;
	//シーンを終了し、予約があった場合はそちらに移動　なかった場合前のシーンへ移動
	virtual void KillScene()noexcept = 0;
	//予約しているすべてのシーンを削除する
	virtual void ClearReservedScene()noexcept =0;
};

