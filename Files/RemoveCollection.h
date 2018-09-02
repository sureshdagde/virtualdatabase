
 
int RemoveCollection(char Db[],char collection[])
{
   int status;
  ;
    char file_name[500]="/home/suresh/Desktop/searcer/Database/";
    strcat(file_name,Db);
    strcat(file_name,"/"); 
    strcat(file_name,collection);
   
    status = remove(file_name);
 
   if (status == 0)
      printf("%s collection deleted successfully.\n", collection);
   else
   {
      printf("Unable to delete the file\n");
      perror("Error");
   }
 
   return 0;
}