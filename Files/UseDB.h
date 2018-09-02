int UseDB(char DBName[50])
{
char dir[500]="/home/suresh/Desktop/searcer/Database/";
		strcat(dir,DBName);

		DIR *di =opendir(dir);
		if(di)
		{
			printf("mount %s",DBName);
			//closedir(di);
			return 1;

		}
		else
		{
			printf("The Database Of Name -> %s <- is Not Exist",DBName);
			printf("\nprior Database is unmounted\n");
			return 0;
		}
		
		
}