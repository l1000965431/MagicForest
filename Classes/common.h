#pragma once
#include "cocos2d.h"
USING_NS_CC;

#define INITGLOBALCLASS( T )\
	private:\
	static T* s_##T;\
	public:\
	static T* GetIntace( void ){ if( s_##T == nullptr ) s_##T = new T(); return s_##T; }

#define INITSTATICVALUE( T )\
	T* T::s_##T = nullptr;