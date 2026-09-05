#include<iostream>
#include<queue>
#include<vector>
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

void solve(Node* root,vector<int> &ans,int level){
    if(root==NULL)
    return;

    if(level==ans.size())
    ans.push_back(root->data);

    solve(root->right,ans,level+1);
    solve(root->left,ans,level+1);
}

vector<int> rightview(Node*root){
    vector<int> ans;
    solve(root,ans,0);
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

    vector<int> ans=rightview(root);

    for(int i : ans)
    cout<<i<<" ";

    return 0;
}