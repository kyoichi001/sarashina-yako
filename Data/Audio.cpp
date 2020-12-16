#include "Audio.h"
#include "dxlib.h"

bool BGMEverLoadFlag[12] = { false };
const char* BGMHdl[12] = {
	"Music/BGM/th02_01.wav",
	"Music/BGM/th02_02.wav",
	"Music/BGM/th02_03.wav",
	"Music/BGM/th02_04.wav",
	"Music/BGM/th02_05.wav",
	"Music/BGM/th02_06.wav",
	"Music/BGM/th02_07.wav",
	"Music/BGM/th02_08.wav",
	"Music/BGM/th02_09.wav",
	"Music/BGM/th02_10.wav",
	"Music/BGM/th02_11.wav",
	"Music/BGM/th02_12.wav",
};

Audio::~Audio() {
	for (int i = 0; i < 12; ++i)
		DeleteSoundMem(mBGMHdl[i]);
}

void Audio::initBGM() {
	for (int i = 0; i < 12; i++) {
		mBGMHdl[i] = LoadBGM(BGMHdl[i]);
	}
}

void Audio::initSE() {
	mSEHdl["OK"] = LoadSoundMem("Music/SE/SE_OK.wav");
	mSEHdl["Shoot"] = LoadSoundMem("Music/SE/ShootSE.wav");
	mSEHdl["Shoot"] = LoadSoundMem("Music/SE/Mixdown.wav");
	mSEHdl["Cancel"] = LoadSoundMem("Music/SE/RenewSE(2).wav");
	mSEHdl["Charge"] = LoadSoundMem("Music/SE/RenewSE(3).wav");
}

void Audio::playBGM(int bgm) {
	if (!BGMEverLoadFlag[bgm]) {
		//mBGMHdl[bgm] = LoadSoundMem(BGMHdl[bgm]);
		//BGMEverLoadFlag[bgm] = true;
	}
	stopBGM();
	//SetVolumeSoundMem(255 * 3 / 4 * Data.BGMVol, bgm[num]);
	//PlaySoundMem(mBGMHdl[bgm], DX_PLAYTYPE_LOOP);
}
void Audio::playSE(const std::string& se){
	PlaySoundMem(mSEHdl[se], DX_PLAYTYPE_BACK);
}

void Audio::stopBGM() {
	for (int i = 0; i < 12; ++i)
		StopSoundMem(mBGMHdl[i]);
}
