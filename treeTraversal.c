#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* left;
    int data;
    struct Node* right;
}node;

node* insert(node* root, int val){
    if(!root){
        node* newnode = (node*)malloc(sizeof(node));
        newnode->data = val;
        newnode->left = NULL;
        newnode->right =  NULL;
        root = newnode;
    } else {
        if(val > root->data){
            root->right = insert(root->right, val);
        } else{
            root->left = insert(root->left, val);
        }
    }
    return root;
}

void inorder(node* root){
    if(root){
        inorder(root->left);
        printf("%d\n", root->data);
        inorder(root->right);
    }
}

void display(node* root){
    if(root){
        printf("%d ", root->data);
    } else{
        return;
    }
}

int main(){
    int r, num;
    printf("How many nodes do you want in your tree?\n");
    scanf("%d", &num);
    printf("Enter the root node:\n");
    scanf("%d", &r);
    node* root = (node*)malloc(sizeof(node));
    insert(root, r);
    for(int i = 0; i < num; i++){
        int data;
        printf("Enter node #%d:\n", i+2);
        scanf("%d", &data);
        insert(root, data);
    }
    inorder(root);
    return 0;
}