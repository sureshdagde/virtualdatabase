



struct attribute
{
	char a[223][233];
};

struct attribute insert2(char [],char [],char [],FILE *fp);
struct attribute insert1(char [],char [],char [],FILE *fp,int*);
struct attribute RootAttribute(FILE *fp);
struct attribute CheckSequence(struct attribute,struct attribute,FILE *fp,int,char[]);

void insert(char Db[],char collection[],char cmdword[])
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
		//printf("%d\n",c);
		if(c!=48)
		{
			fprintf(fp,"%d\n",0);
			CollectionAttribute=insert1(Db,collection,cmdword,fp,&position);
			fprintf(fp,"%d\n",position);
			//PUTS ATTRIBUTE INTO FILE
			while(i<position)
			{		

					//fprintf(fp,"%s","\t");

					fprintf(fp,"%s\t",CollectionAttribute.a[i]);
					i++;
			}
			fprintf(fp, "%s",";" );
			fprintf(fp,"%s","\n");
			CollectionAttributeValue=insert2(Db,collection,cmdword,fp);
			i=0;//imp
			while(i<position)
			{
				    //fprintf(fp,"%s","\t");

					fprintf(fp,"%s\t",CollectionAttributeValue.a[i]);
					i++;
			}
			printf("%s collection is created\n",collection);
			printf("Record inserted successfully");
			fprintf(fp, "%s",";" );
		}
		else
		{
			i=0;
			struct attribute final;
			position=find(fp);
			CollectionAttributeValue=insert2(Db,collection,cmdword,fp);//value
			CollectionAttribute=insert1(Db,collection,cmdword,fp,&position);//attribute
			final=CheckSequence(CollectionAttribute,CollectionAttributeValue,fp,position,dir);//position is the numbert of attribute in the newquery not same as find();
			
			//PUTS THE VALUE INTO FILE;
			if(final.a[0][0]!='z')//if invalid attriute
			{
					fprintf(fp,"%s","\n");
			
				i=0;
				while(i<position)
				{
						//fprintf(fp,"%s","\t");
						fprintf(fp,"%s\t",final.a[i]);
						//printf("\n------%s\n",final.a[i]);
				i++;
				}
				fprintf(fp, "%s",";" );
			}
			else
			{
				printf("invalid attribute");
			}
		printf("Record inserted successfully");
		}
	}
	fclose(fp);
}

struct attribute insert1(char Db[],char collection[],char cmdword[],FILE *fp,int *position)
{
			int i=0,j=0,k=0,retn=0;
			struct attribute str;
			//printf("ddddddddddd");
//		{number:131,name:suresh,salary:500}
//{number:131,name:[f:suresh,l:daagde],salary:500}

			//fprintf(fprintfp,"%s","\n");
			
