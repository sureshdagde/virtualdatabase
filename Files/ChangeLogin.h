ChangeLogin()
{
	char username[20];
	char password[20];
	char newusername[20];
	char newpassword[20];
	char oldusername[20];
	char oldpassword[20];
	char zero[2];
	
	printf("enter the old username--->\n");
	gets(username);
	printf("enter the old password--->\n");
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
			printf("\nyou can change\n");
			printf("enter the new username---->");
			gets(newusername);
			printf("enter the new password---->");
			gets(newpassword);
			fp=fopen("/home/suresh/Desktop/searcer/Database/login.txt","w+");
					fprintf(fp,"%d",0);
					fprintf(fp,"%d",1);
					fprintf(fp,"%s","\n");
					fprintf(fp,"%s",newusername);
					fprintf(fp,"%s","\n");
					fprintf(fp,"%s",newpassword);
					fclose(fp);

		}
		else
		{
			printf("sorry you can not chage ");
		}
}