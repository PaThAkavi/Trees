#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* left;
    int data;
    struct Node* right;
}node;

int main(){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = 30;
    newnode->left = NULL;
    newnode->right =  NULL;
    printf("%d\n", newnode->data);
    return 0;
}