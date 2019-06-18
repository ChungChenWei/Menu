#ifndef MODE2_H
#define MODE2_H
#include"include.h"

#define max 101           //腹絏礟计秖 
#define row_right_title 5 //睲虫夹繷 ︽计 
#define row_kind    6     //都珇贺摸 ︽计 
#define row_number  7     //璹虫计秖 ︽计 
#define row_money   8     //肂陪ボ ︽计 
#define row_recheck 11    //絋粄璹虫 ︽计 

#define drink_kinds 2     //都贺计 

#define price           29   //虫狹基
#define discount_num    4    //疭基狹计 
#define discount_price  100  //疭基基 


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
