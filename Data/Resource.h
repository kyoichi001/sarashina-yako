
#pragma once

extern int Font01, Font02, Font03, Font04, Font05, Font06;

extern int TrainHdl, TreeHdl, BuildingHdl, RailHdl;

extern int EnemyMarkerHdl;

extern int  PlayerCoreHdl, HitEffectHdl, SlowEffectHdl;

extern int BulletEffectHdl[10], SnowHdl, PBuletBreakHdl, BossBreakHdl, EnemyBreakHdl,PlayerBreakHdl;

extern int StageBackShadowHdl, Stage1Hdl;

extern int Ghost3DHdl,Clowd3DHdl,Snow3DHdl;

void Init3D()noexcept;

void LoadAllData()noexcept;
