struct arr
{
	char a[223][233];
};
struct arr insert2(char [],char [],char [],FILE *fp);
insert(char Db[],char collection[],char cmdword[])
{
	int position;
	int l=0,m=0;
	char c;
	char str[223][233];
	
	char dir[500]="/home/suresh/Desktop/searcer/Database/";
	strcat(dir,Db);
	strcat(dir,"/");
	strcat(dir,collection);
	strcat(dir,".txt");
	
	printf("%s\n",dir);
	printf("%s",cmdword);
	FILE *fp;
	fp=fopen(dir,"a+");
	if(fp==NULL)
		printf("enable to open");
	else
	{
		c=fgetc(fp);
		printf("%d\n",c);
		if(c!=48)
		{
			position= insert1(Db,collection,cmdword,fp);
			fprintf(fp,"%s","\n");
			fseek(fp,position,1);
		   fprintf(fp, "%d",position);
		   	fprintf(fp,"%s","\n");

			insert2(Db,collection,cmdword,fp);
		}
		else
		{
			insert2(Db,collection,cmdword,fp);
		}
	}
	fclose(fp);
}

int insert1(char Db[],char collection[],char cmdword[],FILE *fp)
{
			int i=0,j=0,k=0;
			char str[223][233];
			printf("ddddddddddd");
//		{number:131,name:[f:suresh,l:daagde],name:[f:suresh,l:daagde],salary:500,name:[f:suresh,l:daagde]}
			fprintf(fp,"%d\n",0);
			//fprintf(fp,"%s","\n");
			while(i<strlen(cmdword))
			{
				if(cmdword[i]=='{'||cmdword[i]=='['||cmdword[i]==',')
				{
					
					while(cmdword[i+1]!=':')
					{
					str[j][k]=cmdword[i+1];
					i++;
					k++;
					}
					k=0;
					
					//fprintf(fp,"%s","\n");
					fprintf(fp,"%s",str[j]);
					fprintf(fp, "%s","\t");
					j++;
				}
			i++;
			}
		   fprintf(fp, "%s","\t");
		  return j;
	    
}
//value
struct arr insert2(char Db[],char collection[],char cmdword[],FILE *fp)
{
	int position=0;
	position= find(fp);
printf("\nvalue is--->%d\n",position);







	printf("ssssssssss");
			int i=0,j=0,k=0;
//{number:131,name:[f:suresh,l:daagde],name:[f:suresh,l:daagde],salary:500,name:[f:suresh,l:daagde]}

	    //	char str[223][223];
	    struct arr str;
	    	while(i<strlen(cmdword))
			{
				if(cmdword[i]==':'  && cmdword[i+1]!='[')
				{
					
					while(cmdword[i]!=',' && i<strlen(cmdword)-1)
					{
						if(cmdword[i]!=':' && cmdword[i]!=']' )
							{
								fputc(cmdword[i],fp);
								printf("%c",cmdword[i]);
								str.a[j][k]=cmdword[i];
								k++;
							
							}
						i++;
						
					}
				
					fprintf(fp, "%s","\t");
					k=0;
					j++;
				}
			 i++;
			}
			printf("\n%s",str.a[4]);
 fprintf(fp, "%s","\n");
 printf("\n%d\t%d\n",position,j);
}




find(FILE *fp)
{
	int position=0;
	char s[500];
	fseek(fp,0,0);
	while(fgetc(fp)!='\n')
	{
		position++;
	}
	fgetc(fp);
	while(fgetc(fp)!='\n')
	{
		position++;
	}

	fscanf(fp,"%s[^'\n']",&s);
	position=atoi(s);

	
	return position;
}






	/*printf("ddddddddddd");
//		{number:131,name:[f:suresh,l:daagde],salary:500}
			fprintf(fp,"%d\n",0);
			//fprintf(fp,"%s","\n");
			while(i<strlen(cmdword))
			{
				if(cmdword[i]=='{'||cmdword[i]=='['||cmdword[i]==',')
				{
					
					while(cmdword[i+1]!=':')
					{
					str[j][k]=cmdword[i+1];
					i++;
					k++;
					}
					k=0;
					
					//fprintf(fp,"%s","\n");
					fprintf(fp,"%s",str[j]);
					fprintf(fp, "%s","\t");
					j++;
				}
			i++;
			}
		   fprintf(fp, "%s","\n");
	    }
	    else
	    {
	    	//{number:131,name:[f:suresh,l:daagde],salary:500}
	    	printf("ssssssssss");
			i=0;j=0;k=0;
	    	
	    	char str[223][223];
	    	while(i<strlen(cmdword))
			{
				if(cmdword[i]==':'  && cmdword[i+1]!='[')
				{
					
					while(cmdword[i]!=',' && i<strlen(cmdword)-1)
					{
						if(cmdword[i]!=':' && cmdword[i]!=']' )
							{
								fputc(cmdword[i],fp);
								printf("%c",cmdword[i]);
								//str[j][k]=cmdword[i];
							}
						i++;
						k++;
					}
					//str[j][k+1]='|';
					fprintf(fp, "%s","\t");
					k=0;
					j++;
				}
			 i++;
			}
			fprintf(fp, "%s","\n");*/

/*
			 while(l<j)
		 	    {
				 	while(str[l][m]!='|')
					{
						fputc(str[l][m],fp);
						printf("%c",str[l][m]);
						m++;
					}
					fprintf(fp, "%s","\t");
					
					m=0;
					l++;
		
		        }
		        fprintf(fp,"%s","\n");
			
	    }						
	}					
			
			fclose(fp);				
}						
			
		 	
			
	   
	
/*
		 while(check<strlen(cmd))
		 {
		 if(cmdword[2][0]=='[')
		 			i++;
		 if(cmdword[2][0]==']')
		 	{if(i==0)invlid
		 				if(,==0)
		 				{
		 					invalid
		 				}
		 				esle if()
		 		 	i--;

		 		 if(cmdword[2][0]==';')
		 		 	{
		 		 		if(i!=0)
		 		 		{
		 		 			printf("invlaid command");
		 		 		}
		 		 	}

		 		 		
		 		 			
		 check++;
		 }			*/

