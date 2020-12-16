/*#pragma once

#include <memory>
#include <list>

#include "../QuadTree/QuadTree.h"

#ifdef _DEBUG
#include "../Timer.h"
#endif

template<typename T>
//単一クラスのオブジェクトをリストに生成し、動的に管理するリスト
//登録するクラスには
//void Update(float)      void Draw() const void Kill()  が必要
class FixedObjectListMorton {
	QuadTree<T> mTree;
public:
	FixedObjectListMorton()noexcept : mTree(2, { Point::Zero,700,700 }) {}
	~FixedObjectListMorton()noexcept {}

	void Update(float t = 1.0f)noexcept {
#ifdef _DEBUG
		mUpdateTimer.restart();
#endif
		mTree.update(t);
#ifdef _DEBUG
		mUpdateTimer.elapsed();
#endif
	}
	void Draw()noexcept {
#ifdef _DEBUG
		mDrawTimer.restart();
#endif
		for (const auto &it : mList)it.Draw();
#ifdef _DEBUG
		mDrawTimer.elapsed();
#endif
	}
	void Kill()noexcept {
		for (auto &it : mList)it.Kill();
		mTree.clear();
	}

	template<typename ...Args>
	T* Emplace(const Args&... args)noexcept {
#ifdef _DEBUG
		mMakeTimer.restart();
#endif
		mList.emplace_front(args...);
#ifdef _DEBUG
		mMakeTimer.elapsed();
#endif
		return &mList.front();
	}

	template<class Active>
	void Collided(Active* obj) {
		mTree.Collided<Active>(obj);
	}

	auto begin() { return mList.begin(); }
	auto end() { return mList.end(); }
	size_t size() const { return mList.size(); }

#ifdef _DEBUG
	int GetUpdateTime()const { return mUpdateTimer.getDuration(); }
	int GetDrawTime()const { return mDrawTimer.getDuration(); }
	int GetMakeTime()const { return mMakeTimer.getDuration(); }
protected:
	Timer mUpdateTimer;
	Timer mDrawTimer;
	Timer mMakeTimer;
#endif
};

*/