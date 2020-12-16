#pragma once

#include "../../../Library/Scene/Task.h"
class GameOver : public Task {
	int mTime;
public:
	GameOver()noexcept;
	~GameOver()noexcept;
	void Initialize()noexcept override;
	void Finalize()noexcept override;
	void Update(float t = 1.0f)noexcept override;
	void Draw()const noexcept override;
};