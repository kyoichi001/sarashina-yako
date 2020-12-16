#include "StageScript.h"
#include "../../../MediatorClass/ObjectAdaptor.h"

StageScript::StageScript(){}

void StageScript::update(int chapter, ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept{
	for (auto& data : mData[chapter]) {
		if (t == data.mTime) {
			//Obj.FacEmy().
		}
	}
}
/*void StageScript::setEnemy(int t, uchar ID, int interval, int makeTime, const UPrimitive& prim, float value){

}*/
void StageScript::setBoss(int t, uchar ID, int X, int Y){}

void setEnemy(lua_State *L) {

}
void setEnemyEmi(lua_State *L) {

}
void setBoss(lua_State *L) {

}