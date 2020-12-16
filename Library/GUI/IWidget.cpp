
#include "IWidget.h"

IWidget::IWidget()noexcept:Rect(), mParent(nullptr), mUp(nullptr), mDown(nullptr), mLeft(nullptr), mRight(nullptr), mState(1) {}
IWidget::IWidget(const std::string& name)noexcept : IWidget() { mName = name; }
void IWidget::Activate()noexcept { mState = 0; }
void IWidget::InActivate()noexcept { mState = 1; }
