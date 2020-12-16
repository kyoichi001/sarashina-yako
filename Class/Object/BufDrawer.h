#pragma once

#include <vector>
#include "../../Library/ObjectList/ObjectMap.h"
#include "Effect\IEffect.h"

template<typename T>
class BufDrawer {
	T* mObj;
	ObjectMap<std::string,IEffect> mPreEffect;
	ObjectMap<std::string,IEffect> mPostEffect;
public:
	BufDrawer(T* Obj)noexcept : mObj(Obj) {}
	void RegisterPre(const std::string& Name,IEffect* Effect)noexcept { mPreEffect.push(Name, Effect); }
	void RegisterPost(const std::string& Name, IEffect* Effect)noexcept { mPostEffect.push(Name, Effect); }
	void Update()noexcept {
		mPreEffect.Update();
		mPostEffect.Update();
	}
	void Draw()const noexcept {
		mPreEffect.Draw();
		mObj->drawPlane();
		mPostEffect.Draw();
	}
};
