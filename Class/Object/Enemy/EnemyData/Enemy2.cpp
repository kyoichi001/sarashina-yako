
#include "Enemy2.h"
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

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//
//stage 2
//
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void Init20(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(0, 1, Red, Leaf, 0, Aiming);
	List.FacEmy().pushData(Move20,End20, &EnemyAnim[2], 60, 30);
}
void Move20(IGhost* Obj, ObjectAdaptor& List, int t) noexcept {
	Obj->p.y += 0.6f;
	Obj->p.x += Obj->mFirst.x < 350 ? 1.5f : -1.5f;
	if (RANGE(20, t, 200)) {
		if (t % dif(90, 60, 40, 30) == 0) {
			List.FacBul().Bullet(0, 0, Obj->p, 3, 0.0f, dif(2.0f, 3.0f, 4.0f, 5.5f), 0.5f);
		}
	}
}
void End20(IGhost* Obj, ObjectAdaptor& List)noexcept {
	NormalEnemyEnd(Obj, List);
}

void Init21(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(1, 1, Yerrow, SOval, 0, Aiming);
	List.FacEmy().pushData(Move21, End21, &EnemyAnim[3], 60, 30);
}
void Move21(IGhost* Obj, ObjectAdaptor& List, int t)noexcept {
	Obj->p.y += 1.0f;
	Obj->p.x += Obj->mFirst.x < 350 ? 2.0f : -2.0f;
	if (RANGE(20, t, 200)) {
		if (t % dif(90, 60, 40, 30) == 0) {
			List.FacBul().Bullet(1, 0, Obj->p, 2, 0.0f, dif(2.5f, 3.0f, 4.5f, 5.8f), 0.5f);
		}
	}
}
void End21(IGhost* Obj, ObjectAdaptor& List)noexcept {
	NormalEnemyEnd(Obj, List);
}

void Init22(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(2, dif(3, 4, 5, 6), Orange, Small);
	List.FacBul().setDammakuData(3, dif(0, 8, 12,15), Orange, Midium);
	List.FacEmy().pushData(Move22, End22, &EnemyAnim[2], 330, 30);
}
void Move22(IGhost* Obj, ObjectAdaptor& List, int t) noexcept {
	if (t < 600) {
		if (Obj->mFirst.x < 350) Obj->p += D_Curve2({ 420.0f, 200.0f }, { 120.0f, 50.0f }, 0, 280, t);
		else Obj->p += D_Curve2({ -420.0f, 200.0f }, { -120.0f, 50.0f }, 0, 280, t);
	}
	else {
		Obj->p.y += D_lerp(600.0f, 600, 780, t, D_Ease<D_Quad>::In);
	}
	if (RANGE(20, t, 500)) {
		if (t % dif(200, 180, 160, 140) == 0) {
			List.FacBul().BulletEmitter(2, 0, &Obj->p, 2, 8, dif(4, 7, 10, 12), 0.0f, dif(2.0f, 3.0f, 4.0f, 5.0f), 0.11f)->SetDelta(0, Obj->mFirst.x < 350 ? 0.08f : -0.08f);
			if (difficulty >= 2) {
				List.FacBul().BulletEmitter(2, 0, &Obj->p, 2, 8, dif(4, 7, 10, 12), 0.0f, dif(2.0f, 3.0f, 4.0f, 5.0f), 0.11f)->SetDelta(0, Obj->mFirst.x < 350 ? -0.08f : 0.08f);
			}
			List.FacBul().Bullet(3, 0, Obj->p, 1, 0.0f, dif(2.0f, 3.0f, 4.0f, 5.0f));
		}
	}
}
void End22(IGhost* Obj, ObjectAdaptor& List)noexcept {
	NormalEnemyEnd(Obj, List);
}

void Init23(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(4, dif(3, 5, 7, 9), Blue, SOval, 0, Aiming);
	List.FacEmy().pushData(Move23, End23, &EnemyAnim[1], 280, 30);
}
void Move23(IGhost* Obj, ObjectAdaptor& List, int t)noexcept {
	if (t < 60) {
		Obj->p.y = lerp(Obj->mFirst.y, 200.0f, 0, 60, t, Ease<Quad>::Out);
	}
	else {
		if (t % dif(120, 100, 80, 70) == 0) {
			List.FacBul().BulletEmitter(4, 0, &Obj->p, 1, 0, dif(5,7), 0.0f, dif(2.0f, 3.0f, 4.0f, 4.5f), 0.07f, 20)->SetDelta(0, 0.1f, -0.2f);
		}
		if (t > 270) {
			Obj->p.y = lerp(200, -100, 270, 500, t, Ease<Back>::In);
			if (Obj->mFirst.x < 350) Obj->p.x += D_lerp(800, 270, 500, t, D_Ease<D_Quad>::In);
			else Obj->p.x += D_lerp(-80 - 2 * Obj->mFirst.x, 270, 500, t, D_Ease<D_Quad>::In);
		}
	}
}
void End23(IGhost* Obj, ObjectAdaptor& List)noexcept {
	NormalEnemyEnd(Obj, List);
}

