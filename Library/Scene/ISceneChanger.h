#pragma once

class Task;

//�V�[����ύX���邽�߂̃C���^�[�t�F�C�X�N���X
class ISceneChanger {
public:
	virtual ~ISceneChanger()noexcept{}
	//�w��V�[���Ɉړ�����
	virtual Task* PushScene(Task* Scene)noexcept = 0;
	;//���݂̃V�[�����w��V�[���ɕύX����
	virtual Task* GotoScene(Task* Scene)noexcept = 0;
	//�V�[����\�񂷂�
	virtual Task* ReserveScene(Task* Scene)noexcept = 0;
	//���X�g�̃V�[����S�č폜���A�w��V�[�������蒼��
	virtual void Restart(Task* Scene)noexcept = 0;
	//�O�̃V�[���ɕύX���A�\�񂵂Ă����V�[�����폜����(�������V�[����������Ȃ��ꍇ���삵�Ȃ�)
	virtual void BackScene()noexcept = 0;
	//�O�̃V�[���ɕύX���邪�A�V�[���͍폜���Ȃ�
	virtual void UndoScene()noexcept = 0;
	//�V�[���}�l�[�W���[���I������
	virtual void EndSceneManager()noexcept = 0;
	//�V�[�����I�����A�\�񂪂������ꍇ�͂�����Ɉړ��@�Ȃ������ꍇ�O�̃V�[���ֈړ�
	virtual void KillScene()noexcept = 0;
	//�\�񂵂Ă��邷�ׂẴV�[�����폜����
	virtual void ClearReservedScene()noexcept =0;
};

