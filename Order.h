#ifndef Order_H
#define Order_H
#include"include.h"



int Order()
{
			//�I�\�� 
			cout_xy(1,row_kind,"���~����:   ����   �i��   ");
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
    		         case 75://�� 
    		         	 //cout<<drink<<" ��\n";
						 drink--;
						 break;
     		         case 77://�k 
     		        	 //cout<<drink<<" �k\n";
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
			//�������
			return drink;
}
#endif

