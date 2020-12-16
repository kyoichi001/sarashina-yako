#pragma once

#include <string>

//会話する個人のデータを扱う
struct Talker {
	int FontColor;
	int Hdl;
};

//今何をどんな表情で話しているのか
struct TalkData {
	std::string mText;
};