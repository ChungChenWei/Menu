#ifndef MAP_H
#define MAP_H
#include"include.h"
#define mapx 150    //�e�� 
#define mapy 42     //���� 
using namespace std;

/*
�o�O�@�ӫإ���ت��N�X 
�����f�tsystem("mode �e") 
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
