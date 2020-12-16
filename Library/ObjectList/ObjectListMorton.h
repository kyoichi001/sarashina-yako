/*#pragma once

#include <memory>
#include <list>
#include "../QuadTree/QuadTree.h"

#ifdef _DEBUG
#include "../Timer.h"
#endif

template<typename T>
//オブジェクトをスマートポインタで動的に管理するリスト
//登録するクラスには
//void Update(float)      void Draw() const void Kill()  が必要
class ObjectListMorton {
	std::list<std::unique_ptr<T>> mObj;
	QuadTree<T> mTree;
public:
	ObjectListMorton()noexcept : mTree(2, { Point::Zero, 700, 700 }) {}
	~ObjectListMorton()noexcept {}

	void Update(float t = 1.0f)noexcept {
#ifdef _DEBUG
		mUpdateTimer.restart();
#endif
		mTree.clear();
		for (auto it = mList.begin(), ite = mList.end(); it != ite;) {
			if (!(*it)->Update(t)) {
				it = mList.erace(it);
				continue;
			}
			else {
				mTree.push((*it).get());
				++it;
			}
		}
#ifdef _DEBUG
		mUpdateTimer.elapsed();
#endif
	}
	void Draw()noexcept {
#ifdef _DEBUG
		mDrawTimer.restart();
#endif
		for (const auto &it : mObj)it->Draw();
#ifdef _DEBUG
		mDrawTimer.elapsed();
#endif
	}
	void Kill()noexcept {
		for (auto &it : mObj)it->Kill();
		mTree.clear();
	}

	T* SetObject(T* Obj)noexcept {
#ifdef _DEBUG
		mMakeTimer.restart();
#endif
		mObj.emplace_front(Obj);
#ifdef _DEBUG
		mMakeTimer.elapsed();
#endif
		return mObj.front().get();
	}
	auto begin() { return mObj.begin(); }
	auto end() { return mObj.end(); }
	size_t size()const { return mObj.size(); }

	template<class Active>
	void Collided(Active* obj) {
		mTree.Collided<Active>(obj);
	}

#ifdef _DEBUG

	void Draw_noDebug()const noexcept {
		for (const auto &it : mObj)it->Draw();
	}

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