count(char Db[],char collection[])
{
	int i=-1;
	char c;
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
   	//fseek(fp,2,0);
	
	   	while((c=fgetc(fp))!=EOF)
	   	{	
	   		
	   		if(c==';')
	   		i++;
		}
	}
printf("%d",i);
}