
#pragma once

#include "../../../Library/Primitive/Primitive.h"

class ObjectAdaptor;
struct GhostData;

class IGhost :public Circle {
protected:
	//1なら動いている、2なら被弾している、3ならLifeが0になった、4ならリストから排除してよし
	char mState;
	int mHP;
	int mTime;
	GhostData* mData;
	static ObjectAdaptor* mCList;

	void Finalize()noexcept;
public:
	IGhost(const Point& P, GhostData* data, float Value = 0.0f)noexcept;
	~IGhost()noexcept{}
	void Init(const Point& P, GhostData* data, float Value = 0.0f) noexcept;

	float mValue;
	Point mFirst;
	Vec2 mSpeed;
	void Draw()const noexcept;
	bool Update(float t)noexcept;
	bool IsLive()const noexcept { return mState != 4; }
	void Kill()noexcept { mState = 3; }
	void Damage(int damage)noexcept;
	//範囲外になったか
	bool IsOver()const noexcept;
	//死亡時のエフェクトを表示させずに削除
	void Erase()noexcept { mState = 4; }
	int GetTime()const noexcept { return mTime; }
	void static SetClassList(ObjectAdaptor* ClassListPtr)noexcept { mCList = ClassListPtr; }
};
