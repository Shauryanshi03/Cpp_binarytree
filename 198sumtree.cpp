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

pair<bool,int> issumtreefast(Node* root){
    if(root==NULL){
        pair<bool,int> p=make_pair(true,0);
        return p;
    }
    if(root->left==NULL && root->right==NULL){
        pair<bool,int> p=make_pair(true,root->data);
        return p;
    }

    pair<bool,int> leftans=issumtreefast(root->left);
    pair<bool,int> rightans=issumtreefast(root->right);

    bool left=leftans.first;
    bool right=rightans.first;
    bool condition=root->data==leftans.second+rightans.second;

    pair<bool,int> ans;
    if(left && right && condition){
        ans.first=true;
        ans.second=2*root->data;
    }
    else{
        ans.first=false;
    }
    return ans;
}

bool issumtree(Node* root){
    return issumtreefast(root).first;
}

int main(){
    Node*root=new Node(26);
    root->left=new Node(10);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(6);
    root->right->right=new Node(3);

    if(issumtree(root)){
        cout<<"tree is a sum tree"<<endl;
    }
    else{
        cout<<"tree is not a sum tree"<<endl;
    }

    return 0;
}