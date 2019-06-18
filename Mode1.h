#ifndef MODE1_H
#define MODE1_H
#include"include.h"

#define max 101           //號碼牌數量 
#define row_right_title 5 //清單標頭 行數 
#define row_kind    6     //飲品種類 行數 
#define row_number  7     //訂單數量 行數 
#define row_money   8     //金額顯示 行數 
#define row_recheck 11    //確認訂單 行數 

#define drink_kinds 2     //飲料種數 

#define price           29   //單杯價格
#define discount_num    4    //特價杯數 
#define discount_price  100  //特價價格 


void Mode1_right(int waiting,int kind1,int kind2,int row);
void Mode1_clean(int order_row);
int Order(int);
void show_order(int next_num,int kind,int kind_num,int order_row);

void Mode1(FILE *fout,FILE *ftmp)
{
	int next_num=1,waiting_num=1,row_right=1,income=0;
	int list[max][2+drink_kinds];//號碼、雪碧、可樂、總額 
	
	//檔案輸出標題 
	fprintf(fout,"號碼\t雪碧\t可樂\t總金額\t累計收入\n");
	//fprintf(ftmp,"測試輸入完成");
	//fflush(ftmp);
	fflush(fout);
	//檔案輸出完成 
	
	cout_xy(1,1,"歡迎使用214點單系統!\n\n");
	
	char a[2];
	loopall:
	int num=0,mo=0,inm=0,first=0;
		
	frame();
	
	//list reset
	list[row_right][0]=next_num;
	list[row_right][1]=0;
	list[row_right][2]=0;
	list[row_right][3]=0;
	//
	 
    //目前已知Bug 若輸入非數字 則陷入循環 
	gotoxy(1,4);
	printf("目前抽單號碼是 %d 號!\t\t\t\t\t\t\t\t目前等單號碼是 %d 號!",next_num,waiting_num);
	cout_xy(1,row_right_title,"\t\t\t\t\t\t\t\t\t\t號碼\t雪碧\t可樂");
	cout_xy(1,2,"請選擇模式(1.點單 2.出貨 3.特定出貨 4.取消訂單 5.離開): ");
	clean_xy(57,2,5);
	int test=scanf("%d",&mo);
	if(!test)
	{
		scanf("%s",a);
		goto loopall;
	}
	
	//功能鍵 
	/*
	char c1,c2;
	
	c1=getch();
	if(c1==(0))
	{
		c2=getch();
		switch(c2)
		{
         case 59:
			 cout<<"F1";
			 break;
         case 60:
			 cout<<"F2";
			 break;
         case 61:
			 cout<<"F3";
			 break;
         case 62:
			 cout<<"F4";
			 break;
		}
	}
	mo=(c1-'0');
	*/ 
	
	switch(mo)
	{
		case 1:
			{
			char finish;
			//點餐區                                 目前已知Bug 若輸入非數字 則陷入循環 
			int order_row=1;
			order_loop:
			int drink_kind = Order(first);
			int in=0;
			
			int test1,test2;
			first++;
			switch(drink_kind)
			{
				case -2:
					Mode1_clean(order_row);//左邊清理
					goto loopall;
				case 0:
					cout_xy(1,row_number,"數量: ");
					//in=1;
					//cin>>in;
					test2=scanf("%d",&in);
					if(!test2)
					{
						scanf("%s",a);
						goto order_loop;
					}
					cout_xy(7,row_number,"        ");
					num+=in;
					list[row_right][1]+=in;
					show_order(next_num,drink_kind,in,order_row);
					++order_row;
					goto order_loop;
				case 1:
					cout_xy(1,row_number,"數量: ");
					//in=1;
					//cin>>in;
					test1=scanf("%d",&in);
					if(!test1)
					{
						scanf("%s",a);
						goto order_loop;
					}
					cout_xy(7,row_number,"        ");
					num+=in;
					list[row_right][2]+=in;
					show_order(next_num,drink_kind,in,order_row);
					++order_row;
					goto order_loop;
				default:
				case -1:
					break;	
			}
			//點餐結束 
			
			//算錢區 
			int sum;
			sum=price*(num%discount_num)+discount_price*(num/discount_num);
			//完成結算 
			
			//找錢區
			loop: 
			gotoxy(1,row_money);
			printf("共 %d 杯\n#應收: %d \t實收:          ",num,sum);
			gotoxy(22,row_money+1);
			//inm=50;
			scanf("%d",&inm);
			gotoxy(1,row_money+2);
			if(sum>inm)
			{
				printf("給的錢太少了!");
				goto loop;
			}
			else
			{
				clean_xy(1,row_money+2,13);
				printf("找零: %d",inm-sum);
				//getch();
			}
			//找錢完成
			
			//確認訂單 
			cout_xy(1,row_recheck,"確認訂單!");
			cout_xy(1,row_recheck+2+order_row,"謝謝您的光臨!");
			getch();
			//完成訂單 
			
			//list input
			list[row_right][3]=sum;
			//
			
			Mode1_clean(order_row);//左邊清理
			
			//等候區 
			Mode1_right(list[row_right][0],list[row_right][1],list[row_right][2],row_right);
			//
			
			++next_num;
			++row_right;
			
			goto loopall;
			}
		
		case 2:
			//等候區若空 
			if(row_right==1)
			{
				goto loopall;
			}
			
			income+=list[1][3];//紀錄總額 
			
			//輸出檔案 
			fprintf(fout,"%d\t%d\t%d\t%d\t%d\n",list[1][0],list[1][1],list[1][2],list[1][3],income);
			fflush(fout);
			//輸出完成 
			
			clean_xy(80,row_right_title+1,40);
			
			//更新等候區 
			for(int i=1+1;i<=row_right;i++)
			{
				Mode1_right(list[i][0],list[i][1],list[i][2],i-1);
				list[i-1][0]=list[i][0];
				list[i-1][1]=list[i][1];
				list[i-1][2]=list[i][2];
				list[i-1][3]=list[i][3];
			}
			clean_xy(80,row_right_title+row_right-1,40);
			++waiting_num;
			--row_right;
			goto loopall;
		
		case 3:
		case 4:
			{
			//等候區空 
			if(row_right==1)
			{
				goto loopall;
			}
			
			//選擇區 
			mouse(78,row_right_title+1,1,1,0,23,0);			
			int mode1=1,mode1_d=1,lim1=row_right;
			int c1,c2;
			do
			{
				mode1_d=mode1;
				c1=getch();
				if(c1==224)
				{
					c2=getch();
					switch(c2)
					{
    		         case 72://上 
						 mode1--;
						 break;
     		        case 80://下 
						 mode1++;
						 break;
					}
				}
				if(mode1<1)
				{
					mode1=lim1-1;
				}
				else if(mode1>lim1-1)
				{
					mode1=1;
				}
				mouse_d(78,row_right_title+1,1,mode1_d,0,23,0);
				mouse(78,row_right_title+1,1,mode1,0,23,0);
			}while(c1!=13);
			mouse_d(78,row_right_title+1,1,mode1_d,0,23,0);
			//完成選擇 
			
			//輸出檔案 
			if(mo==3)
			{
				income+=list[mode1][3];//紀錄總額 
				fprintf(fout,"%d\t%d\t%d\t%d\t%d\n",list[mode1][0],list[mode1][1],list[mode1][2],list[mode1][3],income);
				fflush(fout);
			}
			//輸出完成 
			
			clean_xy(80,row_right_title+mode1,40);
			
			//更新等候區 
			for(int i=mode1+1;i<=row_right;i++)
			{
				Mode1_right(list[i][0],list[i][1],list[i][2],i-1);
				list[i-1][0]=list[i][0];
				list[i-1][1]=list[i][1];
				list[i-1][2]=list[i][2];
				list[i-1][3]=list[i][3];
			}
			clean_xy(80,row_right_title+row_right-1,40);
			++waiting_num;
			--row_right;
			goto loopall;
			}
			
		case 5:
			break;
			
			
		default:
			goto loopall;
			
		
	}
} 

