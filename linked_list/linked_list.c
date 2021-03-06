#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node * create_node() {
	struct node *new_node = malloc(sizeof(*new_node));
	new_node->next = NULL;
	printf("Enter the data: ");
	scanf(" %d", &new_node->data);
	return new_node;
}

void print_linked_list(struct node *head) {
	printf("\n---------------------------------------------------------\n");
	while (head != NULL) {
		printf("%d\t", head->data);
		head = head->next;
	}
	printf("\n---------------------------------------------------------\n");
}

void insert_at_beg(struct node **indirect) {
	struct node *tmp = create_node();
	tmp->next = (*indirect);
	*indirect = tmp;
}

void insert_at_end(struct node **indirect) {
	struct node *tmp = create_node();
	while(*indirect != NULL)
		indirect = &(*indirect)->next;
	*indirect = tmp;
}

void delete_node(struct node **indirect) {
	struct node *tmp = *indirect;
	*indirect = (*indirect)->next;
	free(tmp);
}

void delete_at_beg(struct node **indirect) {
	if (*indirect == NULL) {
		printf("\nList is empty!!!\n\n");
		return;
	}
	delete_node(indirect);
}

void delete_at_end(struct node **indirect) {
	if(*indirect == NULL ) {
		printf("\nList is empty!!!\n\n");
		return;
	}
	
	while((*indirect)->next != NULL)
		indirect = &(*indirect)->next;

	delete_node(indirect);
}

int main() {

	int choice;
	struct node *head = NULL;

	do {	
		printf("\nEnter your choice \
			\n\r1. Insert node at begining \
			\n\r2. Insert node at end \
			\n\r3. Delete node at begining \
			\n\r4. Delete node at end \
			\n\r9. Print Linked List \
			\n\r0. EXIT \
			\n\n\rEnter your choice: ");
		scanf(" %d", &choice);

		switch(choice) {
			case 1:	insert_at_beg(&head); break;
			case 2:	insert_at_end(&head); break;
			case 3:	delete_at_beg(&head); break;
			case 4:	delete_at_end(&head); break;
			case 9:	print_linked_list(head); break;
			case 0:	exit(EXIT_SUCCESS);
		}
	} while(choice);

	return 0;
}
