// Program to implement an integer linked list

#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
};

void add_node(int value, struct node **first) {
	// Create new node for insertion
	struct node *temp = malloc(sizeof(struct node));
	temp->value = value;
	temp->next = NULL;
	// Working pointers
	struct node *previous = NULL;
	struct node *current = *first;
	//struct node *next = first->next;
	// Is there only one node in the list?
	if(current->next == NULL){
		if(current->value > value) {
			temp->next = current;
			*first = temp;
		} else {
			current->next = temp;
		}
	} else {
		// Otherwise, search the list and insert the node where it belongs
		while(current->next != NULL && current->value <= value) {
			previous = current;
			current = current->next;
		}
		// Insert node between previous and current
		previous->next = temp;
		temp->next = current;
	}
}

// Remove a node by its value. If multiple nodes of the same value
// exist, remove all of them.
void remove_node(int value, struct node **first) {
	struct node *current = *first;
	struct node *previous = NULL;
	while(current != NULL) {
		if(current->value == value && previous == NULL) {
			*first = current->next;
			current = *first;
		} else {
			if(current->value == value){
				previous->next = current->next;
				free(current);
				current = previous->next;
			} else {
				previous = current;
				current = current->next;
			}
		}
	}
}

void print_list(struct node *first) {
	int i = 0;
	struct node *current = first;
	while(current != NULL && i < 10) {
		i += 1;
		printf("%d\n", current->value);
		current = current->next;
	}
}

int main() {
	
	// Create a pointer to struct node to hold the first node of our list
	struct node *first = NULL;
	// Allocate enough memory at this pointer for a node struct
	first = malloc(sizeof(struct node));
	// Initialize the node with a null pointer for an address and a value to hold
	first->next = NULL;
	first->value = 1;
	printf("Starting list: \n");
	//print_list(first);
	// Begin adding values out of order
	add_node(3, &first);
	add_node(2, &first);
	printf("After adding values:\n");
	print_list(first);
	// Remove all nodes with a value of 2
	remove_node(2, &first);
	printf("After removing '2':\n");
	print_list(first);
	// Add another '1', one of which already exists in the list
	add_node(1, &first);
	printf("After adding another '1':\n");
	print_list(first);
	return 0;
	
}