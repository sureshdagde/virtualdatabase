#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include "mkdir.h"
#include "collection.h"
#include "ShowDir.h"
#include "UseDB.h"
#include "ShowCollection.h"
#include "CheckCollection.h"
#include "RemoveCollection.h"
#include "RemoveCollectionAll.h"
#include "RemoveDatabase.h"
#include "connect.h"
#include "CreteLogin.h"
#include "ChangeLogin.h"
#include "help.h"
#include "NextPre.h"
#include "insert.h"
#include "SelectAll.h"
#include "find.h"
#include "count.h"
#include "HelpSpecific.h"
#include "findcondition.h"
#include "delete.h"
#include "insert_value.h"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_BLUE "\x1b[37m"
int CreateTable(char [][233],int,char []);
void Insert(char cmdword[][233],int CommandWordLength)
{

}
int main()
{	
	FILE *fp;
	fp=fopen("/home/suresh/Desktop/searcer/system/login.txt","a+");
		int check1=fgetc(fp);
		int check2=fgetc(fp);
		int ccl=0;
		int login;
		if(check1==48 && check2==49)
		{
			login=1;

		}
		else
		{
			login=0;
		}
		
		char mount[500]="unmount";
		int connect=0,done=1;
		char UserName[20],Password[20];
		struct stack_t *theStack = newStack();
  		char *data;
  		char c;
	while(1)
	{
	
		int c,i=0,CommandWordLength=0,k=0,flag=1;
		char cmd[22222]={0};
		char cmdword[233][233]={0};
		printf(ANSI_COLOR_RED "\n>>");
		printf(ANSI_COLOR_GREEN "");
		gets(cmd);
		push(theStack,cmd);
		//printf("%u\n",strlen(cmd));

		//show(theStack);
		printf(ANSI_COLOR_BLUE "");
		while(i<strlen(cmd))
		{
			if(cmd[i]==' ')//connect  
			{		i++;
				if(i<strlen(cmd))
				{
					if(cmd[i]==' ')
						continue;
					else
				        CommandWordLength++;
				}
				k=0;
				
			}
			if(cmd[i]!=' ' && i<strlen(cmd)) //imp to avoid the white space
			cmdword[CommandWordLength][k]=cmd[i];//p
			
			i++;
			k++;
		}

		
			//remove the history of current command or remove the current command history
	
		if(!strcmp(cmdword[0],"insert"))
			{
				if(strlen(cmdword[2])>4)
				{

					if(connect)
					{
						
						if(!strcmp(mount,"unmount"))
						{
							printf("please mount database first");
						}
						else
						{
							insert(mount,cmdword[1],cmdword[2]);
						}
					}
					else
					{
						printf("connection not establised");
					}
					
				}
				else
				{
					printf("invalid command   [space is not allowed]or[Empty data]");
				}
			}
			else if(!strcmp(cmdword[0],"insert_value"))
			{
				if(connect)
				{
					if(!strcmp(mount,"unmount"))
					{
						printf("please mount database first");
					}
					else if(CheckCollection(mount,cmdword[1]))
					{
					insert_value(mount,cmdword[1],cmdword[2]);
					}
					else
					{
						printf("collection not found");
					//CreateTable(cmdword,CommandWordLength,mount);
					}
				}
				else
				{
					printf("connection not establised");
				}
			}
			else if(!strcmp(cmdword[0],"select") && !strcmp(cmdword[2],"*"))
			{
				if(connect)
				{
					if(!strcmp(mount,"unmount"))
					{
						printf("please mount database first");
					}
					else if(CheckCollection(mount,cmdword[1]))
					{
					SelectAll(mount,cmdword[1]);
					}
					else
					{
						printf("collection not found");
					//CreateTable(cmdword,CommandWordLength,mount);
					}
				}
				else
				{
					printf("connection not establised");
				}
			}

		else if(!strcmp(cmdword[0],"count"))
		{
			if(connect)
					{
						if(!strcmp(mount,"unmount"))
						{
							printf("please mount database first");
						}
						else if(CheckCollection(mount,cmdword[1]))
						{
						count(mount,cmdword[1]);
						}
						else
						{
							printf("collection not found");
							//CreateTable(cmdword,CommandWordLength,mount);
						}
					}
					else
					{
						printf("connection not establised");
					}
		}
		else if(!strcmp(cmdword[0],"delete") && CommandWordLength==2 && strlen(cmdword[1])>0)
		{
			if(connect)
					{
						if(!strcmp(mount,"unmount"))
						{
							printf("please mount database first");
						}
						else
						{
							deletecondition(cmdword[1],mount,cmdword[2]);
						}
					}
					else
					{
						printf("connection not establised");
					}
			
		}
		else if(!strcmp(cmdword[0],"finds") && CommandWordLength==2 && strlen(cmdword[1])>0)
		{
			if(connect)
					{
						if(!strcmp(mount,"unmount"))
						{
							printf("please mount database first");
						}
						else
						{
							findcondition(cmdword[1],mount,cmdword[2]);
						}
					}
					else
					{
						printf("connection not establised");
					}
			
		}
		else if(!strcmp(cmdword[0],"find")  && CommandWordLength<=3)
				{
					if(connect)
					{
						if(!strcmp(mount,"unmount"))
						{
							printf("please mount database first");
						}
						else if(CheckCollection(mount,cmdword[1]))
						{
							//printf("%s",cmdword[3]);
							if(CommandWordLength==2)
							{
								findall(mount,cmdword[1],cmdword[2],"1000");	
							}
							else
							{
								findall(mount,cmdword[1],cmdword[2],cmdword[3]);		
							}
						
						}
						else
						{
							printf("collection not found");
							//CreateTable(cmdword,CommandWordLength,mount);
						}
					}
					else
					{
						printf("connection not establised");
					}
			}

	   else if(!strcmp(cmdword[0],"r") && CommandWordLength==0)
		{
			
			pop(theStack);
			pop(theStack);
			printf("%s\t is removed from history",top(theStack));		
		}

		//remove the history
		else if(!strcmp(cmdword[0],"r") && !strcmp(cmdword[1],"all") && CommandWordLength==1)
		{
			RemoveAll(theStack);		
		}
		//check the last n Activity or commands
		else if(!strcmp(cmdword[0],"c") && strcmp(cmdword[1],"n") && CommandWordLength==1)
		{
			int start=0;
		
			while(start<atoi(cmdword[1]))
			{
			printf("%s\n",catchdata(theStack));
			start++;
			}
		}
		//check the previous command
		else if(!strcmp(cmdword[0],"c") && CommandWordLength==0)
		{
		//	int ddd=CheckNULL(theStack);
		//	if(dd!=1)
			printf("%s",catchdata(theStack));
		//	else
		//		pritnf("no command found");
		}
		//c n---------->print the Number of current command
		else if( !strcmp(cmdword[0],"c") && !strcmp(cmdword[1],"n") && CommandWordLength==1)
		{
	
			printf("%d\n",theStack->stackSize-1);
		}
		//to show the history of command
		else if(!strcmp(cmdword[0],"h") && CommandWordLength==0)
		{

			
		 ShowAll(theStack);
		}
		//to login the database
		else if(!strcmp(cmdword[0],"connect") && CommandWordLength==0)
			{
				ccl=0;

				if(connect)
				{

					printf("already connected");
				}
				
				if(login)
				{
					connect =ConnectDB();
				}
				else
				{
					printf("you cannot create login yet. you want to creaate login type 1/0");
					scanf("%d",&ccl);
					if(ccl==1)
					{
						login=CreteLogin(UserName,Password);
					}
				}
				
				
			}
				//disconnect the database
		else if(!strcmp(cmdword[0],"disconnect") && CommandWordLength==0)
			{
				ccl=0;
				if(login)
				{
				connect =0;
				printf("disconnected");
				}
				else
				{
					printf("you cannot create login yet. you want to creaate login type 1/0");
					scanf("%d",&ccl);
					if(ccl==1)
					{
					login=CreteLogin(UserName,Password);
					}
				}
				connect=0;
			}
			//create login
		else if(!strcmp(cmdword[0],"create") && !strcmp(cmdword[1],"login") && CommandWordLength==1)
			{
				login=CreteLogin(UserName,Password);
				
			}
				//change login
		else if(!strcmp(cmdword[0],"change") && !strcmp(cmdword[1],"login") && CommandWordLength==1)
			{
				ChangeLogin(UserName,Password);
			}
		//help of command
		else if(!strcmp(cmdword[0],"help") && CommandWordLength==0)
			{

				help();
			}
		else if(!strcmp(cmdword[0],"help") && CommandWordLength==1)
			{

				HelpSpecific(cmdword[1]);
			}
		else if(!strcmp(cmdword[0],"create") && !strcmp(cmdword[1],"db") && 
			strcmp(cmdword[2],";") && CommandWordLength==2)
			{
				if(connect)
				{
					CreateDatabase(cmdword[2]);
				}
				else
				{
					printf("connection not establised");
				}
			}
			//use or mount DBName
		else if(!strcmp(cmdword[0],"use") && CommandWordLength==1)
			{	
				if(connect)
				{

					if((strlen(cmd))>=5)
					{
						int a=UseDB(cmdword[1]);
						if(a)
						{
							strcpy(mount,cmdword[1]);
						}
						else
						{
							strcpy(mount,"unmount");
						}
					}
					else
					{
						printf("Invalid command");
					}
				}
				else
				{
					printf("connection not establised");
				}
			}
			//show all dbs
		else if(!strcmp(cmdword[0],"show") && !strcmp(cmdword[1],"dbs") && CommandWordLength==1)
			{
				if(connect)
				{
					ShowDir();
				}
				else
				{
					printf("connection not establised");
				}
			}
			//show all collection in the current database
		else if(!strcmp(cmdword[0],"show") && !strcmp(cmdword[1],"c") && CommandWordLength==1)
			{
				if(connect)
				{
					if(!strcmp(mount,"unmount"))
					{
						printf("please mount database first");
					}
					else
					{
						ShowCollection(mount);
					}
				}
				else
				{
					printf("connection not establised");
				}
			}
			else if(!strcmp(cmdword[0],"db") &&  CommandWordLength==0)
			{
				if(connect)
				{
					if(!strcmp(mount,"unmount"))
					{
						printf("please mount database first");
					}
					else
					{
						printf("%s",mount);
					}
				}
				else
				{
					printf("connection not establised");
				}
			}
			//create the new collection in current collection 
		else if(!strcmp(cmdword[0],"create")  && !strcmp(cmdword[1],"c"))
			{
				if(connect)
				{
					if(!strcmp(mount,"unmount"))
					{
						printf("please mount database first");
					}
					else if(CheckCollection(mount,cmdword[2]))
					{
						printf("collection already exist");
					}
					else
					{
					CreateTable(cmdword,CommandWordLength,mount);
					}
				}
				else
				{
					printf("connection not establised");
				}
			}
			//to remove single collection;
		else if(!strcmp(cmdword[0],"rm") && !strcmp(cmdword[1],"c") && strcmp(cmdword[2],"all") && CommandWordLength==2)
			{
				if(connect)
				{
					char s[222];
					strcpy(s,cmdword[2]);
					if(!strcmp(mount,"unmount"))
					{
						printf("please mount database first");
					}
					else
					{
						if(CheckCollection(mount,cmdword[2]))
						{
							RemoveCollection(mount,cmdword[2]);
						}
						else
						{
							printf("%s collection not found",s);
						}
					}
				}
				else
				{
					printf("connection not establised");
				}
			}

			//to remove All Collection in current working database
			else if(!strcmp(cmdword[0],"rm") && !strcmp(cmdword[1],"c") && !strcmp(cmdword[2],"all") && CommandWordLength==2)
			{
				
				ConnectDB();
				if(!strcmp(mount,"unmount"))
				{
					printf("please mount database first");
				}
				else
				{

				//	RemoveCollectionAll(mount);
				}
			}

			//to remove single database   PAINDDING 
			else if(!strcmp(cmdword[0],"rm") && !strcmp(cmdword[1],"db") && strcmp(cmdword[2],"all") && CommandWordLength==2)
			{
				
					ConnectDB();
					char path[100]="/home/suresh/Desktop/searcer/Database/";
					strcat(path,cmdword[2]);
					//printf("%s\n",path);
					remove_directory(path);
				
			}
			//remove all collection 	PAINDDING 
			else if(!strcmp(cmdword[0],"rm") && !strcmp(cmdword[1],"db") && !strcmp(cmdword[2],"all") && CommandWordLength==2)
			{
				
					ConnectDB();

					char path[100]="/home/suresh/Desktop/searcer/Database/";
				remove_directory(path);
			}
			//exit from searcer
		else if(!strcmp(cmdword[0],"exit")&& CommandWordLength==0)
			{
				
				exit(1);
			}
		else
		{
			printf("invalid command");
		}

	}
 return 0;

}
	
/*
	if(!strcmp(cmdword[0],"insert"))
	{
		Insert(cmdword,CommandWordLength);
	}
	if(!strcmp(cmdword[0],"update"))
	{
		CreateTable(cmdword,CommandWordLength);
	}
	if(!strcmp(cmdword[0],"delete"))
	{
		CreateTable(cmdword,CommandWordLength);
	}*/
