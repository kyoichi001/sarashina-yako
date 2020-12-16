#pragma once

class ObjectAdaptor;
class ISceneChanger;

class Task {
protected:
	int mValue;
	//false になると次のシーンが予約されていた場合、次のシーンへ
	//予約がない場合、前のシーンへ
	bool mLiveFlag;
	static ObjectAdaptor* mObj;
	ISceneChanger* mSceneChanger;
public:
	Task()noexcept;
	Task(int Value)noexcept;
	virtual ~Task() noexcept;

	virtual void Initialize()noexcept {}
	virtual void Finalize()  noexcept {}
	virtual void Update(float t=1.0f)noexcept = 0;
	virtual void Draw()const noexcept = 0;

	bool IsLive()const noexcept { return mLiveFlag; }
	void Kill()noexcept { mLiveFlag = false; }
	void SetSceneChanger(ISceneChanger* changer) noexcept { mSceneChanger = changer; }
	void EndScene()noexcept { mLiveFlag = false; }
	ISceneChanger* GetSceneChanger()noexcept { return mSceneChanger; }

	void static SetAdaptor(ObjectAdaptor* Adaptor)noexcept;

#ifdef _DEBUG
protected:
	static int TaskMany;
public:
	static int GetTaskMany()noexcept;
#endif
};

