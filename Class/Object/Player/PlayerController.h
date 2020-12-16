#pragma once

class IPlayer;
class Vec2;

//プレイヤーをキーで操作したり
//プレイヤーの移動範囲を制御するクラス
class PlayerController {
	IPlayer* mPlayer;
public:
	PlayerController()noexcept{}
	void set(IPlayer* Player) { mPlayer = Player; }
	Vec2 GetSpeedFromKey()noexcept;
	void UpdateMove()noexcept;
	void UpdateShot()noexcept;
};