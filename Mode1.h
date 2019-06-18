#ifndef MODE1_H
#define MODE1_H
#include"include.h"

#define max 101           //���X�P�ƶq 
#define row_right_title 5 //�M����Y ��� 
#define row_kind    6     //���~���� ��� 
#define row_number  7     //�q��ƶq ��� 
#define row_money   8     //���B��� ��� 
#define row_recheck 11    //�T�{�q�� ��� 

#define drink_kinds 2     //���ƺؼ� 

#define price           29   //��M����
#define discount_num    4    //�S���M�� 
#define discount_price  100  //�S������ 


void Mode1_right(int waiting,int kind1,int kind2,int row);
void Mode1_clean(int order_row);
int Order(int);
void show_order(int next_num,int kind,int kind_num,int order_row);

void Mode1(FILE *fout,FILE *ftmp)
{
	int next_num=1,waiting_num=1,row_right=1,income=0;
	int list[max][2+drink_kinds];//���X�B���ѡB�i�֡B�`�B 
	
	//�ɮ׿�X���D 
	fprintf(fout,"���X\t����\t�i��\t�`���B\t�֭p���J\n");
	//fprintf(ftmp,"���տ�J����");
	//fflush(ftmp);
	fflush(fout);
	//�ɮ׿�X���� 
	
	cout_xy(1,1,"�w��ϥ�214�I��t��!\n\n");
	
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
	 
    //�ثe�w��Bug �Y��J�D�Ʀr �h���J�`�� 
	gotoxy(1,4);
	printf("�ثe��渹�X�O %d ��!\t\t\t\t\t\t\t\t�ثe���渹�X�O %d ��!",next_num,waiting_num);
	cout_xy(1,row_right_title,"\t\t\t\t\t\t\t\t\t\t���X\t����\t�i��");
	cout_xy(1,2,"�п�ܼҦ�(1.�I�� 2.�X�f 3.�S�w�X�f 4.�����q�� 5.���}): ");
	clean_xy(57,2,5);
	int test=scanf("%d",&mo);
	if(!test)
	{
		scanf("%s",a);
		goto loopall;
	}
	
	//�\���� 
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
			//�I�\��                                 �ثe�w��Bug �Y��J�D�Ʀr �h���J�`�� 
			int order_row=1;
			order_loop:
			int drink_kind = Order(first);
			int in=0;
			
			int test1,test2;
			first++;
			switch(drink_kind)
			{
				case -2:
					Mode1_clean(order_row);//����M�z
					goto loopall;
				case 0:
					cout_xy(1,row_number,"�ƶq: ");
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
					cout_xy(1,row_number,"�ƶq: ");
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
			//�I�\���� 
			
			//����� 
			int sum;
			sum=price*(num%discount_num)+discount_price*(num/discount_num);
			//�������� 
			
			//�����
			loop: 
			gotoxy(1,row_money);
			printf("�@ %d �M\n#����: %d \t�ꦬ:          ",num,sum);
			gotoxy(22,row_money+1);
			//inm=50;
			scanf("%d",&inm);
			gotoxy(1,row_money+2);
			if(sum>inm)
			{
				printf("�������Ӥ֤F!");
				goto loop;
			}
			else
			{
				clean_xy(1,row_money+2,13);
				printf("��s: %d",inm-sum);
				//getch();
			}
			//�������
			
			//�T�{�q�� 
			cout_xy(1,row_recheck,"�T�{�q��!");
			cout_xy(1,row_recheck+2+order_row,"���±z�����{!");
			getch();
			//�����q�� 
			
			//list input
			list[row_right][3]=sum;
			//
			
			Mode1_clean(order_row);//����M�z
			
			//���԰� 
			Mode1_right(list[row_right][0],list[row_right][1],list[row_right][2],row_right);
			//
			
			++next_num;
			++row_right;
			
			goto loopall;
			}
		
		case 2:
			//���԰ϭY�� 
			if(row_right==1)
			{
				goto loopall;
			}
			
			income+=list[1][3];//�����`�B 
			
			//��X�ɮ� 
			fprintf(fout,"%d\t%d\t%d\t%d\t%d\n",list[1][0],list[1][1],list[1][2],list[1][3],income);
			fflush(fout);
			//��X���� 
			
			clean_xy(80,row_right_title+1,40);
			
			//��s���԰� 
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
			//���԰Ϫ� 
			if(row_right==1)
			{
				goto loopall;
			}
			
			//��ܰ� 
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
    		         case 72://�W 
						 mode1--;
						 break;
     		        case 80://�U 
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
			//������� 
			
			//��X�ɮ� 
			if(mo==3)
			{
				income+=list[mode1][3];//�����`�B 
				fprintf(fout,"%d\t%d\t%d\t%d\t%d\n",list[mode1][0],list[mode1][1],list[mode1][2],list[mode1][3],income);
				fflush(fout);
			}
			//��X���� 
			
			clean_xy(80,row_right_title+mode1,40);
			
			//��s���԰� 
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
    		         	 cout<<drink<<" ��\n";
						 drink--;
						 break;
     		         case 77://�k 
     		        	 cout<<drink<<" �k\n";
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
			//�������
			first++;
			return drink;
}

void show_order(int next_num,int kind,int kind_num,int order_row)
{
	cout_xy(1,row_recheck+1,"���X\t���~����\t�ƶq");
	gotoxy(1,row_recheck+order_row+1);
	if(kind==0)
	printf(" %d\t  %s  \t%d",next_num,"����",kind_num);
	else
	printf(" %d\t  %s  \t%d",next_num,"�i��",kind_num);
}

#endif
