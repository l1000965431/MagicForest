#include "GameEditorScene.h"
#include "GameEdotorUILayer.h"
#include "GameEditorControlLayer.h"
#include "GameEditorData.h"

GameEditorScene::GameEditorScene()
{

}

GameEditorScene::~GameEditorScene()
{

}

void GameEditorScene::InitScene()
{
	GameEditorControlLayer* pGameEditorControlLayer = GameEditorControlLayer::create( GameEditorData::GetIntace() );
	this->addChild( pGameEditorControlLayer,2 ); 

	GameEditorUILayer* pGameEditorUILayer = GameEditorUILayer::create( GameEditorData::GetIntace() );
	this->addChild( pGameEditorUILayer,1 );
}