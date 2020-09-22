//
// Created by Ilja Moisejevs on 8/16/20.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* left;
    struct node* right;
} node_t;

//todo
int min(node_t* node) {
    return 1;
}

//todo
int max(node_t* node) {
    return 1;
}

void print_tree(node_t* n, int indent) {
    //base case, tree leaves
    //NOTE have to catch n being null rather than both of its kids, coz what if 1 kid is null and we follow it?
    if (n == NULL) {
        return;
    } else {
        //print current level
        printf("%*c", indent, ' ');
        printf("%d\n", n->val);
        //then kids
        print_tree(n->left, indent+2);
        print_tree(n->right, indent+2);
    }
}

int bst() {
    node_t* n1;
    n1 = (node_t*) malloc(sizeof(node_t));

    //level 1 children
    n1->val = 5;
    n1->left = (node_t*) malloc(sizeof(node_t));
    n1->right = (node_t*) malloc(sizeof(node_t));

    //level 2 children
    n1->left->val = 3;
    n1->left->left = (node_t*) malloc(sizeof(node_t));
    n1->left->right = NULL;

    n1->right->val = 10;
    n1->right->left = (node_t*) malloc(sizeof(node_t));
    n1->right->right = NULL;

    //level 3 children
    n1->left->left->val = 1;
    n1->left->left->left = NULL;
    n1->left->left->right = NULL;

    n1->right->left->val = 6;
    n1->right->left->left = NULL;
    n1->right->left->right = NULL;

    print_tree(n1, 0);

    return 1;
}

