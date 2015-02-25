//
//  GameEdotorUILayer.cpp
//  MagicForest
//
//  Created by liumin on 15/2/19.
//
//

#include "GameEdotorUILayer.h"
#include "GameEditorData.h"

GameEditorUILayer::GameEditorUILayer()
{
    
}

GameEditorUILayer::~GameEditorUILayer()
{
    
}

GameEditorUILayer* GameEditorUILayer::create( GameEditorData* pGameEditorData )
{
	GameEditorUILayer* pTemp = GameEditorUILayer::create(); 
	pTemp->_GameEditorData = pGameEditorData;
	return pTemp;
}

void GameEditorUILayer::InitLayer()
{
	//this->setAnchorPoint( Vec2( 0.f,0.f ) );
	//this->setContentSize( Size( 800,600 ) );

    int nMaxRow = _GameEditorData->GetMaxRow();
    int nMaxCloumn = _GameEditorData->GetMaxCloumn();
    
	this->setColor( Color3B( 255,0,0 ) );
	this->setOpacity( 100 );

    for( int i = 1; i <= nMaxRow; ++i )
    {
        for( int j = 1; j <= nMaxCloumn; ++j )
        {
            GameEditorElement* pTempElement = dynamic_cast<GameEditorElement*>(_GameEditorData->GetElementByRowCloumen(i, j) );
            
            if( pTempElement != nullptr )
            {
                this->addChild( pTempElement,nMaxRow-i );
                pTempElement->setPosition( 300+((j-1)%nMaxCloumn)*50,260+(i-1)*50 );
				pTempElement->SetGameEditorElementType( GameEditorElement_Terrain );
            }
        }
    }
}

