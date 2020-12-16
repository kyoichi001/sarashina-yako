#pragma once

#include "../../../../Library/Typedef.h"
#include "../../../../Library/Primitive/Primitive.h"
#include "../../../../Library/Lua/LuaScript.h"

#include <vector>

class ObjectAdaptor;
class StageChapter;

struct StageData {
	int mTime;
	uchar mID;
	int mInterval;
	int mMakeTime;
	//Primitive mPrimitive;
};

class StageScript {
	std::vector<std::vector<StageData>> mData;
public:
	StageScript();
	void update(int chapter,ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept;
//	void setEnemy(int t, uchar ID, int interval, int makeTime, const Primitive& prim, float value = 1.0f);
	void setBoss(int t, uchar ID, int X, int Y);
};

void setEnemy(lua_State *L);
void setBoss(lua_State *L);
