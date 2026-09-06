#include<iostream>
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

void solve(Node* root,int k,int &count,vector<int>& path){
    if(root==NULL){
        return;

        path.push_back(root->data);

        solve(root->left,k,count,path);
        solve(root->right,k,count,path);

        int size=path.size();
        int sum=0;
        for(int i=size-1;i>=0;i--){
            sum+=path[i];
            if(sum==k)
            count++;
        }
        path.pop_back();
    }
}

int sumK(Node *root,int k){
    vector<int> path;
    int count=0;
    solve(root,k,count,path);
    return count;
}

int main(){

    Node*root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);

    cout<<"No. of paths : "<<sumK(root,3);

    return 0;
}