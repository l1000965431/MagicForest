/*///////////////////////////////////////////////////////////////////////////////
--作者:seele
--功能说明:游戏层的基础类
///////////////////////////////////////////////////////////////////////////////*/
#pragma once
#include "common.h"

class GameLayerBase:public LayerColor
{
public:
	GameLayerBase();
	virtual ~GameLayerBase();
    virtual bool init();
    virtual void onEnter() override;
public:
	CREATE_FUNC(GameLayerBase);
    virtual void InitLayer( void );
};
