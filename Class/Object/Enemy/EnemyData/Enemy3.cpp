
#include "Enemy3.h"
#include "../EnemyData.h"

#include "../../Leazer/LeazerDATA.h"
#include "../../Bullet/RenewManager.h"
#include "../../Bullet/BulletEmitter.h"

#include "../../../MediatorClass/ObjectAdaptor.h"
#include "../../../../Library/Func.h"
#include "../../../../Library/Renderer.h"//BLEND_ADD
#include "../../../../Library/Math/Constant.h"
#include "../../../../Library/Math/Geometory.h"
#include "../../../../Library/Math/Random.h"

#include "../../../../Library/Sprite/Animation.h"

//---------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------
//
//stage 3
//
//---------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------

void Init30(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(0, dif(2,3,4,5), Green, Big, 0, Aiming);
	List.FacBul().setDammakuData(1, dif(2, 3, 4, 5), Green, Midium, 0, Aiming);
	List.FacEmy().pushData(Move30,End30, &EnemyAnim[3], 80, 30);
}
void Move30(IGhost* Obj, ObjectAdaptor& List, int t)noexcept {
	Obj->p.y += 2.0f;
	Obj->p.x += Obj->mFirst.x < 350 ? 4.5f : -4.5f;
	if (RANGE(30, t, 280) && t % 30 == 0) {
		List.FacBul().Bullet(0, 0, Obj->p, 1, Rand(0.5f), dif(2.0f,3.0f,4.0f,5.0f));
		List.FacBul().Bullet(1, 0, Obj->p, 2, Rand(0.5f), dif(2.0f, 3.0f, 4.0f, 5.0f), 0.35f);
	}
}
void End30(IGhost* Obj, ObjectAdaptor& List)noexcept {
	NormalEnemyEnd(Obj, List);
}

void Init31(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(2, dif(2,3,4,5), White, SOval);
	List.FacEmy().pushData(Move31, End31, &EnemyAnim[1], 140, 30);
}
void Move31(IGhost* Obj, ObjectAdaptor& List, int t)noexcept {
	Obj->p.y += 3.0f;
	Obj->p.x += Obj->mFirst.x < 350 ? 3.0f : -3.0f;
	if (RANGE(20, t, 250) && t % 5 == 0) {
		List.FacBul().Bullet(2, 0, Obj->p, 1, Rand(PI), Rand(3.0f, 4.5f));
	}
}
void End31(IGhost* Obj, ObjectAdaptor& List)noexcept {
	NormalEnemyEnd(Obj, List);
}

void Init32(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(3, 1, Blue, Small, 0, 0, BLEND_ADD);
	List.FacBul().setDammakuData(4, 1, Red, Small, 0, 0, BLEND_ADD);
	Renew.Push(1, [](IBullet& Obj, int t, ObjectAdaptor& List) {
		if (RANGE(20, t, 30))Obj.Accel(0.08f);
		else if (RANGE(40, t, 70))Obj.Turn(-0.08f);
		else if (RANGE(80, t, 100))Obj.Turn(0.08f);
	});
	List.FacEmy().pushData(Move32, End32, &EnemyAnim[3], 200, 30);
}
void Move32(IGhost* Obj, ObjectAdaptor& List, int t)noexcept {
	Obj->p.y += D_lerp(200.0f, 0, 100, t, D_Ease<D_Quad>::Out);
	Obj->p.y += D_lerp(-600.0f, 350, 500, t, D_Ease<D_Quad>::In);
	if (RANGE(110, t, 250) && t % dif(8,6,4,4) == 0) {
		List.FacBul().BulletEmitter(3, 1, &Obj->p, 1, 2, 20, float(t) / 4.0f, 4.0f);
		List.FacBul().BulletEmitter(4, 1, &Obj->p, 1, 2, 20, -float(t) / 4.0f, 4.0f, 0.0f, 30);
	}
}
void End32(IGhost* Obj, ObjectAdaptor& List)noexcept {
	NormalEnemyEnd(Obj, List);
}

