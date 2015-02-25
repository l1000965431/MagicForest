//
//  GameEdotorUILayer.h
//  MagicForest
//  地图数学计算类
//  Created by liumin on 15/2/19.
//
//
#include "common.h"

namespace Calculate
{
	static const int g_MaxGrideWidth = 50;
	static const int g_MaxGrideHight = 50; 

	class MapCalculate
	{
	public:
		//根据点的xy位置计算行
		static int Calculate_Row_ByPoint( const Vec2& );

		//根据点的xy位置计算列
		static int Calculate_Cloumn_ByPoint( const Vec2& );

		//根据行列计算格子的位置( 该位置是格子锚点的位置（0.5,1.0） )
		static Vec2 Calculate_GridPoint_ByRowCloumn( const int nRow,const int nCloumn );

		//根据点的XY位置计算格子的下标
		static Vec2 Calculate_GridIndex_ByPoint( const Vec2& );

		//计算行坐标根据行号
		static int  Calculate_RowPoint_ByRow( const int nRow );

		//计算列坐标根据列号
		static int  Calculate_CloumnPoint_ByRow( const int nCloumn );
	};
}