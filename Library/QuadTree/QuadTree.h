#pragma once

#include <vector>
#include <list>
#include <memory>

#include "QuadObjectContainer.h"
#include "../Primitive/Primitive.h"
#include "../Math/Morton.h"


template<class T>
class QuadTree {
	std::vector<QuadObjectContainer<std::unique_ptr<T>>> mList;
	std::vector<QuadObjectContainer<std::unique_ptr<T>*>> mListBegin;
	int mLevel;
	Point mOrigin;
	int mCellX, mCellY;

	/*template<class Func, class Obj>
	void forEachChild(int morton, Func& function, Obj& object) {
	for (auto it = mList[morton].begin(), ite = mList[morton].end(); it != ite;) {
	function(it, object);
	}
	if (morton * 4 + 1 >= mList.size())return;
	forEachChild(morton * 4 + 1, function, object);
	forEachChild(morton * 4 + 2, function, object);
	forEachChild(morton * 4 + 3, function, object);
	forEachChild(morton * 4 + 4, function, object);
	}*/
	template<class Obj>
	void forEachChildCollided(int morton, Obj* object) {
		for (auto &it : mList[morton]) {
			object->Collided(*it);
		}
		if (morton * 4 + 1 >= mList.size())return;
		forEachChildCollided(morton * 4 + 1, object);
		forEachChildCollided(morton * 4 + 2, object);
		forEachChildCollided(morton * 4 + 3, object);
		forEachChildCollided(morton * 4 + 4, object);
	}

public:
	QuadTree(int level, const Rect& region) noexcept
		: mLevel(level), mOrigin(region.tl), mCellX(region.width / pow(2, level)), mCellY(region.height / pow(2, level)) {
		for (int i = 0, max = (pow(4, level + 1) - 1) / 3; i <max; ++i) {
			mList.emplace_back();
			mListBegin.push_back(mList[i].begin());
		}
	}
	void update(float t) {
		int i = 0;
		for (auto& obj : mList) {
			mListBegin[i] = *obj;
			++i;
		}
		i = 0;
		for (auto &list : mList) {
			for (auto it = mListBegin[i], ite = mList.end(); it != ite;) {
				if (!(*it)->Update(t)) {
					it = mList.erase(it);
					continue;
				}
				else {
					push(*it);
					++it;
				}
			}
			++i;
		}
	}
	void push(T* obj) {
		mList[getMorton(obj, mOrigin, mCellX, mCellY)].emplace_front(obj);
	}
	void push(int morton, T* obj) {
		mList[morton].emplace_front(obj);
	}
	void clear() noexcept {
		for (auto& list : mList) {
			list.clear();
		}
	}
	template<class Obj>
	void Collided(Obj* object) {
		int morton = getMorton(object, mOrigin, mCellX, mCellY);
		//parent
		for (int i = morton - 1; i >= 0; i /= 4) {
			for (auto &it : mList[i]) {
				object->Collided(*(*it));
			}
		}
		//child
		forEachChildCollided(morton, object);
		//this node
		for (auto &it : mList[morton]) {
			object->Collided(*it);
		}
	}
};