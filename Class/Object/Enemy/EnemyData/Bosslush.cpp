
#include "Bosslush.h"
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

void InitEX_0(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacEmy().pushData("Azami Yotsuya", EnemyBack1Hdl, 2800, 50, Boss[0], false, { MoveAppear,MoveEX_0 });
	List.FacBul().setDammakuData(0, 1, Purple, Midium, 0, 0, BLEND_ADD);
	List.FacBul().setDammakuData(1, 1, Purple, Big, 0, Sequence, BLEND_ADD);
	List.FacBul().setDammakuData(2, 4, Cyan, Fuda, 0, Sequence, BLEND_SUB);
	Renew.Push(1, [](IBullet& Obj, int t, ObjectAdaptor& List) {
		if (t < 60) {
			Obj.Accel(-0.1f);
		}
		else if (RANGE(60, t, 120)&&t%2==0) {
			Obj.Split(1, 0, 1, 0.0f, -10.0f, 0.0f, true);
		}
		else if (t == 120) {
			Obj.Kill();
		}
	});
	Renew.Push(2, [](IBullet& Obj, int t, ObjectAdaptor& List) {if (t < 100&&t%3!=0) Obj.Turn(0.008f); });
	Renew.Push(3, [](IBullet& Obj, int t, ObjectAdaptor& List) {if (t < 100&&t%3!=0) Obj.Turn(-0.008f);});

}
void MoveEX_0(IBoss* Obj, ObjectAdaptor& List, int t)noexcept {
	if (t == 5) {
		Obj->SetMovePoint(Point{350,100}, 70, Ease<Quad>::InOut);
	}
	if ((t - 50) % 500 == 10) {
		List.FacBul().BulletEmitter(0, 1, &Obj->p, 1, 1, 100,0.0f, 5.0f)->SetDelta(0,0.1f);
	}
	if ((t - 50) % 500 == 260) {
		List.FacBul().BulletEmitter(0, 1, &Obj->p, 1, 1, 100, 0.0f, 5.0f)->SetDelta(0, -0.1f);
	}
	if ((t - 50) % 240 == 0) {
		List.FacBul().BulletEmitter(2, 2, &Obj->p, 1, 1, 80, 0.0f, 5.0f)->SetDelta(0, 0.1f);
	}
	if ((t - 50) % 240 == 10) {
		List.FacBul().BulletEmitter(2, 2, &Obj->p, 1, 1, 80, 0.0f, 5.0f, 0.0f, 10)->SetDelta(0, 0.1f);
	}
	if ((t - 50) % 240 == 120) {
		List.FacBul().BulletEmitter(2, 3, &Obj->p, 1, 1, 80, 0.1f*80.0f, 5.0f)->SetDelta(0, -0.1f);
	}
	if ((t - 50) % 240 == 130) {
		List.FacBul().BulletEmitter(2, 3, &Obj->p, 1, 1, 80, 0.1f*80.0f, 5.0f, 0.0f, 10)->SetDelta(0, -0.1f);
	}
}

void InitEX_1(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacEmy().pushData("Kikyo Yamabuki", EnemyBack1Hdl, 2800, 50, Boss[1], false, { MoveAppear,MoveEX_1 });
	List.FacBul().setDammakuData(10, 6,Lime, Midium);
	List.FacBul().setDammakuData(11, 5, Purple, SOval, 0, Sequence, BLEND_ADD);
	Renew.Push(11, [](IBullet& Obj, int t, ObjectAdaptor& List) {if (t == 60) Obj.Kill();});
	Renew.Push(12, [](IBullet& Obj, int t, ObjectAdaptor& List) {if (t == 60) Obj.Accel(5.0f); });
}
void MoveEX_1(IBoss* Obj, ObjectAdaptor& List, int t)noexcept {
	if ((t - 50) % 120 == 0)Obj->SetMovePoint(Rand(Rect{ { 70, 70 },{ 500, 230 } }), 70, Ease<Quad>::InOut);
	if ((t - 50) % 60 == 0) {
		List.FacBul().BulletEmitter(10, 11, &Obj->p, 1, 2, 65, Rand(PI), 0.01f)->SetDelta(0, 0.01f, 0.0f, 0.0f, 10);
	}
	if ((t - 50) % 60 == 30) {
		List.FacBul().BulletEmitter(10, 11, &Obj->p, 1, 2, 65, Rand(PI), 0.01f)->SetDelta(0, -0.01f, 0.0f, 0.0f, 10);
	}
	if ((t - 50) % 5 == 0) {
		List.FacBul().Bullet(11, 12, Rand(Rect{ { 70, 70 },{ 500, 230 } }), 1, Rand(PI), 0.01f);
	}
}

