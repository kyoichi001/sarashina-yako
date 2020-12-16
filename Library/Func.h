
#pragma once

#define RANGE(minValue,Value,maxValue) ((minValue)<(Value)&&(Value)<(maxValue))
#define N_RANGE(minValue,Value,maxValue) ((Value)<(minValue)||(maxValue)<(Value))
#define RANGE_EQUAL(minValue,Value,maxValue) ((minValue)<=(Value)&&(Value)<=(maxValue))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

//2進数のm-1桁目を返す関数
int GetDigit(int Num, int DigitNum)noexcept;
//2進数のm-1桁目を返す関数
int RaiseFlag(int Num, int DigitNum)noexcept;
//2進数のm-1桁目を返す関数
int DownFlag(int Num, int DigitNum)noexcept;
//2進数のm-1桁目を返す関数
int RiverseFlag(int Num, int DigitNum)noexcept;


template<typename T>
T Clamp(T min, T val, T max) {
	if (val < min)return min;
	if (val > max)return max;
	return val;
}