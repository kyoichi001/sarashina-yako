#pragma once

#include <unordered_map>
#include <memory>

template<typename Key,typename T>
class ObjectMap {
	std::unordered_map<Key,std::unique_ptr<T>> mMap;
public:
	ObjectMap() {}
	void Update() {
		for (auto it = mMap.begin(), ite = mMap.end(); it != ite;) {
			if (!it->second->Update(1.0f)) {
				it = mMap.erase(it);
				continue;
			}
			++it;
		}
	}
	void Draw() const {
		for (const auto& it : mMap) {
			it.second->Draw();
		}
	}
	void clear(){}
	int size()const { return 0; }
	void push(Key key, T* Obj) { mMap.emplace(key,Obj); }
};