void Init24(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(5, 1, White, Big, 0, Aiming);
	List.FacBul().setDammakuData(6, dif(0,4,8,12), White, Midium, 0, Aiming);
	Renew.Push(1, [](IBullet& Obj, int t, ObjectAdaptor& List) {
		if (t == 30)Obj.Renew(List.FacBul().GetBullettoPlayerAngle(Obj.p), 0.4f, Absolute, Absolute);
		if (RANGE(35, t, 100))Obj.Accel(0.1f);
	});
	List.FacEmy().pushData(Move24, End24, &EnemyAnim[2], 140, 30);
}
void Move24(IGhost* Obj, ObjectAdaptor& List, int t) noexcept {
	if (Obj->mFirst.x < 350) Obj->p += D_Curve2({ 750.0f, 700.0f }, { 320.0f, 120.0f }, 0, 280, t);
	else Obj->p += D_Curve2({ -750.0f, 700.0f }, { -320.0f, 120.0f }, 0, 280, t);

	if (RANGE(40, t, 300) && t % 5 == 0) {
		List.FacBul().Bullet(5, 1, Obj->p, 1, PI, 0.6f);
		List.FacBul().Bullet(6, 0, Obj->p, 1, PI, dif(0.0f,3.0f,4.0f,5.0f));
	}
}
void End24(IGhost* Obj, ObjectAdaptor& List)noexcept {
	NormalEnemyEnd(Obj, List);
}

void Init25(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(7, dif(1, 2, 3, 3), Yerrow, Midium, 0, Aiming);
	List.FacBul().setDammakuData(8, dif(0, 2, 3, 3), Yerrow, Midium, 0, Aiming);
	List.FacBul().setDammakuData(9, dif(0, 0, 0, 3), Orange, Midium, 0, Aiming);
	List.FacEmy().pushData(Move25, End25, &EnemyAnim[1], 200, 30);
}
void Move25(IGhost* Obj, ObjectAdaptor& List, int t) noexcept {
	if (t < 100)Obj->p.y += D_lerp(200.0f, 0, 100, t, D_Ease<D_Quad>::In);
	else if (280 < t)Obj->p.y += D_lerp(-200.0f, 280, 350, t, D_Ease<D_Quad>::In);
	if (RANGE(100, t, 270) && t % 2 == 0) {
		Vec2 P = { cosf(float(t) / 30.0f),sinf(float(t) / 30.0f) };
		List.FacBul().Bullet(7, 0, Obj->p + P * 50.0f, 1, float(t) / 10.0f, 3.0f);
		List.FacBul().Bullet(8, 0, Obj->p + P * 50.0f, 3, float(t) / 10.0f, 2.6f);
		List.FacBul().Bullet(9, 0, Obj->p + P * 50.0f, 3, float(t) / 10.0f, 2.4f);
	}
}
void End25(IGhost* Obj, ObjectAdaptor& List)noexcept {
	NormalEnemyEnd(Obj, List);
}

void Init26(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(10, dif(2, 3, 4, 5), Orange, Water, 0, Aiming);
	List.FacEmy().pushData(Move26, End26, &EnemyAnim[3], 100, 30);
}
void Move26(IGhost* Obj, ObjectAdaptor& List, int t)noexcept {
	if (t < 100)Obj->p.y += D_lerp(200.0f, 0, 100, t, D_Ease<D_Quad>::In);
	else if (360 < t)Obj->p.y += D_lerp(-200.0f, 360, 420, t, D_Ease<D_Quad>::In);
	if (RANGE(120, t, 310) && t % 3 == 0) {
		for (int i = 0; i <2; ++i) {
			Vec2 P = { PI2/3.0f*float(i),float(t - 120) / 1.0f ,0};
			List.FacBul().Bullet(10, 0, Obj->p + P, 1, float(t) / 20.0f, dif(1.5f, 3.0f, 4.0f, 5.0f));
		}
	}
}
void End26(IGhost* Obj, ObjectAdaptor& List)noexcept {
	NormalEnemyEnd(Obj, List);
}

