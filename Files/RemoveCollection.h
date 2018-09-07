
 
int RemoveCollection(char Db[],char collection[])
{
   int status,i=0;
  char collectiononlyname[50];
    char file_name[500]="/home/suresh/Desktop/searcer/Database/";
    strcat(file_name,Db);
    strcat(file_name,"/"); 
    strcat(file_name,collection);
   
    status = remove(file_name);
 
   if (status == 0)
   {
    while(i<strlen(collection)-4)
          {
            collectiononlyname[i]=collection[i];
            i++;
          }
      printf("%s collection deleted successfully.\n", collectiononlyname);
   }
   else
   {
      printf("Unable to delete the file\n");
      perror("Error");
   }
 
   return 0;
}