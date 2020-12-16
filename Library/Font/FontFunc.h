#pragma once

#include <string>

#define FONTTYPE_ANTIALIASING 0x02

namespace DxWrp {
	int CreateFontToHandle(const std::string& fontname,int size,int thick,int fontType,int charset=-1,int edge=-1,int italic=0,int handle=0);
}