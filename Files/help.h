void help()
{
	printf("space must be not allowed after the command\nmust be only one space is allowed between the command \n");
	printf("1)ceate db Database_Name                  -->\t used to create the database (must be not duplicate)\n");
	printf("2)show dbs                                -->\t used to show the all list of database\n");
	printf("3)use db Database_Name                    -->\t used to mount(select) the database\n");
	printf("4)show c                                  -->\t used to show all list of collection in current database but need to mount database\n");
	printf("5)create c all_parameter_of_collection    -->\t used to create collection but need to mount database\n");
	printf("6)rm db database_name                     -->\t used to remove database\n");
	printf("7)rm all db database_name                 -->\t used to all remove database\n");
	printf("8)rm c collection_name                    -->\t used to remove collection\n");
	printf("9)rm c all collection_name                -->\t used to remove all collection \n");
	printf("10)exit                                   -->\t used to exit\n");
}