#ifndef STARTMODE_H
#define STARTMODE_H
#include"include.h"
using namespace std;
void startmode(const int a,const int b)
{
	system("mode 150");
	frame();
	gotoxy(0,0);
	cout_xy(a,b,  "歡迎使用214點單程式!");
	cout_xy(a,2*b,"開    始    使    用");
	cout_xy(a,3*b,"上    次    記    錄");
	cout_xy(a,4*b,"讀    取    報    表");
	cout_xy(a,5*b,"離    開    程    式");
}
#endif
