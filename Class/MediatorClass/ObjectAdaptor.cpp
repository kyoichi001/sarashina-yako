
#include "ObjectAdaptor.h"

#ifdef _DEBUG
#include "DxLib.h"
#include "../../Library/GUI/Widget.h"
#include "../../Data/Resource.h"
#include "../../Data/DATA.h"
#endif

ObjectAdaptor::ObjectAdaptor()noexcept :mBulFac(this),mEneFac(this),mLezFac(this), mStgFac(this), mPlayer(nullptr)
#ifdef _DEBUG
, mDebug(this)
#endif
{
//	Item::SetPlayerPtr(&mPlayer);
	IGhost::SetClassList(this);
	IBoss::SetClassList(this);
	IPlayer::SetAdaptor(this);
	IPBullet::SetClassList(this);
	IBom::SetClassList(this);
	IBullet::SetClassList(this);
	IOption::SetClassList(this);
	ILeazer::setAdaptor(this);
	ILeazer2::setAdaptor(this);
	I3D::setCamera(&mCamera);
	I3DEffect::setCamera(&mCamera);
	mAudio.initBGM();
	mAudio.initSE();
}

void ObjectAdaptor::ObjectListUpdate()noexcept {
	float t = 1.0f;
	if (!pauseflag) {
		mBulList.Update(bulletDeltaTime);
		IBullet::UpdateTurnAngle();
		mEmiList.Update(t);
		if (Draw3DFlag)
			m3DsList.Update(t);
		mEneList.Update(t);
		mBssList.Update(t);
		mPBlList.Update(t);
		mBomList.Update(t);
		mEffList.Update(t);
		m3EfList.Update(t);
		mTalk.update(t);
		//mItmList.Update(t);
		mLezList1.Update(t);
		mLezList2.Update(t);
	}
#ifdef _DEBUG
	if (Key[KEY_INPUT_J] == 1)debugflag = !debugflag;
	if (debugflag) {
		mDebug.Update();
	}
#endif
}

void ObjectAdaptor::ObjectUpdate()noexcept {
	if(mPlayer)mPlayer->Update();
	mCamera.Update();
}

void ObjectAdaptor::setPlayer(IPlayer* player) {
	mPlayer.reset(player);
	mPyctrl.set(mPlayer.get());
	IItem::SetPlayerPtr(mPlayer.get());
#ifdef _DEBUG
	mDebug.getGUI().GetWidget<Tab>("tab1").Push(new Viewer<Circle>("Player", { Font01, 0xFFFFFF, 0xAAAAAA }, mPlayer.get()));
#endif
}