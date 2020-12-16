
#include "Animation.h"
#include "../Primitive/Primitive.h"
#include "DxLib.h"

Animation::Animation(const std::vector<int>& Handle, int Interval)noexcept :mHdl(Handle),mInterval(Interval),mSize(mHdl.size()){}
Animation::Animation(const int* Handle, int Size, int Interval)noexcept: mHdl(0), mInterval(Interval),mSize(Size){
	for (int i = 0; i < Size; ++i) {
		mHdl.emplace_back(Handle[i]);
	}
}

void Animation::Set(int Interval, const int* Handle,int Size)noexcept {
	mInterval = Interval;
	mSize += Size;
	for (int i = 0; i < Size; ++i) {
		mHdl.emplace_back(Handle[i]);
	}
}


void Animation::Regster(int Handle)noexcept {
	mHdl.emplace_back(Handle);
	++mSize;
}
void Animation::Regster(const char* Handle)noexcept {
	mHdl.emplace_back(LoadGraph(Handle));
	++mSize;
}
void Animation::Regster(const char* Handle, int AllMany, int xMany, int yMany, int xSize, int ySize)noexcept {
	std::vector<int> Anim(AllMany);
	LoadDivGraph(Handle, AllMany, xMany, yMany, xSize, ySize, &Anim[0]);
	mHdl.insert(mHdl.end(),Anim.begin(),Anim.end());
	mSize+=AllMany;
}

void Animation::Draw(const Point& P, int t)const noexcept {
	DrawGraph(P.x,P.y, mHdl[(t/mInterval)% mSize],TRUE);
}
void Animation::Draw(const Point& P, int t, float Angle, float ExRate)const noexcept {
	DrawRotaGraph(P.x,P.y, ExRate, Angle, mHdl[(t/mInterval)%mSize], TRUE);
}