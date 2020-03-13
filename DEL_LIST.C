#include<stdio.h>
#include<conio.h>
typedef struct linked_list
{
	int info;
	struct linked_list *link;
}node;
node *head,*last,*ptr;
void empty()
{
	head=NULL;
}
void insert()
{
	node *ptr=(node*) malloc(sizeof(node));
	scanf("%d",&ptr->info);
	if(head==NULL)
		head=last=ptr;
	else
	{
		last->link=ptr;
		last=ptr;
	}
	ptr->link=NULL;
}
void traversal()
{
	node *ptr=head;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->info);
		ptr=ptr->link;
	}
}
void delete_beg()
{
	node *ptr;
	if(head==NULL)
		printf("The list is empty");
	else
	{
		ptr=head;
		head=head->link;
		free(ptr);
	}
}
void delete_end()
{
	node *ptr,*loc;
	if(head==NULL)
		printf("The list is empty");
	else
	{
		loc=head;
		ptr=head->link;
		while(ptr->link!=NULL)
		{
			loc=ptr;
			ptr=ptr->link;
			loc->link=NULL;
			free(ptr);
		}
	 }
}
void main()
{
	int i,n,ch;
	clrscr();
	empty();
	printf("Enter number of nodes : ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("Enter the %d node : ",i);
		insert();
	}
	printf("\n The linked list is : ");
	traversal();
	delete_beg();
	printf("\nAfter deletion from begining of list : ");
	traversal();
	delete_end();
	printf("\nAfter deletion from end of the list : ");
	traversal();
	getch();
}