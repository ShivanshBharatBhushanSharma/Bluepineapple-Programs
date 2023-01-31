#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int BOOK_Id = 0;

void display_Book();
void display_IssuedBook();
void insert_Book();
void issue_Book();
void remove_Book(int);
void return_Book();
void remove_IssuedBook(int);
void search_by_BookName();
void search_by_AuthorName();


struct book
{
	int book_id;
	char book_name[80];
	char author_name[80];
	struct book *next;
}*headb=NULL,*lastb,*tempb;

struct student
{
	char student_name[80];
	int book_id;
	char book_name[80];
	char author_name[80];
	struct student *next;
}*headi=NULL,*lasti,*tempi;

void main(int argc,char *argv[])
{	
	int ch;
    
 	
	while(1)
	{
	printf("\n***MENU***\n");
	printf("1.Display Book \n2.Display Issued Book \n3.Insert Book \n4.Issue Book \n");
	printf("5.Return Book \n6.Search By Author Name \n7.Search By Book Name\n8.Exit \n\nChoose Menu = ");
	scanf("%d",&ch);	

		switch(ch)
		{
			case 1:display_Book();
				 break;
			case 2:display_IssuedBook();
				 break;
			case 3:insert_Book();
				 break;	 
			case 4:issue_Book();
				 break;
            case 5:return_Book();
				 break;                        
			case 6:search_by_AuthorName();
				 break;                        
            case 7:search_by_BookName();
                 break;
			case 8:exit(0);
				 break;
			default: printf("\nPlease enter vaild input.\n");	 
			
		}
	}
}

void display_Book()
{   
    if(headb!=NULL)
	{
        for(tempb=headb;tempb!=NULL;tempb=tempb->next)
        {
            printf("Book Id=%d\t",tempb->book_id);
            printf("Book Name=%s\t",tempb->book_name);
            printf("Author Name=%s\n",tempb->author_name);
        }
    }
    else{
        printf("No Data to display in Book\n");
    }
}
void display_IssuedBook()
{
    if(headi!=NULL){
        for(tempi=headi;tempi!=NULL;tempi=tempi->next)
        {
        	printf("Student Name=%s\t",tempi->student_name);
            printf("Book Id=%d\t",tempi->book_id);
            printf("Book Name=%s\t",tempi->book_name);
            printf("Author Name=%s\n",tempi->author_name);
        }
    } else{
        printf("No Data to display in Student\n");
    }
	
}


void insert_Book()
{   

	char bookName[80];
	char authorName[80];

	struct book *newbook;
	newbook=(struct book *)malloc(sizeof(struct book));
    printf("Enter Book Name: ");
    scanf("%s",bookName);
    printf("Enter Author Name: ");
    scanf("%s",authorName);
    
	newbook->book_id=++BOOK_Id;                
	strcpy(newbook->book_name,bookName);
	strcpy(newbook->author_name,authorName);
	newbook->next=NULL;

	if(headb==NULL)
	{
		headb=newbook;
	}
	else
	{
		lastb=headb;
		while(lastb->next!=NULL)
		{
			lastb=lastb->next;
		}
		lastb->next=newbook;
	}
}

void issue_Book()
{   
	char studentName[80];
	int bookId; 
	struct book *temp=headb;
	int flag = 0;
	int position = 1;
	
	printf("\nEnter Studnet Name to Issue Book= ");
	scanf("%s",studentName);
	printf("Enter Book Id= ");
	scanf("%d",&bookId);
	
	while(temp!=NULL)
	{    
		if(temp->book_id == bookId)
		{
			struct student *newbook;
			newbook=(struct student *)malloc(sizeof(struct student));
			
			strcpy(newbook->student_name,studentName);
			newbook->book_id=temp->book_id;                
			strcpy(newbook->book_name,temp->book_name);
			strcpy(newbook->author_name,temp->author_name);
			newbook->next=NULL;
		    
		    if(headi==NULL)
			{
				headi=newbook;
			}
			else
			{
				lasti=headi;
				while(lasti->next!=NULL)
				{
					lasti=lasti->next;
				}
				lasti->next=newbook;
			}
			flag = 1;
			remove_Book(position);
		}
		temp=temp->next;
		position++;
	}
	if(flag == 0) {
		printf("No such Book Id to Issue Book!!!\n");	
	} else {
		printf("Book Issued Successfully!!!\n");
	} 	
}

void remove_Book(int pos){
	int i;
	struct book *temp=headb,*p;
	if(pos == 1)
	{
		headb=headb->next;
		temp->next=NULL;
		free(temp);
	}
	else
	{
		p=headb;
		for(i=1;i<pos-1;i++)
		{
			p=p->next;
		}
		temp=p->next;
		p->next=temp->next;
		temp->next=NULL;
		free(temp);
	}
}

void return_Book()
{   
	int bookId; 
	struct student *temp=headi;
	int flag = 0;
	int position = 1;
	
	printf("Enter Book Id= ");
	scanf("%d",&bookId);
	
	while(temp!=NULL)
	{    
		if(temp->book_id == bookId)
		{
			struct book *newbook;
			newbook=(struct book *)malloc(sizeof(struct book));
			
			newbook->book_id=temp->book_id;                
			strcpy(newbook->book_name,temp->book_name);
			strcpy(newbook->author_name,temp->author_name);
			newbook->next=NULL;
		    
		    if(headb==NULL)
			{
				headb=newbook;
			}
			else
			{
				lastb=headb;
				while(lastb->next!=NULL)
				{
					lastb=lastb->next;
				}
				lastb->next=newbook;
			}
			flag = 1;
			remove_IssuedBook(position);
		}
		temp=temp->next;
		position++;
	}
	if(flag == 0) {
		printf("No such Book Id to Return Book!!!\n");	
	} else {
		printf("Book Return Successfully!!!\n");
	} 	
}

void remove_IssuedBook(int pos){
	int i;
	struct student *temp=headi,*p;
	if(pos == 1)
	{
		headi=headi->next;
		temp->next=NULL;
		free(temp);
	}
	else
	{
		p=headi;
		for(i=1;i<pos-1;i++)
		{
			p=p->next;
		}
		temp=p->next;
		p->next=temp->next;
		temp->next=NULL;
		free(temp);
	}
}


void search_by_BookName()
{
char bookName[80];
struct book *temp=headb;
int flag = 0;

printf("Enter book name to search = ");
scanf("%s\n",bookName);

while(temp!=NULL)
{
if(strstr(temp->book_name,bookName)!=NULL)
{
printf("Book Id=%d\t",temp->book_id);
printf("Book Name=%s\t",temp->book_name);
printf("Author Name=%s\n",temp->author_name);
flag = 1;
}
temp=temp->next;
}
if(flag == 0) printf("No Book Found!!!\n");
}

void search_by_AuthorName()
{
char authorName[80];
struct book *temp=headb;
int flag = 0;

printf("Enter author name to search book=");
scanf("%s\n",authorName);

while(temp!=NULL)
{
if(strstr(temp->author_name,authorName)!=NULL)
{
printf("Book Id=%d\t",temp->book_id);
printf("Book Name=%s\t",temp->book_name);
printf("Author Name=%s\n",temp->author_name);
flag = 1;
}
temp=temp->next;
}
if(flag == 0) printf("No Book Found for author!!!\n");
}