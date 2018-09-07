splite(char cmd[])
{
	printf("sfs");
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
	}