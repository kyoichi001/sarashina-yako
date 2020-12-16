
#pragma once

#include "I3DObject.h"

class CTrain :public I3D{
public:
	CTrain()noexcept;
	CTrain(const Vec3& P, int Value)noexcept;
	void UpdateObj()noexcept override;
};

class CTree :public I3D{
	int mExRate;
public:
	CTree()noexcept;
	CTree(const Vec3& P,  int Value)noexcept;
	void Draw()const noexcept override;
};

class CBuilding :public I3D{
public:
	CBuilding()noexcept;
	CBuilding(const Vec3& P,int Value)noexcept;
};

class CRail :public I3D{
public:
	CRail()noexcept;
	CRail(const Vec3& P, int Value)noexcept;
};

class CGround :public I3D {
public:
	CGround()noexcept;
	CGround(const Vec3& P, int Value)noexcept;
	void Draw()const noexcept override;
};
class CChunk1_1 :public I3D{
	CTree mTree[4];
	CGround mGround;
public:
	CChunk1_1(const Vec3& P, int Value)noexcept;
	void UpdateObj()noexcept override;
	void Draw()const noexcept override;
#ifdef _DEBUG
	void virtual DrawDebug()const noexcept override;
#endif
};
class CChunk1_2 :public I3D {
	CRail mRail[2];
	CGround mGround;
public:
	CChunk1_2(const Vec3& P, int Value)noexcept;
	void UpdateObj()noexcept override;
	void Draw()const noexcept override;
#ifdef _DEBUG
	void virtual DrawDebug()const noexcept override;
#endif
};
class CChunk2 :public I3D {
	CBuilding mBuilding;
public:
	CChunk2(const Vec3& P, int Value)noexcept;
	void UpdateObj()noexcept override;
	void Draw()const noexcept override;
#ifdef _DEBUG
	void virtual DrawDebug()const noexcept override;
#endif
};
class CChunk4 :public I3D {
	CBuilding mBuilding[3];
public:
	CChunk4(const Vec3& P, int Value)noexcept;
	void UpdateObj()noexcept override;
	void Draw()const noexcept override;
#ifdef _DEBUG
	void virtual DrawDebug()const noexcept override;
#endif
};