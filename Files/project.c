#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<dirent.h>
#include<string.h>
#include"mkdir.h"
#include"collection.h"
#include"ShowDir.h"
#include"UseDB.h"
#include"ShowCollection.h"
#include"CheckCollection.h"
#include"RemoveCollection.h"
#include"RemoveCollectionAll.h"
#include"RemoveDatabase.h"
#include"connect.h"
#include"CreteLogin.h"
#include"ChangeLogin.h"
#include"help.h"
int CreateTable(char [][233],int,char []);
void Insert(char cmdword[][233],int CommandWordLength)
{

}
int main()
{
		char mount[500]="unmount";
		int connect=0;
		char UserName[20],Password[20];
	while(1)
	{
	
		int c,i=0,CommandWordLength=0,k=0,flag=1;
		char cmd[22222]={0};
		char cmdword[233][233]={0};
		printf("\n>>");
		gets(cmd);
		while(i<strlen(cmd))
		{
			if(cmd[i]==' ')
			{

				CommandWordLength++;
				k=0;
				i++;
			}
			if(cmd[i]!=' ') //imp to avoid the white space
			cmdword[CommandWordLength][k]=cmd[i];
			else
				CommandWordLength--;
			i++;
			k++;
		}





		if(!strcmp(cmdword[0],"connect") && CommandWordLength==0)
			{
				connect =ConnectDB();
			}
				//disconnect the database
		else if(!strcmp(cmdword[0],"disconnect") && CommandWordLength==0)
			{
				connect =0;
			}
			//create login
		else if(!strcmp(cmdword[0],"create") && !strcmp(cmdword[1],"login") && CommandWordLength==1)
			{
				CreteLogin(UserName,Password);
			}
				//change login
		else if(!strcmp(cmdword[0],"change") && !strcmp(cmdword[1],"login") && CommandWordLength==1)
			{
				ChangeLogin(UserName,Password);
			}
		
		else if(!strcmp(cmdword[0],"help") && CommandWordLength==0)
			{

				help();
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
			//use DBName
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
		else if(!strcmp(cmdword[0],"create")  && !strcmp(cmdword[1],"c"))
			{
				if(connect)
				{
					if(!strcmp(mount,"unmount"))
					{
						printf("please mount database first");
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

			//to remoce All Collection in current working database
			else if(!strcmp(cmdword[0],"rm") && !strcmp(cmdword[1],"c") && !strcmp(cmdword[2],"all") && CommandWordLength==2)
			{
				
				ConnectDB();
				if(!strcmp(mount,"unmount"))
				{
					printf("please mount database first");
				}
				else
				{
					RemoveCollectionAll(mount);
				}
			}

			//to remove single collection
			else if(!strcmp(cmdword[0],"rm") && !strcmp(cmdword[1],"db") && strcmp(cmdword[2],"all") && CommandWordLength==2)
			{
				
					ConnectDB();
					RemoveDatabase(cmdword[2]);
				
			}
			else if(!strcmp(cmdword[0],"rm") && !strcmp(cmdword[1],"db") && !strcmp(cmdword[2],"all") && CommandWordLength==2)
			{
				if(connect)
				{
				
					if(!strcmp(mount,"unmount"))
					{
						printf("please mount database first");
					}
					else
					{
						RemoveCollectionAll(mount);
					}
				}
				else
				{
					printf("connection not establised");
				}
			}
		else if(!strcmp(cmdword[0],"exit")&& CommandWordLength==0)
			{
				
				exit(0);
			}
		else
		{
			printf("invalid command");
		}
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
	
return 0;
}
