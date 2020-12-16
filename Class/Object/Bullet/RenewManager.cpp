
#include "RenewManager.h"

BulletRenewManager::BulletRenewManager()noexcept { mFunc[0] = [](IBullet&, int, ObjectAdaptor&){}; }
BulletRenewManager::~BulletRenewManager()noexcept {}
void BulletRenewManager::Push(uchar ID, func Func) noexcept { mFunc[ID] = Func; }