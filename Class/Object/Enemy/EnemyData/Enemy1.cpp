
#include "Enemy1.h"
#include "../EnemyData.h"

#include "../../Leazer/LeazerDATA.h"
#include "../../Bullet/RenewManager.h"
#include "../../Bullet/BulletEmitter.h"

#include "../../../MediatorClass/ObjectAdaptor.h"
#include "../../../../Library/Func.h"
#include "../../../../Library/Renderer.h"//BLEND_ADD
#include "../../../../Library/Math/Constant.h"
#include "../../../../Library/Math/Random.h"
#include "../../../../Library/Math/Geometory.h"

#include "../../../../Library/Sprite/Animation.h"

//-----------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------
//
//stage 1
//
//-----------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------

void Init10(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(0, 1, Blue, Midium, 0, Aiming);
	List.FacBul().setDammakuData(1, 1, Lime, Big, 0, Aiming);
	List.FacEmy().pushData(Move10, End10,&EnemyAnim[1], 40, 30);
}
void Move10(IGhost* Obj, ObjectAdaptor& List, int t)noexcept {
	Obj->mSpeed.y = 1.5f;
	Obj->mSpeed.x = D_lerp(Obj->mFirst.x < 350 ? 650 : -650, 60, 400, t, D_Ease<D_Sin>::InOut);
	if (RANGE(20, t, 200)) {
		if (t % dif(300, 120, 60, 30) == 0) {
			float speed = dif(2.0f, 2.5f, 5.0f, 6.0f);
			List.FacBul().Bullet(0, 0, Obj->p, 1, 0.0f, speed);
			List.FacBul().Bullet(1, 0, Obj->p, dif(0, 0, 2, 4), 0.0f, speed, 1.3f);
		}
	}
}
void End10(IGhost* Obj, ObjectAdaptor& List)noexcept {
	NormalEnemyEnd(Obj, List);
}

void Init11(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(3, 1, Blue, Midium, 0, Aiming);
	List.FacEmy().pushData(Move11, End11, &EnemyAnim[3], 40, 30);
}
void Move11(IGhost* Obj, ObjectAdaptor& List, int t)noexcept {
	Obj->p.y = lerp(Obj->mFirst.y, 200.0f, 0, 75, t, Ease<Quad>::Out);
	Obj->p.x = lerp(Obj->mFirst.x, Obj->mValue, 0, 75, t, Ease<Quad>::Out);
	if (t < 200) {
		if (t % dif(60, 40, 30, 10) == 0) List.FacBul().Bullet(3, 0, Obj->p, dif(1, 2), 0.0f, dif(2.0f, 3.0f, 4.0f, 5.0f), 0.3f);
	}
	else if (t > 230) {
		Obj->p.y = lerp(200, 850, 230, 380, t, Ease<Quad>::In);
	}
}
void End11(IGhost* Obj, ObjectAdaptor& List)noexcept {
	NormalEnemyEnd(Obj, List);
}

void Init12(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(4, dif(3, 5, 8, 10), Yerrow, Big, BLEND_ADD, Aiming);
	List.FacEmy().pushData(Move12, End12, &EnemyAnim[1], 160, 30);
}
void Move12(IGhost* Obj, ObjectAdaptor& List, int t)noexcept {
	if (t < 60) {
		Obj->p.y = lerp(Obj->mFirst.y, 200.0f, 0, 60, t, Ease<Quad>::Out);
	}
	else {
		if (t % dif(120, 100, 80, 70) == 0) {
			List.FacBul().BulletEmitter(4, 0, &Obj->p, 1, 0, dif(2, 3, 4, 6), 0.0f, dif(2.0f, 3.0f, 4.0f, 4.5f), 0.07f, 0)->SetDelta(1, 0.0f, -0.2f);
		}
		if (t > 270) {
			Obj->p.y = lerp(200, -100, 270, 500, t, Ease<Back>::In);
			if (Obj->mFirst.x < 350)Obj->p.x += D_lerp(800, 270, 500, t, D_Ease<D_Quad>::In);
			else Obj->p.x += D_lerp(-80 - 2 * Obj->mFirst.x, 270, 500, t, D_Ease<D_Quad>::In);
		}
	}
}
void End12(IGhost* Obj, ObjectAdaptor& List)noexcept {
	NormalEnemyEnd(Obj, List);
}

