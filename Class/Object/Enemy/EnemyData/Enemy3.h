#pragma once

class BulletRenewManager;
class ObjectAdaptor;
class IGhost;
class IBoss;

//----------------------------------------------------------------------------------------------------------
//stage 3
//----------------------------------------------------------------------------------------------------------

void setBulletData3(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept;

void Move30(IGhost* Obj, ObjectAdaptor& List, int t)noexcept;
void End30(IGhost* Obj, ObjectAdaptor& List)noexcept;
void Move31(IGhost* Obj, ObjectAdaptor& List, int t)noexcept;
void End31(IGhost* Obj, ObjectAdaptor& List)noexcept;
void Move32(IGhost* Obj, ObjectAdaptor& List, int t)noexcept;
void End32(IGhost* Obj, ObjectAdaptor& List)noexcept;
void Move33(IGhost* Obj, ObjectAdaptor& List, int t)noexcept;
void End33(IGhost* Obj, ObjectAdaptor& List)noexcept;
void Move34(IGhost* Obj, ObjectAdaptor& List, int t)noexcept;
void End34(IGhost* Obj, ObjectAdaptor& List)noexcept;
void Move35(IGhost* Obj, ObjectAdaptor& List, int t)noexcept;
void End35(IGhost* Obj, ObjectAdaptor& List)noexcept;
void Move36(IGhost* Obj, ObjectAdaptor& List, int t)noexcept;
void End36(IGhost* Obj, ObjectAdaptor& List)noexcept;

void Move4_0(IBoss* Obj, ObjectAdaptor& List, int t)noexcept;
void Move4_0_S(IGhost* Obj, ObjectAdaptor& List, int t)noexcept;
void End4_0_S(IGhost* Obj, ObjectAdaptor& List)noexcept;
void Move4_1(IBoss* Obj, ObjectAdaptor& List, int t)noexcept;
void Move4_2(IBoss* Obj, ObjectAdaptor& List, int t)noexcept;

void Move5_0(IBoss* Obj, ObjectAdaptor& List, int t)noexcept;
void Move5_1(IBoss* Obj, ObjectAdaptor& List, int t)noexcept;
void Move5_2(IBoss* Obj, ObjectAdaptor& List, int t)noexcept;
void Move5_3(IBoss* Obj, ObjectAdaptor& List, int t)noexcept;
void Move5_4(IBoss* Obj, ObjectAdaptor& List, int t)noexcept;
void Move5_5(IBoss* Obj, ObjectAdaptor& List, int t)noexcept;
