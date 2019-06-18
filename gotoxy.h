#ifndef GOTOXY_H
#define GOTOXY_H
#include"include.h"

using namespace std;

void gotoxy(int xpos, int ypos)
{
  COORD scrn;
  HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
  scrn.X = xpos; scrn.Y = ypos;
  SetConsoleCursorPosition(hOuput,scrn);
}

void cout_xy(int x,int y,const char * s)
{
	gotoxy(x,y);
	cout<<s;
}

void clean_xy(int x,int y,int num)
{
	gotoxy(x,y);
	for(int i=0;i<num;i++)
	{
		cout<<" ";
	}
	gotoxy(x,y);	
}
#endif
