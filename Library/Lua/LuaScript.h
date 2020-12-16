#pragma once

#include <string>
#include <vector>

extern "C" {
# include "lua.h"
# include "lauxlib.h"
# include "lualib.h"
}

class LuaScript {
	lua_State* L;
	//テーブルの深さ
	int level;

	//変数名をスタックに積む
	//成功したら true 失敗したら falseを返す
	bool lua_gettostack(const std::string& variableName);
	//スタックをクリア
	void clean();
public:
	//ファイルをロードし実行する
	LuaScript(const std::string& filename);
	~LuaScript();
	//未実装
	void printError(const std::string& variableName, const std::string& reason);

	template<typename T>
	//テーブルの中やグローバルにかかわらず変数を取得できる
	//table.table2.varなど
	T get(const std::string& variableName) {
		if (!L) {
			printError(variableName, "Script is not loaded");
			return lua_getdefault<T>(variableName);
		}

		T result;
		if (lua_gettostack(variableName)) { // variable succesfully on top of stack
			result = lua_get<T>(variableName);
		}
		else {
			result = lua_getdefault<T>(variableName);
		}

		lua_pop(L, level + 1); // pop all existing elements from stack
		return result;
	}

	lua_State* getLuaState() { return L; }

	// Generic get さきに定義
	//変数のキャスト用 テーブルから取得するわけではない
	template<typename T>
	T lua_get(const std::string& variableName) {
		return 0;
	}

	// Generic default get
	template<typename T>
	T lua_getdefault(const std::string& variableName) {
		return 0;
	}
	//配列をstring型で取得
	std::vector<std::string> getStringVector(const std::string& name);
	//配列をint型で取得
	std::vector<int> getIntVector(const std::string& name);
	//テーブルのキーを取得
	std::vector<std::string> getTableKeys(const std::string& name);
};


template <>
inline bool LuaScript::lua_get(const std::string& variableName) {
	return (bool)lua_toboolean(L, -1);
}

template <>
inline float LuaScript::lua_get(const std::string& variableName) {
	if (!lua_isnumber(L, -1)) {
		printError(variableName, "Not a number");
	}
	return (float)lua_tonumber(L, -1);
}

template <>
inline int LuaScript::lua_get(const std::string& variableName) {
	if (!lua_isnumber(L, -1)) {
		printError(variableName, "Not a number");
	}
	return (int)lua_tonumber(L, -1);
}

template <>
inline std::string LuaScript::lua_get(const std::string& variableName) {
	std::string s = "null";
	if (lua_isstring(L, -1)) {
		s = std::string(lua_tostring(L, -1));
	}
	else {
		printError(variableName, "Not a string");
	}
	return s;
}

// Generic default get
template<>
inline bool LuaScript::lua_getdefault(const std::string& variableName) { return false; }
template<>
inline int LuaScript::lua_getdefault(const std::string& variableName) {return 0;}
template<>
inline float LuaScript::lua_getdefault(const std::string& variableName) {return 0.0f;}
template<>
inline std::string LuaScript::lua_getdefault(const std::string& variableName) {return "null";}