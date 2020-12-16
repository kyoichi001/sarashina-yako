#pragma once

#include "../../../Library/Typedef.h"

enum BulletShape :char;
enum BulletColor :char;

struct DammakuData {
	int mCirMany;
	BulletColor mColor;
	BulletShape mShape;
	int mTill;
	char mAngleState;
	char mDrawBlend;
	char mPolygon;
};

class BulletDatabase {
public:
	BulletDatabase()noexcept;
	~BulletDatabase()noexcept;
	void set(uchar ID, int cirMany, BulletColor color, BulletShape shape, int till = 0, char AngleState = 0, char drawBlend = 0,char polygon=0)noexcept;
	void clear()noexcept;
	DammakuData mBullet[256];
};
