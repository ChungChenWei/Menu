
#include"include.h"
#include <iostream>
#include <stdio.h> 
#include <conio.h> 

#define a 70    //���D�Y�� 
#define b 7     //���D��Z 

int main()
{ 
	bool used_new=false;
	bool used_old=false;
	//char filename_tmp[30];
	
	//�ɶ��ɦW�غc
	time_t t=time(0);
	char time[30];
	char time_tmp[30];
	//
	
	//�ɮ׫غc 
	FILE *file, *ftmp;
	//
	
	loop:
	int mode=menu(a,b);
	switch(mode)
	{
	case 1:
		strftime(time,sizeof(time),"%Y�~%m��%d��%H��%M��������",localtime(&t));
		clean();
		file=fopen(time,"wt");
		
		/*�W������ 
		//memcpy(time_tmp,time,sizeof(time_tmp));
		//ftmp=fopen("�W������","wt");
		//fprintf(ftmp,time_tmp);
		//fflush(ftmp);
		*/ 
		
		Mode1(file,ftmp);
		fclose(file);
		//fclose(ftmp);
		clean();
		used_new=true;
		goto loop;
	case 2:
		/*
		clean();
		
		ftmp=fopen("�W������","rt");
		fscanf(ftmp,"%s",&filename_tmp);
		file=fopen(filename_tmp,"wt");
		
		Mode2(file,ftmp,filename_tmp);
		fclose(file);
		fclose(ftmp);
		clean();
		used_new=false;
		used_old=true;	
		*/
		goto loop;
	case 3:
		clean();
		if(used_new)
		printf("%s\n",time);
		else if(used_old)
		printf("%s\n",time_tmp);
		file=fopen(time,"rt");
		Mode3(file);
		fclose(file);
		clean();
		goto loop;
	case 4:
		break;
		
	}
	return 0;
		
}