void Init33(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(5, 1, Blue, Fuda);
	List.FacBul().setDammakuData(6, 1, Cyan, Midium);
	List.FacEmy().pushData(Move33, End33, &EnemyAnim[2], 80, 30);
}
void Move33(IGhost* Obj, ObjectAdaptor& List, int t)noexcept {
	Obj->p.y += D_lerp(120, 0, 90, t, D_Ease<D_Quad>::Out);
	if (t > 160) {
		Obj->p.y += D_lerp(600, 160, 400, t, D_Ease<D_Quad>::Out);
		Obj->p.x += Obj->mFirst.x < 350 ? -2.0f : 2.0f;
	}
	if (RANGE(20, t, 260) && t % 30 == 0) {
		List.FacBul().Bullet(5, 0, Obj->p, 1, HALF_PI, 3.0f);
		List.FacBul().Bullet(6, 0, Obj->p, dif(0, 0, 3, 5), HALF_PI, 3.0f);
	}
}
void End33(IGhost* Obj, ObjectAdaptor& List)noexcept {
	NormalEnemyEnd(Obj, List);
}

void Init34(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(7, 20, Cyan, Arrow);
	List.FacEmy().pushData(Move34, End34, &EnemyAnim[2], 200, 30);
}
void Move34(IGhost* Obj, ObjectAdaptor& List, int t)noexcept {
	Obj->p.y += D_lerp(120, 0, 90, t, D_Ease<D_Quad>::Out);
	Obj->p.y += D_lerp(-200, 460, 560, t, D_Ease<D_Quad>::In);
	if (RANGE(100, t, 460) && t % 30 == 0) {
		List.FacBul().Bullet(7, 0, Obj->p, 1, float(t) / 10.0f, 3.0f);
	}
}
void End34(IGhost* Obj, ObjectAdaptor& List)noexcept {
	NormalEnemyEnd(Obj, List);
}

void Init35(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(8, 12, Orange, Arrow);
	Renew.Push(2, [](IBullet& Obj, int t, ObjectAdaptor& List) {
		if (t == 0)Obj.Turn(-PI / 8);
		int T = t % 240;
		if (RANGE(5, T, 90))Obj.Accel(-5.0f / 90.0f);
		if (T == 120) {
			Obj.Turn(PI / 3 * 2);
			Obj.Accel(5.0f);
		}
		if (RANGE(120, T, 210))Obj.Accel(-5.0f / 90.0f);
		if (T == 238)Obj.Turn(-PI / 3);
	});
	List.FacEmy().pushData(Move35, End35, &EnemyAnim[3], 180, 30);
}
void Move35(IGhost* Obj, ObjectAdaptor& List, int t)noexcept {
	Obj->p.y += D_lerp(120, 0, 90, t, D_Ease<D_Quad>::Out);
	Obj->p.y += D_lerp(-200, 460, 560, t, D_Ease<D_Quad>::In);
	if (RANGE(100, t, 460)) {
		if ((t - 90) % 50 == 0) {
			List.FacBul().BulletEmitter(8, 2, &Obj->p, 1, 5, 14, float(t) / 10.0f, 5.0f);
		}
	}
}
void End35(IGhost* Obj, ObjectAdaptor& List)noexcept {
	NormalEnemyEnd(Obj, List);
}

void Init36(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(9, 7, Yerrow, Small, 0, Aiming);
	List.FacEmy().pushData(Move36, End36, &EnemyAnim[2], 80, 30);
}
void Move36(IGhost* Obj, ObjectAdaptor& List, int t)noexcept {
	if (Obj->mFirst.x < 350) {
		Obj->p += D_Besier2({ 560,700 }, { 530,100 }, 0, 300, t);
	}
	else {
		Obj->p += D_Besier2({ 0,700 }, { 20,100 }, 0, 300, t);
	}
	if (RANGE(30, t, 140) && t % 3 == 0) {
		List.FacBul().Bullet(13, 0, Obj->p, 2, 0.0f, 3.1f);
	}
}
void End36(IGhost* Obj, ObjectAdaptor& List)noexcept {
	NormalEnemyEnd(Obj, List);
}

//===================================================================================================================
//
//Boss
//
//===================================================================================================================

