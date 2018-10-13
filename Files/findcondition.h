findcondition(char collection[],char db[],char cmdword[])
{
	char record[500][50][50];
	//printf("%d",strlen(cmdword)-1);
	char value[10][10];
	char attribute[10][10];
	int done =1,check=1;
	int array[20];
	int condition;
	int d=0,flag=1;
	int total=0;
	int j=0,i=1,k=0,numbertofattribute=0,numbertofcheckattribute=0;
	char c;
	if(cmdword[0]=='{' && cmdword[strlen(cmdword)-1]=='}')
		{
			while(cmdword[i]!='}')
			{
				if(cmdword[i]==':')
				{
					done=0;
					i++;
					k=0;
					continue;
				}
				if(cmdword[i]==',' || cmdword[i]=='|')
				{
					if(cmdword[i]==',')
						condition=1;
						if(cmdword[i]=='|')
							condition=0;
					done=1;
					i++;
					j++;
					k=0;
					continue;
				}
				if(done==1)	
				attribute[j][k]=cmdword[i];
				if(done==0 && cmdword[i]!=':')
					value[j][k]=cmdword[i];
				i++;
				k++;
			}
			
			numbertofcheckattribute=j+1;
			
		}

	else
		printf(" { or } is missing");
i=0,j=0,k=0;
FILE *fp;
char path[100]="/home/suresh/Desktop/searcer/Database/";
strcat(path,db);
strcat(path,"/");
strcat(path,collection);
strcat(path,".txt");

fp=fopen(path,"r");
if(fp==NULL)
	{printf("collection not found");}
else
{
	fseek(fp,4,0);
	while((c=fgetc(fp))!=EOF)
		{
					if(c=='\t' || c=='\n' )
					{	
						j++;
						k=0;
						
						if((c=='\n' || c=='\t')&&check)
						numbertofattribute++;
						continue;
					}
						

					if(c==';')
					{	

						
						j=0;
						i++;
						check=0;
						continue;
					}
						
						if(c!='\t' || c!='\n' ||c!=';' || c!=' ')
							record[i][j][k]=c;
						
						
					k++;

		}
		int totalrecord=i;
	i=0,k=0,j=0;

	while(i<numbertofcheckattribute)
	{
		j=0;
		
		while(j<numbertofattribute)
		{
				
		if(!strcmp(attribute[i],record[0][j]))
			{
				//printf("record is--->%s,",record[0][j]);
				//printf("char record is--->%c\n",record[3][0][0]);
				array[k]=j;
				k++;
			}
		j++;
		}
		i++;
	}
	int l=k;
	i=0,j=0,k=0;
	//add:pune,age:21
	while(i<totalrecord)
	{
		j=0;
		d=0;
		while(j<numbertofattribute)
		{
			k=0;
			while(k<l)
			{
				if(!condition)//or
				{
					if(array[k]==j) 
					{
						int checkvalue=0;
						while(checkvalue<numbertofcheckattribute)
						{
							if(!strcmp(value[checkvalue],record[i][j+1]))
							{
								

							int newi=i,newj=0;
							printf("\n");
								while(newj<numbertofattribute)
								{
								printf("%s\t",record[i][newj+1]);
								newj++;

								}
								j++;
							}
							checkvalue++;
						}
				    }
			    }
			    else//and
				{
					//printf("and start");
	/*				
	name	add	age	;
	suresh	latur	12	;
	suresh	pune	34	;
	suresh	solapur	90	;
	suresh	latur	12	;*/
					
					if(array[k]==j) 
					{
						int checkvalue=0;
						
						
							
							if(!strcmp(value[k],record[i][j+1]))
							{

								//d=1;
								d++;
								
							}/*
							else
							{
								d=0;
							
							
							}*/
							//	d++;
								//printf("%d",)
								/*
								if(!strcmp(value[0],record[i][j+2]))
								{
									printf("%s\t",record[i][j]);
								printf("%s\t",record[i][j+1]);
								printf("%s\t",record[i][j+2]);

								}*/
							
							/*	printf("d is%d\n",d);
								j++;
								d++;
	*/
								/*printf("%s->%s-===",value[checkvalue],record[i][j+1]);
								printf("yes===");
								printf("%s\n",record[i][j+1]);
								checkvalue++;
								j++;
								
								if(d<numbertofcheckattribute)
								continue;
							}
							if(d==numbertofcheckattribute)
							{
							int	newj=0;
								while(newj<numbertofattribute)
								{
								printf("%s\t",record[i][newj+1]);
								newj++;

								}
							*/
							//}
							
							
								
					}
							
				}
				  
			    
			 k++;
			}
		//	printf("\n");
		j++;
		}
					if(d==numbertofcheckattribute)
						{	
							//printf("%d%d",d,numbertofcheckattribute);
								printf("\n");
								int	newj=0;
								while(newj<numbertofattribute)
								{
								printf("%s\t",record[i][newj+1]);
								newj++;

								}
									//printf("\n");
						}
		i++;
		}
	}
}
/*
find rr {[name:suresh,add:pune,age:reahul]|name:pk}
find rr {[name:suresh|add:pune,age:reahul]|name:pk}
find rr {name:suresh|name:pk}
find rr {name:suresh,name:pk}
find rr {name:suresh}*/