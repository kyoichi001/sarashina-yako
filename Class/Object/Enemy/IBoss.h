#pragma once

#include "../../../Library/Primitive/Primitive.h"
#include "../../../Library/Easing/EasingClass.h"
#include "EnemyChapter.h"
#include "../BufDrawer.h"

class IEffect;
class StageChapter;
struct BossData;

using BossCallBack = void(*)(StageChapter&, ObjectAdaptor&);

class IBoss :public Circle {
protected:
	//Boss 0 登場 1なら動いている、2なら被弾している、3ならLifeが0になった、4ならリストから排除してよし 5 なら逃げている 6 なら弾を消している 7 なら待機中
	char mState;
	float DefencePer;//被ダメージ率
	Easing<Point> mMoveEase;
	void Finalize()noexcept;
	void Next()noexcept;
	BossCallBack mFunc;
	BossData* mData;
	BufDrawer<IBoss> mDrawer;
	EnemyChapter mChapter;
	StageChapter* mStage;
	int mHP;
	int mTime;
	static ObjectAdaptor* mCList;

public:
	IBoss(const Point& P, BossData* Data, StageChapter* Stage)noexcept;
	~IBoss()noexcept;
	void SetMovePoint(const Point& P, int Time, EasingFunc Easing = Ease<Liner>::In)noexcept;

	bool IsLive()const noexcept { return mState != 4; }
	void Kill()noexcept { mState = 4; }
	void Damage(int damage)noexcept;
	bool Update(float t)noexcept;
	void Draw()const noexcept;
	void drawPlane()const noexcept;
	void Start()noexcept;
	void MoveNext()noexcept;
	void pushMoveFunc(boss_func Obj)noexcept;
	void SetFinishFunc(BossCallBack Func)noexcept { mFunc = Func; }
	int GetTime()const noexcept { return mTime; }
	void static SetClassList(ObjectAdaptor* ClassListPtr)noexcept { mCList = ClassListPtr; }

	friend void MoveAppear(IBoss* Obj, ObjectAdaptor& List, int t)noexcept;
	friend void MoveEscape(IBoss* Obj, ObjectAdaptor& List, int t)noexcept;

#ifdef _DEBUG
	void DrawDebug()const noexcept;
#endif

};

void MoveAppear(IBoss* Obj, ObjectAdaptor& List, int t)noexcept;
void MoveEscape(IBoss* Obj, ObjectAdaptor& List, int t)noexcept;
