int ConnectDB()
{
	char zero[20];
	char username[20];
	char password[20];
	char oldusername[20];
	char oldpassword[20];
	printf("enter the  username--->\n");
	gets(username);
	printf("enter the password--->\n");
	gets(password);
	FILE *fp;
	fp=fopen("/home/suresh/Desktop/searcer/Database/login.txt","r+");
	if(fp==NULL)
	{
		printf("could not open");
	}
		fscanf(fp,"%s[^\n]",zero);
		fscanf(fp,"%s[^\n]",oldusername);
		fscanf(fp,"%s[^\n]",oldpassword);
		printf("%s",oldusername);
		printf("\n%s",oldpassword);
		if(!strcmp(username,oldusername) && !strcmp(password,oldpassword))
		{
			printf("connection establised succesfully\n");
			return 1;
		}
printf("could not connect");
 return 0;

}