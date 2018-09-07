struct attribute
{
	char a[223][233];
};

struct attribute insert2(char [],char [],char [],FILE *fp);
struct attribute insert1(char [],char [],char [],FILE *fp,int*);
struct attribute RootAttribute(FILE *fp);
struct attribute CheckSequence(struct attribute,struct attribute,FILE *fp,int);

insert(char Db[],char collection[],char cmdword[])
{
	int position;
	int i=0,j=0;
	char c;
	struct attribute CollectionAttribute;
	struct attribute CollectionAttributeValue;
	
	char dir[500]="/home/suresh/Desktop/searcer/Database/";
	strcat(dir,Db);
	strcat(dir,"/");
	strcat(dir,collection);
	strcat(dir,".txt");
	
	//printf("%s\n",dir);
	///printf("%s",cmdword);
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
			fprintf(fp,"%d\n",0);
			CollectionAttribute=insert1(Db,collection,cmdword,fp,&position);
			fprintf(fp,"%d\n",position);
			//PUTS ATTRIBUTE INTO FILE
			while(i<position)
			{
					fprintf(fp,"%s\t",CollectionAttribute.a[i]);
					i++;
			}
			fprintf(fp,"%s","\n");
			CollectionAttributeValue=insert2(Db,collection,cmdword,fp);
			i=0;//imp
			while(i<position)
			{
					fprintf(fp,"%s\t",CollectionAttributeValue.a[i]);
					i++;
			}
			
		}
		else
		{
			i=0;
			struct attribute final;
			position=find(fp);
			CollectionAttributeValue=insert2(Db,collection,cmdword,fp);//value
			CollectionAttribute=insert1(Db,collection,cmdword,fp,&position);//attribute
			final=CheckSequence(CollectionAttribute,CollectionAttributeValue,fp,position);//position is the numbert of attribute in the newquery not same as find();
			
			
			//PUTS THE VALUE INTO FILE;
			fprintf(fp,"%s","\n");
		
			i=0;
			while(i<position)
			{
					fprintf(fp,"%s\t",final.a[i]);
					printf("\n------%s\n",final.a[i]);
			i++;
			}
		
		}
	}
	fclose(fp);
}

struct attribute insert1(char Db[],char collection[],char cmdword[],FILE *fp,int *position)
{
			int i=0,j=0,k=0;
			struct attribute str;
			//printf("ddddddddddd");
//		{number:131,name:suresh,salary:500}
			
			//fprintf(fprintfp,"%s","\n");
			
			
			while(i<strlen(cmdword))
			{
				if(cmdword[i]=='{'||cmdword[i]=='['||cmdword[i]==',')
				{
					
					while(cmdword[i+1]!=':')
					{
					str.a[j][k]=cmdword[i+1];
					i++;
					k++;
					}
					str.a[j][k]='\0';
					k=0;
					j++;
				}
			i++;
			}
		 *position=j;
		  return str;
	    
}
//value
struct attribute insert2(char Db[],char collection[],char cmdword[],FILE *fp)
{
	
			int i=0,j=0,k=0;
//{number:131,name:[f:suresh,l:daagde],name:[f:suresh,l:daagde],salary:500,name:[f:suresh,l:daagde]}

	        struct attribute str;
	    	while(i<strlen(cmdword))
			{
				if(cmdword[i]==':'  && cmdword[i+1]!='[')
				{
					
					while(cmdword[i]!=',' && i<strlen(cmdword)-1)
					{
						if(cmdword[i]!=':' && cmdword[i]!=']' )
							{
								str.a[j][k]=cmdword[i];
							//	printf("%c",cmdword[i]);
								k++;
							}
						i++;
					}
					str.a[j][k]='\0';
					k=0;
					j++;
				}
			 i++;
			}
		//	printf("kkkkkkkkkkkkkkkkk");
			i=0;
			while(i<j)
			{
			//	printf("%s",str.a[i]);
				i++;
			}

			return str;
}

struct attribute CheckSequence(struct attribute CollectionAttribute,struct attribute CollectionAttributeValue,FILE *fp,int NewNumOfatt)
{
	int i=0,j=0;
	int AttNumber;
	AttNumber=find(fp);
	struct attribute root,final;
	root=RootAttribute(fp);
	
	while(i<AttNumber)
	{
		printf("------------------------------->%s",CollectionAttribute.a[i]);
		i++;
	}
	i=0;
	while(i<AttNumber)
	{
		while(j<AttNumber)
		{
			
			if(!strcmp(root.a[i],CollectionAttribute.a[j]))//if same
			{
				printf("j is %d and value is-->%s\n",j,CollectionAttributeValue.a[i]);
						strcpy(final.a[i],CollectionAttributeValue.a[j]);//or root.a[i];both are same
					printf("------->%s\t",final.a[i]);
					j=j+AttNumber;
			}
			else
			{
				printf("%s-->%s--\n",root.a[i],CollectionAttribute.a[j]);
			}

			j++;
		}
		j=0;
		i++;
	}
	i=0;	
	//printf("\nppppppppppppppppp\n");
	//printf("%s\t",final.a[0]);
	//printf("%s\t",final.a[1]);
//	printf("%s\t",final.a[2]);
//	printf("\n");
	
return final;

}

struct attribute RootAttribute(FILE *fp)
{
	int position;
	position=find(fp);
	int i=0,j=0;
	struct attribute p;
	char c;
	
	rewind(fp);
	fseek(fp,3,0);
	
		while(i<position)
		{
			while((c=fgetc(fp))!='\t')
			{	
				if(c!=' ' || c!='\t' || c!='\n')
				p.a[i][j]=c;
				j++;
			}
			p.a[i][j]='\0';
			j=0;
			i++;

		}
		return p;
		
}


int find(FILE *fp)
{
	int position=0;
	char s[10];
	char d;
	fseek(fp,0,0);
	fscanf(fp,"%s",&s);
	fscanf(fp,"%s",&s);
	//printf("---%s---",s);
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
		*/