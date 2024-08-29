#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node (int val)
    {
        data = val;
        left = right = nullptr;
    }
};

void preOrderHelper(Node *root){
    if (root == nullptr){
        return;
    }
    cout << " " << root->data;
    preOrderHelper(root->left);
    preOrderHelper(root->right);
}

void preOrder(Node *root){
    cout << "preOrder: ";
    preOrderHelper(root);
    cout << endl;
}

void postOrderHelper(Node *root) {
    if (root == nullptr){
        return;
    }
    postOrderHelper(root->left);
    postOrderHelper(root->right);
    cout <<" "<< root->data ;
}

void postOrder(Node *root){
    cout << "postOrder:";
    postOrderHelper(root);
    cout << endl;
}

void inOrderHelper(Node *root){
    if (root == nullptr){
        return;
    }
    inOrderHelper(root->left);
    cout << " " << root->data;
    inOrderHelper(root->right);
}

void inOrder(Node *root){
    cout << "inorder:";
    inOrderHelper(root);
    cout << endl;
}

void bstInsert(Node *& root,int data){
    if (root == nullptr){
        root = new Node(data);
        return;
    }
    if (data <= root -> data){
        bstInsert(root->left,data);
    }
    else{
        bstInsert(root->right,data);
    }
} 

void forestfire(Node *&root){
    if (root == nullptr){
        return;
    }
    forestfire(root->left);
    forestfire(root->right);
    delete root;
    root = nullptr;
}

void test(){
    Node *root = nullptr;
    bstInsert(root,50);
    bstInsert(root,30);
    bstInsert(root,55);
    bstInsert(root,40);
    bstInsert(root,35);
    bstInsert(root,45);
    preOrder(root);
    postOrder(root);
    inOrder(root);
    forestfire(root);
}

int main(){
    test();
    return 0;
}