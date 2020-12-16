#pragma once

#include <list>

#ifdef _DEBUG
#include "../Timer.h"
#endif

template<typename T>
//単一クラスのオブジェクトをリストに生成し、動的に管理するリスト
//登録するクラスには
//void Update(float)      void Draw() const void Kill()  が必要
class FixedObjectList {
	std::list<T> mObj;
public:
	FixedObjectList()noexcept {}
	~FixedObjectList()noexcept {}

	void Update(float t = 1.0f)noexcept {
#ifdef _DEBUG
		mUpdateTimer.restart();
#endif
		for (auto it = mObj.begin(), ite = mObj.end(); it != ite;) {
			if (!(*it).Update(t)) {
				it = mObj.erase(it);
				continue;
			}
			++it;
			}
#ifdef _DEBUG
		mUpdateTimer.elapsed();
#endif
	}
	void Draw()noexcept {
#ifdef _DEBUG
		mDrawTimer.restart();
#endif
		for (const auto &it : mObj)it.Draw();
#ifdef _DEBUG
		mDrawTimer.elapsed();
#endif
	}
	void Kill()noexcept {
		for (auto &it : mObj)it.Kill();
	}

	template<typename ...Args>
	T* Emplace(const Args&... args)noexcept {
#ifdef _DEBUG
		mMakeTimer.restart();
#endif
		mObj.emplace_front(args...);
#ifdef _DEBUG
		mMakeTimer.elapsed();
#endif
		return &mObj.front();
	}
	auto begin() {return mObj.begin();}
	auto end() {return mObj.end();}
	size_t size() const { return mObj.size(); }

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
