StringToken(char *cmd,char cmdword,int CommandWordLength)
{
	int i=0,k=0;
	while(i<strlen(cmd))
		{
			if(cmd[i]==' ')
			{

				CommandWordLength++;
				k=0;
				i++;
			}
			if(cmd[i]!=' ') //imp to avoid the white space
			*cmdword[CommandWordLength][k]=cmd[i];
			else
				CommandWordLength--;
			i++;
			k++;
		}
}