#pragma once

class IGhost;
class ObjectAdaptor;
class Animation;

using enemy_func = void(*)(IGhost*, ObjectAdaptor&, int t);
using enemy_endfunc = void(*)(IGhost*, ObjectAdaptor&);

struct GhostData {
	GhostData(enemy_func Func,enemy_endfunc endFunc, Animation* anim, int hp, int radius) :
		func(Func),endfunc(endFunc), animation(anim), HP(hp), r(radius){}
	enemy_func func;
	enemy_endfunc endfunc;
	Animation* animation;
	int HP;
	int r;
};