
#include "Enemy4.h"
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
//stage 4
//
//---------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------

void Init40(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(0, 1, Cyan, Midium,0,Aiming);
	List.FacEmy().pushData(Move40,End40, &EnemyAnim[1], 80, 30);
}
void Move40(IGhost* Obj, ObjectAdaptor& List, int t)noexcept {
	if (t == 0)Obj->mSpeed.y = 5.0f;
	else {
		if (RANGE(20, t, 140)) {
			Obj->mSpeed.Rotate(Obj->mFirst.x < 350 ? PI2 / 120.0f : -PI2 / 120.0f);
			if (t % dif(25, 20, 15, 10) == 0) {
			List.FacBul().Bullet(0, 0, Obj->p, dif(3, 5), 0.0f, dif(4.0f, 5.5f), 0.65f);
			}
		}
	}
}
void End40(IGhost* Obj, ObjectAdaptor& List)noexcept {
	NormalEnemyEnd(Obj, List);
}

void Init41(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(1, 1, Purple, Fuda);
	List.FacEmy().pushData(Move41, End41, &EnemyAnim[3],500, 30);
}
void Move41(IGhost* Obj, ObjectAdaptor& List, int t)noexcept {
	if (t <= 90)Obj->mSpeed.y = D_lerp(130.0f, 0, 90, t, Ease<Quad>::Out);
	else if (t == 150) {
		List.FacBul().BulletEmitter(1, 0, &Obj->p, 3, 10, 20, List.FacBul().GetBullettoPlayerAngle(Obj->p), dif(3.5f, 4.5f, 5.0f, 5.5f), 0.0f)->SetDelta(0, 0, 0, 0.3f);
		List.FacBul().BulletEmitter(1, 0, &Obj->p, 3, 10, 20, List.FacBul().GetBullettoPlayerAngle(Obj->p), dif(2.5f, 3.5f, 4.0f, 4.5f), 0.0f)->SetDelta(0, 0, 0, 0.3f);
		List.FacBul().BulletEmitter(1, 0, &Obj->p, 3, 10, 20, List.FacBul().GetBullettoPlayerAngle(Obj->p), dif(1.5f, 2.5f, 3.0f, 3.5f), 0.0f)->SetDelta(0, 0, 0, 0.3f);
	}
	else if (t == 355) {
		List.FacBul().BulletEmitter(1, 0, &Obj->p, 3, 10, 20, List.FacBul().GetBullettoPlayerAngle(Obj->p), dif(3.5f, 4.5f, 5.0f, 5.5f), 0.0f)->SetDelta(0, 0, 0, 0.3f);
		List.FacBul().BulletEmitter(1, 0, &Obj->p, 3, 10, 20, List.FacBul().GetBullettoPlayerAngle(Obj->p), dif(1.5f, 2.5f, 3.0f, 3.5f), 0.0f)->SetDelta(0, 0, 0, 0.3f);
	}
	else if (t >= 355 + 10 * 20 + 30)Obj->mSpeed.y = -2.0f;
}
void End41(IGhost* Obj, ObjectAdaptor& List)noexcept {
	NormalEnemyEnd(Obj, List);
}

void Init42(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(2, dif(5,7,10,12), Red,Big, 0, Aiming);
	List.FacEmy().pushData(Move42, End42, &EnemyAnim[2], 80, 30);
}
void Move42(IGhost* Obj, ObjectAdaptor& List, int t)noexcept {
	if (t <= 30) {
		Obj->mSpeed.y = 2.0f;
		Obj->mSpeed.x = 2.0f;
	}
	else {
		if (RANGE(30, t, 160)) {
			Obj->mSpeed.Rotate(Obj->mFirst.x < 350 ? PI2 / 130.0f : -PI2 / 130.0f);
			if (t % 15 == 0) {
				List.FacBul().Bullet(2, 0, Obj->p, 1, 0.0f, dif(2.0f, 3.5f), 0.3f);
			}
		}
	}
}
void End42(IGhost* Obj, ObjectAdaptor& List)noexcept {
	NormalEnemyEnd(Obj, List);
}

