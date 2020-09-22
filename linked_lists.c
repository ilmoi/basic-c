#include <stdio.h>
#include <stdlib.h>

//define a struct in a RECURSIVE manner, which is ok in C
typedef struct node {
    int val;
    struct node * next;
} node_t;

void print_list(node_t *head) {
    //we define a variable "current" that initially points to head
    node_t *current = head;

    //then we recursively traverse the list
    while (current != NULL) {
        printf("Currently at node %d\n", current->val);
        current = current->next;
    }
}

void push(node_t *head, int val) {
    node_t *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = (node_t*) malloc(sizeof(node_t));
    current->next->val = val;
    current->next->next = NULL;
}

node_t* prepend(node_t *head, int val) {
    //create new node pointer
    node_t *new_node = (node_t*) malloc(sizeof(node_t));
    new_node->val = val;
    new_node->next = head; //set its next to existing head (pointer of pointer)
    //repoint head and return it
    head = new_node;
    return head;
}

node_t* pop(node_t *head) {
    //create a pointer called next_node that for now points to NULL
    node_t *next_node = NULL;
    //make next_node the currently 2nd node
    next_node = head->next;
    //get rid of head
    free(head);
    //repoint head to next_node and return it
    head = next_node;
    return head;
}

void remove_last(node_t* head) {
    //create current pointer
    node_t* current = head;
    //move to penultimate node
    while (current->next->next != NULL) {
        current = current->next;
    }
    //sets it next pointer to NULL, saving the last node to a new pointer
    node_t* to_be_deleted = current->next;
    current->next = NULL;
    //remove last node
    free(to_be_deleted);
}

void remove_specific(node_t* head, int val) {
    //what if no head?
    if (head == NULL) {
        return;
    }

    //what if only one node?
    if (head->next == NULL) {
        if (head->val == val) {
            free(head); //todo in theory here I could call pop, but my pop returns a value that this fn doesnt support so I cant
            return;
        }
        return;
    }

    //initiate a current pointer
    node_t* current = head;
    //move to node before the desired
    while (current->next->val != val) {

        //what if node not found?
        if (current->next->next == NULL) {
            return;
        }

        current = current->next;
    }
    //save the node to a sep pointer
    node_t* to_be_removed = current->next;
    //set the current's next pointer to one after
    current->next = current->next->next;
    //delete the node
    free(to_be_removed);
    //think about edge cases
}

int my_first_ll() {

    //define a local variable called head that will point to the first node
    node_t *head = NULL;
    head = (node_t*) malloc(sizeof(node_t));

    //check for null pointer
    if (head == NULL) {
        return 1;
    }

    //note how because head is a pointer we're using -> rather than dot notation to access attributes
    head->val = 1;
    head->next = (node_t*) malloc(sizeof(node_t));
    head->next->val = 2;
    head->next->next = NULL; //last item should point to a NULL

    //print_list(head);

    //add 3 and 4
    push(head, 3);
    push(head, 4);

    //add 0
    head = prepend(head, 0);

    //then pop it
    head = pop(head);

    //remove last one twice
    remove_last(head);
    remove_last(head);

    //back where we've started!
    //print_list(head);

    push(head, 6);
    push(head, 10);
    push(head, 16);

    //print_list(head);

    //lets remove node 10
    remove_specific(head, 11);

    print_list(head);
}

