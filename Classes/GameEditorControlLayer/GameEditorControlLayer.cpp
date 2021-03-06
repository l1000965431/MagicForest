//
//  GameEditorControlLayer.cpp
//  MagicForest
//
//  Created by liumin on 15/2/19.
//
//

#include "GameEditorControlLayer.h"
#include "MapCalculate.h"
#include "GameEditorElement.h"
#include "GameEditorData.h"

using namespace Calculate;


GameEditorControlLayer::GameEditorControlLayer()
{
	_UILayerState = None_State;
}

GameEditorControlLayer::~GameEditorControlLayer()
{

}

GameEditorControlLayer* GameEditorControlLayer::create( GameEditorData* pGameEditorData )
{
	GameEditorControlLayer* pTemp = GameEditorControlLayer::create();
	if( pTemp && pTemp->init() )
	{
		pTemp->_GameEditorData = pGameEditorData;
		return pTemp;
	}
	return nullptr;
}

bool GameEditorControlLayer::init()
{
	if( !GameLayerBase::init() )
		return false;

	return true;
}

void GameEditorControlLayer::InitLayer()
{
	auto PlantMenu = MenuItemImage::create("tree1.png","tree1.png",CC_CALLBACK_1(GameEditorControlLayer::SetPlantState,this));
	//图标放在
	PlantMenu->setPosition(300,-120);

	auto EarseMenu = MenuItemImage::create("Terrain.png","Terrain.png",CC_CALLBACK_1(GameEditorControlLayer::SetEarseState,this));

	//图标放在
	EarseMenu->setPosition(400,-120);
	auto menu = Menu::create(PlantMenu,EarseMenu,NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu,100);
}

void GameEditorControlLayer::onEnter()
{
	GameLayerBase::onEnter();

	this->setContentSize( Size( 500,250 ) );
	this->setPosition( 275,260 );

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(GameEditorControlLayer::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(GameEditorControlLayer::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(GameEditorControlLayer::onTouchEnded, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

bool GameEditorControlLayer::onTouchBegan(Touch *touch, Event *unused_event)
{
	Rect LayerRect = Rect( this->getPositionX(),this->getPositionY(),this->getContentSize().width,this->getContentSize().height );
	Vec2 touchLocation = touch->getLocation();

	if( !LayerRect.containsPoint( touchLocation ) )
	{
		return false;
	}

	switch (_UILayerState)
	{
	case None_State:
		break;
	case Plant_State:
		PlantTouchBegan( touch );
		break;
	case Erase_State:
		EraseTouchBegan( touch );
		break;
	case Entrance_State:
		break;
	case Exite_State:
		break;
	default:
		break;
	}


	return true;
}

void GameEditorControlLayer::onTouchMoved(Touch *touch, Event *unused_event)
{

	Rect LayerRect = Rect( this->getPositionX(),this->getPositionY(),this->getContentSize().width,this->getContentSize().height );
	Vec2 touchLocation = touch->getLocation();

	if( !LayerRect.containsPoint( touchLocation ) )
	{
		return;
	}

	switch (_UILayerState)
	{
	case None_State:
		break;
	case Plant_State:
		PlantTouchMoved( touch );
		break;
	case Erase_State:
		EraseTouchMoved( touch );
		break;
	case Entrance_State:
		break;
	case Exite_State:
		break;
	default:
		break;
	}
}

void GameEditorControlLayer::onTouchEnded(Touch *touch, Event *unused_event)
{
	Rect LayerRect = Rect( this->getPositionX(),this->getPositionY(),this->getContentSize().width,this->getContentSize().height );
	Vec2 touchLocation = touch->getLocation();

	if( !LayerRect.containsPoint( touchLocation ) )
	{
		return;
	}


	switch (_UILayerState)
	{
	case None_State:
		break;
	case Plant_State:
		PlantTouchEnded( touch );
		break;
	case Erase_State:
		EraseTouchEnded( touch );
		break;
	case Entrance_State:
		break;
	case Exite_State:
		break;
	default:
		break;
	}
}

void GameEditorControlLayer::PlantTouchBegan( Touch *touch )
{


}

void GameEditorControlLayer::PlantTouchEnded( Touch *touch )
{
	Vec2 TouchBeginPoint = touch->getLocation();
	Point LayerLocalPoint = this->convertToNodeSpace( TouchBeginPoint );
	//设置地图类型
	Vec2 GrideIndex = MapCalculate::Calculate_GridIndex_ByPoint( LayerLocalPoint );
	//int RandNum = random(1,10);
	//if( RandNum % 2 == 0 )
	//{
	//	_GameEditorData->SetGameEditorElementTypeByRowCloumn( GrideIndex.y,GrideIndex.x,GameEditorElement_Tree1 );
	//}
	//else
	//{
		_GameEditorData->SetGameEditorElementTypeByRowCloumn( GrideIndex.y,GrideIndex.x,GameEditorElement_Tree2 );
	//}
}

void GameEditorControlLayer::PlantTouchMoved( Touch *touch )
{
	Vec2 TouchBeginPoint = touch->getLocation();
	Point LayerLocalPoint = this->convertToNodeSpace( TouchBeginPoint );

	//设置地图类型
	Vec2 GrideIndex = MapCalculate::Calculate_GridIndex_ByPoint( LayerLocalPoint );
	//int RandNum = random(1,10);
	//if( RandNum % 2 == 0 )
	//{
	//	_GameEditorData->SetGameEditorElementTypeByRowCloumn( GrideIndex.y,GrideIndex.x,GameEditorElement_Tree1 );
	//}
	//else
	//{
		_GameEditorData->SetGameEditorElementTypeByRowCloumn( GrideIndex.y,GrideIndex.x,GameEditorElement_Tree2 );
	//}
}

void GameEditorControlLayer::EraseTouchBegan( Touch *touch )
{

}

void GameEditorControlLayer::EraseTouchMoved( Touch *touch )
{
	Vec2 TouchBeginPoint = touch->getLocation();
	Point LayerLocalPoint = this->convertToNodeSpace( TouchBeginPoint );

	//设置地图类型
	Vec2 GrideIndex = MapCalculate::Calculate_GridIndex_ByPoint( LayerLocalPoint );
	_GameEditorData->SetGameEditorElementTypeByRowCloumn( GrideIndex.y,GrideIndex.x,GameEditorElement_Terrain );
}

void GameEditorControlLayer::EraseTouchEnded( Touch *touch )
{
	Vec2 TouchBeginPoint = touch->getLocation();
	Point LayerLocalPoint = this->convertToNodeSpace( TouchBeginPoint );

	//设置地图类型
	Vec2 GrideIndex = MapCalculate::Calculate_GridIndex_ByPoint( LayerLocalPoint );
	_GameEditorData->SetGameEditorElementTypeByRowCloumn( GrideIndex.y,GrideIndex.x,GameEditorElement_Terrain );
}

void GameEditorControlLayer::SetEarseState( Ref* pSender )
{
	_UILayerState = Erase_State;
}

void GameEditorControlLayer::SetPlantState( Ref* pSender )
{
	_UILayerState = Plant_State;
}