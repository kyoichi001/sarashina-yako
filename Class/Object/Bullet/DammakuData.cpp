
#include "DammakuData.h"

BulletDatabase::BulletDatabase()noexcept {}
BulletDatabase::~BulletDatabase()noexcept {}
void BulletDatabase::set(uchar ID, int cirMany, BulletColor color, BulletShape shape, int till, char AngleState, char drawBlend,char polygon)noexcept {
	mBullet[ID] = { cirMany ,color ,shape ,till ,AngleState ,drawBlend ,polygon};
}
void BulletDatabase::clear()noexcept {
	for (auto&i : mBullet) {
		i = {};
	}
}