#include<iostream>
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

void createmapping(int in[],map<int,int> &nodetoindex,int n){
    for(int i=0;i<n;i++){
        nodetoindex[in[i]]=i;
    }
}

Node* solve(int in[],int pre[], int &index,int inorderstart,int inorderend,int n,map<int,int> &nodetoindex){
    if(index>=n || inorderstart>inorderend){
        return NULL;
    }

    int element=pre[index++];
    Node* root=new Node(element);
    int position=nodetoindex[element];

    root->left=solve(in,pre,index,inorderstart,position-1,n,nodetoindex);
    root->right=solve(in,pre,index,position+1,inorderend,n,nodetoindex);

    return root;
}

Node* buildtree(int in[],int pre[],int n){
    int preorderindex=0;
    map<int,int> nodetoindex;
    createmapping(in,nodetoindex,n);
    Node* ans=solve(in,pre,preorderindex,0,n-1,n,nodetoindex);
    return ans;
}

void postorder(Node* root){
    if(root==NULL)
    return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main(){
    int inorder[]={4,2,5,1,6,3,7};
    int preorder[]={1,2,4,5,3,6,7};

    int n=7;
    int index=0;

    Node* root1=buildtree(inorder,preorder,n);

    cout<<"Root : "<<root1->data<<endl;

    Node* root2=buildtree(inorder,preorder,n);
    postorder(root2);

    return 0;
}