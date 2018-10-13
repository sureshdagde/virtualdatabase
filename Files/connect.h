int ConnectDB()
{
	char zero[20];
	char username[20];
	char oldusername[20];
	char oldpassword[20];
	int i;
	char ch;
	printf("enter the  username:");
	gets(username);
	printf("\nenter the password:");
	char *password=getpass("");
	FILE *fp;
	fp=fopen("/home/suresh/Desktop/searcer/system/login.txt","r+");
	if(fp==NULL)
	{
		printf("could not open");
	}
		fscanf(fp,"%s[^\n]",zero);
		fscanf(fp,"%s[^\n]",oldusername);
		fscanf(fp,"%s[^\n]",oldpassword);
		
		if(!strcmp(username,oldusername) && !strcmp(password,oldpassword))
		{
			printf("\nconnection establised succesfully\n");
			return 1;
		}
printf("could not connect");
 return 0;

}

/*
#define Enter 13
#define Space 32
#define Tab 9
#define BKSP 8

while(1)
		{
			ch=getch();
			if(ch==Enter)
			{
				password[i]='\0';
				break;
			}
			else if(ch==Tab || ch==Space)
			{
				continue;
			}
			else if (ch==BKSP)
			{
				if(i>0)
				{
					i--;
					printf("\b \b");
				}

			}
			else
			{
				password[i]=ch;
				i++;
				printf("*");
			}
		}
	*/