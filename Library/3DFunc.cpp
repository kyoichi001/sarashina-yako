
#include "3DFunc.h"
#include "DxLib.h"

namespace DxWrp {

	void SetFogColor(int R, int G, int B) noexcept { DxLib::SetFogColor(R, G, B); }
	void SetFogStartEnd(int Start, int End) noexcept { DxLib::SetFogStartEnd(Start, End); }
	void SetFogEnable(bool Flag)noexcept { DxLib::SetFogEnable(Flag); }

}