#include<iostream>
#include<climits>
#include<map>
using namespace std;
struct Node{
    int data;
    Node*left;
    Node*right;

    Node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

Node* lca(Node* root,int n1,int n2){
    if(root==NULL){
        return NULL;
    }
    if(root->data==n1 || root->data==n2){
        return root;
    }

    Node* leftans=lca(root->left,n1,n2);
    Node* rightans=lca(root->right,n1,n2);

    if(leftans!=NULL && rightans!=NULL){
        return root;
    }
    else if(leftans!=NULL && rightans==NULL){
        return leftans;
    }
    else if(leftans==NULL && rightans!=NULL){
        return rightans;
    }
    else{
        return NULL;
    }
}

int main(){

    Node*root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);

    cout<<"LCA : "<<lca(root,4,7)->data;

    return 0;
}