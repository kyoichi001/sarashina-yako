#pragma once

#include "../../../Library/Typedef.h"

enum LeazerShape :char;
enum BulletColor :char;

struct LeazerDammakuData {
	int mCirMany;
	BulletColor mColor;
	LeazerShape mShape;
	int mTill;
	int mLength;
	char mAngleState;
	char mDrawBlend;
	char mPolygon;
};

class LeazerDatabase {
public:
	LeazerDatabase()noexcept;
	~LeazerDatabase()noexcept;
	void set(uchar ID, int cirMany, BulletColor color, LeazerShape shape, int till = 0,int length=0, char AngleState = 0, char drawBlend = 0, char polygon = 0)noexcept;
	void clear()noexcept;
	LeazerDammakuData mLeazer[256];
};
