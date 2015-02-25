#include "GameSceneBase.h"

GameSceneBase::GameSceneBase()
{

}

GameSceneBase::~GameSceneBase()
{

}

bool GameSceneBase::init()
{
	if( !Scene::init() )
		return false;

	InitScene();

	return true;
}