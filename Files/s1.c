#include <stdio.h>
#include <string.h>
main()
{

	int position;
	position=3;
	int i=0,j=0;
	char p[30][50];
	char c;
	FILE *fp=fopen("/home/suresh/Desktop/searcer/Files/s1.txt","a+");
	if(fp==NULL)
		{printf("fsdf");}
	else{
	rewind(fp);
	fseek(fp,3,0);
	
		while(i<3)
		{
			while((c=fgetc(fp))!='\t')
			{	
				p[i][j]=c;
				j++;
			}
			p[i][j]='\0';
			j=0;
			i++;

		}
		i=0;
		j=0;
		printf("%s\n",p[0]);
		while(i<3)
		{
			while(p[i][j]!='\0')
			{	
				printf("%c",p[i][j]);
				j++;
			}
			printf("\n");
			j=0;
			i++;

		}	

		
    }














/*
	int a=0,done=1;
	char p[22];
	char c;
	char d[]="suresh";
	FILE *fp=fopen("/home/suresh/Desktop/searcer/Files/s1.txt","a+");
	if(fp==NULL)
		{printf("fsdf");}
	else{
	rewind(fp);
	fseek(fp);

	fseek(fp,3,0);
	
		while(done)
		{
			while()
			if((c=fgetc(fp))!='\t')
			{	
				p[a]=c;
				a++;
			}
			else
			{
				done=0;
			}
		}
		
	
	printf("%s",p);
	strcpy(p,d);
	printf("%s",p);
	fclose(fp);
	}*/
}