#include"include.h"

#define str 2   //�}�l��� 
#define lim 5   //���ƶq 
#define left 5
#define right 25
#define where 10

int menu(const int a,const int b)
{ 
	startmode(a,b);
	mouse(a,b,b,str,left,right,where);
	int mode=str,mode_d=str;
	int c1,c2;
	do
	{
		mode_d=mode;
		c1=getch();
		if(c1==224)
		{
			c2=getch();
			switch(c2)
			{
             case 72://�W 
				 mode--;
				 break;
             case 80://�U 
				 mode++;
				 break;
			}
			
		}
		if(mode<str)
		{
			mode=lim;
		}
		else if(mode>lim)
		{
			mode=str;
		}
		mouse_d(a,b,b,mode_d,left,right,where);
		mouse(a,b,b,mode,left,right,where);
	}while(c1!=13);
    return --mode; 
}
