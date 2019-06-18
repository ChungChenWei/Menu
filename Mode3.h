#ifndef MODE3_H
#define MODE3_H
#include"include.h"

void Mode3(FILE *fin)
{

	if(!fin)
	{
        cout<<"目前還沒有任何資料喔!!"<<endl;
    }
	else
	{
		while(!feof(fin))
		{
			printf("%c",fgetc(fin));
		}
	}
	getch();	
}

#endif
