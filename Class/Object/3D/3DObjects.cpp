
#include "3DObjects.h"
#include "../../../Data/Resource.h"
#include "../../../Library/Math/Constant.h"
#include "../../../Library/Math/Random.h"
#include "DxLib.h"
#include "../../../Data/Camera.h"

#define CHUNKSIZE 1500
#define HALFCHUNKSIZE 750

CTrain::CTrain()noexcept {}
CTrain::CTrain(const Vec3& P,  int Value)noexcept :I3D(P, Value) {
	mHandle = MV1DuplicateModel(TrainHdl);
	MV1SetScale(mHandle, { 50.0f, 50.0f, 50.0f });
}

void CTrain::UpdateObj()noexcept {
	if (mTime % 100 == 15)y -= 8;
	if (mTime % 100 == 10)y += 8;
}

CTree::CTree()noexcept {}
CTree::CTree(const Vec3& P, int Value) noexcept: I3D(P, Value),mExRate(Rand(500,1500)) {
	mHandle = TreeHdl;
	/*MV1SetScale(mHandle, { 20.0f + R, 20.0f + 1.5f*R, 20.0f + R });*/
}
void CTree::Draw()const noexcept {
	float fogAlpha = mCamera->getFogAlpha({ x + mParent->x, y + mParent->y, z + mParent->z });
	SetDrawBright(fogAlpha, fogAlpha, fogAlpha);
	DrawBillboard3D({ x + mParent->x, y + mParent->y, z + mParent->z }, 0.5f, 0.5f, float(mExRate), 0.0f, mHandle, TRUE);
	SetDrawBright(255, 255, 255);
}

CBuilding::CBuilding()noexcept {}
CBuilding::CBuilding(const Vec3& P, int Value)noexcept : I3D(P, Value){
	mHandle = MV1DuplicateModel(BuildingHdl);
	MV1SetScale(mHandle, { 30.0f, 30.0f, 30.0f });
}

CRail::CRail() noexcept {}
CRail::CRail(const Vec3& P, int Value) noexcept: I3D(P, Value){
	mHandle = MV1DuplicateModel(RailHdl);
	MV1SetScale(mHandle, { 90.0f, 90.0f, 90.0f });
	MV1SetRotationXYZ(mHandle, {0.0f,HALF_PI,0.0f});
}

CGround::CGround()noexcept {}
CGround::CGround(const Vec3& P, int Value)noexcept: I3D(P, Value) {

}
void CGround::Draw()const noexcept {
	float X = mParent->x + x, Z = mParent->z + z;
	DrawTriangle3D({ X ,0,Z  },
		{ X ,0,Z + CHUNKSIZE },
		{ X + CHUNKSIZE,0,Z },
		0x000000, TRUE);
	DrawTriangle3D({ X + CHUNKSIZE,0,Z },
		{ X + CHUNKSIZE,0,Z + CHUNKSIZE },
		{ X ,0,Z + CHUNKSIZE },
		0x000000, TRUE);
}

CChunk1_1::CChunk1_1(const Vec3& P, int Value)noexcept : I3D(P, Value) {
	for (int i = 0; i < 4; ++i) {
		mTree[i] = { {Rand(0.0f,1500.0f),600.0f, Rand(0.0f,1500.0f)} ,Value };
		mTree[i].SetParent(this);
	}
	mGround = { Vec3::Zero,Value };
	mGround.SetParent(this);
}

void CChunk1_1::UpdateObj() noexcept {
	x += 10;
	if (x > 1000)x -= 4500;
	for (auto &i : mTree) {
		i.Update(1.0f);
	}
	mGround.Update(1.0f);
}
void  CChunk1_1::Draw()const noexcept {
	for (auto &i : mTree) {
		i.Draw();
	}
	mGround.Draw();
}

CChunk1_2::CChunk1_2(const Vec3& P, int Value)noexcept: I3D(P, Value) {
	for (int i = 0; i < 2; ++i) {
		mRail[i] = { { 0.0f,0.0f, i*750.0f} ,Value };
		mRail[i].SetParent(this);
	}
	mGround = { Vec3::Zero,Value };
	mGround.SetParent(this);
}

void CChunk1_2::UpdateObj()noexcept {
	x += 10;
	if (x > 1000)x -= 4500;
	for (auto &i : mRail) {
		i.Update(1.0f);
	}
	mGround.Update(1.0f);
}

void CChunk1_2::Draw()const noexcept {
	for (auto &i : mRail) {
		i.Draw();
	}
	mGround.Draw();
}

CChunk2::CChunk2(const Vec3& P, int Value) noexcept: I3D(P, Value) {
	mBuilding = { { 0.0f,0.0f, 750.0f } ,Value };
	mBuilding.SetParent(this);
}

void CChunk2::UpdateObj()noexcept {
	x += 10;
	if (x > 1000)x -= 4500;
	mBuilding.Update(1.0f);
}

void CChunk2::Draw()const noexcept {
	mBuilding.Draw();
}


CChunk4::CChunk4(const Vec3& P, int Value) noexcept: I3D(P, Value) {
	for (int i = 0; i < 3; i++) {
		mBuilding[i] = { { 0.0f,900.0f*float(i), 750.0f } ,Value };
		mBuilding[i].SetParent(this);
	}
}

void CChunk4::UpdateObj()noexcept {
	x += 10;
	if (x > 1000)x -= 4500;
	for (auto &obj : mBuilding) {
		obj.Update(1.0f);
	}
}

void CChunk4::Draw()const noexcept {
	for (auto &obj : mBuilding) {
		obj.Draw();
	}
}
#ifdef _DEBUG

void DrawChunkDebug(const Vec3& P) {
	for (int i = 0; i < 10; ++i) {
		DrawLine3D({ P.x + i * CHUNKSIZE / 10, P.y, P.z }, { P.x + i * CHUNKSIZE / 10, P.y, P.z + CHUNKSIZE }, 0x0000FF);
		DrawLine3D({ P.x, P.y, P.z + i * CHUNKSIZE / 10 }, { P.x + CHUNKSIZE, P.y, P.z + i * CHUNKSIZE / 10 }, 0x00FF00);
	}
	DrawLine3D({ P.x, 0, P.z }, { P.x, 2000, P.z }, 0xFF0000);
	DrawLine3D({ P.x, 0, P.z + CHUNKSIZE }, { P.x, 2000, P.z + CHUNKSIZE }, 0xFF0000);
	DrawLine3D({ P.x + CHUNKSIZE, 0, P.z }, { P.x + CHUNKSIZE, 2000, P.z }, 0xFF0000);
	DrawLine3D({ P.x + CHUNKSIZE, 0, P.z + CHUNKSIZE }, { P.x + CHUNKSIZE, 2000, P.z + CHUNKSIZE }, 0xFF0000);
}

void CChunk1_1::DrawDebug()const noexcept {
	DrawChunkDebug(*this);
}
void CChunk1_2::DrawDebug()const noexcept {
	DrawChunkDebug(*this);
}
void CChunk2::DrawDebug()const noexcept {
	DrawChunkDebug(*this);
}
void CChunk4::DrawDebug()const noexcept {
	DrawChunkDebug(*this);
}
#endif