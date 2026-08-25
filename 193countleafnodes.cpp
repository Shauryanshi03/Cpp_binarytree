#include<iostream>
#include<queue>
using namespace std;

template<typename T>
class binarytreenode{
    public:
    T data;
    binarytreenode<T> *left;
    binarytreenode<T> *right;

    binarytreenode(T data){
        this->data=data;
        left=NULL;
        right=NULL;
    }

void inorder(binarytreenode<int> *root,int &count){
    if(root==NULL){
        return;
    }

    inorder(root->left,count);
    
    if(root->left==NULL && root->right==NULL){
        count++;
    }

    inorder(root->right,count);
}

int noOfleaf(binarytreenode<int> *root){
    int cnt=0;
    inorder(root,cnt);
    return cnt;
}
};

int main(){

    binarytreenode<int>* root=new binarytreenode<int>(1);

    root->left=new binarytreenode<int>(2);
    root->right=new binarytreenode<int>(3);

    root->left->left=new binarytreenode<int>(4);
    root->left->right=new binarytreenode<int>(5);

    root->right->left=new binarytreenode<int>(6);

    cout<<"number of leaf nodes : "<<root->noOfleaf(root)<<endl;

    return 0;
}