void Init43(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacLez().setLeazerData(0, 1, Cyan, Thin, 100, 0,Aiming);
	List.FacBul().setDammakuData(3, dif(2, 3, 4, 5), Yerrow, Midium);
	//List.FacBul().setDammakuData(4, dif(2,3,4,5), Orange, Small);
	List.FacEmy().pushData(Move43, End43, &EnemyAnim[2], 170, 30);
}
void Move43(IGhost* Obj, ObjectAdaptor& List, int t)noexcept {
	if (t <= 90)Obj->mSpeed.y = D_lerp(130.0f, 0, 90, t, Ease<Quad>::Out);
	else if(RANGE(90,t,280)){
		if (t==100) {
			List.FacLez().Leazer01(0, 0, &Obj->p, 0.0f, dif(1,3,5,7), 0.3f);
		}
		if (RANGE(0, t % 40, 20) && t % 2 == 0) {
			List.FacBul().Bullet(3, 0, Obj->p, 1, float(t) / 55.0f, dif(2.0f,3.0f ,4.0f,5.0f));
		}
	}
	else {
		Obj->mSpeed.y = -2.0f;
	}
}
void End43(IGhost* Obj, ObjectAdaptor& List)noexcept {
	NormalEnemyEnd(Obj, List);
}

void Init44(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(5, 1, Purple, Leaf,0,Aiming);
	List.FacEmy().pushData(Move44, End44, &EnemyAnim[1], 270, 30);
}
void Move44(IGhost* Obj, ObjectAdaptor& List, int t)noexcept {
	if (t <= 30)Obj->mSpeed.y = D_lerp(230.0f, 0, 30, t, Ease<Quad>::Out);
	else {
		if (t % 10 == 0) {
			List.FacBul().Bullet(5, 0, Obj->p, dif(3,5,7,9), Rand(0.2f), dif(3.0f,3.5f,4.0f,5.0f),0.45f);
		}
	}
	Obj->mSpeed.x = Obj->mFirst.x <= 350 ? 2.0f : -2.0f;
}
void End44(IGhost* Obj, ObjectAdaptor& List)noexcept {
	NormalEnemyEnd(Obj, List);
}

void Init45(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(6, 1, Cyan, Big, 0, 0, BLEND_ADD);
	List.FacBul().setDammakuData(7, 1, Blue, Big, 0, 0,BLEND_ADD);
	List.FacEmy().pushData(Move45, End45, &EnemyAnim[0], 500, -1);
}
void Move45(IGhost* Obj, ObjectAdaptor& List, int t)noexcept {
	if (t <= 40) {
		if (t % 3 == 0) {
			List.FacBul().Bullet(Rand_TF(0.5f) ? 6 : 7, 0, Obj->p, 1, Obj->mFirst.x <= 350 ? 0.0f : PI, dif(1.8f, 2.8f, 3.8f, 4.8f));
		}
	}
	else {
		Obj->Kill();
	}
}
void End45(IGhost* Obj, ObjectAdaptor& List)noexcept {}

void Init46(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(8, 1, Purple, Huge, 0, 0, BLEND_ADD);
	List.FacBul().setDammakuData(9, 1, Blue, Huge, 0, 0, BLEND_ADD);
	List.FacEmy().pushData(Move46, End46, &EnemyAnim[0], 500, -1);
}
void Move46(IGhost* Obj, ObjectAdaptor& List, int t)noexcept {
	if (t <= 30) {
		if (t % 5 == 0) {
			List.FacBul().Bullet(Rand_TF(0.5f) ? 8 : 9, 0, Obj->p, 1, Obj->mFirst.y <= 320 ? HALF_PI : -HALF_PI, 3.0f);
		}
	}
	else {
		Obj->Kill();
	}
}
void End46(IGhost* Obj, ObjectAdaptor& List)noexcept {}

//===================================================================================================================
//
//Boss
//
//===================================================================================================================

