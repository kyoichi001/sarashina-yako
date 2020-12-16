#pragma once

class IWidget;

class Cursor {
	IWidget* mWidget;
public:
	Cursor()noexcept;
	void SetWidget(IWidget* Widget)noexcept;
	void Update()noexcept;
	void Draw()const noexcept;
};