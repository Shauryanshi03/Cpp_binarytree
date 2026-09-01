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

pair<bool,int> isbalancedfast(Node* root){
     if(root==NULL){
        pair<bool,int>p=make_pair(true,0);
        return p;
     }

    pair<int,int> left= isbalancedfast(root->left);
    pair<int,int> right= isbalancedfast(root->right);

    bool leftans=left.first;
    bool rightans=right.first;

    bool diff=abs (left.second-right.second)<=1;

    pair<bool,int> ans;
    ans.second=max(left.second,right.second)+1;
    if(leftans && rightans && diff){
        ans.first=true;
    }
    else{
        ans.first=false;
    }
    return ans;
}

bool isbalanced(Node*root){
    return isbalancedfast(root).first;
}

int main(){
    Node*root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);

    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);

    if(isbalanced(root)){
        cout<<"tree is balanced"<<endl;
    }
    else{
        cout<<"tree is not balanced"<<endl;
    }
    return 0;
}