
int SelectAll(char Db[],char collection[])
{
   int i=0;
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
   	//printf("%s",file_name);
	   	while((c=getc(fp))!=EOF)
	   	{
        if(c!=';')
	   		printf("%c",c);
	   	}
    }
}