void InitEX_2(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacEmy().pushData("Heigo Yanagikawa", EnemyBack1Hdl, 2800, 50, Boss[2], false, { MoveAppear,MoveEX_2 });

	List.FacBul().setDammakuData(20, 1, Red, Huge, 0, 0);
	List.FacBul().setDammakuData(21, 15, Orange, Huge, 0, Sequence);
	List.FacBul().setDammakuData(22, 15, Red, Midium, 0, 0, BLEND_SUB, 6);
	Renew.Push(21, [](IBullet& Obj, int t, ObjectAdaptor& List) {if (t == 60) Obj.Kill(); });
	Renew.Push(22, [](IBullet& Obj, int t, ObjectAdaptor& List) {
		if (RANGE(0,t,20)) Obj.Accel(0.1f);
	});
}
void MoveEX_2(IBoss* Obj, ObjectAdaptor& List, int t)noexcept {
	if ((t - 50) % 700 == 0)Obj->SetMovePoint(Rand(Rect{ { 70, 70 },{ 660, 230 } }), 70, Ease<Quad>::InOut);
	static Rect ex2rect = { { 70, 70 },{ 500, 230 } };
	if ((t - 50) % 500 == 0) {
		List.FacBul().BulletEmitter(20, 22, &ex2rect, 1, 8, 10, Rand(PI), 0.3f)->SetDelta(0, 0.1f,0,0,2);
	}
	if ((t - 50) % 500 == 180) {
		List.FacBul().BulletEmitter(21, 0, &Obj->p, 1, 15, 10, Rand(PI), 5.0f)->SetDelta(0, 0.1f, 0, 0, 2);
	}
	if (RANGE(10,(t - 50) % 500,200) ) {
		List.FacBul().BulletForeach(20, [](IBullet& Obj, int t, ObjectAdaptor& List) {
			Obj.Renew(0.0f,4.0f,Aiming);
		});
	}
	if ((t - 50) % 500 == 340) {
		List.FacBul().BulletEmitter(22, 22, &Obj->p, 1, 4, 10, 0.0f, 5.0f, 0, 40)->SetDelta(0, -0.07f, 0, 0);
		List.FacBul().BulletEmitter(22, 22, &Obj->p, 1, 4, 10, 0.0f, 5.0f, 0, 33)->SetDelta(0, -0.07f, 0, 0);
		List.FacBul().BulletEmitter(22, 22, &Obj->p, 1, 4, 10, 0.0f, 5.0f, 0, 26)->SetDelta(0, -0.07f, 0, 0);
		List.FacBul().BulletEmitter(22, 22, &Obj->p, 1, 4, 10, 0.0f, 5.0f, 0, 19)->SetDelta(0, -0.07f, 0, 0);
		List.FacBul().BulletEmitter(22, 22, &Obj->p, 1, 4, 10, 0.0f, 5.0f, 0, 12)->SetDelta(0, -0.07f, 0, 0);
	}
	if ((t - 50) % 500 == 420) {
		List.FacBul().BulletEmitter(22, 22, &Obj->p, 1, 4, 10, 0.0f, 5.0f, 0, 40)->SetDelta(0, 0.07f, 0, 0);
		List.FacBul().BulletEmitter(22, 22, &Obj->p, 1, 4, 10, 0.0f, 5.0f, 0, 33)->SetDelta(0, 0.07f, 0, 0);
		List.FacBul().BulletEmitter(22, 22, &Obj->p, 1, 4, 10, 0.0f, 5.0f, 0, 26)->SetDelta(0, 0.07f, 0, 0);
		List.FacBul().BulletEmitter(22, 22, &Obj->p, 1, 4, 10, 0.0f, 5.0f, 0, 19)->SetDelta(0, 0.07f, 0, 0);
		List.FacBul().BulletEmitter(22, 22, &Obj->p, 1, 4, 10, 0.0f, 5.0f, 0, 12)->SetDelta(0, 0.07f, 0, 0);
	}
}

void InitEX_3(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacEmy().pushData("Uhgohn", EnemyBack1Hdl, 3000, 50, Boss[3], false, { MoveAppear,MoveEX_3 });
	List.FacBul().setDammakuData(30, 20, White, Small, 0, 0, BLEND_ADD, 4);
	List.FacBul().setDammakuData(31, 1, Red, Big, 0, Aiming, BLEND_ADD);
	Renew.Push(31, [](IBullet& Obj, int t, ObjectAdaptor& List) {if (t == 90) Obj.Kill(); });
	Renew.Push(32, [](IBullet& Obj, int t, ObjectAdaptor& List) {if (t == 120) Obj.Accel(5.0f); });
}

void MoveEX_3(IBoss* Obj, ObjectAdaptor& List, int t)noexcept {
	static Point Cood[10];
	if (t == 5) {
		Obj->SetMovePoint({ 350,230 }, 70, Ease<Quad>::InOut);
	}
	if ((t - 50) % 350 == 0) {
		for (int i = 0; i < 10; i++) {
			Cood[i] = { 50.0f + float(i * 60),70.0f };
			List.FacBul().BulletEmitter(30, 31, &Cood[i],1,25,15,HALF_PI/2,0.1f,0.0f,Rand(0,5))->SetDelta(0,0,0,0,50);
		}
	}
	if ((t - 50) % 20 == 0) {
		Point rnd = Rand(Rect{ { 70, 70 },{ 500, 230 } });
		for (int i = 0; i < 10; i++)
			List.FacBul().Bullet(31, 0, rnd, 1, 0.0f, 5.0f, 0, i * 8);
	}
}