void Init13(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(5, dif(2, 4, 6, 8), Red, Midium, 0, Aiming);
	List.FacEmy().pushData(Move13, End13, &EnemyAnim[4], 200, 30);
}
void Move13(IGhost* Obj, ObjectAdaptor& List, int t)noexcept {
	if (t < 60) {
		Obj->p.y = lerp(Obj->mFirst.y, 200.0f, 0, 60, t, Ease<Quad>::Out);
	}
	else {
		if (t % dif(120, 100, 80, 70) == 0) {
			List.FacBul().BulletEmitter(5, 0, &Obj->p, 2, 0, dif(2, 4, 7, 10), 0.0f, dif(2.0f, 3.0f, 4.0f, 4.5f), 0.0f, 20)->SetDelta(0, 0.0f, -0.2f, 0.03f);
		}
		if (t > 270) {
			Obj->p.y = lerp(200, -100, 270, 500, t, Ease<Back>::In);
			if (Obj->mFirst.x < 350) Obj->p.x += D_lerp(800, 270, 500, t, D_Ease<D_Quad>::In);
			else Obj->p.x += D_lerp(-80 - 2 * Obj->mFirst.x, 270, 500, t, D_Ease<D_Quad>::In);
		}
	}
}
void End13(IGhost* Obj, ObjectAdaptor& List)noexcept {
	NormalEnemyEnd(Obj, List);
}


void Init14(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(6, 1, Cyan, Small, 0, Aiming);
	List.FacEmy().pushData(Move14, End14, &EnemyAnim[2], 40, 30);
}
void Move14(IGhost* Obj, ObjectAdaptor& List, int t)noexcept {
	Obj->p.x += Obj->mFirst.x > 350 ? -4 : 4;
	if (t % dif(200, 150, 100, 60) == 0)List.FacBul().Bullet(6, 0, Obj->p, dif(1, 3, 3, 5), 0.0f, dif(2.0f, 3.0f, 4.0f, 5.0f), 0.5f);
}
void End14(IGhost* Obj, ObjectAdaptor& List)noexcept {
	NormalEnemyEnd(Obj, List);
}

void Init15(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(7, dif(2, 3, 4, 5), Cyan, SOval, BLEND_ADD, Aiming);
	List.FacEmy().pushData(Move15, End15, &EnemyAnim[4], 120, 30);
}
void Move15(IGhost* Obj, ObjectAdaptor& List, int t)noexcept {
	if (t < 60) {
		Obj->p.y = lerp(Obj->mFirst.y, 200.0f, 0, 60, t, Ease<Quad>::Out);
	}
	else {
		if (t % dif(120, 100, 80, 70) == 0) {
			List.FacBul().BulletEmitter(7, 0, &Obj->p, 2, 0, 5, 0.0f, dif(2.0f, 3.0f, 4.0f, 4.5f), 0.07f, 20)->SetDelta(0.0f, -0.2f, 0.1f);
		}
		if (t > 270) {
			Obj->p.y = lerp(200, -100, 270, 500, t, Ease<Back>::In);
			if (Obj->mFirst.x < 350) Obj->p.x += D_lerp(800, 270, 500, t, D_Ease<D_Quad>::In);
			else Obj->p.x += D_lerp(-80 - 2 * Obj->mFirst.x, 270, 500, t, D_Ease<D_Quad>::In);
		}
	}
}
void End15(IGhost* Obj, ObjectAdaptor& List)noexcept {
	NormalEnemyEnd(Obj, List);
}

void Init16(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(8, 1, Blue, Fuda, 0, Aiming);
	List.FacEmy().pushData(Move16, End16, &EnemyAnim[2], 40, 30);
}
void Move16(IGhost* Obj, ObjectAdaptor& List, int t)noexcept {
	Obj->p.y += 1.5f;
	if (Obj->mFirst.x < 350) Obj->p.x += D_lerp(730, 60, 400, t, D_Ease<D_Sin>::InOut);
	else Obj->p.x += D_lerp(-730, 60, 400, t, D_Ease<D_Sin>::InOut);

	if (RANGE(20, t, 200)) {
		if (t % dif(360, 200, 70, 30) == 0) {
			List.FacBul().Bullet(8, 0, Obj->p, 3, 0.0f, dif(2.0f, 2.5f, 5.0f, 6.0f), 0.15f);
		}
	}
}
void End16(IGhost* Obj, ObjectAdaptor& List)noexcept {
	NormalEnemyEnd(Obj, List);
}

//===================================================================================================================
//
//Boss
//
//===================================================================================================================

