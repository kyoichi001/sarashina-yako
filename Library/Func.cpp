
#include "Func.h"

int GetDigit(int Num, int DigitNum)noexcept {
	int B = Num & (1 << DigitNum);
	return (B >> DigitNum);
}
int RaiseFlag(int Num, int DigitNum)noexcept { return Num | (1 << DigitNum); }
int DownFlag(int Num, int DigitNum) noexcept { return Num&~(1 << DigitNum); }
int RiverseFlag(int Num, int DigitNum)noexcept {
	return GetDigit(Num, DigitNum) ? DownFlag(Num, DigitNum) : RaiseFlag(Num, DigitNum);
}

