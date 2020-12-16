
#pragma once

class Fps{
	int mStartTime;//測定開始時刻
	int mCount;//カウンタ
	float mFps;//fps
	static const int N = 60;//平均を取るサンプル数
public:
	Fps()noexcept;
	~Fps()noexcept;
	void Update()noexcept;
	float GetFps()const noexcept;
};