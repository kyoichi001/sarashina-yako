
#include "EnemyChapter.h"

EnemyChapter::EnemyChapter()noexcept:chapter(0), mTime(0){}
EnemyChapter::EnemyChapter(const std::vector <boss_func> &Move)noexcept : chapter(0), mTime(0) {
	for (const auto &i : Move) {
		PushMoveFunc(i);
	}
}
EnemyChapter::~EnemyChapter()noexcept{}
void EnemyChapter::PushMoveFunc(boss_func Obj)noexcept {
	mMove.push_back(Obj);
}
void EnemyChapter::Update(IBoss* Obj, ObjectAdaptor& List, float t)noexcept {
	if (IsFinished())return;
	mMove[chapter](Obj, List, mTime);
	++mTime;
}
void EnemyChapter::Next()noexcept {
	if (IsFinished())return;
	++chapter;
	mTime = 0;
}
char EnemyChapter::GetChapterMany()const noexcept { return mMove.size(); }
bool EnemyChapter::IsFinished()const noexcept { return chapter >= mMove.size(); }
