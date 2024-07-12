#include <bits/stdc++.h>
#include <string>
using namespace std;
struct Node{
    int key;
    Node* lchild;
    Node* rchild;
};
Node* root=NULL;
Node* find(Node* r, int u){
    if(r==NULL) return NULL;
    if(r->key==u) return r;
    Node* rl=find(r->lchild, u);
    if(rl!=NULL) return rl;
    Node* rr=find(r->rchild, u);
    return rr;
}
Node* newnode(int u){
    Node* newNode= new Node;
    newNode->key=u;
    newNode->lchild=NULL;
    newNode->rchild=NULL;
    return newNode;
}
void addr(int u, int v){
    Node* p=find(root, v);
    Node* c=find(root, u);
    if(p==NULL || c!=NULL || p->rchild!=NULL) return;
    Node* n=newnode(u);
    p->rchild=n;
}
void addl(int u, int v){
    Node* p=find(root, v);
    Node* c=find(root, u);
    if(p==NULL || c!=NULL || p->lchild!=NULL) return;
    Node* n=newnode(u);
    p->lchild=n;
}
void PreOrder(Node* r){
    if(r==NULL) return;
    cout <<r->key <<' ';
    PreOrder(r->lchild);
    PreOrder(r->rchild);
}
void InOrder(Node* r){
    if(r==NULL) return;
    InOrder(r->lchild);
    cout <<r->key <<' ';
    InOrder(r->rchild);
}
void PostOrder(Node* r){
    if(r==NULL) return;
    PostOrder(r->lchild);
    PostOrder(r->rchild);
    cout <<r->key <<' ';
}
bool BST(Node* r, int min, int max){
    if(r==NULL) return 1;
    if(r->key<min || r->key>max) return 0;
    return (BST(r->lchild, min, r->key-1) && BST(r->rchild, r->key+1, max));
}
int count(Node* r){
    if(r==NULL) return 0;
    int i=1+count(r->lchild)+count(r->rchild);
    return i;
}
int sum(Node* r){
    if(r==NULL) return 0;
    int i=r->key+sum(r->lchild)+sum(r->rchild);
    return i;
}
int CountLeaves(Node* r){
    if(r==NULL) return 0;
    int s=0;
    if(r->rchild==NULL && r->lchild==NULL) s=1;
    else s=CountLeaves(r->lchild)+CountLeaves(r->rchild);
    return s;
}
void FindLeaves(Node* r){
    if(r!=NULL){
        if(r->lchild==NULL && r->rchild==NULL){
            cout <<r->key <<' ';
        }
        FindLeaves(r->lchild);
        FindLeaves(r->rchild);
    }
}
int height(Node* node){
    if (node == NULL)
        return 0;
    return 1 + max(height(node->lchild), height(node->rchild));
}
bool Balanced(Node* root){
    int lh, rh;
    if (root == NULL)
        return 1;
    lh = height(root->lchild);
    rh = height(root->rchild);
    if (abs(lh - rh) <= 1 && Balanced(root->lchild) && Balanced(root->rchild))
        return 1;
    return 0;
}
int main() {
    while(1){
        string s;
        cin >>s;
        int u, v;
        if(s=="*") break;
        else if(s=="MakeRoot"){
            cin >>u; 
            root=newnode(u);
        }
        else if(s=="AddRight"){
            cin >>u >>v;
            addr(u, v);
        }
        else if(s=="AddLeft"){
            cin >>u >>v;
            addl(u, v);
        }
        else if(s=="PreOrder"){
            PreOrder(root);
            cout <<'\n';
        }
        else if(s=="InOrder"){
            InOrder(root);
            cout <<'\n';
        }
        else if(s=="PostOrder"){
            PostOrder(root);
            cout <<'\n';
        }
        else if(s=="Count"){
            cout <<count(root);
            cout <<'\n';
        }
        else if(s=="Sum"){
            sum(root);
            cout <<'\n';
        }
        else if(s=="Height"){
            cin >>u;
            Node* p=find(root, u);
            if(p!=NULL) cout <<height(p) <<' ';
        }
        else if(s=="FindLeaves"){
            FindLeaves(root);
            cout <<'\n';
        }
    }
    cout <<BST(root, INT_MIN, INT_MAX) <<' ' <<sum(root);
    return 0;
}