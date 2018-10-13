insert_value(char db[],char collection[],char cmdword[])
{
	char n[2];
	int i=0;
	int count=1;
	char path[100]="/home/suresh/Desktop/searcer/Database/";
	strcat(path,db);
	strcat(path,"/");
	strcat(path,collection);
	FILE *fp;
	fp=fopen(path,"a+");
	if(fp==NULL)
		{
		printf("enable to open\n");
		}
	else
		{
			fseek(fp,2,0);
			fscanf(fp,"%s",n);
			printf("%s",n);
			while((cmdword[i]!='}') && (i<strlen(cmdword)))
				{
					if(cmdword[i]==',')
					{
						count++;
					}
					i++;
				}
				printf("--------->%d\n",atoi(n));
				if(count==atoi(n))
				{
					fputc('\n',fp);
					i=1;
					while((cmdword[i]!='}') && (i<strlen(cmdword)))
						{
							if(cmdword[i]==',')
							{
								fputc('\t',fp);
							}
							else
							{
								fputc(cmdword[i],fp);	
							}
						
						i++;
						}
						putc('\t',fp);
						fputc(';',fp);
						
				}
				else if(count<atoi(n))
				{
					printf("Not inserted [Error] less values");
				}
				else
				{
					printf("Not inserted [Error] more value");
				}

		
			fclose(fp);
		}
	
}