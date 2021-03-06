//
//  GameEditorControlLayer.h
//  MagicForest
//  用户编辑器的UI控制层 全部以消息通知的形式 通知界面层改变
//  Created by liumin on 15/2/19.
//
//

#ifndef __MagicForest__GameEditorControlLayer__
#define __MagicForest__GameEditorControlLayer__

#include "common.h"
#include "GameLayerBase.h"

class GameEditorData;

enum UILayerState
{
	None_State,                    //初始状态
	Plant_State,                   //种植状态
	Erase_State,                   //擦除状态
	Entrance_State,                //设置起点状态
	Exite_State,                   //设置终点状态
};

class GameEditorControlLayer:public GameLayerBase
{
public:
	GameEditorControlLayer();
	virtual ~GameEditorControlLayer();
	bool init() override;
	CREATE_FUNC( GameEditorControlLayer );
	static GameEditorControlLayer* create( GameEditorData* );
	virtual void onEnter() override;
	virtual void InitLayer() override;
public:
	virtual bool onTouchBegan(Touch *touch, Event *unused_event) override;
	virtual void onTouchMoved(Touch *touch, Event *unused_event) override;
	virtual void onTouchEnded(Touch *touch, Event *unused_event) override;

private:
	//种植状态下的操作
	void PlantTouchBegan( Touch *touch );
	void PlantTouchMoved( Touch *touch );
	void PlantTouchEnded( Touch *touch );

	//删除状态下的操作
	void EraseTouchBegan( Touch *touch );
	void EraseTouchMoved( Touch *touch );
	void EraseTouchEnded( Touch *touch );

	void SetPlantState( Ref* pSender );
	void SetEarseState( Ref* pSender );

private:
	UILayerState _UILayerState;
	GameEditorData* _GameEditorData;
};
#endif /* defined(__MagicForest__GameEditorControlLayer__) */
