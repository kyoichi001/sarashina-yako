#pragma once

#include <stdio.h>

template<typename SaveFileClass>
class Selialize {
	const char* mFilename;
	SaveFileClass& mData;
	bool mOpenedFlag;
	FILE *mFp;
public:
	Selialize(const char* filename, const SaveFileClass& data) :mFilename(filename), mData(data) {
		mFp = fopen(filename, "rb");
		mOpenedFlag = fp != NULL;
	}
	Selialize() {
		fclose(mFp);
	}

	bool readfile() {
		if (!mOpenedFlag)return false;
		fread(&mData, sizeof(mData), 1, mFp);
		return true;
	}
	

	bool savefile() {
		if (!mOpenedFlag)return false;
		fwrite(&mData, sizeof(mData), 1, mFp); // SaveData_t\‘¢‘Ì‚Ì’†g‚ğo—Í
		return true;
	}

};
