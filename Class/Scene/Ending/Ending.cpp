
#include "Ending.h"

#include "../../../Library/Renderer.h"
#include "../../../Data/Resource.h"
#include "../../../Data/DATA.h"

#include "../../Object/Effect/IEffect.h"
#include "../../MediatorClass/ObjectAdaptor.h"

#include <string>

Ending::Ending()noexcept{}
Ending::~Ending()noexcept{}

class StaffLole :public IEffect {
	std::string mMessage;
public:
	StaffLole(const Point& p,const std::string& message)noexcept : IEffect(p,10), mMessage(message) {}
	bool Update(float t)noexcept override {
		++mTime;
		y -= 4.0f;
		return y>=0.0f;
	}
	void Draw()const noexcept override {
		DxWrp::DrawFormatString(x,y, 0xFFFFFF, mMessage.c_str(), 1.0f);
	}
};

std::string text[] = {
	"更級シリーズ2作目　更級夜行",
	"",
	"",
	"制作期間　１年",
	"",
	"",
	"プログラム",
	"グラフィック",
	"BGM",
	"SE",
	"　　　　　　　響一",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"プレイしていただきありがとうございました！",
};

void Ending::Initialize()noexcept {
	mLiveFlag = true;
	Key[Data.Key.Button16] = 0;
	mTime = 0;
}
void Ending::Finalize()noexcept {}
void Ending::Update(float t )noexcept {
	if ( mTime>= 5 * 60 + 21 * 50) {
		mLiveFlag = false;
	}
	for (int i = 0; i < 21; i++) {
		if (mTime == 5 * 60+i*30) {
			mObj->ObjEff().SetObject(new StaffLole({ 500.0f,800.0f }, text[i]));
		}
	}
	++mTime;
}

void Ending::Draw()const noexcept {
	DxWrp::DrawStringToHandle(30, 30, "ending", 0xCC00FF, Font05, 0xFFFFFF);
#ifdef _DEBUG
	mObj->ObjEff().Draw_noDebug();
#else
	mObj->ObjEff().Draw();
#endif
}