/*///////////////////////////////////////////////////////////////////////////////
--����:seele
--����˵��:��Ϸ�����Ļ�����
///////////////////////////////////////////////////////////////////////////////*/
#pragma once
#include "common.h"

class GameSceneBase:public Scene
{
public:
	GameSceneBase();
	virtual ~GameSceneBase();
	virtual bool init() override;

public:
	virtual void InitScene() = 0;
};
