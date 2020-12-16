#pragma once

#include <unordered_map>
#include <string>

class Audio {
	int mBGMHdl[12];
	std::unordered_map<std::string, int> mSEHdl;
public:
	Audio() {}
	~Audio();
	void initBGM();
	void initSE();
	void playBGM(int bum);
	void playSE(const std::string& se);
	void stopBGM();
};