//===================================================================================================================
//
//Boss
//
//===================================================================================================================

void Init2_0(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(11, 1, Yerrow, Midium);
	List.FacBul().setDammakuData(12, 1, Purple, SOval);
	List.FacBul().setDammakuData(13, dif(1, 2), Orange, Leaf);
	List.FacBul().setDammakuData(14, dif(1, 2), Cyan, Leaf);
	List.FacEmy().pushData("Kikyo Yamabuki", EnemyBack1Hdl, 2800, 50, Boss[1], false, { MoveAppear, Move2_0, Move2_1 });
}
void Move2_0(IBoss* Obj, ObjectAdaptor& List, int t)noexcept {
	if ((t - 50) % 800 == 400) Obj->SetMovePoint(Rand(Rect{ { 110, 110 },{ 480, 300 } }), 40, Ease<Quad>::InOut);
	if (RANGE(10, (t - 50) % 400, 200)) {
		Vec2 P0 = { cosf(float(t) / dif(8.2f,6.2f) + PI / 8.0f),sinf(float(t) / dif(8.2f,6.2f)) };
		List.FacBul().Bullet(11, 0, Obj->p + P0 * 60.0f, 1, P0.Angle(), P0.lengthSqu()*2.0f, 0.0f);
		if (difficulty > 2)List.FacBul().Bullet(11, 0, Obj->p - P0 * 60.0f, 1, P0.Angle() + PI, P0.lengthSqu() *2.0f);
	}
	else if (RANGE(210, (t - 50) % 400, 380)) {
		Vec2 P1 = { cosf(float(-t) / dif(8.2f,6.5f) - PI / 8.0f),sinf(float(-t) / dif(8.2f,6.5f)) };
		List.FacBul().Bullet(12, 0, Obj->p + P1 * 100.0f, 1, P1.Angle(), P1.lengthSqu() *2.0f, 0.0f);
		if (difficulty > 2)List.FacBul().Bullet(12, 0, Obj->p - P1 * 100.0f, 1, P1.Angle() + PI, P1.lengthSqu() *2.0f);
	}
	if ((t - 50) % 400 == 5) List.FacBul().BulletEmitter(13, 0, &Obj->p, 1, 5, 40, 0.0f, dif(3.0f, 4.0f), 0.0f, 40)->SetDelta(0, 0.15f);
	if ((t - 50) % 400 == 220) List.FacBul().BulletEmitter(14, 0, &Obj->p, 1, 5, 40, 0.0f, dif(3.0f, 4.0f), 0.0f, 40)->SetDelta(0, -0.15f);
}
void Init2_1(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(14, dif(3,5,7,9), Black, Fuda);
	List.FacBul().setDammakuData(15, 1, Black, Void, 255);
	List.FacBul().setDammakuData(16, 1, Purple, Huge, 0, Aiming);
	List.FacBul().setDammakuData(17, 1, Green, Huge, 0, Aiming);
	List.FacBul().setDammakuData(18, dif(3,5), Purple, Big, 0, 0, BLEND_ADD);
	Renew.Push(2, [](IBullet& Obj, int t, ObjectAdaptor& List) {
		if (RANGE(20, t, 50))Obj.Accel(-0.05f);
		if (t == 60) {
			Obj.Split(15, 3, 1, Rand(PI), 0.1f);
		}
	});

	Renew.Push(3, [](IBullet& Obj, int t, ObjectAdaptor& List) {
		if (t == 2) {
			float Angle = Rand(PI);
			List.FacBul().BulletEmitter(18, 5, &Obj.p, 2, 4, 40, Angle, 0.0f, 0.05f)->SetDelta(0, 0.0f, 0.0f, 0.0f, 15);
			List.FacBul().BulletEmitter(18, 5, &Obj.p, 4, 2, 30, Angle, 0.0f, 0.4f)->SetDelta(0, 0.0f, 0.0f, -0.013f, 10);
		}
		if (t == 200) Obj.Kill();
	});
	Renew.Push(4, [](IBullet& Obj, int t, ObjectAdaptor& List) {if (t == 200) Obj.Kill();});
	Renew.Push(5, [](IBullet& Obj, int t, ObjectAdaptor& List) {if (t == 60) Obj.Kill();});
}
void Move2_1(IBoss* Obj, ObjectAdaptor& List, int t)noexcept {
	if ((t - 50) % 800 == 0) Obj->SetMovePoint(Rand(Rect{ { 120, 120 },{ 550, 320 } }), 70, Ease<Quad>::InOut);
	if ((t - 50) % dif(80,60,40,20) == 0) List.FacBul().Bullet(14, 0, Obj->p, 10, Rand(PI), 3.0f, 0.5f);
	if ((t - 50) % 400 == 10) List.FacBul().Bullet(16, 2, Obj->p, 1, 0.0f, 3.0f, 0.0f);
	if ((t - 50) % 400 == 110) List.FacBul().Bullet(16, 2, Obj->p, 1, Rand(PI / 1.5f), 3.0f);
	if ((t - 50) % 400 == 260) List.FacBul().Bullet(17, 2, Obj->p, 1, Rand(PI / 1.5f), 4.5f);
	if ((t - 50) % 400 == 320) List.FacBul().Bullet(16, 2, Obj->p, 1, Rand(PI / 1.5f), 6.0f);
}

