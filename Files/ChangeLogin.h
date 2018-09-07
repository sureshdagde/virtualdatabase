int ChangeLogin()
{
	char username[20];
	char password[20];
	char newusername[20];
	char newpassword[20];
	char oldusername[20];
	char oldpassword[20];
	char rcu[20],rcp[20];
	char zero[2];
	int done=1;
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
		//printf("%s",oldusername);
		//printf("\n%s",oldpassword);
	if(!strcmp(username,oldusername) && !strcmp(password,oldpassword))
	{
			printf("\nyou can change\n");
			

		while(done)
		{

			
			printf("enter the new username---->");
			gets(newusername);
			if(strlen(newusername)<=4)
				{
					printf("Error-->UserName must be greter then 4 character\n");

					continue;
				}
			
			printf("enter the new password---->");
			gets(newpassword);
			    if(strlen(newpassword)<=4)
				{
					printf("Error-->password must be greter then 4 character\n");
					printf("NOTE-->please enter username again\n");
					continue;
				}
				printf("conform the UserName and Password\n");
				printf("Confermation--enter the UserName--->");
				gets(rcu);
				printf("Confermation--enter the password--->");
				gets(rcp);
				
				if(!strcmp(newusername,rcu) && !strcmp(newpassword,rcp))
				{
					fp=fopen("/home/suresh/Desktop/searcer/Database/login.txt","w+");
					fprintf(fp,"%d",0);
					fprintf(fp,"%d",1);
					fprintf(fp,"%s","\n");
					fprintf(fp,"%s",newusername);
					fprintf(fp,"%s","\n");
					fprintf(fp,"%s",newpassword);
					fclose(fp);
					done=0;
				}
				else
				{
					printf("Not Match please create login again\n");
				}
		}

	}
	else
	{
		printf("sorry you can not chage ");
	}
		return 0;

}


