#include "GameSpriteBase.h"

GameSpriteBase::GameSpriteBase()
{

}

GameSpriteBase::~GameSpriteBase()
{

}

GameSpriteBase* GameSpriteBase::createWithTexture(Texture2D *texture)
{
	GameSpriteBase *sprite = new (std::nothrow) GameSpriteBase();
	if (sprite && sprite->initWithTexture(texture))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

GameSpriteBase* GameSpriteBase::createWithTexture(Texture2D *texture, const Rect& rect, bool rotated)
{
	GameSpriteBase *sprite = new (std::nothrow) GameSpriteBase();
	if (sprite && sprite->initWithTexture(texture, rect, rotated))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

GameSpriteBase* GameSpriteBase::create(const std::string& filename)
{
	GameSpriteBase *sprite = new (std::nothrow) GameSpriteBase();
	if (sprite && sprite->initWithFile(filename))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

GameSpriteBase* GameSpriteBase::create(const std::string& filename, const Rect& rect)
{
	GameSpriteBase *sprite = new (std::nothrow) GameSpriteBase();
	if (sprite && sprite->initWithFile(filename, rect))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

GameSpriteBase* GameSpriteBase::createWithSpriteFrame(SpriteFrame *spriteFrame)
{
	GameSpriteBase *sprite = new (std::nothrow) GameSpriteBase();
	if (sprite && spriteFrame && sprite->initWithSpriteFrame(spriteFrame))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

GameSpriteBase* GameSpriteBase::createWithSpriteFrameName(const std::string& spriteFrameName)
{
	SpriteFrame *frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameName);

#if COCOS2D_DEBUG > 0
	char msg[256] = {0};
	sprintf(msg, "Invalid spriteFrameName: %s", spriteFrameName.c_str());
	CCASSERT(frame != nullptr, msg);
#endif

	return createWithSpriteFrame(frame);
}

GameSpriteBase* GameSpriteBase::create()
{
	GameSpriteBase *sprite = new (std::nothrow) GameSpriteBase();
	if (sprite && sprite->init())
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}