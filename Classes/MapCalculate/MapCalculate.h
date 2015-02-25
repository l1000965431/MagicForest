//
//  GameEdotorUILayer.h
//  MagicForest
//  ��ͼ��ѧ������
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
		//���ݵ��xyλ�ü�����
		static int Calculate_Row_ByPoint( const Vec2& );

		//���ݵ��xyλ�ü�����
		static int Calculate_Cloumn_ByPoint( const Vec2& );

		//�������м�����ӵ�λ��( ��λ���Ǹ���ê���λ�ã�0.5,1.0�� )
		static Vec2 Calculate_GridPoint_ByRowCloumn( const int nRow,const int nCloumn );

		//���ݵ��XYλ�ü�����ӵ��±�
		static Vec2 Calculate_GridIndex_ByPoint( const Vec2& );

		//��������������к�
		static int  Calculate_RowPoint_ByRow( const int nRow );

		//��������������к�
		static int  Calculate_CloumnPoint_ByRow( const int nCloumn );
	};
}