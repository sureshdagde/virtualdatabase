CreteLogin(char *UserName,char *password)
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
			printf("you already created the login please use this");

		}
		else
		{
			while(done)
			{
			printf("enter the UserName--->");
			gets(UserName);
			printf("enter the password--->");
			gets(password);
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
				}
			else
				{
					printf("Not Match please create login again\n");
				}
			}
		}
}