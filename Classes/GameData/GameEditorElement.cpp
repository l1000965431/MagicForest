//
//  GameEditorElement.cpp
//  MagicForest
//
//  Created by liumin on 15/2/19.
//
//

#include "GameEditorElement.h"

GameEditorElement::GameEditorElement()
{
    SetGameEditorElementType( GameEditorElement_None );
}

GameEditorElement::~GameEditorElement()
{
    
}

GameEditorElement* GameEditorElement::createWithTexture(Texture2D *texture)
{
    GameEditorElement *sprite = new (std::nothrow) GameEditorElement();
    if (sprite && sprite->initWithTexture(texture))
    {
        sprite->autorelease();
        return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return nullptr;
}

GameEditorElement* GameEditorElement::createWithTexture(Texture2D *texture, const Rect& rect, bool rotated)
{
    GameEditorElement *sprite = new (std::nothrow) GameEditorElement();
    if (sprite && sprite->initWithTexture(texture, rect, rotated))
    {
        sprite->autorelease();
        return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return nullptr;
}

GameEditorElement* GameEditorElement::create(const std::string& filename)
{
    GameEditorElement *sprite = new (std::nothrow) GameEditorElement();
    if (sprite && sprite->initWithFile(filename))
    {
        sprite->autorelease();
        return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return nullptr;
}

GameEditorElement* GameEditorElement::create()
{
	GameEditorElement *sprite = new (std::nothrow) GameEditorElement();
	if (sprite && sprite->init())
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}


GameEditorElement* GameEditorElement::create(const std::string& filename, const Rect& rect)
{
    GameEditorElement *sprite = new (std::nothrow) GameEditorElement();
    if (sprite && sprite->initWithFile(filename, rect))
    {
        sprite->autorelease();
        return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return nullptr;
}

GameEditorElement* GameEditorElement::createWithSpriteFrame(SpriteFrame *spriteFrame)
{
    GameEditorElement *sprite = new (std::nothrow) GameEditorElement();
    if (sprite && spriteFrame && sprite->initWithSpriteFrame(spriteFrame))
    {
        sprite->autorelease();
        return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return nullptr;
}

GameEditorElement* GameEditorElement::createWithSpriteFrameName(const std::string& spriteFrameName)
{
    SpriteFrame *frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameName);
    
#if COCOS2D_DEBUG > 0
    char msg[256] = {0};
    sprintf(msg, "Invalid spriteFrameName: %s", spriteFrameName.c_str());
    CCASSERT(frame != nullptr, msg);
#endif
    
    return createWithSpriteFrame(frame);
}

void GameEditorElement::SetGameEditorElementType(GameEditorElementType Type)
{
    if( Type == _GameEditorElementType )
        return;
    
    _GameEditorElementType = Type;
    
    switch (_GameEditorElementType) 
	{
        case GameEditorElement_Entrance:
			this->initWithFile( "EnTrance.png" );
            break;
        case GameEditorElement_Exit:
			this->initWithFile( "Exite.png" );
            break;
        case GameEditorElement_Tree1:
			this->initWithFile( "tree2.png" );
            break;
        case GameEditorElement_Tree2:
			this->initWithFile( "tree1.png" );
            break;
		case GameEditorElement_Terrain:
			this->initWithFile( "Terrain.png" );
			break;
        default:
            break;
    }
	this->setAnchorPoint( Point( 0.5f,0.0f ) );
}

GameEditorElementType GameEditorElement::GetGameEditorElementType()
{
    return _GameEditorElementType;
}

void GameEditorElement::onEnter()
{
	GameSpriteBase::onEnter(); 
	this->setAnchorPoint( Point( 0.5f,0.f ) );
}

void GameEditorElement::setAnchorPoint(const Vec2& anchor)
{
	GameSpriteBase::setAnchorPoint( anchor );
}