
#include "Enemy5.h"

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

void Init50(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept{
	List.FacBul().setDammakuData(0, dif(12,14,16,18), Cyan, Leaf);
	List.FacEmy().pushData(Move50, End50, &EnemyAnim[1], 80, 30);
}
void Move50(IGhost* Obj, ObjectAdaptor& List, int t)noexcept {
	if (t <= 90)Obj->mSpeed.y = D_lerp(Obj->mFirst.y <= 380 ? 430.0f : -430.0f, 0, 90, t, Ease<Quad>::Out);
	else {
		if (RANGE(100, t, 340)) {
			if (t % dif(20, 15, 10, 8) == 0) {
				List.FacBul().Bullet(0, 0, Obj->p, 1, 0.0f, dif(4.0f, 5.5f));
			}
		}
		Obj->mSpeed.y = Obj->mFirst.y <= 380 ? -1.0f : 1.0f;
	}
}
void End50(IGhost* Obj, ObjectAdaptor& List)noexcept{
	NormalEnemyEnd(Obj, List);
}

void Init51(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(1, dif(1, 3, 5, 5), Red, Fire, 0, Aiming);
	List.FacEmy().pushData(Move51, End51, &EnemyAnim[1], 300, 30);
}
void Move51(IGhost* Obj, ObjectAdaptor& List, int t)noexcept {
	if (t == 2) {
		Obj->mSpeed = { Obj->mFirst.x <= 350 ? 3.0f : -3.0f,1.0f };
	}
	else {
		if (t % dif(80, 60, 40, 20) == 0) {
			List.FacBul().Bullet(1, 0, Obj->p, 1, 0.0f, dif(4.0f, 5.5f));
		}
	}
}
void End51(IGhost* Obj, ObjectAdaptor& List)noexcept{
	NormalEnemyEnd(Obj, List);
}

void Init52(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {}
void Move52(IGhost* Obj, ObjectAdaptor& List, int t)noexcept{}
void End52(IGhost* Obj, ObjectAdaptor& List)noexcept		{}
void Init53(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {}
void Move53(IGhost* Obj, ObjectAdaptor& List, int t)noexcept{}
void End53(IGhost* Obj, ObjectAdaptor& List)noexcept		{}
void Init54(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {}
void Move54(IGhost* Obj, ObjectAdaptor& List, int t)noexcept{}
void End54(IGhost* Obj, ObjectAdaptor& List)noexcept	{}
void Init55(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {}
void Move55(IGhost* Obj, ObjectAdaptor& List, int t)noexcept{}
void End55(IGhost* Obj, ObjectAdaptor& List)noexcept		{}
void Init56(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {}
void Move56(IGhost* Obj, ObjectAdaptor& List, int t)noexcept{}
void End56(IGhost* Obj, ObjectAdaptor& List)noexcept	{}

//===================================================================================================================
//
//Boss
//
//===================================================================================================================

void Init7_0(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacEmy().pushData("Hirako Tsukinowa", EnemyBack1Hdl, 3000, 50, Boss[4], false, { MoveAppear, Move7_0, Move7_1});
	List.FacBul().setDammakuData(9, 1, Red, dif(Midium,Big),0,Aiming);
	List.FacBul().setDammakuData(10, dif(3, 4, 5, 6), Lime, Fuda);
	List.FacBul().setDammakuData(11, dif(3, 4, 5, 6), Green, Fuda);
}
void Move7_0(IBoss* Obj, ObjectAdaptor& List, int t)noexcept {
	if ((t - 50) % 800 == 400) {
		Point P = Rand(Rect{ { 110, 110 },{ 480, 300 } });
		Obj->SetMovePoint(P, 40, Ease<Quad>::InOut);
	}
	if (RANGE(0, (t - 50) % 20, 12) && t % 4 == 0) {
		List.FacBul().Bullet(10, 0, Obj->p, 1, float(t) / 60.0f, dif(2.0f,3.0f,4.0f,5.0f), 0.0f, 80);
		List.FacBul().Bullet(11, 0, Obj->p, 1, float(-t) / 60.0f, dif(2.0f, 3.0f, 4.0f, 5.0f), 0.0f, 80);
	}
	if (t%dif(60, 40, 20, 10)==0) {
		List.FacBul().Bullet(9, 0, Obj->p, 1, 0.0f, dif(1.0f,2.0f,3.0f,4.0f), 0.0f, 80);
	}
}
void Init7_1(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(10, dif(3, 4, 5, 6), Lime, Fuda);
	List.FacBul().setDammakuData(11, dif(3, 4, 5, 6), Green, Fuda);
}
void Move7_1(IBoss* Obj, ObjectAdaptor& List, int t)noexcept {
	if (t == 30) {
		Point P = { 350.0f,370.0f };
		Obj->SetMovePoint(P, 40, Ease<Quad>::InOut);
	}
	if (RANGE(0, (t - 50) % 20, 12)) {
		List.FacBul().Bullet(10,0, Obj->p, 1, float(t) / 60.0f, 5.0f, 0.0f, 80);
		List.FacBul().Bullet(11,0, Obj->p, 1, float(-t) / 60.0f, 5.0f, 0.0f, 80);
	}							
}

void Init8_0(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacEmy().pushData("Aki Yonaga", EnemyBack1Hdl, 3000, 50, Boss[5], false, { MoveAppear, Move8_0, Move8_1,Move8_2,Move8_3,Move8_4 ,Move8_5 ,Move8_6 ,Move8_7 ,Move8_8 });
	List.FacBul().setDammakuData(12, 1, Yerrow, Huge);
	List.FacBul().setDammakuData(13, dif(20, 30, 40, 50), Red, Midium,0,Aiming);
}
void Move8_0(IBoss* Obj, ObjectAdaptor& List, int t)noexcept{
	if ((t - 50) % 800 == 400) {
		Point P = Rand(Rect{ { 110, 110 },{ 480, 300 } });
		Obj->SetMovePoint(P, 40, Ease<Quad>::InOut);
	}
	if (RANGE(0, (t - 50) % 100, 40)) {
		int b = dif(30, 18, 14, 10);
		if (t%b== 0) {
			for (int i = 0; i < 8; i++)
				List.FacBul().Bullet(12, 0, { i*128.0f,0.0f }, 1, HALF_PI, 3.0f);
		}
	}
	else {
		if (t % 20 == 0) {
			List.FacBul().Bullet(13, 0, Obj->p, 1, 0.0f, dif(3.0f,4.0f,5.0f,5.5f));
		}
	}
}
void Init8_1(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(14, 1, Yerrow, Gem);
	List.FacBul().setDammakuData(15, 1, Orange, Gem);
	List.FacBul().setDammakuData(16, 1, Red, Gem);
	List.FacBul().setDammakuData(17, dif(20, 35, 45, 55), Red, Midium, 0, Aiming);
}
void Move8_1(IBoss* Obj, ObjectAdaptor& List, int t)noexcept {
	if ((t - 50) % 400 == 0) {
		Point P = Rand(Rect{ { 110, 110 },{ 480, 300 } });
		Obj->SetMovePoint(P, 40, Ease<Quad>::InOut);
	}
	int b = dif(40, 35, 30, 25);
	if (t%b == 0) {
		List.FacBul().Bullet(14 + Rand(0, 2), 0, { Rand(50.0f,650.0f),0.0f }, 1, HALF_PI, 3.0f);
	}
	if (t % 20 == 0) {
		List.FacBul().Bullet(17, 0, Obj->p, 1, 0.0f, dif(1.0f, 1.5f, 2.0f, 2.5f));
	}
}
void Init8_2(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(18, 1, Blue, Gem);
	List.FacBul().setDammakuData(19, dif(2, 3, 3, 4), Cyan, Huge, 0, Aiming, BLEND_ADD);
	List.FacBul().setDammakuData(20, dif(2, 3, 3, 4), Blue, Midium, 0, Aiming,BLEND_ADD);
	List.FacBul().setDammakuData(21, dif(2, 3, 3, 4), Blue, Big, 0, Aiming, BLEND_ADD);
	Renew.Push(6, [](IBullet& Obj, int t, ObjectAdaptor& List) {
		if (t == 60) {
			Obj.Split(19, 0, dif(1,2), Rand(0.1f), dif(1.0f, 2.0f), 0.3f, true);
			Obj.Split(19, 0, dif(1,2), Rand(0.1f), dif(0.5f, 2.5f), 0.3f, true);
			Obj.Split(20, 0, dif(1,2), Rand(0.1f), dif(3.0f, 4.0f), 0.3f, true);
			Obj.Split(20, 0, dif(1,2), Rand(0.1f), dif(2.5f, 4.5f), 0.3f, true);
			Obj.Split(20, 0, dif(1,2), Rand(0.1f), dif(2.0f, 4.0f), 0.3f, true);
			Obj.Split(21, 0, dif(1,2), Rand(0.1f), dif(2.0f, 4.0f), 0.3f, true);
			Obj.Split(21, 0, dif(1,2), Rand(0.1f), dif(1.0f, 3.5f), 0.3f);
		}
	});
}
void Move8_2(IBoss* Obj, ObjectAdaptor& List, int t)noexcept{
	if ((t - 50) % 400 == 0) {
		Point P = Rand(Rect{ { 110, 110 },{ 480, 300 } });
		Obj->SetMovePoint(P, 40, Ease<Quad>::InOut);
	}
	int b = dif(50, 40, 35, 30);
	if (t%b == 0) {
		List.FacBul().Bullet(18, 6, { Rand(50.0f,650.0f),0.0f }, 1, HALF_PI, 3.0f);
	}
}
void Init8_3(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(22, dif(10, 20, 30, 40), Red, Midium);
	List.FacBul().setDammakuData(23, dif(5, 7, 9, 11), Blue, Big);
	Renew.Push(17, [](IBullet& Obj, int t, ObjectAdaptor& List) {
	});
}
void Move8_3(IBoss* Obj, ObjectAdaptor& List, int t)noexcept{
	if (t == 5) {
		Obj->SetMovePoint({Obj->p.x,-1000.0f}, 40, Ease<Quad>::InOut);
	}
	int b = dif(30, 18, 14, 10);
	if (t%b == 0) {
		if (t <= 14 * 60) {
			List.FacBul().Bullet(22, 0, { 350.0f,330.0f }, 1, float(t) / dif(30.0f,25.0f,20.0f,15.0f), 3.0f);
		}
		else if (t <= 25 * 60) {
			List.FacBul().Bullet(23, 0, { 350.0f,330.0f }, 1, float(-t) / dif(30.0f, 25.0f, 20.0f, 15.0f), 3.0f);
			if (t>=20*60&&t % dif(60,45,30,30) == 0) {
				List.FacBul().Bullet(18, 0, { Rand(50.0f,600.0f),30.0f }, 1, HALF_PI, 3.0f);
			}
		}
		else {
			Obj->MoveNext();
		}
	}
}
void Init8_4(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(24, 1, Red, Huge);
	List.FacBul().setDammakuData(25, 1, Yerrow, Huge);
	List.FacBul().setDammakuData(26, 1, Green, Huge);
	List.FacBul().setDammakuData(27, 1, Blue, Huge);

	List.FacBul().setDammakuData(28, 1, White, Midium);

	Renew.Push(7, [](IBullet& Obj, int t, ObjectAdaptor& List) {
		if (t %2== 0) {
			Obj.Split(28, 8, 1, 0.0f, 0.0f,0.0f,true);
		}
	});
	Renew.Push(8, [](IBullet& Obj, int t, ObjectAdaptor& List) {
		if (t == dif(15,20,25,30)) {
			Obj.Kill();
		}
	});
}
void Move8_4(IBoss* Obj, ObjectAdaptor& List, int t)noexcept {
	if ((t - 50) % 400 == 0) {
		Point P = Rand(Rect{ { 110, 110 },{ 480, 300 } });
		Obj->SetMovePoint(P, 40, Ease<Quad>::InOut);
	}
	if (t%dif(10, 9, 8, 6) == 0) {
		List.FacBul().Bullet(24+Rand(0,3), 7, { Rand(30.0f,600.0f),30.0f }, 1, HALF_PI + Rand(0.1f), dif(3.0f, 5.0f, 7.0f, 7.0f));
	}
}

void Init8_5(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	static Vec2 speed;
	static Point cood;
	List.FacBul().setDammakuData(29, 1, Blue, Gem);
	List.FacBul().setDammakuData(30, dif(3,5,7,9), Cyan, Small);

	Renew.Push(9, [](IBullet& Obj, int t, ObjectAdaptor& List) {
		if (t % 4 == 0) {
			Obj.Split(30, 0, 1, float(t)/20.0f, 3.0f, 0.0f, true);
		}
		if (Obj.isReflected(15, cood, speed)) {
			Obj.SetSpeed(speed);
		}
		if(t>280){
			Obj.Kill();
		}
	});
}
void Move8_5(IBoss* Obj, ObjectAdaptor& List, int t)noexcept{
	if ((t - 50) % 400 == 0) {
		Point P = Rand(Rect{ { 110, 110 },{ 480, 300 } });
		Obj->SetMovePoint(P, 40, Ease<Quad>::InOut);
	}
	if (t % 300 == 0) {
		List.FacBul().Bullet(29, 9,Obj->p, 1, Rand(PI), 3.0f,0.0f,60);
	}
}
void Init8_6(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(31, 1, White, Gem);
	List.FacBul().setDammakuData(32, 1, Black, Gem);
	List.FacBul().setDammakuData(33, dif(1,2,2,3), White, Midium,0,0,BLEND_ADD);
	List.FacBul().setDammakuData(34, dif(1,2), Black, Huge);

	static Vec2 speed;
	static Point cood;
	static int afterstopped[2] = { 0,0 };
	static bool stopped[2] = { false,false };
	Renew.Push(10, [](IBullet& Obj, int t, ObjectAdaptor& List) {
		if (t % 4 == 0) {
			Obj.Split(33, 0, 1, float(t) / 20.0f, 3.0f, 0.0f, true);
		}
		if (Obj.isReflected(15, cood, speed)) {
			Obj.SetSpeed(Vec2::Zero);
			stopped[0] = true;
		}
		if (stopped[0]) {
			++afterstopped[0];
			if (afterstopped[0] > 30) {
				Obj.SetSpeed({ List.FacBul().GetBullettoPlayerAngle(Obj.p),dif(3.0f,5.0f),0 });
				afterstopped[0] = 0;
				stopped[0] = false;
			}
		}
		if (t>280) {
			Obj.Kill();
		}
	});
	Renew.Push(11, [](IBullet& Obj, int t, ObjectAdaptor& List) {
		if (t % 12 == 0) {
			Obj.Split(34, 0, 1, float(t) / 20.0f, 3.0f, 0.0f, true);
		}
		if (Obj.isReflected(15, cood, speed)) {
			Obj.SetSpeed(Vec2::Zero);
			stopped[1] = true;
		}
		if (stopped[1]) {
			++afterstopped[1];
			if (afterstopped[1] > 30) {
				Obj.SetSpeed({ List.FacBul().GetBullettoPlayerAngle(Obj.p),dif(3.0f,5.0f),0 });
				afterstopped[1] = 0;
				stopped[1] = false;
			}
		}
		if (t>280) {
			Obj.Kill();
		}
	});

}
void Move8_6(IBoss* Obj, ObjectAdaptor& List, int t)noexcept{
	if ((t - 50) % 400 == 0) {
		Point P = Rand(Rect{ { 110, 110 },{ 480, 300 } });
		Obj->SetMovePoint(P, 40, Ease<Quad>::InOut);
	}
	if (t % 300 == 0) {
		List.FacBul().Bullet(31, 10, Obj->p, 1, Rand(PI), dif(3.0f, 5.0f), 0.0f, 60);
	}
	if (t % 300 == 150) {
		List.FacBul().Bullet(32, 11, Obj->p, 1, Rand(PI), dif(3.0f, 5.0f), 0.0f, 60);
	}
}
void Init8_7(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacLez().setLeazerData(6, 1, Red, Thin, 180, 0, BLEND_ADD);
	List.FacBul().setDammakuData(35, 1, White,Fuda,0,Aiming);
}
void Move8_7(IBoss* Obj, ObjectAdaptor& List, int t)noexcept{
	static Point leazer[6];
	if ((t - 50) % 400 == 0) {
		Point P = Rand(Rect{ { 110, 110 },{ 480, 300 } });
		Obj->SetMovePoint(P, 40, Ease<Quad>::InOut);
	}
	for (int i = 0; i < 6; i++) {
		leazer[i] = {float((t + i * 100 )%600)+40.0f,500.0f+180.0f*sin(float(t + i * 100)/50.0f)};
	}
	if (t % 200 == 0) {
		for (int i = 0; i < 6; ++i) {
			List.FacLez().Leazer01(6, 0, &leazer[i], HALF_PI, 1);
		}
	}
	if (t%dif(30, 20, 10, 5)==0) {
		List.FacBul().Bullet(35, 0, Obj->p, 1, 0.0f, dif(3.0f, 5.0f));
	}
}
void Init8_8(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacBul().setDammakuData(40, 1, Red, Gem);
	List.FacBul().setDammakuData(41, 1, Orange, Gem);
	List.FacBul().setDammakuData(42, 1, Yerrow, Gem);
	List.FacBul().setDammakuData(43, 1, Lime, Gem);
	List.FacBul().setDammakuData(44, 1, Green, Gem);
	List.FacBul().setDammakuData(45, 1, Cyan, Gem);
	List.FacBul().setDammakuData(46, 1, Blue, Gem);
	List.FacBul().setDammakuData(47, 1, Purple, Gem);
	List.FacBul().setDammakuData(48, dif(2,3,4,5), Orange, LOval);
	static Vec2 speed;
	static Point cood;
	Renew.Push(15, [](IBullet& Obj, int t, ObjectAdaptor& List) {
		if (Obj.isReflected(15, cood, speed)) {
			Obj.Split(40 + Rand(0, 7), 0, 1, speed.Angle(), 3.0f);
		}
	});
}
void Move8_8(IBoss* Obj, ObjectAdaptor& List, int t)noexcept{

	if ((t - 50) % 200 == 0) {
		Point P = Rand(Rect{ { 110, 110 },{ 480, 300 } });
		Obj->SetMovePoint(P, 40, Ease<Quad>::InOut);
	}
	if (RANGE(0, t % 300, 200)) {
		if (t % 60 == 0) {
			for (int i = 0; i < 8; i++) {
				List.FacBul().Bullet(40 + i, Rand_TF(0.5f) ? 0 : 15, Obj->p, 1, PI2 / 8.0f*float(i), dif(3.0f, 4.0f, 5.0f, 6.0f), 0.0f, 100);
			}
		}
	}
	else if(RANGE(220,t%300,290)){
		List.FacBul().Bullet(48, 0, Obj->p, 1,Rand(PI), dif(3.5f, 4.5f, 5.5f, 6.5f), 0.0f, 100);
	}
}


void setBulletData5(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {

	List.FacBul().clearDammakuData();
	List.FacEmy().clearData();
	Init50(Renew, List);
	Init51(Renew, List);
	Init52(Renew, List);
	Init53(Renew, List);
	Init54(Renew, List);
	Init55(Renew, List);
	Init56(Renew, List);
	Init7_0(Renew, List);
	Init7_1(Renew, List);
	Init8_0(Renew, List);
	Init8_1(Renew, List);
	Init8_2(Renew, List);
	Init8_3(Renew, List);
	Init8_4(Renew, List);
	Init8_5(Renew, List);
	Init8_6(Renew, List);
	Init8_7(Renew, List);
	Init8_8(Renew, List);
}
