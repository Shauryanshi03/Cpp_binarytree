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

vector<int> verticalorder(Node* root){
    map<int, map<int,vector<int> > > nodes;
    queue<pair<Node*, pair<int,int> > >q;
    vector<int> ans;

    if(root==NULL)
    return ans;

    q.push(make_pair(root,make_pair(0,0)));

    while(!q.empty()){
        pair<Node*, pair<int,int> > temp=q.front();
        q.pop();
        Node* frontnode=temp.first;
        int hd=temp.second.first;
        int lvl=temp.second.second;
        nodes[hd][lvl].push_back(frontnode->data);

        if(frontnode->left!=NULL)
        q.push(make_pair(frontnode->left,make_pair(hd-1,lvl+1)));

        if(frontnode->right!=NULL)
        q.push(make_pair(frontnode->right,make_pair(hd+1,lvl+1)));
    }
    for(auto i: nodes){
        for(auto j: i.second){
            for(auto k: j.second){
                ans.push_back(k);
            }
        }
    }
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

    vector<int> ans=verticalorder(root);

    for(int x : ans)
    cout<<x<<" ";

    return 0;
}