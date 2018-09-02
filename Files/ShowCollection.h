
int ShowCollection(char DB[])
{
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
		printf("%s\n",de->d_name);
	}
	closedir(dr);
	return 0;
}

