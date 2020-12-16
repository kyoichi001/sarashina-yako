
#pragma once

#include "BossData.h"

class IBoss;
class ObjectAdaptor;
using boss_func = void(*)(IBoss*, ObjectAdaptor&, int t);

class EnemyChapter{
	char chapter;
	std::vector<boss_func> mMove;
	int mTime;
public:
	EnemyChapter()noexcept;
	EnemyChapter(const std::vector<boss_func>& Move)noexcept;
	~EnemyChapter()noexcept;
	void PushMoveFunc() noexcept {};
	template<class ...Args>
	void PushMoveFunc(boss_func Move, Args... args)noexcept {
		mMove.push_back(Move);
		PushMoveFunc(args...);
	}
	void PushMoveFunc(boss_func Obj)noexcept;
	void Update(IBoss* Obj,  ObjectAdaptor& List, float t)noexcept;
	void Next()noexcept;
	char GetNowChapter()const noexcept { return chapter; }
	char GetChapterMany()const noexcept;
	bool IsFinished()const noexcept;
	int GetTime()const noexcept {return mTime;}
};