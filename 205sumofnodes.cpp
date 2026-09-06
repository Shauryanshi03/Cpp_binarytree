#include<iostream>
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

void solve(Node* root,int sum,int &maxsum,int len,int &maxlen){
    if(root==NULL){
        if(len>maxlen){
            maxlen=len;
            maxsum=sum;
        }
        else if(len==maxlen){
            maxsum=max(sum,maxsum);
        }
        return;
    }
    sum=sum+root->data;
    solve(root->left,sum,maxsum,len+1,maxlen);
    solve(root->right,sum,maxsum,len+1,maxlen);
}

int sumoflongestroute(Node *root){
    int len=0;
    int maxlen=0;

    int sum=0;
    int maxsum=INT_MIN;

    solve(root,sum,maxsum,len,maxlen);

    return maxsum;
}

int main(){

    Node*root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);

    cout<<"sum of lonest path : "<<sumoflongestroute(root);

    return 0;
}