void Init0_0(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(9, 1, dif(Blue, Purple), Midium);
	List.FacBul().setDammakuData(10, 1, dif(Yerrow, Cyan), Fuda);
	List.FacBul().setDammakuData(11, 1, dif(Red, Blue), Small);
	List.FacBul().setDammakuData(12, dif(1, 2, 3, 4), dif(Yerrow, Cyan), Small);
	Renew.Push(1, [](IBullet& Obj, int t, ObjectAdaptor& List) {
		if (RANGE(40, t, 50))Obj.Accel(-0.4f);
		if (RANGE(80, t, 90))Obj.SetSpeed({ Rand(PI),1.5f,0 });
	});
	List.FacEmy().pushData("Azami Yotsuya",EnemyBack1Hdl, 2800, 50, Boss[0], true, { MoveAppear,Move0_0,MoveEscape });
}
void Move0_0(IBoss* Obj, ObjectAdaptor& List, int t)noexcept {
	if ((t - 50) % 600 == 0) Obj->SetMovePoint(Rand(Rect{ { 70, 70 },{ 600, 320 } }), 70, Ease<Quad>::InOut);
	if ((t - 50) % 1200 == 0) List.FacBul().BulletEmitter(9, dif(0, 1, 1, 1), &Obj->p, dif(1, 2, 5, 8), 2, 40, 0.0f, 4.0f, 0.15f, 100)->SetDelta(0, 0.15f);
	else if ((t - 50) % 1200 == 300)List.FacBul().BulletEmitter(10, dif(0, 1, 1, 1), &Obj->p, dif(1, 2, 5, 8), 2, 40, PI, 4.0f, 0.15f, 100)->SetDelta(0, -0.15f);
	else if ((t - 50) % 1200 == 750) List.FacBul().BulletEmitter(11, 0, &Obj->p, dif(3, 6), 7, 45, 0.0f, 4.0f, 0.3f, 100)->SetDelta(0, 0.25f);
	else if ((t - 50) % 1200 == 900)List.FacBul().BulletEmitter(12, 0, &Obj->p, dif(1, 2), 2, 40, 0.0f, dif(3.0f, 3.5f, 4.0f, 4.5f), 0.1f)->SetDelta(0, -0.15f);
}
void Init1_0(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(13, 1, dif(Blue, Purple), Midium);
	List.FacBul().setDammakuData(14, 1, dif(Yerrow, Cyan), Fuda);
	Renew.Push(2, [](IBullet& Obj, int t, ObjectAdaptor& List) {
		if (RANGE(40, t, 50))Obj.Accel(-0.4f);
		if (RANGE(80, t, 90))Obj.SetSpeed({ Rand(PI),1.5f,0 });
	});
	List.FacEmy().pushData("Azami Yotsuya", EnemyBack1Hdl, 2800, 50, Boss[0], false, { MoveAppear,Move1_0,Move1_1 ,Move1_2,Move1_3/*,Move1_4 */});
}
void Move1_0(IBoss* Obj, ObjectAdaptor& List, int t) noexcept {
	if ((t - 50) % 800 == 0) Obj->SetMovePoint(Rand(Rect{ { 70, 70 },{ 600, 320 } }), 70, Ease<Quad>::InOut);
	if ((t - 50) % 800 == 0) List.FacBul().BulletEmitter(13, 2, Obj, dif(1, 2, 3, 4), 2, dif(150, 180), 0.0f, 4.0f, 0.15f, 100)->SetDelta(0, 0.15f);
	if ((t - 50) % 800 == 400) List.FacBul().BulletEmitter(14, 2, Obj, dif(1, 2, 3, 4), 2, dif(150, 180), PI, 4.0f, 0.15f, 100)->SetDelta(0, -0.15f);
}
void Init1_1(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(15, 1, dif(Yerrow, Cyan), Midium);
	List.FacBul().setDammakuData(16, 8, static_cast<BulletColor>(Rand(5, 7)), Huge);
	List.FacBul().setDammakuData(17, 1, Black, static_cast<BulletShape>(Rand(1, 3)));

	Renew.Push(3, [](IBullet& Obj, int t, ObjectAdaptor& List) {
		if (t % 3 == 0) List.FacBul().Bullet(17, 5, Obj.p + Vec2(Rand(PI2), 20.0f, 0), 1, 0.0f, 0.0f);
		Obj.Turn(0.01f);
	});
	Renew.Push(4, [](IBullet& Obj, int t, ObjectAdaptor& List) {
		if (t % 3 == 0) List.FacBul().Bullet(17, 5, Obj.p + Vec2(Rand(PI2), 20.0f, 0), 1, 0.0f, 0.0f);
		Obj.Turn(-0.01f);
	});
	Renew.Push(5, [](IBullet& Obj, int t, ObjectAdaptor& List) {if (t > 80)Obj.Kill(); });
}
void Move1_1(IBoss* Obj, ObjectAdaptor& List, int t)noexcept {
	if ((t - 50) % 700 == 0)Obj->SetMovePoint(Rand(Rect{ { 70, 70 },{ 200, 230 } }), 70, Ease<Quad>::InOut);
	if ((t - 50) % dif(375, 300, 225, 150) == 0)List.FacBul().BulletEmitter(15, 0, &Obj->p, dif(1, 2, 3, 4), dif(12, 10, 8, 6), dif(30, 50), 0.0f, dif(3.0f, 3.5f, 4.0f, 4.5f), 0.05f, 30)->SetDelta(0, -0.15f);
	if ((t - 50) % dif(125, 100, 75, 50) == 0) List.FacBul().Bullet(16, Rand(3, 4), Obj->p, 1, Rand(PI), 4.5f);
}
void Init1_2(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(18, 1, dif(Blue, Purple), Midium);
	List.FacBul().setDammakuData(19, 1, dif(Yerrow, Orange), Fuda);
}
void Move1_2(IBoss* Obj, ObjectAdaptor& List, int t)noexcept {
	if ((t - 50) % 600 == 0) {
		Point P = Rand(Rect{ { 70, 70 },{ 600, 320 } });
		Obj->SetMovePoint(P, 70, Ease<Quad>::InOut);
	}
	if ((t - 50) % 600 == 0) List.FacBul().BulletEmitter(18, 0, Obj, dif(1, 2, 3, 4), 2, dif(90, 140), 0.0f, 4.0f, 0.15f, 100)->SetDelta(0, 0.15f);
	if ((t - 50) % 600 == 300)List.FacBul().BulletEmitter(18, 0, Obj, dif(1, 2, 3, 4), 2, dif(90, 140), PI, 4.0f, 0.15f, 100)->SetDelta(0, -0.15f);
}
void Init1_3(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(20, dif(6, 7, 9, 10), Purple, Midium);
	List.FacBul().setDammakuData(21, dif(6, 7, 9, 10), Black, Midium);
	List.FacBul().setDammakuData(22, 1, Purple, Fire, 0, Aiming);
	List.FacBul().setDammakuData(23, 1, Yerrow, Fuda, 0, Aiming, BLEND_ADD);
	Renew.Push(8, [](IBullet& Obj, int t, ObjectAdaptor& List) {t % 80<40 ? Obj.Turn(0.05f) : Obj.Turn(-0.05f); });
	Renew.Push(9, [](IBullet& Obj, int t, ObjectAdaptor& List) {t % 80<40 ? Obj.Turn(-0.05f) : Obj.Turn(0.05f);  });
}
void Move1_3(IBoss* Obj, ObjectAdaptor& List, int t) noexcept {
	if (t % 1200 == 0) Obj->SetMovePoint(Rand(Rect{ { 170, 170 },{ 500, 200 } }), 70, Ease<Quad>::InOut);
	if (t % 1200 == 0) List.FacBul().BulletEmitter(20, 0, &Obj->p, 1, dif(16, 14, 11, 8), dif(25, 28, 38, 50), 0.0f, dif(1.5f, 2.0f, 2.5f, 3.0f))->SetDelta(0, 0.15f);
	if (t % 1200 == 600) List.FacBul().BulletEmitter(21, 0, &Obj->p, 1, dif(16, 14, 11, 8), dif(25, 28, 38, 50), 0.0f, dif(1.5f, 2.0f, 2.5f, 3.0f))->SetDelta(0, -0.15f);

	if (RANGE(30, t % 1200, 1000)) {
		if (t % 2 == 0)List.FacBul().BulletEmitter(23, Rand(8, 9), &Obj->p, 1, 3, 4, PI + Rand(PI / 3), 5.0f);
		if (t % 100 == 0) List.FacBul().Bullet(22, 0, Obj->p, 3, 0.0f, 3.0f, 0.55f);
		if (t % 100 == 50) List.FacBul().Bullet(22, 0, Obj->p, 2, 0.0f, 3.0f, 0.55f);
	}
}
void Init1_4(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(24, 200, Red, Big, 0, 0, BLEND_ADD);
}
void Move1_4(IBoss* Obj, ObjectAdaptor& List, int t)noexcept {
	if ((t - 50) % 700 == 0)Obj->SetMovePoint(Rand(Rect{ { 70, 70 },{ 200, 230 } }), 70, Ease<Quad>::InOut);
	if ((t - 50) % 10 == 0) List.FacBul().Bullet(24, 0, Obj->p, 1, 0.0f, 3.0f);
}

void setBulletData1(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().clearDammakuData();
	List.FacEmy().clearData();
	Init10(Renew, List);
	Init11(Renew, List);
	Init12(Renew, List);
	Init13(Renew, List);
	Init14(Renew, List);
	Init15(Renew, List);
	Init16(Renew, List);
	Init0_0(Renew, List);
	Init1_0(Renew, List);
	Init1_1(Renew, List);
	Init1_2(Renew, List);
	Init1_3(Renew, List);
	Init1_4(Renew, List);
}

