#include <stdio.h>
main()
{

//{ n u m b e r : 1 3  1  ,  n  a  m  e  :  [  f  :  s  u  r  e  s  h  ,  l  :  d  a  a  g  d  e  ]  ,  s  a  l  a  r  y  :  5  0  0  ,  s  t  u  d  y  :  m  c  s  f  y  }"
//1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 31 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60
 
 
	    	int i=0,j=0,k=0;
	    	char cmdword[]="{number:131,name:[f:suresh,l:daagde],salary:500,study:mcsfy}";
	    	printf("%c\n",cmdword[5]);
	    	printf("%d\n",strlen(cmdword));
	    	getchar();
	    	char str[223][223];
	    	int pp=strlen(cmdword);
	    	pp-=5;
	    	while(i<strlen(cmdword)-2)
			{
				printf("%d\t",i);
				printf("%d\t",j);
				printf("%d\t",k);
				printf("\n");
				if(cmdword[i]==':'  && cmdword[i+1]!='[')
				{
					
					while(cmdword[i]!=',' && i<strlen(cmdword)-1)
					{
						//i++;
						if(i>53)
						{
						printf("%d\t",i);
						}
						
						if(cmdword[i]!=':' && cmdword[i]!=']' )
						str[j][k]=cmdword[i];
					i++;
					k++;
					}

					str[j][k+1]='|';
					//printf("%d\t",k);
					//printf("%d",j);
					//printf(fp,"%d",0);
					//fprintf(fp,"%s","\n");
					
					
					//printf("\n");
					k=0;
					j++;
				
				}
			 i++;
			}
			printf("hdvhdsf");
			int l=0,m=0;
		 while(l<5)
		 {//printf("ss\t");
		 	while(str[l][m]!='|')
			{
			//	printf("ss\t");
				printf("%c",str[l][m]);
				m++;
			}
			printf("\n");
			m=0;
			l++;
		 
		 }
	 
 }