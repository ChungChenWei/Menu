#ifndef MOUSE_H
#define MOUSE_H
#include"include.h"


using namespace std;
void mouse(const int x,const int y,const int distance,const int row,const int left,const int right,const int where)
{
	gotoxy(x-left,y+(row-1)*distance);
	cout<<">";
	gotoxy(x+right,y+(row-1)*distance);
	cout<<"<";
	gotoxy(x+where,y+(row-1)*distance);
}
void mouse_d(const int x,const int y,const int distance,const int row,const int left,const int right,const int where)
{
	gotoxy(x-left,y+(row-1)*distance);
	cout<<" ";
	gotoxy(x+right,y+(row-1)*distance);
	cout<<" ";
	gotoxy(x+where,y+(row-1)*distance);
}
#endif
