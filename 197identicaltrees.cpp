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

bool isidentical(Node *r1,Node *r2){
    if(r1==NULL && r2==NULL){
        return true;
    }

    if(r1==NULL && r2!=NULL){
        return false;
    }

    if(r1!=NULL && r2==NULL){
        return false;
    }

    bool left=isidentical(r1->left,r2->left);
    bool right=isidentical(r1->right,r2->right);

    bool value=r1->data==r2->data;

    if(left && right && value){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    Node*r1=new Node(1);
    r1->left=new Node(2);
    r1->right=new Node(3);
    r1->left->left=new Node(4);
    r1->left->right=new Node(5);

    Node*r2=new Node(1);
    r2->left=new Node(2);
    r2->right=new Node(3);
    r2->left->left=new Node(4);
    r2->left->right=new Node(5);

    if(isidentical(r1,r2)){
        cout<<"trees are identical"<<endl;
    }
    else{
        cout<<"trees are not identical"<<endl;
    }

    return 0;
}