
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

//�V�[���`�F���W���Ǘ�����N���X
class CSceneMgr : public ISceneChanger{
	//�V�[���Ǘ��ϐ����X�g
	std::vector<std::unique_ptr<Task>> mSceneList;
	//���̃V�[���̊Ǘ����X�g�̓Y����
	int mNowSceneIndex;
	// -1 �����s 0 ���s�� 3 �I���� 4 �I��
	int mState;
	void SceneRenew()noexcept;
public:
	CSceneMgr()noexcept;
	~CSceneMgr()noexcept;
	void Start(Task* Scene)noexcept;//���ێ�����Ă���Scene���폜���A�o�^�����V�[�����n�߂�
	void Start()noexcept;//�ŏ��ɓo�^�����V�[������n�߂�
	void Resume()noexcept;//�Ō�Ɏ��s�����V�[������n�߂�
	void Finalize()noexcept;//�����s���Ă���V�[�����I�����A�V�[���}�l�[�W���[���~������
	void Update(float t = 1.0f)noexcept;
	void Draw()const noexcept;

	bool IsEnd() const noexcept { return mState == 4; }
	bool IsRunning() const noexcept { return (mState != -1 && mState != 4); }

	//���̃V�[���Ɉړ�����
	//nullptr�������ꍇSceneManager���I������
	Task* PushScene(Task* Scene)noexcept override;
	//�V�[����؂�ւ���
	//nullptr�������ꍇSceneManager���I������
	Task* GotoScene(Task* Scene)noexcept override;
	//�V�[����\�񂷂�
	//nullptr�������ꍇ���̃V�[���Ɉړ������Ƃ�SceneManager���I������
	Task* ReserveScene(Task* Scene)noexcept override;
	void Restart(Task* Scene)noexcept override;
	//�O�̃V�[���ɖ߂�
	//�ۗL����V�[������̂Ƃ��͎��s����Ȃ�
	//�߂����Ƃ��A�ȑO�̃V�[������\�񂵂��V�[���܂ł���������
	 void BackScene()noexcept override;
	 //�O�̃V�[���ɖ߂�
	 //�ۗL����V�[������̂Ƃ��͎��s����Ȃ�
	 //������͖߂����Ƃ��A�ȑO�̃V�[������\�񂵂��V�[���܂ł��������Ȃ�
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
