
#include "LeazerRenewManager.h"

LeazerRenewManager::LeazerRenewManager()noexcept { 
	mFunc[0] = [](ILeazer&, int, ObjectAdaptor&) {};
	mFunc2[0] = [](ILeazer2&, int, ObjectAdaptor&) {};
}
LeazerRenewManager::~LeazerRenewManager()noexcept {}
void LeazerRenewManager::Push(uchar ID, func Func) noexcept { mFunc[ID] = Func; }
void LeazerRenewManager::Push(uchar ID, func2 Func) noexcept { mFunc2[ID] = Func; }
