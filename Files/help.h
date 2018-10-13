void help()
{
	FILE *fp;
	char s[50];
	fp=fopen("/home/suresh/Desktop/searcer/login/helpall.txt","r");
	if(fp==NULL)
	{
		printf("sorry");
	}
	else
	{
		
		while(getc(fp)!=EOF)
			{

				fscanf(fp,"%s",s);
				if(!strcmp(s,"end"))
					printf("\n");
				if(strcmp(s,"end"))
				printf("%s",s);
				printf(" ");
			}
	}
				
}//home/suresh/Desktop/searcer/Files/help.h