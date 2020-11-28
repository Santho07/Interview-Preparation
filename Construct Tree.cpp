#include <stdio.h>
#include <iostream>
using namespace std;

struct node{
 int data;
 node *left, *right;
};
node* newNode(int data);

class Btree{
public:
    node *root;
    Btree(){ root = NULL; }
    void Insert(int key){
        if(root==NULL) root = newNode(key);
        else Insert(root, key);
    }
    void Insert(node *root, int data);
};
void Btree::Insert(node *root, int key){
    if(key < root->data){
        if(root->left!=NULL) Insert(root->left, key);
        else{
            root->left = newNode(key);
        }
    }
    else{
        if(root->right!=NULL) Insert(root->right, key);
        else root->right = newNode(key);
    }
}
node* newNode(int data){
    node *temp = new node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return(temp);
}
void PrintPostOder(node *Node){
    if(Node==NULL) return;
    PrintPostOder(Node->left);
    PrintPostOder(Node->right);
    cout<<Node->data<<" ";
}
int main(){
    Btree tree;
    tree.Insert(1);
    tree.Insert(2);
    tree.Insert(3);
    tree.Insert(4);
    tree.Insert(6);
    tree.Insert(7);
    tree.Insert(8);
    tree.Insert(9);
    PrintPostOder(tree.root);
}
