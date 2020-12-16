#pragma once

class ObjectAdaptor;
class StageChapter;

//================================================================================================
//
//stage 2
//
//================================================================================================

void Stage2Init(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept;
void Stage20(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept;
void Stage21(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept;
void Stage2MidBoss(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept;
void Stage22(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept;
void Stage2Talk(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept;
void Stage2Boss(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept;
void Stage2Clear(ObjectAdaptor& Obj, StageChapter* Chapter, int t)noexcept;