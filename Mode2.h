#ifndef MODE2_H
#define MODE2_H
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
int Order();
void show_order(int next_num,int kind,int kind_num,int order_row);

void Mode2(FILE *fout,FILE *ftmp,const char *filename)
{
	cout<<filename;
	getch();
} 


#endif