void Init3_0(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(19, 1, Red, Leaf, 0, Aiming);
	List.FacBul().setDammakuData(20, 1, Black, Small);
	List.FacEmy().pushData("Heigo Yanagikawa", EnemyBack1Hdl, 3600, 50, Boss[2], false, { MoveAppear, Move3_0, Move3_1 ,Move3_2,Move3_3,Move3_4 ,Move3_5});
}
void Move3_0(IBoss* Obj, ObjectAdaptor& List, int t)noexcept {
	if ((t - 50) % 800 == 400) Obj->SetMovePoint(Rand(Rect{ { 110, 110 },{ 480, 300 } }), 40, Ease<Quad>::InOut);

	if (t % 10 == 0) List.FacBul().Bullet(19, 0, Obj->p, dif(3, 4, 5, 6), Rand(PI / 6), dif(2.5f, 3.5f, 4.5f, 5.5f), dif(1.2f,0.6f));
	if (t % dif(25, 15, 8, 4) == 0) List.FacBul().Bullet(20, 0, Rand(Rect{ { 50, 50 },{ 580, 50 } }), 1, Rand(PI / 24) + HALF_PI,dif(1.0f,1.5f,2.0f,2.5f));
}
void Init3_1(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(21, dif(10, 15, 18, 20), Red, Huge, 0, Aiming);
	List.FacBul().setDammakuData(22, dif(10, 15, 18, 20), Red, Huge, 0, Aiming);
	/*Renew.Push(6, [](IBullet& Obj, int t, ObjectAdaptor& List) {
		if (t == 30)Obj.Renew(0.0f, 0.1f, Aiming, Absolute);
		if (RANGE(35, t, 100))Obj.Accel(0.1f);
	});*/
}
void Move3_1(IBoss* Obj, ObjectAdaptor& List, int t)noexcept {
	if ((t - 50) % 800 == 400) {
		Point P = Rand(Rect{ { 110, 110 },{ 480, 300 } });
		Obj->SetMovePoint(P, 40, Ease<Quad>::InOut);
	}

	if (RANGE(10, (t - 50) % 300, 200)) {
		if (t % 60 == 0) {
			List.FacBul().Bullet(21, 0, Obj->p, 1, 0.0f, 2.0f);
			List.FacBul().Bullet(22, 0, Obj->p, 1, 0.0f, 2.0f);
		}
	}
	if (RANGE(210, (t - 50) % 300, 260)) {
		List.FacBul().BulletForeach(21, [](IBullet& Obj, int t, ObjectAdaptor& List) {
			if (t <= 240) {
				Obj.Turn(-0.05f);
			}
		});
		List.FacBul().BulletForeach(22, [](IBullet& Obj, int t, ObjectAdaptor& List) {
			if (t <= 240) {
				Obj.Turn(-0.05f);
			}
		});
	}
	else if ((t - 50) % 300 == 270) {
		List.FacBul().BulletForeach(22, [](IBullet& Obj, int t, ObjectAdaptor& List) {
			if (t <= 240) {
				Obj.Renew(0.0f, 2.5f, Aiming, Absolute);
				Obj.Remake(Orange);
			}
		});
	}
}

