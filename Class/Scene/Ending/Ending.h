#pragma once


#include "../../../Library/Scene/Task.h"
//ゲーム画面クラス
class Ending : public Task {
	int mTime;
public:
	Ending()noexcept;
	~Ending()noexcept;
	void Initialize()noexcept override;
	void Finalize()noexcept override;
	void Update(float t = 1.0f)noexcept override;
	void Draw()const noexcept override;
};