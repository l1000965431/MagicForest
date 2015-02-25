#include "GameLayerBase.h"

GameLayerBase::GameLayerBase()
{
    
}

GameLayerBase::~GameLayerBase()
{
    
}

bool GameLayerBase::init()
{
    LayerColor::init();
    return true;
}

void GameLayerBase::onEnter()
{
	LayerColor::onEnter();
	InitLayer();
}

void GameLayerBase::InitLayer()
{
    
}