
#include "FontFunc.h"
#include "DxLib.h"

namespace DxWrp {
	int CreateFontToHandle(const std::string& fontname, int size, int thick, int fontType, int charset, int edge, int italic, int handle) {
		return DxLib::CreateFontToHandle(fontname.c_str(), size, thick, fontType, charset, edge, italic, handle);
	}
}