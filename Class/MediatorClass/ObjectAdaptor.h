#pragma once

#include "../Object/Bullet/BulletFactory.h"
#include "../Object/Leazer/LeazerFactory.h"
#include "../Object/Enemy/EnemyFactory.h"
#include "../Object/Player/PlayerFactory.h"
#include "../Scene/Game/Stage/StageFactory.h"

//#include "../Object/Bom/BomObject.h"
#include "../Object/3D/I3DObject.h"
#include "../Object/Enemy/IGhost.h"
#include "../Object/Enemy/IBoss.h"
#include "../Object/Item/IItem.h"
#include "../Object/Player/PBullet/IPbullet.h"
#include "../Object/Player/Bom/IBom.h"
#include "../Object/Leazer/ILeazer.h"
#include "../Object/Leazer/LeazerRenewManager.h"
#include "../Object/Bullet/RenewManager.h"
#include "../Object/Bullet/IBullet.h"
#include "../Object/Effect/IEffect.h"
#include "../Object/Effect/3DEffects.h"

#include "../../Library/ObjectEmitter.h"

#include "../../Library/ObjectList/ObjectListClass.h"
#include "../../Library/ObjectList/FixedObjectList.h"
#include "../../Library/ObjectList/FixedObjectListMorton.h"
#include "../../Library/ObjectList/ObjectListMorton.h"

#include "../Object/Player/IPlayer.h"
#include "../../Data/Camera.h"
#include "../Object/Player/PlayerController.h"

#include "../Talking/TalkingManager.h"

#include "../../Data/Audio.h"

#ifdef _DEBUG
#include "DebugInfo.h"
//#include "../Debug/MessageBox.h"
#endif

class BulletFactory;
class EnemyFactory;

class ObjectAdaptor {
	BulletFactory mBulFac;
	EnemyFactory mEneFac;
	LeazerFactory mLezFac;
	StageFactory mStgFac;
	PlayerFactory mPlyFac;

	ObjectList<Emitter> mEmiList;
	ObjectList<I3D> m3DsList;
	ObjectList<IEffect> mEffList;
	ObjectList<I3DEffect> m3EfList;
	ObjectList<IPBullet> mPBlList;
	ObjectList<IBom> mBomList;
	FixedObjectList<ILeazer> mLezList1;
	FixedObjectList<ILeazer2> mLezList2;
	BulletRenewManager mBRenList;
	LeazerRenewManager mLRenList;
	FixedObjectList<IBullet> mBulList;
	FixedObjectList<IGhost> mEneList;
	FixedObjectList<IBoss> mBssList;
	ObjectList<IItem> mItmList;

	std::unique_ptr<IPlayer> mPlayer;
	Camera mCamera;

	PlayerController mPyctrl;
	TalkingManager mTalk;
	Audio mAudio;
public:
	ObjectAdaptor()noexcept;

	auto& FacBul()noexcept { return mBulFac; }
	auto& FacEmy()noexcept { return mEneFac; }
	auto& FacLez()noexcept { return mLezFac; }
	auto& FacStg()noexcept { return mStgFac; }
	auto& FacPly()noexcept { return mPlyFac; }

	auto& ObjEmi()noexcept { return mEmiList; }
	auto& Obj3Ds()noexcept { return m3DsList; }
	auto& ObjEmy()noexcept { return mEneList; }
	auto& ObjBss()noexcept { return mBssList; }
	auto& ObjItm()noexcept { return mItmList; }
	auto& ObjPBl()noexcept { return mPBlList; }
	auto& ObjBom()noexcept { return mBomList; }
	auto& ObjEff()noexcept { return mEffList; }
	auto& Obj3Ef()noexcept { return m3EfList; }
	auto& ObjLez1()noexcept { return mLezList1; }
	auto& ObjLez2()noexcept { return mLezList2; }
	auto& ObjBRen()noexcept { return mBRenList; }
	auto& ObjLRen()noexcept { return mLRenList; }
	auto& ObjBul()noexcept { return mBulList; }

	IPlayer* GetPlayer()noexcept { return mPlayer.get(); }
	auto& GetCamera()noexcept { return mCamera; }

	auto& getAudio()noexcept { return mAudio; }

	void setPlayer(IPlayer* player);

	auto& GetPlayerController()noexcept { return mPyctrl; }

	auto& getTalkManager()noexcept { return mTalk; }

	void ObjectListUpdate()noexcept;
	void ObjectUpdate()noexcept;


#ifdef _DEBUG
private:
	DebugInfo mDebug;
public:
	auto& DbgInfo()noexcept { return mDebug; }

#endif
};