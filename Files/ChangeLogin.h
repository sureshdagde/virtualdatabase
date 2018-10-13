int ChangeLogin()
{
	char username[20];
	//char password[20];
	char newusername[20];
	char newpassword[20];
	char oldusername[20];
	char oldpassword[20];
	char rcu[20],rcp[20];
	char zero[2];
	int done=1;
	printf("enter the old username:");
	gets(username);
	printf("\nenter the old password:");
	//gets(password);
	char *password=getpass("");
	FILE *fp;
	fp=fopen("/home/suresh/Desktop/searcer/system/login.txt","r+");
	if(fp==NULL)
	{
		printf("could not open");
		system("notify-send 'Error' 'could not open' ");
	}
		fscanf(fp,"%s[^\n]",zero);
		fscanf(fp,"%s[^\n]",oldusername);
		fscanf(fp,"%s[^\n]",oldpassword);
		//printf("%s",oldusername);
		//printf("\n%s",oldpassword);
	if(!strcmp(username,oldusername) && !strcmp(password,oldpassword))
	{
			printf("\nyou can change\n");
			system("notify-send 'Welocme' 'you can change' ");

		while(done)
		{

			
			printf("enter the new username:");
			gets(newusername);
			if(strlen(newusername)<=4)
				{
					printf("Error-->UserName must be greter then 4 character\n");
					system("notify-send 'Error' 'UserName must be greter then 4 character' ");
					continue;
				}
			
			printf("\nenter the new password:");
			//gets(newpassword);
			char *newpassword=getpass("");
			//printf("-->%s--",newpassword);
			    if(strlen(newpassword)<=4)
				{
					printf("Error-->password must be greter then 4 character\n");
					printf("NOTE-->please enter username again\n");
					system("notify-send 'Error' 'please enter username again'");
					continue;
				}
				printf("conform the UserName and Password\n");
				printf("Confermation:enter the UserName:");
				gets(rcu);
				if(!strcmp(newusername,rcu))
				{
				printf("Confermation:enter the password:");
				fflush(stdin);
				char *rcp=getpass("");
				}
				else
				{
					printf("not match\n");
					system("notify-send 'Error' 'Not Match'");
					continue;
				}
			//	printf("------------>%s------%s-------",rcp,newpassword);
				if(strcmp(newpassword,rcp))
				{
					fp=fopen("/home/suresh/Desktop/searcer/system/login.txt","w+");
					fprintf(fp,"%d",0);
					fprintf(fp,"%d",1);
					fprintf(fp,"%s","\n");
					fprintf(fp,"%s",newusername);
					fprintf(fp,"%s","\n");
					fprintf(fp,"%s",newpassword);
					fclose(fp);
					done=0;
					printf("login changed successfully\n");
				}
				else
				{
					printf("Not Match please create login again\n");
					system("notify-send 'Error' 'Not Match please create login again'");
				}
		}

	}
	else
	{
		printf("sorry you can not chage ");
	}
		return 0;

}