void Init3_2(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(23, dif(2, 4, 6, 8), Orange, Huge);
	List.FacBul().setDammakuData(24, dif(3, 5, 8, 11), Red, SOval);
	List.FacBul().setDammakuData(25, dif(3, 5, 8,11), Yerrow, SOval);
	Renew.Push(7, [](IBullet& Obj, int t, ObjectAdaptor& List) {
		if (t == 30)Obj.Renew(0.0f, dif(2.0f,3.0f,4.0f,5.0f), Sequence);
	});
}
void Move3_2(IBoss* Obj, ObjectAdaptor& List, int t)noexcept {
	if ((t - 50) % 1000 == 400) {
		Point P = Rand(Rect{ { 110, 110 },{ 480, 300 } });
		Obj->SetMovePoint(P, 40, Ease<Quad>::InOut);
	}

	if (RANGE(10, (t - 50) % 500, 460)) {
		if (t % dif(15,10,8,6) == 0) {
			List.FacBul().Bullet(23, 7, Obj->p, 1, float(t) / 15.0f, 6.0f);
		}
	}
	if (t % 4 == 0) {
		List.FacBul().Bullet(Rand_TF(0.5) ? 24 : 25, 0, Obj->p, 1, Rand(PI), 4.0f);
	}
}
void Init3_3(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(26, 1, Red, Trump);
	List.FacBul().setDammakuData(27, 1, Orange, Trump);
	List.FacBul().setDammakuData(28, 1, Yerrow, Trump);
	List.FacBul().setDammakuData(29, 1, Blue, Trump);
	List.FacBul().setDammakuData(30, 1, Cyan, Trump);
	List.FacBul().setDammakuData(30, 1, Cyan, Trump);
	List.FacBul().setDammakuData(31, dif(6, 9, 13, 16), Cyan, Midium);
	Renew.Push(8, [](IBullet& Obj, int t, ObjectAdaptor& List) {
		if (RANGE(30, t, 100)) {
			Obj.Accel(dif(0.02f,0.05f,0.06f,0.07f));
		}
	});
}
void Move3_3(IBoss* Obj, ObjectAdaptor& List, int t)noexcept {
	if ((t - 50) % 1000 == 400) {
		Point P = Rand(Rect{ { 110, 110 },{ 480, 300 } });
		Obj->p = P;
	}
	if (RANGE(10, (t - 50) % 500, 460)&&t%3==0) {
		Point P1 = { 350.0f + 300.0f*sin(float(t) / 20.0f),50.0f };
		Point P2 = { 350.0f - 300.0f*sin(float(t) / 20.0f),50.0f };
		List.FacBul().Bullet(Rand(26, 30), 8, P1, 1, HALF_PI, 1.0f);
		List.FacBul().Bullet(Rand(26, 30), 8, P2, 1, HALF_PI, 1.0f);
		if (t % 15 == 0) {
			List.FacBul().Bullet(31, 0, Obj->p, 1, float(t) / 20.0f, 3.0f);
		}
	}
}

void Init3_4(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(32, dif(7,10,13,15), Red, Huge);
}
void Move3_4(IBoss* Obj, ObjectAdaptor& List, int t)noexcept {
	if ((t - 50) % 1000 == 400) {
		Point P = Rand(Rect{ { 110, 110 },{ 480, 300 } });
		Obj->SetMovePoint(P, 40, Ease<Quad>::InOut);

	}

	if (RANGE(10, (t - 50) % 500, 460)) {
		if (t % 10 == 0) {
			List.FacBul().Bullet(Rand(26, 30), 7, Obj->p, 1, float(t) / 10.0f, 6.0f);
		}
	}
	if (t % 20 == 0) {
		List.FacBul().Bullet(32, 0, Obj->p, 1, Rand(PI), 4.0f);
	}
}
void Init3_5(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(33, 1, Red, Fire,0,Aiming);
	List.FacBul().setDammakuData(34, 1, Blue, Leaf);
}
void Move3_5(IBoss* Obj, ObjectAdaptor& List, int t)noexcept {
	if ((t - 50) % 400 == 0) {
		Point P = Rand(Rect{ { 480, 110 },{ 500, 300 } });
		Obj->SetMovePoint(P, 40, Ease<Quad>::InOut);
	}
	if ((t - 50) % 400 == 200) {
		Point P = Rand(Rect{ { 60, 110 },{ 80, 300 } });
		Obj->SetMovePoint(P, 40, Ease<Quad>::InOut);
	}
	if (t % 20 == 0) {
		List.FacBul().Bullet(33, 0, Obj->p, 1, Rand(PI), 4.0f);
		List.FacBul().setDammakuData(34, 1, Blue, Leaf);
	}

}
void setBulletData2(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().clearDammakuData();
	List.FacEmy().clearData();
	Init20(Renew, List);
	Init21(Renew, List);
	Init22(Renew, List);
	Init23(Renew, List);
	Init24(Renew, List);
	Init25(Renew, List);
	Init26(Renew, List);
	Init2_0(Renew, List);
	Init2_1(Renew, List);
	Init3_0(Renew, List);
	Init3_1(Renew, List);
	Init3_2(Renew, List);
	Init3_3(Renew, List);
	Init3_4(Renew, List);
	Init3_5(Renew, List);
}