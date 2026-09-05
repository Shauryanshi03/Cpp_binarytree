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

vector<int> topview(Node* root){
    vector<int> ans;
    if(root==NULL)
    return ans;

    map<int,int> topnode;
    queue<pair<Node*,int> >q;

    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<Node*,int> temp=q.front();
        q.pop();

        Node* frontnode=temp.first;
        int hd=temp.second;

        if(topnode.find(hd)==topnode.end())
        topnode[hd]=frontnode->data;

        if(frontnode->left)
        q.push(make_pair(frontnode->left,hd-1));

        if(frontnode->right)
        q.push(make_pair(frontnode->right,hd+1));
    }
    for(auto i: topnode){
        ans.push_back(i.second);
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

    vector<int> ans=topview(root);

    for(int i : ans)
    cout<<i<<" ";

    return 0;
}