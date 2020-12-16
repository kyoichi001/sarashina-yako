#pragma once

class ObjectAdaptor;
class StageChapter;

//================================================================================================
//
//stage 1
//
//================================================================================================

void Stage1Init(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept;
void Stage10(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept;
void Stage11(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept;
void Stage1MidBoss(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept;
void Stage12(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept;
void Stage1Talk(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept;
void Stage1Boss(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept;
void Stage1Clear(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept;