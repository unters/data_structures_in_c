/**
 * bst.h
 * 
 * This file defines the structure of binary search tree node and declares
 * basic functions to work with binary search trees.
 * 
 * Binary search tree
 * Operation    Average Worst
 * Memory       n       n
 * Search       logn    n
 * Insert       logn    n
 * Remove       logn    n
 */

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include "stddef.h"
#include "stdlib.h"
#include "stdio.h"


struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

struct Node* create_binary_search_tree(int);

struct Node* find(struct Node*, int);

struct Node* insert(struct Node*, int);

struct Node* remove_node(struct Node*, int);

struct Node* remove_root(struct Node*);

void infix_traverse(struct Node*);

void remove_tree(struct Node*);

#endif
