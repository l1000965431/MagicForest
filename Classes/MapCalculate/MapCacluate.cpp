#include "MapCalculate.h"

using namespace Calculate;

int MapCalculate::Calculate_Row_ByPoint( const Vec2& sPoint )
{
	int x = sPoint.x;
	return ( (x/g_MaxGrideHight)+1 );
}

int MapCalculate::Calculate_Cloumn_ByPoint( const Vec2& sPoint )
{
	int y = sPoint.y;
	return ( (y/g_MaxGrideWidth)+1 );
}

Vec2 MapCalculate::Calculate_GridPoint_ByRowCloumn( const int nRow,const int nCloumn )
{
   return Vec2( nCloumn*g_MaxGrideWidth+(g_MaxGrideWidth<<1),nRow*g_MaxGrideHight );
}

Vec2 MapCalculate::Calculate_GridIndex_ByPoint( const Vec2& sPoint )
{
	int nRow    = Calculate_Row_ByPoint( sPoint );
	int nCloumn = Calculate_Cloumn_ByPoint( sPoint );

	return Vec2( nRow,nCloumn );
}

int MapCalculate::Calculate_RowPoint_ByRow( const int nRow )
{
  return nRow*g_MaxGrideHight;
}

int MapCalculate::Calculate_CloumnPoint_ByRow( const int nCloumn )
{
	return (nCloumn*g_MaxGrideWidth+(g_MaxGrideWidth<<1));
}