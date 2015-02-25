//
//  GameEditorData.cpp
//  MagicForest
//
//  Created by liumin on 15/2/19.
//
//

#include "GameEditorData.h"

INITSTATICVALUE(GameEditorData)

GameEditorData::GameEditorData()
{
   InitGameEditorData( 5,10 );
}

GameEditorData::~GameEditorData()
{
    
}

void GameEditorData::InitGameEditorData(const int nMaxRow, const int nMaxCloumn)
{
    for( int i = 1; i <= nMaxRow; ++i )
    {
        std::vector<GameEditorElement*> vecElement;
        vecElement.resize( nMaxCloumn );
        vecElement.reserve(nMaxCloumn);
        for (int j = 0; j < nMaxCloumn; ++j)
        {
            GameEditorElement* pTemp = GameEditorElement::create();
            vecElement[j] = pTemp;
        }
        
        _MapListGameEdirorMap[i] = vecElement;
    }
}



GameEditorElement* GameEditorData::GetElementByRowCloumen(const int nRow, const int nCloumn) const
{
    return _MapListGameEdirorMap.at(nRow).at( nCloumn-1 );
}

void GameEditorData::SetGameEditorElementTypeByRowCloumn(const int nRow, const int nCloumn,GameEditorElementType Type)
{
    GetElementByRowCloumen( nRow,nCloumn )->SetGameEditorElementType( Type );
}

int GameEditorData::GetMaxRow() const
{
 return 5;
}

int GameEditorData::GetMaxCloumn() const
{
	return 10;
}
