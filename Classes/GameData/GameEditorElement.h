//
//  GameEditorElement.h
//  MagicForest
//  游戏编辑器元素
//
//  Created by liumin on 15/2/19.
//
//

#ifndef __MagicForest__GameEditorElement__
#define __MagicForest__GameEditorElement__

#include "common.h"
#include "GameSpriteBase.h"

//用户编辑元素类型定义
enum GameEditorElementType
{
	GameEditorElement_None,
    GameEditorElement_Entrance = 1,   //地图入口
    GameEditorElement_Exit     = 2,   //地图出口
    GameEditorElement_Tree1    = 3,   //地图树1
    GameEditorElement_Tree2    = 4,   //地图树2
    GameEditorElement_Terrain  = 5,   //地形
};

class GameEditorElement:public GameSpriteBase
{
public:
    GameEditorElement();
    virtual ~GameEditorElement();

public:
	static GameEditorElement* create();
    
	static GameEditorElement* create(const std::string& filename);
    
    static GameEditorElement* create(const std::string& filename, const Rect& rect);
    
    static GameEditorElement* createWithTexture(Texture2D *texture);
    
    static GameEditorElement* createWithTexture(Texture2D *texture, const Rect& rect, bool rotated=false);
    
    static GameEditorElement* createWithSpriteFrame(SpriteFrame *spriteFrame);
    
    static GameEditorElement* createWithSpriteFrameName(const std::string& spriteFrameName);
    
public:
    void SetGameEditorElementType( GameEditorElementType Type );
    GameEditorElementType GetGameEditorElementType();
    virtual void onEnter() override;
	virtual void setAnchorPoint(const Vec2& anchor) override;

private:
    GameEditorElementType _GameEditorElementType;
    
};

#endif /* defined(__MagicForest__GameEditorElement__) */
