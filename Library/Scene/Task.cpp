
#include "Task.h"

ObjectAdaptor* Task::mObj = nullptr;

#ifndef _DEBUG
Task::Task()noexcept:mValue(0), mLiveFlag(true) {}
Task::Task(int Value)noexcept:mValue(Value), mLiveFlag(true){}
Task::~Task() noexcept {}
#endif // !_DEBUG


void Task::SetAdaptor(ObjectAdaptor* Adaptor)noexcept {mObj = Adaptor;}

#ifdef _DEBUG
int Task::TaskMany = 0;
Task::Task()noexcept :mValue(0), mLiveFlag(true) { ++TaskMany; }
Task::Task(int Value)noexcept : mValue(Value), mLiveFlag(true){
}
Task::~Task()noexcept { --TaskMany; }
int Task::GetTaskMany()noexcept { return TaskMany; }
#endif