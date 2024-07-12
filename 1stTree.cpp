#include <bits/stdc++.h>
#include <string>
using namespace std;
struct Node{
    int key;
    Node* Lchild;
    Node* Rsib;
};
Node* root=NULL;
Node* newnode(int n){
    Node* newNode= new Node;
    newNode->key=n;
    newNode->Lchild=NULL;
    newNode->Rsib=NULL;
    return newNode;
}
Node* find(Node* r, int n){
    if(r==NULL) return NULL;
    if(r->key==n) return r;
    Node* p=r->Lchild;
    while(p!=NULL){
        Node* q=find(p, n);
        if(q!=NULL) return q;
        p=p->Rsib;
    }
    return NULL;
}
void insert(int u, int v){
    Node* p=find(root, v);
    Node* q=find(root, u);
    if(p!=NULL){
        if(p->Lchild==NULL){
            p->Lchild=newnode(u);
        }
        else{
            if(q!=NULL) return;
            Node* q=p->Lchild;
            while(q->Rsib!=NULL){
                q=q->Rsib;
            }
            q->Rsib=newnode(u);
        }
    }
}
int height(Node* p){
    if(p==NULL) return 0;
    int maxh=0;
    Node* q=p->Lchild;
    while(q!=NULL){
        int h=height(q);
        if(h>maxh) maxh=h;
        q=q->Rsib;
    }
    return maxh+1;
}
int depth(Node* r, int v, int d){
    if(r==NULL) return -1;
    if(r->key==v) return d;
    Node* p=r->Lchild;
    while(p!=NULL){
        if(p->key==v) return d+1;
        int dv=depth(p, v, d+1);
        if(dv>0) return dv;
        p=p->Rsib;
    }
    return -1;
}
void PreOrder(Node* r){
    if(r==NULL) return;
    cout <<r->key <<' ';
    Node* p=r->Lchild;
    while(p!=NULL){
        PreOrder(p);
        p=p->Rsib;
    }
}
void InOrder(Node*r){
    if(r==NULL) return;
    Node* p=r->Lchild;
    InOrder(p);
    cout <<r->key <<' ';
    if(p!=NULL){
        p=p->Rsib;
    }
    while(p!=NULL){
        InOrder(p);
        p=p->Rsib;
    }
}
void PostOrder(Node* r){
    if(r==NULL) return;
    Node* p=r->Lchild;
    while(p!=NULL){
        PostOrder(p);
        p=p->Rsib;
    }
    cout <<r->key <<' ';
}
int countTree(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countTree(root->Lchild) + countTree(root->Rsib);
}
int countChild(Node* node) {
    if (node == NULL || node->Lchild == NULL) {
        return 0;
    }
    int res=1;
    Node* p = node->Lchild;
    while(p != NULL){
        res++;
        p = p->Rsib;
    }
    return res;
}
int countLeaves(Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->Lchild == NULL) {
        return 1;
    }
    int count = 0;
    Node* current = root->Lchild;
    while (current != NULL) {
        count += countLeaves(current);
        current = current->Rsib;
    }
    return count;
}
int main(){
    while(1){
        int u, v;
        string s;
        cin >>s;
        if(s=="*") break;
        else if(s=="MakeRoot"){
            cin >>u;
            root=newnode(u);
        }
        else if(s=="Insert"){
            cin >>u >>v;
            insert(u, v);
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
        else if(s=="Depth"){
            cin >>u;
            cout <<depth(root, u, 1) <<'\n';
        }
        else if(s=="Height"){
            cin >>u;
            cout <<height(find(root, u)) <<'\n';
        }
    }
    return 0;
}