void Init4_0(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacEmy().pushData( "Uh-ghon",EnemyBack1Hdl , 2800, 50,Boss[3], true ,{ MoveAppear, Move4_0, Move4_1,Move4_2,MoveEscape });
}
void Move4_0(IBoss* Obj, ObjectAdaptor& List, int t)noexcept {
	if ((t - 50) % 800 == 400) {
		Point P = Rand(Rect{ { 110, 110 },{ 480, 300 } });
		Obj->SetMovePoint(P, 40, Ease<Quad>::InOut);
	}
	if ((t - 50) % 45 == 0) {
		List.FacEmy().CreateEnemy(7, Rand(Rect{ 40.0f,0.0f,600.0f,0.0f }));
	}
}
void Init4_0_S(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(10, 1, White, Big);
	List.FacBul().setDammakuData(11, 1, Orange, Arrow);
	Renew.Push(3, [](IBullet& Obj, int t, ObjectAdaptor& List) {
		if (RANGE(0, t, 80))Obj.Turn(0.08f);
		if (RANGE(80, t, 160))Obj.Turn(-0.08f);
	});
	Renew.Push(4, [](IBullet& Obj, int t, ObjectAdaptor& List) {
		if (RANGE(0, t, 80))Obj.Turn(0.08f);
		if (RANGE(80, t, 160))Obj.Turn(-0.08f);
		if (RANGE(160, t, 170))Obj.Turn(PI / 10.0f);
		//if (t==160)Obj.Renew(HALF_PI,2.0f);
	});
	List.FacEmy().pushData(Move4_0_S, End4_0_S, &EnemyAnim[0], 120, 30);
}
void Move4_0_S(IGhost* Obj, ObjectAdaptor& List, int t)noexcept {
	Obj->p.y += 5.0f;
	Obj->p.x += sin(float(t) / 20.0f);
	if (RANGE(0, t, 480) && t % 3 == 0) {
		List.FacBul().Bullet(10, 3, Obj->p, 1, -HALF_PI, 4.0f, 0.0f, (t - 50) % 400);
		if (t % 2 == 0)List.FacBul().Bullet(11, 4, Obj->p, 2, -HALF_PI, 4.0f, 0.15f);
	}
}
void End4_0_S(IGhost* Obj, ObjectAdaptor& List)noexcept {
	NormalEnemyEnd(Obj, List);
}


void Init4_1(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(12, 3, White, Big);
	List.FacBul().setDammakuData(13, 5, Orange, Small);
	List.FacBul().setDammakuData(14, 1, Blue, SOval, 0, Sequence);
	Renew.Push(5, [](IBullet& Obj, int t, ObjectAdaptor& List) {
		if (t == 200) {
			Obj.Split(14, 0, 1, 0.0f, 3.0f);
		}
	});
}
void Move4_1(IBoss* Obj, ObjectAdaptor& List, int t)noexcept {
	if ((t - 50) % 800 == 400) {
		Point P = Rand(Rect{ { 110, 110 },{ 480, 300 } });
		Obj->SetMovePoint(P, 40, Ease<Quad>::InOut);
	}
	if (t % 3 == 0) {
		List.FacBul().Bullet(12, 5, Obj->p, 1, float(t) / 20.0f, 0.1f, 0.0f, t/2 % 400);
		if (t % 2 == 0)List.FacBul().Bullet(13, 0, Obj->p, 1, Rand(PI), 5.0f);
	}
}

void Init4_2(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(15, dif(1,2), Yerrow, Big,0,0,BLEND_ADD);
	List.FacBul().setDammakuData(16, 1, Yerrow, Small,0,0,BLEND_ADD);
	Renew.Push(6, [](IBullet& Obj, int t, ObjectAdaptor& List) {
		if (RANGE(10, t, 60))Obj.Force({ 0.0f,0.1f });
	});
}

void Move4_2(IBoss* Obj, ObjectAdaptor& List, int t)noexcept {
	if ((t - 50) % 1600 == 400) {
		Point P = Rand(Rect{ { 110, 110 },{ 480, 300 } });
		Obj->SetMovePoint(P, 40, Ease<Quad>::InOut);
	}
	if (t % 3 == 0) {
		List.FacBul().Bullet(15, 6, Obj->p, 1, float(t) / 20.0f, 0.1f, 0.0f, t / 2 % 200+200);
		List.FacBul().Bullet(16, 6, Obj->p, 1, float(t) / 20.0f, 0.1f, 0.0f, t / 2 % 200+200);
	}

}

