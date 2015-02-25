/*///////////////////////////////////////////////////////////////////////////////
--作者:seele
--功能说明:游戏精灵基础类
///////////////////////////////////////////////////////////////////////////////*/
#pragma once
#include "common.h"

class GameSpriteBase:public Sprite
{
public:
	GameSpriteBase();
	virtual ~GameSpriteBase();

public:
	static GameSpriteBase* create(void);

	static GameSpriteBase* create(const std::string& filename);

	static GameSpriteBase* create(const std::string& filename, const Rect& rect);

	static GameSpriteBase* createWithTexture(Texture2D *texture);
	
	static GameSpriteBase* createWithTexture(Texture2D *texture, const Rect& rect, bool rotated=false);

	static GameSpriteBase* createWithSpriteFrame(SpriteFrame *spriteFrame);

	static GameSpriteBase* createWithSpriteFrameName(const std::string& spriteFrameName);

};