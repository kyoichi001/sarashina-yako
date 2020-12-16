
#pragma once

//#include "../CollisionManager.h"
//#include "../../Library/ObjectList/FixedObjectList.h"
//#include "../../Library/ObjectList/ObjectListClass.h"

//#include "../Object/Bullet/BulletObject.h"
//#include "../Object/Enemy/IGhost.h"
//#include "../Object/Enemy/IBoss.h"
//#include "../Object/Player/Player.h"
//#include "../Object/Player/IPBullet.h"


class ObjectAdaptor;

class CollisionMediator{
	ObjectAdaptor* mAdaptor;
	//CollisionManager2<Player,FixedObjectList<IBullet>> mPlayerBullet;
	//CollisionManager<Player, ObjectList<IItem>> mPlayerItem;
	//CollisionManager<ObjectList<IPBullet>, FixedObjectList<IGhost>> mPBulGhost;
	//CollisionManager<ObjectList<IPBullet>, FixedObjectList<IBoss>> mPBulBoss;
	//CollisionManager<ObjectList<IPBullet>,FixedObjectList<IBullet>> mPBulBul;
	void Player()noexcept;
	void PBullet()noexcept;
	void Bom()noexcept;
public:
	CollisionMediator(ObjectAdaptor* Adaptor)noexcept;
	~CollisionMediator()noexcept{}
	void Update()noexcept;
	void EraceOverObject()noexcept;
};