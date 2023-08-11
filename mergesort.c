
#include <stdlib.h>
#include <stdio.h>

struct node* mergesort(struct node* head, int size);
struct node* merge(struct node * head1, struct node * head2);

struct node{
	int data;
	struct node * next;
};

// merges two sorted lists of nodes and returns head of a sorted list
struct node* merge(struct node * head1, struct node * head2)
{
	 
	struct node* temp;
	struct node* newhead;
	if(head2 == NULL) // if the second list is empty
	{
	    printf("List 2 is empty\n");
		return head1; // put head1 at the start of the merged list
	}
	else if (head1 == NULL)//if the first list is empty
	{
		return head2;
	}
	else 
	{
		printf("Both lists not empty\n");
	    printf("First list item: %d\n", head1->data);
		printf("Second list item: %d\n", head2->data);
		if (head1->data <= head2->data) // if the first value of in list 1 is <= the start of list2
		{ 

			newhead = head1;			
			head1->next = merge(head1->next, head2);

		} 
		else // if the first value in list2 is smaller  than the start of list 1
		{ 

			newhead = head2;
			head2->next = merge(head1, head2->next);	

		}
			return newhead;	
	}	
		
}


struct node* mergesort(struct node* head, int size)
{
	int size1 = size/2; //size of the fist half list 
	int size2 = size - size1; // size of the second half list
	struct node* head1 = head;
	struct node* head2 = head; 
	struct node* temp;
	
	if(head == NULL) {return head;}
	else if (head ->next == NULL) {return head;}
	else{
	
		for(int i = 0; i < size1; i++) // split the list into halves
		{
			temp = head2; // temp will finally hold the tail of the left half;
			head2 = head2->next; // head2 will finally hold the head of right half;
		}
		temp->next = NULL; // splits the two lists in half
		return merge(mergesort(head1, size1),mergesort(head2,size2));
	}
}

int main()
{	int count=0;
	struct node * temp = NULL; //a pointer to help print the list
	
	//allocate some new nodes to build up linked list; 
	
	struct node * node1 = (struct node *) malloc (sizeof(struct node));
	struct node * node2 = (struct node *) malloc (sizeof(struct node));
	struct node * node3 = (struct node *) malloc (sizeof(struct node));
	struct node * node4 = (struct node *) malloc (sizeof(struct node));
	struct node * node5 = (struct node *) malloc (sizeof(struct node));
	struct node * node6 = (struct node *) malloc (sizeof(struct node));
	if (node1 != NULL ){node1->data = 3; node1->next = NULL;}
	if (node2 != NULL ){node2->data = 5;node2->next = NULL;}
	if (node3 != NULL ){node3->data = 1; node3->next = NULL;}
	if (node4 != NULL ){node4->data = 2;node4->next = NULL;}
	if (node5 != NULL ){node5->data = 6;node5->next = NULL;}
	if (node6 != NULL ){node6->data = 4;node6->next = NULL;}	
	
	/* 
	//testing merge function
	
	node1->next = node5;
	node3->next = node6;
	temp = merge(node1, node3);
	while(temp!=NULL){
		
		printf("%d\t%d\n", count, temp->data);
		count++;
		temp = temp->next;
	}	
	
    */
	node1->next = node2; 
	node4->next = node5;
	node2->next = node3;
	node5->next = node6;
	node3->next = node4;
	temp = node1; 
	printf("before calling mergesort\n");
	while(temp!=NULL){
		
		printf("%d\t%d\n", count, temp->data);
		count++;
		temp = temp->next;
	}

	temp = mergesort(node1, 6);
	printf("test test\n");

	printf("test test\n");
	count = 0;
	while(temp!=NULL){
		
		printf("%d\t%d\n", count, temp->data);
		count++;
		temp = temp->next;
	}
		

	//release the memory allocated for the linked list.  
	free(node1);
	free(node2);
	free(node3);
	free(node4);
	free(node5);
	free(node6);
	return 0;
}