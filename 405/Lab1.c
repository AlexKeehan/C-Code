#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Linked List implementation
struct node 
{
   int data;
   struct node *next;
};

struct node *head = NULL;


// Prints Linked List
void printList()
{
   struct node *p = head;
   printf("\n[");

   while(p != NULL) {
      printf(" %d ",p->data);
      p = p->next;
   }
   printf("]\n");
}


// Inserts elements into Linked List at the beginning
void insert(int data)
{

   struct node *ll = (struct node*) malloc(sizeof(struct node));
   ll->data = data;
   ll->next = head;
   head = ll;
}


// Deletes elements from the beginning of the Linked List
void delete()
{
	if (head != NULL)
	{
		struct node* temp;
		temp = head;
		head = head->next;
		free(temp);
	}
	else 
	{
		printf("\nStack is already empty.\n");
		return;
	}
}


// Push elements onto the front of the Linked List/top of the stack
void push()
{
	int input;
	printf("\nEnter the element to be added onto the stack: \n");
	scanf("%d", &input);
	insert(input);
}


// Remove elements from the front of the Linked List/top of the stack
void pop()
{
	if (head != NULL)
	{
		printf("\nPopped element: %d\n", head->data);
	}
	delete();
}


// Check if the first node in the Linked List is NULL
void isEmpty()
{
	if (head == NULL)
	{
		printf("\nStack is empty.\n");
		return;
	}
	else
	{
		printf("\nStack is NOT empty.\n");
		printf("The contents of the stack are: ");
		printList();
	}
}



// Main function to get user input
void main()
{
   	int decision;
	
   	while(1)
   	{
	   	printf("Options: \n");
	   	printf("1. Add elements to the stack.\n");
	   	printf("2. Remove elements from the stack.\n");
	   	printf("3. Check if the stack is empty.\n");
	   	printf("4. Print the entire stack.\n");
	   	printf("5. Exit.\n");
	   	scanf("%d", &decision);

	   	switch (decision)
	   	{
		   	case 1:
			   	push();
			   	break;
		   	case 2:
			   	pop();
			   	break;
		   	case 3:
			   	isEmpty();
			   	break;
		   	case 4:
			   	printList();
			   	break;
	           	case 5:
			   	exit(0);
		   	default:
			   	printf("\n Invalid Choice!\n");
	   	}
   	}			   	
}
