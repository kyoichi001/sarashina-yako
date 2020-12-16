#pragma once

class BulletRenewManager;
class ObjectAdaptor;
class IGhost;
class IBoss;

//-----------------------------------------------------------------------------------------------------------------------
//stage 1
//-----------------------------------------------------------------------------------------------------------------------
void setBulletData1(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept;

void Move10(IGhost* Obj, ObjectAdaptor& List, int t)noexcept;
void End10(IGhost* Obj, ObjectAdaptor& List)noexcept;
void Move11(IGhost* Obj, ObjectAdaptor& List, int t)noexcept;
void End11(IGhost* Obj, ObjectAdaptor& List)noexcept;
void Move12(IGhost* Obj, ObjectAdaptor& List, int t)noexcept;
void End12(IGhost* Obj, ObjectAdaptor& List)noexcept;
void Move13(IGhost* Obj, ObjectAdaptor& List, int t)noexcept;
void End13(IGhost* Obj, ObjectAdaptor& List)noexcept;
void Move14(IGhost* Obj, ObjectAdaptor& List, int t)noexcept;
void End14(IGhost* Obj, ObjectAdaptor& List)noexcept;
void Move15(IGhost* Obj, ObjectAdaptor& List, int t)noexcept;
void End15(IGhost* Obj, ObjectAdaptor& List)noexcept;
void Move16(IGhost* Obj, ObjectAdaptor& List, int t)noexcept;
void End16(IGhost* Obj, ObjectAdaptor& List)noexcept;

void Move0_0(IBoss* Obj, ObjectAdaptor& List, int t)noexcept;

void Move1_0(IBoss* Obj, ObjectAdaptor& List, int t)noexcept;
void Move1_1(IBoss* Obj, ObjectAdaptor& List, int t)noexcept;
void Move1_2(IBoss* Obj, ObjectAdaptor& List, int t)noexcept;
void Move1_3(IBoss* Obj, ObjectAdaptor& List, int t)noexcept;
void Move1_4(IBoss* Obj, ObjectAdaptor& List, int t)noexcept;