#include<stdio.h>
main() 
{

  int i=0,done=1;
   int position1,position2,position3;
  char c,s[1000];
  	//printf("%s------\n"	,collection);
    char file_name[500]="/home/suresh/Desktop/searcer/Database/abc/oo.txt";
    
   FILE *fp;
   fp=fopen(file_name,"r");
   if(fp==NULL)
   {
   	printf("could not open");
   }
   else
   {
   	fseek(fp,0,0);
	fscanf(fp,"%s",&s);
	fscanf(fp,"%s",&s);
   	
   	position1=ftell(fp);
	   
	   	while((c=fgetc(fp))!=EOF)
	   	{	
	   		
	   		if(c==';');
	   				position1=ftell(fp);		
	   	
	   		fscanf(fp,"%s",&s);
	   	
	   		if(!strcmp(s,"pune"))
	   		{
	   			position2=ftell(fp);
	   			
	   			position3=position2- position1;
	   			printf("%d\t%d\t%d\t",position1, position2 ,position3);
	   			fseek(fp,-11,1);
	   			
	   			fscanf(fp,"%s",&s);
	   			
	   			while(strcmp(s,";"))
	   			{
	   				
	   				printf("%s",s);
	   				fscanf(fp,"%s",&s);
	   				//fseek(fp,-1,2);			
	   			}
	   		}
	   		
	   	}       
	  }
	}
