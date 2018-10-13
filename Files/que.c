#include<stdio.h>
struct q
{
	int data;
	struct q *next;
};
struct q *a=NULL;
struct q *b=NULL;

void push(int data)
{
	struct q c;
	if(a==NULL)
	{
		
		c.data=data;
		c.next=NULL;
		a=&c;
		b=&c;
		printf("%d\t",b->data);
		printf("1-%d\t-2-%d\t-3-%d\t",&a,&b,&c);

	}
	else
	{
	
		c.data=data;
		c.next=NULL;
		b->next=&c;
		b=&c;
		printf("%d\t",b->data);
		//printf("welcom %d",b->data);
		//	printf("mkmkj");
	}
}
void show()
{ 
	struct q *p;
	struct q *r;
	p=a;
	p=b;
	//p=p->next;
	printf("----%d",p->data);

	/*
	while(p->next!=NULL)
	{
		printf("%d",p->data);
		p=p->next;
	}*/
}
main()
{
push(4);
push(5);
push(6);
push(7);
push(8);
push(9);

show();
}