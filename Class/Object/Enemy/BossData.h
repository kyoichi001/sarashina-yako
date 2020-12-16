#pragma once

#include <string>
#include <vector>

class ObjectAdaptor;
class IBoss;

using boss_func = void(*)(IBoss*, ObjectAdaptor&, int t);

struct BossData {
	BossData(const std::string& name, int backHdl, int maxHP, int r, int hdl, bool escapeflag, const std::vector<boss_func>& func) 
	:Name(name),BackHdl(backHdl),MaxHP(maxHP),radius(r),Hdl(hdl),EscapeFlag(escapeflag),Func(func){}
	std::string Name;
	int BackHdl;
	int MaxHP;
	int radius;
	int Hdl;
	bool EscapeFlag;//���j���ꂽ�Ƃ��ɓ����邩�ǂ���
	std::vector<boss_func> Func;
};