			while(i<strlen(cmdword))
			{
				if(cmdword[i]=='{'||cmdword[i]=='['||cmdword[i]==',')
				{
					retn=i;
					while(cmdword[i+1]!=':')
					{
						i++;
					}	
					if(cmdword[i+2]!='[')
					{
						i=retn;
						while(cmdword[i+1]!=':')
						{
						str.a[j][k]=cmdword[i+1];
						i++;
						k++;
						}
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
			/*i=0;
			while(i<j)
			{
			  //  printf("value is ------%s\n",str.a[i]);
				i++;
			}
*/

			return str;
}

struct attribute CheckSequence(struct attribute CollectionAttribute,struct attribute CollectionAttributeValue,FILE *fp,int NewNumOfatt,char dir[])
{
	
	int  i=0,j=0,k=0;
	int l,found=0;
	int AttNumber;
	AttNumber=find(fp);
	struct attribute root,final;
	root=RootAttribute(fp);
	
	/*printf("root->%s----collection--->%s\n",root.a[0],CollectionAttribute.a[0]);
	printf("root->%s----collection--->%s\n",root.a[1],CollectionAttribute.a[1]);
	printf("root->%s----collection--->%s\n",root.a[2],CollectionAttribute.a[2]);
	printf("root->%s----collection--->%s\n",root.a[3],CollectionAttribute.a[3]);
	printf("NewNumOfatt-->%d--AttNumber--->%d\n",NewNumOfatt,AttNumber);*/
	//printf("\n--------check same -%d-%d-\n",NewNumOfatt,AttNumber);
	if(NewNumOfatt<=AttNumber)
	{
		//printf("if start---------");
		while(i<AttNumber)
		{
			l=0;
			while(j<AttNumber)
			{

				//printf("-----------i is%d\t",i);
				if(!strcmp(root.a[i],CollectionAttribute.a[j]))//if same
				{
					//printf("j is %d and value is-->%s\n",j,CollectionAttributeValue.a[i]);
							strcpy(final.a[i],CollectionAttributeValue.a[j]);//or root.a[i];both are same
							found++;
					//	printf("------->%s\t",final.a[i]);
						//j=j+AttNumber;
				}
				else
				{
					
					
					if(i==0 && l<1)
							{
								k=0;
							while(root.a[0][k]!='\0')
							{
								root.a[0][k]=root.a[i][k+1];
								k++;
							}
						j=j-1;
						}
						l++;
				}

				j++;
			}
			j=0;
			i++;
		}
	}
	else									
	{
			//	printf("else start---------");
			found=0;
			i=0;
			j=0;
			k=0;


			char c;
			char line[233];
			FILE *fp2;
			fp2=fopen("/home/suresh/Desktop/searcer/Database/temp.txt","w+");
			int at=find(fp);
			rewind(fp);
			while(i<3+at-1)
			{
				fscanf(fp,"%s[^\n]",line);
				
				if(i==1)
					fprintf(fp2, "%d\n",atoi(line)+(NewNumOfatt-atoi(line)));
				//printf("%d",)
				else if(i<2)
				{
					fprintf(fp2, "%s",line);
					fprintf(fp2, "%s","\n");
					
				}
				else
				{
				fprintf(fp2, "%s\t",line);
				}
				i++;
			}
			i=0;
			while(i<NewNumOfatt-at)
			{
			fprintf(fp2, "%s",CollectionAttribute.a[at+i]);
			i++;
			}
			//---fprintf(fp2, "%s","\n");
			while((c=fgetc(fp))!=EOF)
			{
				fputc(c,fp2);

			}
			rewind(fp2);
			fp=fopen(dir,"w+");
			while((c=fgetc(fp2))!=EOF)
			{
				fputc(c,fp);
			}
		fclose(fp2);
		fclose(fp);
		fp=fopen(dir,"a+");
			i=0;


				i=0;
				j=0;
				k=0;
					while(i<NewNumOfatt)
					{
						l=0;
						while(j<NewNumOfatt)
						{

							//printf("-----------i is%d\t",i);
							if(!strcmp(root.a[i],CollectionAttribute.a[j]))//if same
							{
								//printf("j is %d and value is-->%s\n",j,CollectionAttributeValue.a[i]);
										strcpy(final.a[i],CollectionAttributeValue.a[j]);//or root.a[i];both are same
										found++;
								//	printf("------->%s\t",final.a[i]);
									//j=j+AttNumber;
							}
							else
							{
								
								
								if(i==0 && l<1)
										{
											k=0;
										while(root.a[0][k]!='\0')
										{
											root.a[0][k]=root.a[i][k+1];
											k++;
										}
									j=j-1;
									}
									l++;
							}

							j++;
						}
						j=0;
						i++;
					}
					}


				i=0;
				while(i<NewNumOfatt-AttNumber) 
						{
							strcpy(final.a[NewNumOfatt-1],CollectionAttributeValue.a[NewNumOfatt-1]);
							NewNumOfatt++;
							AttNumber++;
							found++;
						i++;
					 	}

























j=0;k=0;
	i=0;	
	//printf("\nppppppppppppppppp\n");
	//printf("%s\t",final.a[0]);
	//printf("%s\t",final.a[1]);
//	printf("%s\t",final.a[2]);
//	printf("\n");
/*	printf("start---------\n");
	printf("%s\n",final.a[0]);
	printf("%s\n",final.a[1]);

	printf("%s\n",final.a[2]);
	printf("%s\n",final.a[3]);
	printf("found-->%d\n",found);*/
if(found==AttNumber)
{
return final;
}
else
{
	final.a[0][0]='z';
	
	return final;
}
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
			while((c=fgetc(fp))!='\t' && c!=' ')
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
	fscanf(fp,"%s",s);
	fscanf(fp,"%s",s);
	//printf("---%s---",s);
	position=atoi(s);

	
	return position;
}


int AddNew(FILE *fp)
{
	int j=0;
	rewind(fp);
	fseek(fp,5,0);
		while(fgetc(fp)!='\n')
			{	
				j++;
			}
				printf("fseek j is----->%d",j);
		return j+1;
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
		
else
				{
					k=0;
					while(root.a[i][k]!='\0')
					{
						root.a[i][k]=root.a[i][k+1];
						k++;
					}
					printf("\n%s------is %d length --->%s--->%d\n",CollectionAttribute.a[j],strlen(CollectionAttribute.a[j]),root.a[i],strlen(root.a[i]));
							if(!strcmp(root.a[i],CollectionAttribute.a[j]))//if same
						{
							//printf("j is %d and value is-->%s\n",j,CollectionAttributeValue.a[i]);
									strcpy(final.a[i],CollectionAttributeValue.a[j]);//or root.a[i];both are same
							//	printf("------->%s\t",final.a[i]);
								//j=j+AttNumber;
						}
		//			printf("j is %d and value is-->%s\n",j,CollectionAttributeValue.a[i]);
		//			printf("...%d...",strcmp(root.a[i],CollectionAttribute.a[j]));
		//			printf("%s-->%s--\n",root.a[i],CollectionAttribute.a[j]);
				}





/*
//root 	number name salary       f number   i 4 0       1
//c a     number name salary                  j 4 0 1 2 3 0
printf("else--aaaaaaaaaaaaaaaaaasfsfff\n");
int addat;
addat=AddNew(fp);
//find difference between root and new attriute;

printf("fseek j is-->%d\n",addat);
printf(" AttNumber is-->%d\n",AttNumber);
printf(" NewNumOfatt is-->%d\n",NewNumOfatt);

i=NewNumOfatt-AttNumber;
printf(" defference is-->%d\n",i);

j=0;
fseek(fp,3,0);
fseek(fp,addat,1);
fprintf(fp,"%s","\t");
while(i>0)
{
fprintf(fp, "%s\t", CollectionAttribute.a[AttNumber+j]);
i--;
j++;
}
*/












		