#include<iostream>
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

void flatten(Node* root){
    Node* curr=root;
    while(curr!=NULL){
        if(curr->left){
            Node* pred=curr->left; //(pred=predecessor)
            while(pred->right)
            pred=pred->right;

            pred->right=curr->right;
            curr->right=curr->left;
            curr->left=NULL;
        }
        curr=curr->right;
    }
    curr=root;
    while(curr!=NULL){
        curr->left=NULL;
        curr=curr->right;
    }
}

int main(){

    Node*root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(5);
    root->left->left=new Node(3);
    root->left->right=new Node(4);
    root->right->right=new Node(6);

    flatten(root);

    Node* curr=root;

    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->right;
    }
    return 0;
}