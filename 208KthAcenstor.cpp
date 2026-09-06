#include<iostream>
#include<vector>
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

Node* solve(Node* root,int &k,int node){
    if(root==NULL)
    return NULL;

    if(root->data==node){
        return root;
    }
    Node* leftans=solve(root->left,k,node);
    Node* rightans=solve(root->right,k,node);

    if(leftans!=NULL && rightans==NULL){
        k--;
        if(k<=0){
            k=INT_MAX;
            return root;
        }
        return leftans;
    }
    if(leftans==NULL && rightans!=NULL){
        k--;
        if(k<=0){
            k=INT_MAX;
            return root;
        }
        return rightans;
    }
    return NULL;
}

int kthancestor(Node* root,int k,int node){
   
    Node* ans=solve(root,k,node);

    if(ans==NULL && ans->data==node)
    return -1;

    else
    return ans->data;
}

int main(){

    Node*root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);

    int k=2;
    int node=5;
    cout<<"Kth Ancestor : "<<kthancestor(root,k,node);

    return 0;
}