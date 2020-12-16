
#include "CollisionMediator.h"

#include "../MediatorClass/ObjectAdaptor.h"
#include "../Object/Player/PBullet/PlayerBullet.h"
//#include "../Object/Item/IItem.h"
#include "../../Library/Math/Collision.h"

CollisionMediator::CollisionMediator(ObjectAdaptor* Adaptor) noexcept:mAdaptor(Adaptor){}

void CollisionMediator::Update()noexcept {
	Player();
	PBullet();
	Bom();
}

void CollisionMediator::EraceOverObject()noexcept {
	for (auto &Obj : mAdaptor->ObjEmy()) {
		if (Obj.IsOver()) {
			Obj.Erase();
		}
	}
	for (auto &Obj : mAdaptor->ObjBul()) {
		if (Obj.IsOver()) {
			Obj.Erace();
		}
	}
	for (auto &Obj : mAdaptor->ObjPBl()) {
		if (Obj->IsOver()) {
			Obj->Erace();
		}
	}
}

void CollisionMediator::Player()noexcept {
	IPlayer* player = mAdaptor->GetPlayer();
	if (player) {
		for (auto &Obj : mAdaptor->ObjBul()) player->Collided(Obj);
		for (auto &Obj : mAdaptor->ObjEmy()) player->Collided(Obj);
		for (auto &Obj : mAdaptor->ObjBss()) player->Collided(Obj);
		for (auto &Obj : mAdaptor->ObjLez1()) player->Collided(Obj);
		for (auto &Obj : mAdaptor->ObjLez2()) player->Collided(Obj);
	}
}

void CollisionMediator::PBullet()noexcept {
	for (auto &Bul : mAdaptor->ObjPBl()) {
		for (auto &Obj : mAdaptor->ObjEmy()) Bul->Collided(Obj);
		for (auto &Obj : mAdaptor->ObjBss()) Bul->Collided(Obj);
	}
}

void CollisionMediator::Bom()noexcept {
	for (auto &Bom : mAdaptor->ObjBom()) {
		for (auto &Obj : mAdaptor->ObjEmy()) Bom->Collided(Obj);
		for (auto &Obj : mAdaptor->ObjBss()) Bom->Collided(Obj);
		for (auto &Obj : mAdaptor->ObjBul()) Bom->Collided(Obj);
	}
}