void Init5_0(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacEmy().pushData("Uh-ghon", EnemyBack1Hdl, 2800, 50, Boss[3], false, { MoveAppear, Move5_0, Move5_1,Move5_2,Move5_3 });
	List.FacBul().setDammakuData(17, dif(2,3), White, Midium, 0, 0, BLEND_ADD);
	List.FacBul().setDammakuData(18, dif(1,2,3,4), White, Small,0,0,BLEND_ADD);
}

void Move5_0(IBoss* Obj, ObjectAdaptor& List, int t)noexcept {
	if ((t - 50) % 800 == 400) {
		Point P = Rand(Rect{ { 110, 110 },{ 480, 300 } });
		Obj->SetMovePoint(P, 40, Ease<Quad>::InOut);
	}
	if (RANGE(50,( t - 50)%400, 380) && t % 3 == 0) {
		Point cood = Obj->p + Vec2{ float(t) / 20.0f,50.0f,0 };
		List.FacBul().Bullet(17, 1, cood, 1, Rand(PI), 3.1f, 0.0f);
		List.FacBul().Bullet(18, 1, cood, 1, Rand(PI), 3.1f, 0.0f);
	}
}

void Init5_1(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(19, dif(2, 3, 4, 4), White, Midium, 0, 0, BLEND_ADD);
	List.FacBul().setDammakuData(20, dif(2, 3, 4, 4), Orange, Small, 0, 0, BLEND_ADD);
	List.FacBul().setDammakuData(21, 4, Red, Small, 0, 0, BLEND_ADD);
	List.FacBul().setDammakuData(22, dif(1,3,4,6), Black, Huge, 0, 0, BLEND_ADD);
}

void Move5_1(IBoss* Obj, ObjectAdaptor& List, int t)noexcept {
	if ((t - 50) % 800 == 400) {
		Point P = Rand(Rect{ { 110, 110 },{ 480, 300 } });
		Obj->SetMovePoint(P, 40, Ease<Quad>::InOut);
	}
	if (RANGE(50, (t - 50) % 400, 280) && t % 3 == 0) {
		if (difficulty < 3) {
			List.FacBul().Bullet(19, 0, Obj->p + Vec2{ float(t) / 20.0f,150.0f,0 }, 1, Rand(PI), 3.1f, 0.0f);
			List.FacBul().Bullet(20, 0, Obj->p - Vec2{ float(t) / 20.0f,150.0f,0 }, 1, Rand(PI), 3.1f, 0.0f);
		}
		else {
			List.FacBul().Bullet(19, 0, Obj->p + Vec2{ float(t) / 20.0f,150.0f,0 }, 1, Rand(PI), 3.1f, 0.0f);
			List.FacBul().Bullet(20, 0, Obj->p + Vec2{ float(t) / 20.0f + PI2 / 3.0f,150.0f,0 }, 1, Rand(PI), 3.1f, 0.0f);
			List.FacBul().Bullet(21, 0, Obj->p + Vec2{ float(t) / 20.0f + PI2 / 3.0f*2.0f,150.0f,0 }, 1, Rand(PI), 3.1f, 0.0f);
		}
	}
	if (RANGE(310, (t - 50) % 400, 380) && t % dif(7,6,5,4)== 0) {
			List.FacBul().Bullet(22, 0, Obj->p , 1, float(t) / 20.0f, 4.1f, 0.0f);
	}
}

void Init5_2(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(23, 3, White, Midium, 0, 0, BLEND_ADD);
	List.FacBul().setDammakuData(24, 3, White, Big, 0, 0, BLEND_ADD);
	List.FacBul().setDammakuData(25, 3, Yerrow, Big, 0, 0, BLEND_ADD);
	List.FacBul().setDammakuData(26, 2, Yerrow, Huge, 0, 0, BLEND_ADD);
}

