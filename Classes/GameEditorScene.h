//
//  GameEditorScene.h
//  MagicForest
//  �û��༭������
//  Created by liumin on 15/2/19.
//
//

#include "common.h"
#include "GameSceneBase.h"

class GameEditorScene:public GameSceneBase
{
public:
	GameEditorScene();
	virtual ~GameEditorScene();
	CREATE_FUNC( GameEditorScene );

public:
	virtual void InitScene() override;
};