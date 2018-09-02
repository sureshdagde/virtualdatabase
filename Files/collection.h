
int CreateTable(char CommandWord[][233],int NumberOfTableContent,char mount[500])
{
	char path[500]="/home/suresh/Desktop/searcer/Database/";
	char CollectionPath[500]="/home/suresh/Desktop/searcer/Database/";
	char extention[50]=".txt";

	
	int WordCount=0;
	int TableContentCount=4,word=0,WordCharacter=0,flag=1;
	char FileWord[233][233],ch;
	
	FILE *fp,*File;
	strcat(path,"AllFile.txt");
	File=fopen(path,"a+");
	printf("%s\n",CollectionPath);

	if(File==NULL)
	{
		printf("enable to open");
		exit(1);
	}
	else
	{

		while((ch=fgetc(File))!=EOF)
		{
			if(ch=='.')
			{
				word++;
				WordCharacter=0;
				ch=fgetc(File);		
			}
			FileWord[word][WordCharacter]=ch;
			WordCharacter++;
		}
	}
	
	while(WordCount<=word && flag)
	{
		if(!strcmp(FileWord[WordCount],CommandWord[2]))
		{
		flag=0;	
		}
		WordCount++;
	}

	if(flag)
	{
		
		fputs(CommandWord[2],File);
		fputs(".",File);	
		strcat(CommandWord[2],extention);
		strcat(CollectionPath,mount);
		strcat(CollectionPath,"/");
		strcat(CollectionPath,CommandWord[2]);
		
		printf("%s\n",CollectionPath);

		fp=fopen(CollectionPath,"w");
		while(TableContentCount<=NumberOfTableContent)
		{
			fputs(CommandWord[TableContentCount],fp);
			fputs("\t",fp);
			TableContentCount=TableContentCount+2;
		}
		printf("Table create Succesfully");
	}
	else
	{
		printf("table Allready Exist");
	}
	
return 0;
}