void InitEX_4(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacEmy().pushData("Hirako Tsukinowa", EnemyBack1Hdl, 3200, 50, Boss[4], false, { MoveAppear,MoveEX_4 });
	List.FacBul().setDammakuData(40, 20, Blue, Midium, 0, 0, BLEND_ADD);
	List.FacBul().setDammakuData(41, 1, Blue, Big, 0, 0, BLEND_ADD);
	List.FacBul().setDammakuData(42,1, Blue, SOval, 0, Aiming, BLEND_ADD);
	List.FacLez().setLeazerData(40, 30, Purple, Thin, 60);
	Renew.Push(41, [](IBullet& Obj, int t, ObjectAdaptor& List) {
		Point cood; Vec2 speed;
		if (Obj.isReflected(13, cood, speed)) {
			if (Rand_TF(0.08f)) {
				Obj.Split(42, 42, 1, 0.0f, 0.0f);
			}
			else {
				Obj.Kill();
			}
		}
	});
	Renew.Push(42, [](IBullet& Obj, int t, ObjectAdaptor& List) {
		if (t == 330) {
			float angle = List.FacBul().GetBullettoPlayerAngle(Obj.p);
			Obj.SetSpeed({ angle,3.5f,0 });
		}
	});
	List.ObjLRen().Push(41, [](ILeazer& obj,int t,ObjectAdaptor& adaptor){
		if(RANGE(0,t,100))obj.rotate(0.003f);
	});
	List.ObjLRen().Push(42, [](ILeazer& obj, int t, ObjectAdaptor& adaptor) {
		if (RANGE(0, t, 100))obj.rotate(-0.003f);
	});
}
void MoveEX_4(IBoss* Obj, ObjectAdaptor& List, int t)noexcept {

	if (RANGE(0,(t-50)%1000,200)&&t % 3 == 0) {
		List.FacBul().Bullet(40, 41, Obj->p, 1, sin(float(t)/50.0f)+cos(float(t)/40.0f),3.0f, 0.1f,30);
	}
	if ((t - 50) % 1000 == 600) {
		List.FacLez().Leazer01(40, 41, &Obj->p, 0.0f, 1);
	}
	if ((t - 50) % 1000 == 800) {
		List.FacLez().Leazer01(40, 42, &Obj->p, 0.0f, 1);
	}
}


void InitEX_5(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {
	List.FacEmy().pushData("Aki Yonaga", EnemyBack1Hdl, 3200, 50, Boss[5], false, { MoveAppear,MoveEX_5 });
	List.FacBul().setDammakuData(50, 1, Red, Gem, 500);
	List.FacBul().setDammakuData(51, 1, Red, SOval);
	List.FacBul().setDammakuData(52, 14, Orange, Small);
	List.FacBul().setDammakuData(53, 14, Orange, Midium);
	List.FacBul().setDammakuData(54, 14, Orange, Big);
	List.FacBul().setDammakuData(55, 14, Yerrow, Small);
	List.FacBul().setDammakuData(56, 14, Yerrow, Midium);
	List.FacBul().setDammakuData(57, 14, Yerrow, Big);
	static Vec2 speed;
	static Point cood;
	Renew.Push(51, [](IBullet& Obj, int t, ObjectAdaptor& List) {
		if (t % 4 == 0) {
			Obj.Split(51, 0, 1, float(t) / 20.0f, 3.0f, 0.0f, true);
		}
		if (Obj.isReflected(15, cood, speed)) {
			Obj.SetSpeed(speed);
		}
		if (t > 500) {
			Obj.Kill();
		}
	});
	Renew.Push(52, [](IBullet& Obj, int t, ObjectAdaptor& List) {
		if (t > 100)Obj.Kill();
	});

}
void MoveEX_5(IBoss* Obj, ObjectAdaptor& List, int t)noexcept {
	if ((t - 50) % 700 == 0)Obj->SetMovePoint(Rand(Rect{ { 70, 70 },{ 550, 230 } }), 70, Ease<Quad>::InOut);
	if (RANGE(0,t %900,300)&&t% 100 == 0) {
		List.FacBul().Bullet(50, 51, Obj->p, 1, Rand(PI), 3.0f, 0.1f, 30);
	}
	if (RANGE(300, t % 900, 600)) {
			List.FacBul().Bullet(Rand(52,54), 52, Obj->p, 1,Rand(0.06f)+float(t)/150.0f, 0.01f, 0.1f, (t%300)*3);
	}if (RANGE(600, t % 900, 900)) {
			List.FacBul().Bullet(Rand(55, 57), 52, Obj->p, 1, Rand(0.06f) - float(t) / 150.0f, 0.01f, 0.1f, (t % 300) * 3);
	}
}



void setBulletDataEX(BulletRenewManager& Renew, ObjectAdaptor& List)noexcept {

	List.FacBul().clearDammakuData();
	List.FacEmy().clearData();
	InitEX_0(Renew, List);
	InitEX_1(Renew, List);
	InitEX_2(Renew, List);
	InitEX_3(Renew, List);
	InitEX_4(Renew, List);
	InitEX_5(Renew, List);
}
