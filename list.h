#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
	struct node* next;
	void *value;
};

struct linked_list{
	struct node* head;
};


static inline struct linked_list *
ll_create(void)
{
	//Allocate memory for new linked list
	struct linked_list *new_list = (struct linked_list*)(malloc(sizeof(struct linked_list*)));
	//Check if linked list was created porperly
	if(new_list == NULL) return NULL;

	//Set head of linked list
	new_list->head = NULL;

	return new_list;
}

bool list_is_empty(const struct linked_list *linked_list)
{
	//Check if linked list exists first
	if(linked_list != NULL){
		//Check that head is empty and if so, return true that list is empty
		if(linked_list->head == NULL)
		{
			return 1;
		} 
		else
		{
			//Otherwise, return false for list is empty
			return 0;
		}
	}
	return 0;
}

static inline int 
ll_destroy(struct linked_list *ll)
{
	struct node *ptr = ll->head;

	//Check that linked list exists
	if(ll != NULL)
	{
		//Check that head of linked list is empty
		if(ptr == NULL)
		{
			//If empty, destory list and return logical true
			free(ptr);
			return 1;
		}
		//If list is populated, return logical false
		else return 0;
	}	
	else return 0;
}

static inline void
ll_add(struct linked_list *ll, void *value)
{
	struct node *new_node;
	//Allocate memory for new node structure
	new_node = (struct node*)(malloc(sizeof(struct node)));

	//Set up structure of new node
	new_node->next = ll->head;
	new_node->value = value;
	//Insert value at head of linked list
	ll->head = new_node;

	//Check that new node was created properly and that the linked list exists
	if(new_node == NULL || ll == NULL) return;
}

static inline int
ll_length(struct linked_list *ll)
{
	//Check that linked list exists, if not return 0
	if(ll == NULL) return 0;

	int count = 0;
	struct node* current = ll->head;
	while (current != NULL)
	{
		//Traverse the linked list, added 1 to count after each iteration until list reaches the end
		count++;
		current = current->next;
	}
	return count;
}

static inline void *
ll_remove_first(struct linked_list *ll)
{
	//Use a new pointer variable temp
	struct node *temp = ll->head;
	//Do not use the pointer variable head directly. If we use it, the address location of the first node in the linked list will be lost
	//Pointer to store the next node of the node which we are going to delete
	struct node* holder;
	void *value;

	if(temp != NULL)
	{
		//Executed only if the linked list has atleast one node
		holder = temp->next;
		//Assigning the next parameter of the node which we are going to delete
		ll->head = holder;
		//Making the head pointer point to next node of deleted node
		value = temp->value;
		free(temp);
		return value;
	}
	else return NULL;
}

static inline int
ll_contains(struct linked_list *ll, void *value)
{
	if(ll == NULL) return 0; 
	//Set cursor to head
	struct node* cursor = ll->head;

	//Check that cursor is not empty and traverse linked list
	while(cursor != NULL)
	{
		//If value is found, return logical true
		if((cursor->value) == value) 
			return 1;
		cursor = cursor->next;
	}
	//Otherwise, return logical false
	return 0;
}

#endif
