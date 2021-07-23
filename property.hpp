#pragma once
#include <iostream>
#include <functional>

template<typename T> class property{
public:
	std::function<T()> get;
	std::function<void(const T&)> set;
	property<T>& operator = (const T& val){
		set(val);
		return *this;
	};
	operator const T() const{
		return(get());
	}
	property(std::function<T()> g, std::function<void(const T&)> s){
		get = g;
		set = s;
	}
	property(){

	}
};
