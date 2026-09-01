#include<iostream>
#include<queue>
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

int height(struct Node* node){
    if(node==NULL){
        return 0;
    }
    int left=height(node->left);
    int right=height(node->right);

    int ans=max(left,right)+1;
    return ans;
}

int main(){
    Node*root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);

    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);

    cout<<"height of tree : "<<height(root)<<endl;

    return 0;
}