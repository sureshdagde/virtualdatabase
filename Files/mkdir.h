
void CreateDatabase(const char *name)
	{
		char dir[500]="/home/suresh/Desktop/searcer/Database/";
		strcat(dir,name);

		DIR *di =opendir(dir);
		if(di)
		{
			printf("exist");
			closedir(di);
		}
		else
		{
		
		
		#ifdef __linux__
		mkdir(dir,0777);
		#else
		_mkdir(dir,0777);
		#endif
		printf("folder create succesfully");
		}
	}
