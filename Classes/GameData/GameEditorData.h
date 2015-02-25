//
//  GameEditorData.h
//  MagicForest
//  用户编辑器数据管理器
//
//  Created by liumin on 15/2/19.
//
//

#ifndef __MagicForest__GameEditorData__
#define __MagicForest__GameEditorData__

#include "common.h"
#include "GameEditorElement.h"

class GameEditorElement;

class GameEditorData:public Ref
{
public:
    GameEditorData();
    virtual ~GameEditorData();
	void InitGameEditorData( const int nMaxRow,const int nMaxCloumn );
	INITGLOBALCLASS( GameEditorData );

public:
	GameEditorElement* GetElementByRowCloumen( const int nRow, const int nCloumn ) const;

    void SetGameEditorElementTypeByRowCloumn( const int nRow, const int nCloumn,GameEditorElementType );
    
    int GetMaxRow() const;
    int GetMaxCloumn() const;
    
private:
    std::map<int, std::vector<GameEditorElement*>> _MapListGameEdirorMap;
};
#endif /* defined(__MagicForest__GameEditorData__) */
