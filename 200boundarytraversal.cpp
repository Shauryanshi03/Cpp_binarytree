#include<iostream>
#include<queue>
#include<vector>
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

void traverseleft(Node* root,vector<int> &ans){
    if(root==NULL)
    return;

    if(root->left==NULL && root->right==NULL){
        return;
    }

    ans.push_back(root->data);
    if(root->left)
    traverseleft(root->left,ans);
    else
    traverseleft(root->right,ans);
}

void traverseleaf(Node* root,vector<int> &ans){
    if(root==NULL)
    return;

    if(root->left==NULL && root->right==NULL){
        ans.push_back(root->data);
        return;
    }
    traverseleaf(root->left,ans);
    traverseleaf(root->right,ans);
}

void traverseright(Node* root,vector<int> &ans){
    if(root==NULL)
    return;

    if(root->left==NULL && root->right==NULL){
        return;
    }

    if(root->right)
    traverseright(root->right,ans);
    else
    traverseleft(root->left,ans);

    ans.push_back(root->data);
}

vector<int> boundary(Node* root){
    vector<int> ans;
    if(root==NULL)
    return ans;

    ans.push_back(root->data);

    traverseleft(root->left,ans);

    traverseleaf(root->left,ans);

    traverseleaf(root->right,ans);

    traverseright(root->right,ans);
    
    return ans;
}

int main(){

    Node*root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);

    vector<int> ans=boundary(root);

    for(int x : ans)
    cout<<x<<" ";

    return 0;
}