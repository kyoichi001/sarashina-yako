#pragma once

class BulletRenewManager;
class ObjectAdaptor;
class IGhost;
class IBoss;

//------------------------------------------------------------------------------------------------------------
//stage 2
//------------------------------------------------------------------------------------------------------------
void setBulletData2(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept;

void Move20(IGhost* Obj, ObjectAdaptor& List, int t)noexcept;
void End20(IGhost* Obj, ObjectAdaptor& List)noexcept;
void Move21(IGhost* Obj, ObjectAdaptor& List, int t)noexcept;
void End21(IGhost* Obj, ObjectAdaptor& List)noexcept;
void Move22(IGhost* Obj, ObjectAdaptor& List, int t)noexcept;
void End22(IGhost* Obj, ObjectAdaptor& List)noexcept;
void Move23(IGhost* Obj, ObjectAdaptor& List, int t)noexcept;
void End23(IGhost* Obj, ObjectAdaptor& List)noexcept;
void Move24(IGhost* Obj, ObjectAdaptor& List, int t)noexcept;
void End24(IGhost* Obj, ObjectAdaptor& List)noexcept;
void Move25(IGhost* Obj, ObjectAdaptor& List, int t)noexcept;
void End25(IGhost* Obj, ObjectAdaptor& List)noexcept;
void Move26(IGhost* Obj, ObjectAdaptor& List, int t)noexcept;
void End26(IGhost* Obj, ObjectAdaptor& List)noexcept;

void Move2_0(IBoss* Obj, ObjectAdaptor& List, int t)noexcept;
void Move2_1(IBoss* Obj, ObjectAdaptor& List, int t)noexcept;

void Move3_0(IBoss* Obj, ObjectAdaptor& List, int t)noexcept;
void Move3_1(IBoss* Obj, ObjectAdaptor& List, int t)noexcept;
void Move3_2(IBoss* Obj, ObjectAdaptor& List, int t)noexcept;
void Move3_3(IBoss* Obj, ObjectAdaptor& List, int t)noexcept;
void Move3_4(IBoss* Obj, ObjectAdaptor& List, int t)noexcept; 
void Move3_5(IBoss* Obj, ObjectAdaptor& List, int t)noexcept;