#ifndef STARTMODE_H
#define STARTMODE_H
#include"include.h"
using namespace std;
void startmode(const int a,const int b)
{
	system("mode 150");
	frame();
	gotoxy(0,0);
	cout_xy(a,b,  "�w��ϥ�214�I��{��!");
	cout_xy(a,2*b,"�}    �l    ��    ��");
	cout_xy(a,3*b,"�W    ��    �O    ��");
	cout_xy(a,4*b,"Ū    ��    ��    ��");
	cout_xy(a,5*b,"��    �}    �{    ��");
}
#endif
