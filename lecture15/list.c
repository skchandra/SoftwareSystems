/* Example code for Software Systems at Olin College.

Based on an example from http://www.learn-c.org/en/Linked_lists

Copyright 2014 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} Node;

Node *make_node(int val, Node *next) {
    Node *node = malloc(sizeof(Node));
    node->val = val;
    node->next = next;
    return node;
}

void print_list(Node *head) {
    Node *current = head;

    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}

int pop(Node **head) { //use a pointer to a node, don't create a node
    first = *head;
    Node *next_node;
    int retval = first->val;
    
    if (first == NULL) return -1;
    next_node = first->next;
    free(first);
    first = next_node;
    
    return retval;
}

// Add a new element to the beginning of the list.
void push(Node **head, int val) {
    Node *new_head = make_node(val, *head);
    *head = new_head;
}

// Remove the first element with the given value; return the number
// of nodes removed.
int remove_by_value(Node **head, int val) {
    Node *first = *head;
    Node *rem;

    if (first == NULL) return 0;

    if (first->val == val) {
		pop(head);
		return 1;
    }

    while (first != NULL) {
		if (first->next->val == val) {
			rem = first->next;
			first->next = rem->next;
			free(first);
			return 1;
		}
    }
    return 0;
}

// Reverse the elements of the list without allocating new nodes.
void reverse(Node **head) {
    Node *new_end = *head;
    Node *n; 

    if (new_end == NULL || new_end->next == NULL) {
		return; //end reverse because only one node or empty
    }

    n = new_end->next; //set head's next node
    new_end->next = NULL; //

    while (n != NULL) {
		Node *temp;
		temp = n->next;
		n->next = new_end;
		new_end = n;
		n = temp;
    }
    *head = new_end;
}


int main() {
    Node *test_list = make_node(1, NULL);
    test_list->next = make_node(2, NULL);
    test_list->next->next = make_node(3, NULL);
    test_list->next->next->next = make_node(4, NULL);

    int retval = pop(&test_list);
    push(&test_list, retval+10);

    remove_by_value(&test_list, 3);
    remove_by_value(&test_list, 7);

    reverse(&test_list);

    print_list(test_list);
}
