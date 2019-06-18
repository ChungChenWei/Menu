#ifndef MAP_H
#define MAP_H
#include"include.h"
#define mapx 150    //寬度 
#define mapy 42     //長度 
using namespace std;

/*
這是一個建立邊框的代碼 
必須搭配system("mode 寬") 
*/

void frame()
{
	gotoxy(0,0);
	char map[mapy][mapx];
	memset(map,' ',sizeof(map));
	for(int i=0;i<mapy;i++)
	{
		for(int j=0;j<mapx;j++)
		{
			if(i==0||i==(mapy-1))
			{
				cout_xy(j,i,"#");
			}
			else if(j==0||j==(mapx-1))
			{
				cout_xy(j,i,"#");
			}		
		}
	}
	gotoxy(0,0);
}
#endif
