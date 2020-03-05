#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* left;
    int data;
    struct Node* right;
}node;

void display(node* root){
    if(root){
        printf("%d\n", root->data);
    } else{
        return;
    }
}

int main(){
    node* newnode = (node*)malloc(sizeof(node));
    int r;
    printf("Enter the root node:\n");
    scanf("%d", &r);
    newnode->data = r;
    newnode->left = NULL;
    newnode->right =  NULL;

    display(newnode);
    return 0;
}