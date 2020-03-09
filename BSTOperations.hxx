#include<iostream>
using namespace std;

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
}node;

typedef long long ll;

node* insert(node* root, ll value){
    if(!root){
        node* newnode = (node*)malloc(sizeof(node));
        newnode->data = value;
        newnode->left = NULL;
        newnode->right = NULL;
        root = newnode;
    } else{
        if(value){
            if(value >= root->data){
                root->right = insert(root->right, value);
            } else{
                root->left = insert(root->left, value);
            }
        }
    }
}

void delete(node* root, value){
    
}

int main(){

    ll n, i, val;
    char op;
    cin >> n;
    node* root = NULL;
    for(i = 0; i < n; i++){
        cin >> op >> val;
        if(op == 'i'){
            root = insert(root, val);
        } 
        else if(ch == 'd'){
            delete(root, val);
        } else{
            cout << "No such operation present" << endl;
        }
    }

    return 0;
}