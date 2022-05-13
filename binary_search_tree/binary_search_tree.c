#include "binary_search_tree.h"


struct Node* create_binary_search_tree(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    
    return newNode;
}


struct Node* find(struct Node* root, int value) {
    if (root->value == value)
        return root;

    else if (root->left && value < root->value)
        return find(root->left, value);

    else if (root->right && value > root->value)
        return find(root->right, value);
    
    else
        return NULL;
}


struct Node* insert(struct Node* root, int value) {
    if (value < root->value) {
        if (root->left)
            return insert(root->left, value);
    
        else {
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->value = value;
            root->left = newNode;
            return newNode;
        }
    }

    else if (value > root->value) {
        if (root->right)
            return insert(root->right, value);
    
        else {
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->value = value;
            root->right = newNode;
            return newNode;
        }
    }

    else
        return root;
}


struct Node* remove_node(struct Node* root, int value) {
    if (!root)
        return NULL;

    else if (value < root->value) {
        root->left = remove_node(root->left, value);
        return root;
    }

    else if (value > root->value) {
        root->right = remove_node(root->right, value);
        return root;
    }

    // Is this comparison neccessary? Can I omit this if-statement?
    else if (root->value == value) {
        if (!(root->left)) {
            // If both left and right child child nodes are missing.
            if (!(root->right)) {
                free(root);
                return NULL;
            }

            // If only left node is missing.
            else {
                struct Node* right = root->right;
                free(root);
                return right;
            }
        }

        // If only right child node is missing.
        else if (!(root->right)){
            struct Node* left = root->left;
            free(root);
            return left;
        }

        // If both child nodes are present.
        else {
            if (!(root->right->left)) {
                struct Node* right = root->right;
                right->left = root->left;
                free(root);
                return right;
            }

            else {
                struct Node* minNode = root->right->left;

                while (minNode->left != NULL)
                    minNode = minNode->left;

                struct Node* newNode = create_binary_search_tree(
                    minNode->value);
                newNode->left  = root->left;
                newNode->right = root->right;

                remove_node(root->right, minNode->value);
                free(root);
                return newNode;
            }
        }
    }
}


void infix_traverse(struct Node* root) {
    if (!root)
        return;
        
    infix_traverse(root->left);    
    printf("%d ", root->value);
    infix_traverse(root->right);
}


void remove_tree(struct Node* root) {
    if (root->left)
        remove_tree(root->left);

    if (root->right)
        remove_tree(root->right);

    free(root);
}
