#include<iostream>
#include<queue>
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

Node* createparentmapping(Node* root,int target,map<Node*,Node*> &nodetoparent){
    Node* res=NULL;
    queue<Node*> q;
    q.push(root);
    nodetoparent[root]=NULL;

    while(!q.empty()){
        Node* front=q.front();
        q.pop();

        if(front->data==target){
            res=front;
        }
        if(front->left){
            nodetoparent[front->left]=front;
            q.push(front->left);
        }
        if(front->right){
            nodetoparent[front->right]=front;
            q.push(front->right);
        }
    }
    return res;
}

int burntree(Node* root,map<Node*,Node*> &nodetoparent){
    map<Node*,bool>visited;
    queue<Node*> q;

    q.push(root);
    visited[root]=true;

    int ans=0;

    while(!q.empty()){

        bool flag=0;
        int size=q.size();
        for(int i=0;i<size;i++){
            Node* front=q.front();
            q.pop();

            if(front->left && !visited[front->left]){
                flag=1;
                q.push(front->left);
                visited[front->left]=1;
            }
            if(front->right && !visited[front->right]){
                flag=1;
                q.push(front->right);
                visited[front->right]=1;
            }
            if(nodetoparent[front] && !visited[nodetoparent[front]]){
                flag=1;
                q.push(nodetoparent[front]);
                visited[nodetoparent[front]]=1;
            }
        }
        if(flag==1){
            ans++;
        }
    }
    return ans;
}

int mintime(Node* root,int target){

    map<Node*,Node*> nodetoparent;
    Node* targetNode=createparentmapping(root,target,nodetoparent);

    int ans=burntree(targetNode,nodetoparent);

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

    int target=5;

    cout<<"Minimum time : "<<mintime(root,target)<<endl;;

    return 0;
}