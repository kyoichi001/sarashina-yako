#pragma once

template<class T>
class QuadObjectContainer {
	T* mObj;
	QuadObjectContainer* mPrev;
	QuadObjectContainer* mNext;
public:
	QuadObjectContainer(QuadObjectContainer* prev):mPrev(prev),mNext(nullptr) {}
	T* getObj() { return mObj; }
	void remove() {
		mPrev->mNext = mNext->mPrev;
		mNext->mPrev = mPrev->mNext;
	}
	void setNext(QuadObjectContainer* next) { mNext = next; mNext->mPrev = this; }
	void setPrev(QuadObjectContainer* prev) { mPrev = prev; mPrev->mNext = this; }
};