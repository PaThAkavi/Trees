#include<iostream>
using namespace std;

typedef long long ll;

typedef struct node {
    ll data;
    struct node* left;
    struct node* right;
}node;

node* insert(node* root, ll value){
    if(!root){
        node* newnode = (node*)malloc(sizeof(node));
        newnode->data = value;
        newnode->left = NULL;
        newnode->right = NULL;
        root = newnode;
    } else{
        if(value >= root->data){
            root->right = insert(root->right, value);
        } else{
            root->left = insert(root->left, value);
        }
    }
}

void inorder(node* root){
    if(root){
        inorder(root->left);
        printf("%lld ", root->data);
        inorder(root->right);
    }
}

node * minValueNode(struct node* root) 
{ 
    node* current = root; 
    while (current && current->left != NULL) 
        current = current->left; 
    return current; 
} 

node* deleteNode(node* root, ll key) 
{ 
    if (root == NULL) return root; 
    if (key < root->data) 
        root->left = deleteNode(root->left, key); 
    else if (key > root->data) 
        root->right = deleteNode(root->right, key); 
    else
    { 
        if (root->left == NULL) 
        { 
            node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 
        struct node* temp = minValueNode(root->right); 
        root->data = temp->data; 
        root->right = deleteNode(root->right, temp->data); 
    } 
    return root; 
} 

int main(){

    ll n, i, val, parent;
    char op;
    cout << "Enter number of operations to be performed:\n";
    cin >> n;
    node* root = NULL;
    for(i = 0; i < n; i++){
        cout << "Please specify operation(i or d) and the node value:\n";
        cin >> op >> val;
        if(op == 'i'){
            root = insert(root, val);
        } 
        else if(op == 'd'){
            root = deleteNode(root, val);
        } else{
            cout << "No such operation present" << endl;
        }
        
        if(i == 0){
            printf("%lld\n", i+1);
            parent = i+1;
        } else if(val >= root->data){
            printf("%lld\n", 2*parent+1);
        } else{
            printf("%lld\n", 2*parent);
        }
    }
    inorder(root);
    return 0;
}