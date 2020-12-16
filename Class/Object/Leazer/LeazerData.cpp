
#include "LeazerData.h"

LeazerDatabase::LeazerDatabase()noexcept {}
LeazerDatabase::~LeazerDatabase()noexcept {}
void LeazerDatabase::set(uchar ID, int cirMany, BulletColor color, LeazerShape shape, int till,int length, char AngleState, char drawBlend, char polygon)noexcept {
	mLeazer[ID] = { cirMany ,color ,shape ,till ,length,AngleState ,drawBlend ,polygon };
}
void LeazerDatabase::clear()noexcept {
	for (auto&i : mLeazer) {
		i = {};
	}
}