#pragma once

class IPlayer;
class Vec2;

//�v���C���[���L�[�ő��삵����
//�v���C���[�̈ړ��͈͂𐧌䂷��N���X
class PlayerController {
	IPlayer* mPlayer;
public:
	PlayerController()noexcept{}
	void set(IPlayer* Player) { mPlayer = Player; }
	Vec2 GetSpeedFromKey()noexcept;
	void UpdateMove()noexcept;
	void UpdateShot()noexcept;
};