void Init6_0(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept{
	List.FacEmy().pushData("Hirako Tsukinowa", EnemyBack1Hdl, 3000, 50, Boss[4], false, { MoveAppear, Move6_0, Move6_1,Move6_2,Move6_3,Move6_4,Move6_5,Move6_6});
	List.FacBul().setDammakuData(10, dif(3, 4, 5, 6), Lime, Fuda);
	List.FacBul().setDammakuData(11, dif(3,4,5,6),Green, Fuda);
	Renew.Push(6, [](IBullet& Obj, int t, ObjectAdaptor& List) {
		if(t==10)Obj.Renew(0.0f, dif(2.0f, 3.0f, 4.0f, 5.0f), Sequence);
	});
}
void Move6_0(IBoss* Obj, ObjectAdaptor& List, int t)noexcept{
	if ((t - 50) % 800 == 400) {
		Point P = Rand(Rect{ { 110, 110 },{ 480, 300 } });
		Obj->SetMovePoint(P, 40, Ease<Quad>::InOut);
	}
	if (RANGE(0, (t - 50) % 20, 12)) {
		List.FacBul().Bullet(10, 6, Obj->p, 1, float(t) / 60.0f, 10.0f, 0.0f, 80);
		List.FacBul().Bullet(11, 6, Obj->p, 1, float(-t) / 60.0f, 10.0f, 0.0f, 80);
	}
	if (RANGE(0, (t - 50) % 200, 100)) {
		bulletDeltaTime = 0.5f;
	}
	else {
		bulletDeltaTime = 1.0f;
	}
}

void Init6_1(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(12, dif(6, 8, 10, 12), Blue, Arrow);
	List.FacLez().setLeazerData(6, 1, Orange, Normal, 300, 0, BLEND_ADD);
	Renew.Push(7, [](IBullet& Obj, int t, ObjectAdaptor& List) {
		//Point temp; Vec2 speed;
		//if (Obj.isReflected(13, temp, speed)) {
		//	Obj.SetSpeed(speed);
		//}
		//if (t >= 30)Obj.Rotate({ 350.0f,380.0f }, 0.05f);
	});
	Renew.Push(8, [](IBullet& Obj, int t, ObjectAdaptor& List) {
		//Point temp; Vec2 speed;
		//if (Obj.isReflected(13, temp, speed)) {
	//		Obj.SetSpeed(speed);
	//	}
		//if (t >= 30)Obj.Rotate({ 350.0f,380.0f }, -0.05f);
	});
	List.ObjLRen().Push(1, [](ILeazer& Obj, int t, ObjectAdaptor& List) {
		if (t >= 10)Obj.rotate(dif(.004f, .005f, .006f, .007f));
	});
}
void Move6_1(IBoss* Obj, ObjectAdaptor& List, int t)noexcept {
	if (t - 50 == 60) {
		Obj->SetMovePoint({ 350.0f,380.0f }, 20, Ease<Quad>::Out);
		bulletDeltaTime = 1.0f;
	}
	if (t >= 120) {
		if (t % 30 == 0) {
			List.FacBul().Bullet  (12, 7, Obj->p, 1, Rand(PI), 3.0f);
			List.FacBul().Bullet  (12, 8, Obj->p, 1, Rand(PI), 3.0f);
		}
		if (t % 300 == 0) {
			List.FacLez().Leazer01(6, 1, &Obj->p, Rand(PI), 1);
		}
	}
}

void Init6_2(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept{
	List.FacBul().setDammakuData(13, dif(6, 8, 10, 12), Lime, Fuda);
	List.FacBul().setDammakuData(14, dif(6, 8, 10, 12), Green, Fuda);
	List.FacBul().setDammakuData(15, dif(0, 0, 7, 8), Green, Midium);
}
void Move6_2(IBoss* Obj, ObjectAdaptor& List, int t)noexcept {
	if ((t - 50) % 800 == 400) {
		Point P = Rand(Rect{ { 110, 110 },{ 480, 300 } });
		Obj->SetMovePoint(P, 40, Ease<Quad>::InOut);
	}
	if (t % 4 == 0) {
		if (RANGE(0, (t - 50) % 200, 80)) {
			if (RANGE(0, t % 20, 12)) {
				List.FacBul().Bullet(13, 0, Obj->p, 1, float(t) / 60.0f, 3.0f, 0.0f, 20 + 20 * sin(float(t) / 10.0f));
				List.FacBul().Bullet(13, 0, Obj->p, 1, float(t) / 60.0f, 1.5f, 0.0f, 20 + 20 * sin(float(t) / 10.0f));
				List.FacBul().Bullet(14, 0, Obj->p, 1, float(-t) / 60.0f, 3.0f, 0.0f, 20 + 20 * sin(float(t) / 10.0f));
				List.FacBul().Bullet(14, 0, Obj->p, 1, float(-t) / 60.0f, 1.5f, 0.0f, 20 + 20 * sin(float(t) / 10.0f));
			}
		}
		else if (RANGE(100, (t - 50) % 200, 180)) {
			if (RANGE(0, t % 12, 8)) {
				List.FacBul().Bullet(15, 0, Obj->p, 1, HALF_PI+float(t) / 60.0f, 5.0f, 0.0f);
				List.FacBul().Bullet(15, 0, Obj->p, 1, float(-t) / 60.0f, 5.0f, 0.0f);
			}
		}
	}
}

void Init6_3(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	//List.FacLez().setLeazerData(7, 1, Blue, Thin,0,50);
	List.FacBul().setDammakuData(16, 1, Blue, Big, 320, 0, BLEND_ADD);
	List.FacBul().setDammakuData(17, 1, Blue, Midium, 320, 0, BLEND_ADD);
	List.FacBul().setDammakuData(18, 1, Blue, Small, 320, 0, BLEND_ADD);
	Renew.Push(9, [](IBullet& Obj, int t, ObjectAdaptor& List) {
		Obj.Force(Vec2{ 0.0f,0.045f }*bulletDeltaTime);
		if (t < 0)Obj.Kill();
		//if (t >= 30)Obj.Rotate({ 350.0f,380.0f }, -0.05f);
	});
}
void Move6_3(IBoss* Obj, ObjectAdaptor& List, int t)noexcept {
	if ((t - 50) % 800 == 400) {
		Point P = Rand(Rect{ { 110, 110 },{ 480, 250 } });
		Obj->SetMovePoint(P, 40, Ease<Quad>::InOut);
	}
	/*if (t % 450 == 0) {
	Obj->SetMovePoint({ 880.0f ,200.0f}, 150, Ease<Quad>::In);
	}
	if (t % 450 == 150) {
	Obj->SetMovePoint({370.0f ,240.0f}, 150, Ease<Quad>::In);
	}
	if (t % 450 == 300) {
	Obj->SetMovePoint({ -170.0f ,150.0f }, 150, Ease<Quad>::In);
	}*/
	if (RANGE(0, t % 400, 200) && t % 5 == 0) {
		List.FacBul().Bullet(16, 9, Obj->p, 8, -HALF_PI + 1.0f*sin(float(t) / 20.0f), 4.0f, 0.35f);
		List.FacBul().Bullet(17, 9, Obj->p, 10, -HALF_PI + 1.4f*sin(float(t) / 20.0f), 4.0f, 0.25f);
		List.FacBul().Bullet(18, 9, Obj->p, 15, -HALF_PI + 1.3f*sin(float(t) / 20.0f), 4.0f, 0.15f);
		//List.FacLez().Leazer02(7, 0, Obj->p, 1,float(t) / 50.0f, 6.0f, 0.0f, 80);
	}
	if (RANGE(240, t % 400, 390)) {
		bulletDeltaTime = dif(-0.3f, -0.5f, -0.6f, -0.7f);
	}
	else {
		bulletDeltaTime = 1.0f;
	}
}

void Init6_4(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(19, dif(3, 4, 5, 6), Lime, Fuda);
	List.FacBul().setDammakuData(20, dif(3, 4, 5, 6), Green, Fuda);
}
void Move6_4(IBoss* Obj, ObjectAdaptor& List, int t)noexcept {
	if (t == 5) {
		bulletDeltaTime = 1.0f;
	}
	if ((t - 50) % 800 == 400) {
		Point P = Rand(Rect{ { 110, 110 },{ 480, 300 } });
		Obj->SetMovePoint(P, 40, Ease<Quad>::InOut);
	}
	if (t % 4 == 0) {

		if (RANGE(0, t % 400, 180)) {
			List.FacBul().Bullet(19, 0, Obj->p, 1, float(t) / 60.0f, dif(3.0f, 5.0f), 0.0f, 80);
			List.FacBul().Bullet(20, 0, Obj->p, 1, float(t) / 60.0f, dif(2.5f, 4.5f), 0.0f, 80);
			List.FacBul().Bullet(19, 0, Obj->p, 1, float(t) / 60.0f, dif(2.0f, 4.0f), 0.0f, 80);
			//List.FacBul().Bullet(20, 0, Obj->p, 1, float(t) / 60.0f, dif(1.0f, 2.0f), 0.0f, 80);
		}
		else if (RANGE(200, t % 400, 380)) {
			List.FacBul().Bullet(19, 0, Obj->p, 1, float(-t) / 60.0f, dif(3.0f, 5.0f), 0.0f, 80);
			List.FacBul().Bullet(20, 0, Obj->p, 1, float(-t) / 60.0f, dif(2.5f, 4.5f), 0.0f, 80);
			List.FacBul().Bullet(19, 0, Obj->p, 1, float(-t) / 60.0f, dif(2.0f, 4.0f), 0.0f, 80);
			//List.FacBul().Bullet(20, 0, Obj->p, 1, float(-t) / 60.0f, dif(1.0f, 2.0f), 0.0f, 80);
		}
	}
}

void Init6_5(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(21, 10, Green, Small);
	List.FacBul().setDammakuData(22, 1, Cyan, Big,0,Aiming);
}
void Move6_5(IBoss* Obj, ObjectAdaptor& List, int t)noexcept {

	if ((t - 50) % 800 == 400) {
		Point P = Rand(Rect{ { 110, 110 },{ 480, 300 } });
		Obj->SetMovePoint(P, 40, Ease<Quad>::InOut);
	}
	if (t % 4 == 0) {
		List.FacBul().Bullet(21, 0, Point{ 350.0f,370.0f }, 1, float(t) / 10.0f, dif(3.0f, 5.0f), 0.0f, lerp(300, 200, 30, 200, t, Ease<Liner>::In));
	}
	if (t % 10 == 0) {
		List.FacBul().Bullet(22, 0, Obj->p, 3, 0.0f, dif(3.0f, 5.0f), 0.0f, 25);
	}
}
void Init6_6(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(23, 1, Green, Big);
	List.FacBul().setDammakuData(24, 1, Cyan, Big, 0, Aiming);
	List.FacLez().setLeazerData(10, 1, Orange, Thin, 300,30,0, BLEND_ADD);
}
void Move6_6(IBoss* Obj, ObjectAdaptor& List, int t)noexcept {

	if ((t - 50) % 800 == 400) {
		Point P = Rand(Rect{ { 110, 110 },{ 480, 300 } });
		Obj->SetMovePoint(P, 40, Ease<Quad>::InOut);
	}
	if (t % 4 == 0) {
		List.FacBul().Bullet(21, 0, Point{ 350.0f,370.0f }, 1, float(t) / 10.0f, dif(3.0f, 5.0f), 0.0f, 250);
		List.FacLez().Leazer02(10, 0, Obj->p, 1, float(t) / 10.0f, dif(3.0f, 5.0f), 0.0f, 250);
	}
	if (t % 10 == 0) {
		List.FacBul().Bullet(22, 0, Obj->p, 3, 0.0f, dif(3.0f, 5.0f), 0.0f, 25);
	}
}

void setBulletData4(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {

	List.FacBul().clearDammakuData();
	List.FacEmy().clearData();
	Init40(Renew, List);
	Init41(Renew, List);
	Init42(Renew, List);
	Init43(Renew, List);
	Init44(Renew, List);
	Init45(Renew, List);
	Init46(Renew, List);
	Init6_0(Renew, List);
	Init6_1(Renew, List);
	Init6_2(Renew, List);
	Init6_3(Renew, List);
	Init6_4(Renew, List);
	Init6_5(Renew, List);
	Init6_6(Renew, List);
}
