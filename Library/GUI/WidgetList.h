#pragma once

#include "IWidget.h"
//#include "../../Class/Object/Effect/IEffect.h"
#include "../ObjectList/ObjectMap.h"
#include <string>

class IWidget;

class WidgetList {
protected:
	std::unordered_map<std::string, std::unique_ptr<IWidget>> mMap;
	IWidget* mBeforeWidget;
	IWidget* mLastWidget;
public:
	WidgetList()noexcept;

	IWidget* push(IWidget* widget,bool selectableFlag=true)noexcept;
	IWidget* push(const std::string& key, IWidget* widget, bool selectableFlag = true)noexcept;
	IWidget* push(IWidget* widget, const std::string& up, const std::string&  down = "", const std::string&  left = "", const std::string&  right="")noexcept;
	IWidget* push(const std::string& key, IWidget* widget, const std::string&  up, const std::string&  down = "", const std::string&  left = "", const std::string&  right = "")noexcept;

	void link(const std::string& key, const std::string&  up, const std::string&  down = "", const std::string&  left = "", const std::string&  right = "")noexcept;
	
	void update()noexcept;
	void draw()const noexcept;

	int size() const noexcept { return mMap.size(); }
	void foreach(void(*func)(IWidget*))noexcept;

	bool empty()const noexcept { return mMap.empty(); }

	void clear()noexcept { mMap.clear(); }

	//キーが存在していない場合強制終了(自分で管理しろ)
	IWidget* getWidget(const std::string& key)const noexcept{
		if (mMap.empty()||key.empty())return nullptr;
		return mMap.at(key).get();
	}
	template<typename T>
	T& getWidget(const std::string& key)noexcept {
		return *dynamic_cast<T*>(getWidget(key));
	}
};

/*class WidgetList {
	ObjectMap<std::string, IWidget> mMap;
	IWidget* mBeforeWidget;
public:
	WidgetList(){}
	~WidgetList(){}

	IWidget* push(IWidget* widget)noexcept { return nullptr; }
	IWidget* push(const std::string& key, IWidget* widget)noexcept { return nullptr; }
	void update()noexcept{}
	void draw()const noexcept{}

	int size() const noexcept { return 0; }
	void foreach(void(*func)(IWidget*))noexcept{}

	bool empty()noexcept { return false; }

	//キーが存在していない場合強制終了(自分で管理しろ)
	IWidget* getWidget(const std::string& key)const { return nullptr; }
	template<typename T>
	T& getWidget(const std::string& key)noexcept {
		return *dynamic_cast<T*>(getWidget(key));
	}
};*/