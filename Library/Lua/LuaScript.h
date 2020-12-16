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
	//�e�[�u���̐[��
	int level;

	//�ϐ������X�^�b�N�ɐς�
	//���������� true ���s������ false��Ԃ�
	bool lua_gettostack(const std::string& variableName);
	//�X�^�b�N���N���A
	void clean();
public:
	//�t�@�C�������[�h�����s����
	LuaScript(const std::string& filename);
	~LuaScript();
	//������
	void printError(const std::string& variableName, const std::string& reason);

	template<typename T>
	//�e�[�u���̒���O���[�o���ɂ�����炸�ϐ����擾�ł���
	//table.table2.var�Ȃ�
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

	// Generic get �����ɒ�`
	//�ϐ��̃L���X�g�p �e�[�u������擾����킯�ł͂Ȃ�
	template<typename T>
	T lua_get(const std::string& variableName) {
		return 0;
	}

	// Generic default get
	template<typename T>
	T lua_getdefault(const std::string& variableName) {
		return 0;
	}
	//�z���string�^�Ŏ擾
	std::vector<std::string> getStringVector(const std::string& name);
	//�z���int�^�Ŏ擾
	std::vector<int> getIntVector(const std::string& name);
	//�e�[�u���̃L�[���擾
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