
#pragma once

#include <list>
#include <memory>

#ifdef _DEBUG
#include "../Timer.h"
#endif

template<typename T>
//オブジェクトをスマートポインタで動的に管理するリスト
//登録するクラスには
//void Update(float)      void Draw() const void Kill()  が必要
class ObjectList {
	std::list<std::unique_ptr<T>> mObj;
public:
	ObjectList()noexcept {}
	~ObjectList()noexcept {}

	void Update(float t = 1.0f)noexcept {
#ifdef _DEBUG
		mUpdateTimer.restart();
#endif
		for (auto it = mObj.begin(), ite = mObj.end(); it != ite;) {
			if (!(*it)->Update(t)) {
				it = mObj.erase(it);
				continue;
			}
			++it;
		}
#ifdef _DEBUG
		mUpdateTimer.elapsed();
#endif
	}
#ifdef _DEBUG

	void Draw()noexcept {
		mDrawTimer.restart();
		for (const auto &it : mObj)it->Draw();
		mDrawTimer.elapsed();
	}
#else
	void Draw()const noexcept {
		for (const auto &it : mObj)it->Draw();
	}
#endif
	void Kill()noexcept {
		for (auto &it : mObj)it->Kill();
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
