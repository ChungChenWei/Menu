#ifndef MODE3_H
#define MODE3_H
#include"include.h"

void Mode3(FILE *fin)
{

	if(!fin)
	{
        cout<<"�ثe�٨S�������Ƴ�!!"<<endl;
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
