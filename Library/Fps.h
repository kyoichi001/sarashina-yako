
#pragma once

class Fps{
	int mStartTime;//����J�n����
	int mCount;//�J�E���^
	float mFps;//fps
	static const int N = 60;//���ς����T���v����
public:
	Fps()noexcept;
	~Fps()noexcept;
	void Update()noexcept;
	float GetFps()const noexcept;
};