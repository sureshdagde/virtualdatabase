
int CreateTable(char CommandWord[][233],int NumberOfTableContent,char mount[500])
{
	printf("%d\n",NumberOfTableContent);
	int i=3;
	char CollectionPath[500]="/home/suresh/Desktop/searcer/Database/";
	                    
	//char extention[50]=".txt";
	FILE *fp;
		strcat(CollectionPath,mount);
		strcat(CollectionPath,"/");
		//printf("%s\n",CollectionPath);
		strcat(CollectionPath,CommandWord[2]);
		//printf("%s\n",CollectionPath);
    fp=fopen(CollectionPath,"a+");
	
    if(fp==NULL)
	{
		printf("enable to open");
		//exit(1);
	}
	else
	{
		//printf("\n%s\n",CommandWord);
		//fputs("welcome",fp);
		while(i<NumberOfTableContent)
		{
		fprintf(fp,"%d",strlen(CommandWord[i]));
		i=i+2;
		}
		i=3;
		while(i<NumberOfTableContent)
			{
			fputs("\n",fp);
			fprintf(fp,"%s",CommandWord[i]);
			
			i=i+2;	}
		fclose(fp);
	printf("Collection  create Succesfully");
	}
	return 0;
}
