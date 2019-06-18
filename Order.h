#ifndef Order_H
#define Order_H
#include"include.h"



int Order()
{
			//點餐區 
			cout_xy(1,row_kind,"飲品種類:   雪碧   可樂   ");
			mouse(11,row_kind,row_kind,1,0,7,3);		
			int drink=0,drink_d=1,limd=drink_kinds;
			int d1,d2;
			do
			{
				drink_d=drink;
				d1=getch();
				if(d1==224)
				{
					d2=getch();
					switch(d2)
					{
    		         case 75://左 
    		         	 //cout<<drink<<" 左\n";
						 drink--;
						 break;
     		         case 77://右 
     		        	 //cout<<drink<<" 右\n";
						 drink++;
						 break;
					}
				}
				if(drink<0)
				{
					drink=limd-1;
				}
				else if(drink>limd-1)
				{
					drink=0;
				}
				mouse_d(11+(7*drink_d),row_kind,row_kind,1,0,7,3);
				mouse(11+(7*drink),row_kind,row_kind,1,0,7,3);
			}while(d1!=13);
			mouse_d(11+(6*drink_d),row_kind,row_kind,1,0,7,3);
			//完成選擇
			return drink;
}
#endif

