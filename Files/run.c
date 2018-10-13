#include <stdio.h>
main()
{

//fork();


	/*char s[]="cc project.c";
	char s1[]="./a.out";
	char c[]="clear";
	char const *com=s;
	char const *run=s1;
	char const *cl=c;
	system(com);
	system(cl);
	*/
	system("xterm -e cc project.c");
	system("xterm -e clear");

	system("xterm -hold -fa 'monospace' -fs 14 -cr 'red' -e ./a.out");

	/*
	system("gnome-terminal -e cc project.c");
	system("gnome-terminal -e clear");
	system("gnome-terminal -e ./a.out");
*/


}