void Move5_2(IBoss* Obj, ObjectAdaptor& List, int t)noexcept{
	if ((t - 50) % 800 == 400) {
		Point P = Rand(Rect{ { 110, 110 },{ 480, 300 } });
		Obj->SetMovePoint(P, 40, Ease<Quad>::InOut);
	}
	if (RANGE(10,( t - 50)%600, 290) && t % dif(8,6,4,2) == 0) {
		List.FacBul().Bullet(23, 0, Obj->p + Vec2{ float(t) / 20.0f,50.0f,0 }, 1, Rand(PI), 3.1f, 0.0f);
		List.FacBul().Bullet(24, 0, Obj->p + Vec2{ float(t) / 20.0f,50.0f,0 }, 1, Rand(PI), 3.1f, 0.0f);
	}
	if (RANGE(310, (t - 50) % 600, 590) && t % dif(8, 6, 4, 2) == 0) {
		List.FacBul().Bullet(25, 0, Obj->p + Vec2{ float(-t) / 20.0f,50.0f,0 }, 1, Rand(PI), 3.1f, 0.0f);
		List.FacBul().Bullet(26, 0, Obj->p + Vec2{ float(-t) / 20.0f,50.0f,0 }, 1, Rand(PI), 3.1f, 0.0f);
	}
}

Point cood53; Vec2 speed53;
void Init5_3(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(27, 1, White, Midium, 0, 0, BLEND_ADD);
	List.FacBul().setDammakuData(28,1, White, Midium, 0, 0, BLEND_ADD);
	Renew.Push(7, [](IBullet& Obj, int t, ObjectAdaptor& List) {
		if (RANGE(10, t, 60))Obj.Force({ 0.0f,0.1f });
		if (Obj.isReflected(2, cood53, speed53)) {
			List.FacBul().Bullet(28, 0, cood53, 1, -HALF_PI, dif(1.0f, 2.0f, 3.0f, 4.0f));
			Obj.Kill();
		}
	});
}

void Move5_3(IBoss* Obj, ObjectAdaptor& List, int t)noexcept {
	if ((t - 50) % 800 == 400) {
		Point P = Rand(Rect{ { 110, 110 },{ 480, 300 } });
		Obj->SetMovePoint(P, 40, Ease<Quad>::InOut);
	}
	int T = (t - 50) % 200;
	if (RANGE(0, T, 180) && t % 3 == 0) {
		List.FacBul().Bullet(27, 7, Obj->p + Vec2{ 2.0f*T,Rand(50.0f) }, 1, HALF_PI, 3.1f, 0.0f);
		List.FacBul().Bullet(27, 7, Obj->p - Vec2{ 2.0f*T,Rand(50.0f) }, 1, HALF_PI, 3.1f, 0.0f);
	}
}

void Init5_4(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(30, 1, White, Midium, 0, 0, BLEND_ADD);
	List.FacBul().setDammakuData(31, 1, White, Midium, 0, 0, BLEND_ADD);
}

void Move5_4(IBoss* Obj, ObjectAdaptor& List, int t)noexcept {
	if ((t - 50) % 800 == 400) {
		Point P = Rand(Rect{ { 110, 110 },{ 480, 300 } });
		Obj->SetMovePoint(P, 40, Ease<Quad>::InOut);
	}
	int T = (t - 50) % 200;
	if (RANGE(0, T, 180) && t % 3 == 0) {
		List.FacBul().Bullet(31, 0, Obj->p + Vec2{ 2.0f*T,Rand(50.0f) }, 1, HALF_PI, 3.1f, 0.0f);
		List.FacBul().Bullet(32, 0, Obj->p - Vec2{ 2.0f*T,Rand(50.0f) }, 1, HALF_PI, 3.1f, 0.0f);
	}
}
void setBulletData3(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().clearDammakuData();
	List.FacEmy().clearData();
	Init30(Renew, List);
	Init31(Renew, List);
	Init32(Renew, List);
	Init33(Renew, List);
	Init34(Renew, List);
	Init35(Renew, List);
	Init36(Renew, List);
	Init4_0(Renew, List);
	Init4_0_S(Renew, List);
	Init4_1(Renew, List);
	Init4_2(Renew, List);
	Init5_0(Renew, List);
	Init5_1(Renew, List);
	Init5_2(Renew, List);
	Init5_3(Renew, List);
	Init5_4(Renew, List);
}
