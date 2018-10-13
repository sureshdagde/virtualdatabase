void HelpSpecific(char search[])
{
	FILE *fp;
	char s[20],c;
	int back=strlen(search);
	back+=1;
	fp=fopen("/home/suresh/Desktop/searcer/login/help.txt","r");
	if(fp==NULL)
	{
		printf("sorry");
	}
	else
	{
		
		while(getc(fp)!=EOF)
		{

				fscanf(fp,"%s",s);
				//printf("%s",s);
				if(!strcmp(s,search))
					{
						fseek(fp,-back,1);
						c=fgetc(fp);
						while(c!=';')
						{
							c=fgetc(fp);
							printf("%c",c);
						}
						printf("\n");
					}
				//		fseek(fp,-1,1);
				//		printf("%c",getc(fp));
		}
	}
}