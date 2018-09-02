
int RemoveCollectionAll(char DB[])
{
    // These are data types defined in the "dirent" header
    char file_name[500]="/home/suresh/Desktop/searcer/Database/";
    strcat(file_name,DB);
    DIR *theFolder = opendir(file_name);
    struct dirent *next_file;
    char filepath[256];

    while ( (next_file = readdir(theFolder)) != NULL )
    {
        // build the path for each file in the folder
        sprintf(filepath, "%s/%s", file_name, next_file->d_name);
        remove(filepath);
    }
    closedir(theFolder);
    return 0;
}

