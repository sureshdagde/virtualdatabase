#include <stdio.h>
struct arr
{
	char  arr[323][232];
};
struct arr f1()
{
		int j='a',i='a';
		struct arr a;
	while(i<'z')
	{
	//	printf("dfd");
		while(j<5)
		{
		a.arr[i][j]=(char)i+j;
		j++;
		}
		j=0;
		i++;
	}
return a;
}
int main()
{
	struct arr b;
	b=f1();
	int i='a';
	int j='a';
	while(i<'z')
	{
		while(j<5)
		{
		printf("%c\t",b.arr[i][j]);
		j++;
		}
		printf("\n");
		j=0;
		i++;
	}
	return 0;
}