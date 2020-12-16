
#include "GameOver.h"

#include "../../../Library/Renderer.h"
#include "../../../Library/Math/Constant.h"
#include "../../../Data/Resource.h"
#include "../../../Data/DATA.h"

#include "../../MediatorClass/ObjectAdaptor.h"

class Bubble :public IEffect {
	Vec2 mSpeed;
	int r;
	int mColor;
public:
	Bubble(const Circle& p, const Vec2& speed,int color,int duration)noexcept : IEffect(p.p, duration),r(p.r), mSpeed(speed),mColor(color) {}
	bool Update(float t)noexcept override {
		*this += mSpeed;
		mSpeed += Vec2{ 0.0f,0.01f };
		++mTime;
		return mTime <= mLifeTime;
	}
	void Draw()const noexcept override {
		DxWrp::SetBlendModeAlpha((1.0f - float(mTime) / float(mLifeTime))*255.0f);
		DxWrp::DrawCircle(*this,r, mColor);
		DxWrp::ResetBlendMode();
	}
};

GameOver::GameOver()noexcept {}
GameOver::~GameOver()noexcept {}

void GameOver::Initialize()noexcept {
	mLiveFlag = true;
	mObj->getAudio().playBGM(11);
	mTime = 0;
}
void GameOver::Finalize()noexcept {}
void GameOver::Update(float t)noexcept {
	if (mTime >= 60) {
		if (Key[Data.Key.Button16] == 1 || mTime >= 300) {
			mLiveFlag = false;
			return;
		}
	}
	//if (mTime % 10 == 0) {
	int s = Rand(0, 255);
	int color = 0x000100*s + 0x0000FF;
	for (int i = 0; i < 8; i++) {
		mObj->ObjEff().SetObject(new Bubble({ Rand(0.0f,960.0f),720,Rand(8,20) }, { -HALF_PI + Rand(0.2f),Rand(3.0f,5.0f),0 }, color,60));
		mObj->ObjEff().SetObject(new Bubble({ Rand(0.0f,960.0f),0,Rand(8,20) }, { HALF_PI + Rand(0.2f),Rand(3.0f,5.0f),0 }, color,60));
	}
	if (mTime % 20 == 0) {
		mObj->ObjEff().SetObject(new Bubble({ Rand(0.0f,960.0f),720,Rand(8,20) }, { -HALF_PI + Rand(0.2f),Rand(3.0f,5.0f),0 }, 0xFFFF00, 300));
		mObj->ObjEff().SetObject(new Bubble({ Rand(0.0f,960.0f),0,Rand(8,20) }, { HALF_PI + Rand(0.2f),Rand(3.0f,5.0f),0 }, 0xFFFF00, 300));
	}
	//}
	++mTime;
}

void GameOver::Draw()const noexcept {
	DxWrp::DrawStringToHandle(350, 350, "Game Over", 0xCC00FF, Font05, 0xFFFFFF);
	DxWrp::SetDrawBlendMode(BLEND_ADD,255);
#ifdef _DEBUG
	mObj->ObjEff().Draw_noDebug();
#else
	mObj->ObjEff().Draw();
#endif
	DxWrp::ResetBlendMode();
}