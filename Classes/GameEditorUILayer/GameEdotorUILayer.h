//
//  GameEdotorUILayer.h
//  MagicForest
//  用户编辑器的UI显示层
//  Created by liumin on 15/2/19.
//
//

#ifndef __MagicForest__GameEdotorUILayer__
#define __MagicForest__GameEdotorUILayer__

#include <stdio.h>
#include "common.h"
#include "GameLayerBase.h"

class GameEditorData;

class GameEditorUILayer:public GameLayerBase
{
public:
    GameEditorUILayer();
    virtual ~GameEditorUILayer();
    static GameEditorUILayer* create( GameEditorData* );
    CREATE_FUNC( GameEditorUILayer );

public:
    virtual void InitLayer() override;

	bool onSpriteTouchBegan(Touch *touch, Event *unused_event);
	void onSpriteTouchMoved(Touch *touch, Event *unused_event);
	void onSpriteTouchEnded(Touch *touch, Event *unused_event);


private:
    GameEditorData* _GameEditorData;
	Sprite *_SpriteMouse;                      //鼠标指针精灵
};



#endif /* defined(__MagicForest__GameEdotorUILayer__) */
