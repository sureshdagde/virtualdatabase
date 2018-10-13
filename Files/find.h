
int findall(char Db[],char collection[],char cmdword[],char a[])
{
	
	int limit;
	limit=atoi(a);
   int i=1,done=1;
   int position1,position2,position3;
  char c,s[1000];
  	//printf("%s------\n"	,collection);
    char file_name[500]="/home/suresh/Desktop/searcer/Database/";
    strcat(file_name,Db);
    strcat(file_name,"/"); 
    strcat(file_name,collection);
 
   FILE *fp;
   fp=fopen(file_name,"r");
   if(fp==NULL)
   {
   	printf("could not open");
   }
   else
   {
   	fseek(fp,0,0);
	fscanf(fp,"%s",s);
	fscanf(fp,"%s",s);
   	
   	position1=ftell(fp);
	   
	   	while((c=fgetc(fp))!=EOF && done)
	   	{	
	   		
	   		if(c==';');
	   				{position1=ftell(fp);		
	   	//printf("@%d\n",position1);}
	   		fscanf(fp,"%s",s);
	   	
	   		if(!strcmp(s,cmdword))
	   		{
	   			if(i>=limit)
	   				done=0;
	   			i++;
	   			position2=ftell(fp);
	   			//printf("&%d\n",position2);
	   			position3=position2- position1;
	   			
	   			fseek(fp,-position3,1);
	   			
	   			fscanf(fp,"%s",s);
	   			
	   			
	   				
	   			
	   			
	   			while(strcmp(s,";"))
	   			{
	   				
	   				printf("%s\t",s);
	   				fscanf(fp,"%s",s);
	   				//fseek(fp,-1,1);			
	   			}
	   			printf("\n");
	   		}
	   		
	   	}       
	  }
	}
}
