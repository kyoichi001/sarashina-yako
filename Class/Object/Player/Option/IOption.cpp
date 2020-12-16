
#include "IOption.h"

ObjectAdaptor* IOption::mCList = nullptr;

IOption::IOption(Point* XY, const  Vec2& ofs) noexcept: mParent(XY), mOfs(ofs), mLiveFlag(true), mTime(0){}
IOption::~IOption()noexcept {}

bool IOption::Update(float t)noexcept {
	if (!mParent) {
		mLiveFlag = false;
		return mLiveFlag;
	}
	x = mParent->x + mOfs.x;
	y = mParent->y + mOfs.y;
	++mTime;
	return mLiveFlag;
}

void IOption::SetClassList(ObjectAdaptor* ClassListPtr) noexcept { mCList = ClassListPtr; }