void Mode1_right(int waiting,int kind1,int kind2,int row)
{
	gotoxy(1,row_right_title+row);
	printf("\t\t\t\t\t\t\t\t\t\t%d\t%d    \t%d    ",waiting,kind1,kind2);
}

void Mode1_clean(int order_row)
{
	for(int i=row_kind;i<=(row_recheck+2+order_row);i++)
	clean_xy(1,i,30);
	
}

int Order(int first)
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
    		         	 cout<<drink<<" 左\n";
						 drink--;
						 break;
     		         case 77://右 
     		        	 cout<<drink<<" 右\n";
						 drink++;
						 break;
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
				}
				else if(d1!=13&&(!first))
				{
					drink=-2;
					break;
				}
				else if(d1!=13&&(first))
				{
					drink=-1;
					break;
				}
				
			}while(d1!=13);
			//完成選擇
			first++;
			return drink;
}

void show_order(int next_num,int kind,int kind_num,int order_row)
{
	cout_xy(1,row_recheck+1,"號碼\t飲品種類\t數量");
	gotoxy(1,row_recheck+order_row+1);
	if(kind==0)
	printf(" %d\t  %s  \t%d",next_num,"雪碧",kind_num);
	else
	printf(" %d\t  %s  \t%d",next_num,"可樂",kind_num);
}

#endif
