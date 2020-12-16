
#pragma once

#include "../../../Library/Primitive/Primitive.h"
#include "../../../Library/ObjectList/ObjectListClass.h"
#include "Option/IOption.h"
#include "../BufDrawer.h"

class ObjectAdaptor;
class PlayerController;
class GUI;
class IGhost;
class IBoss;
class IBullet;
class IItem;
class ILeazer;
class ILeazer2;

class IPlayer :public Circle {
protected:
	char mHP;
	char mSubWeapon;
	int mTime;
	int mHitTime;
	int mShoot1Interval;
	bool mHitFlag,mSlowFlag;
	int mScore;
	ObjectList<IOption> mOptionZ;
	ObjectList<IOption> mOptionX;
	BufDrawer<IPlayer> mBuf;
	static ObjectAdaptor* mObj;
	void Hit()noexcept;//ƒvƒŒƒCƒ„[‚ª’e‚É“–‚½‚Á‚½‚±‚Æ‚É‚·‚é
public:
	IPlayer()noexcept;
	~IPlayer()noexcept{}

	bool virtual Update()noexcept;
	void virtual drawPlane()const noexcept=0;
	void Draw()const noexcept;

	void Shoot1()noexcept;
	void Shoot2()noexcept;

	void Slow()noexcept;
	void Fast()noexcept;

	bool IsLive()const noexcept { return mHP >= 0; }

	char GetHP()const noexcept { return mHP; }
	char GetSubWeapon()const noexcept { return mSubWeapon; }
	char getScore()const noexcept { return mScore; }
	void addScore(int score)noexcept { mScore+=score; }
	void setGameScore(GUI& gui)noexcept;
	void Damage(int damage)noexcept;
	void AddHP(char HP)noexcept { mHP += HP; }
	void AddSubWeapon(char subWeapon)noexcept;
	void static SetAdaptor(ObjectAdaptor* Adaptor)noexcept;

	void Collided( IGhost& obj);
	void Collided( IBoss& obj);
	void Collided( IBullet& obj);
	void Collided(IItem& obj);
	void Collided(ILeazer& obj);
	void Collided( ILeazer2& obj);


#ifdef _DEBUG
	void God()noexcept{}
	void UnGod()noexcept{}
	void DrawDebug(int X, int Y)const noexcept;

	void setDebugGUI(GUI& gui)noexcept;

#endif

	friend PlayerController;
};
