int CreteLogin(char *UserName,char *password)
{
	
	 int done=1;
	char rcu[20],rcp[20];
	FILE *fp;
	int check1,check2;
	fp=fopen("/home/suresh/Desktop/searcer/Database/login.txt","a+");
	if(fp==NULL)
		{
			printf("enable to open");
		}
		check1=fgetc(fp);
		check2=fgetc(fp);
		
		if(check1==48 && check2==49)
		{
			printf("you already created the login please use this\n");

		}
		else
		{
			printf("NOTE-->create the login and must be remember the login username and login password\n");		
					getchar();
			while(done)
			{

			printf("enter the UserName--->");
			gets(UserName);
			if(strlen(UserName)<=4)
				{
					printf("Error-->UserName must be greter then 4 character\n");

					continue;
				}
			printf("enter the password--->");
			gets(password);
			if(strlen(password)<=4)
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
			if(!strcmp(UserName,rcu) && !strcmp(password,rcp))
				{
					//strcat(UserName,".");
					//strcat(UserName,password);
				 	
					fprintf(fp,"%d",1);
					fprintf(fp,"%s","\n");
					fprintf(fp,"%s",UserName);
					fprintf(fp,"%s","\n");
					fprintf(fp,"%s",password);
					fclose(fp);
					printf("Your Login Create Succesfully");
					done=0;
					return 1;
				}
			else
				{
					printf("Not Match please create login again\n");
				}
			}
		}
		return 0;
}