
int CheckCollection(char Db[],char collection[])
{
	char dir[500]="/home/suresh/Desktop/searcer/Database/";
	strcat(dir,Db);
	
	struct dirent *de;
	DIR *dr=opendir(dir);
	if(dr == NULL)
	{
		printf("could not found");
		return 0;
	}
	strcat(collection,".txt");
	
	while((de = readdir(dr))!=NULL)
	{
		if(de->d_type==DT_DIR)//read onlyfolder;
		continue;
		
		
		if(!strcmp(de->d_name,collection))
			return 1;
	}
	closedir(dr);
	return 0;
}

