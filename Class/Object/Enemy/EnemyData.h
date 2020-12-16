
#pragma once

class Animation;

void LoadEnemyResource()noexcept;

extern int Boss[6];
extern int EnemyBack1Hdl, EnemyBack2Hdl;

extern Animation EnemyAnim[5];

class ObjectAdaptor;
class IGhost;

void NormalEnemyEnd(IGhost* Obj, ObjectAdaptor& List);
