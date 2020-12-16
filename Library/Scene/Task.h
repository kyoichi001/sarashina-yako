#pragma once

class ObjectAdaptor;
class ISceneChanger;

class Task {
protected:
	int mValue;
	//false �ɂȂ�Ǝ��̃V�[�����\�񂳂�Ă����ꍇ�A���̃V�[����
	//�\�񂪂Ȃ��ꍇ�A�O�̃V�[����
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

