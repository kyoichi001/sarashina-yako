#pragma once

#include "../../../Library/Typedef.h"

class ILeazer;
class ILeazer2;
class ObjectAdaptor;

class LeazerRenewManager {
	using func = void(*)(ILeazer&, int, ObjectAdaptor&);
	using func2 = void(*)(ILeazer2&, int, ObjectAdaptor&);
	func mFunc[128];
	func2 mFunc2[128];
public:
	LeazerRenewManager()noexcept;
	~LeazerRenewManager()noexcept;
	void Push(uchar ID, func Func)noexcept;
	void Push(uchar ID, func2 Func)noexcept;
	void Renew(uchar ID, ILeazer& Obj, int t, ObjectAdaptor& List) noexcept {
		mFunc[ID](Obj, t, List);
	}
	void Renew2(uchar ID, ILeazer2& Obj, int t, ObjectAdaptor& List) noexcept {
		mFunc2[ID](Obj, t, List);
	}
};
