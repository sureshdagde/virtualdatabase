
int ShowCollection(char DB[])
{
	int i;
	int j=0;
	char colle[100];
	char dir[500]="/home/suresh/Desktop/searcer/Database/";
	strcat(dir,DB);
	struct dirent *de;
	DIR *dr=opendir(dir);
	if(dr == NULL)
	{
		printf("could not found");
		return 0;
	}
	while((de = readdir(dr))!=NULL)
	{
		if(de->d_type==DT_DIR)//read onlyfolder;
		continue;
		//printf("%s\n",de->d_name);
		strcpy(colle,de->d_name);
		//printf("%s\n",colle);
		i=strlen(colle);
		while(j<i-4)
		{
			printf("%c",colle[j]);
			j++;
		}
		printf("\n");
		j=0;
	}
	closedir(dr);
	return 0;
}

