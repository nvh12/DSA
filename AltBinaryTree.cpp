#include <iostream>
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
void InOrder(Node* r){
    if(r==NULL) return;
    InOrder(r->lchild);
    cout <<r->key <<' ';
    InOrder(r->rchild);
}
int main() {
    int n;
    cin >>n;
    int a[3*n];
    for(int i=0; i<3*n; i++){
        cin >>a[i];
    }
    root=newnode(a[0]);
    for(int i=1; i<3*n; i++){
        if(i%3==1 && a[i]!=-1){
            addr(a[i-1], a[i]);
        }
        else if(i%3==2 && a[i]!=-1){
            addl(a[i-2], a[i]);
        }
    }
    for(int i=0; i<n; i++){
        int a, b, c;
        cin >>a >>b >>c;
        if(i==0) root=newnode(a);
        if(b!=-1) addr(b, a);
        if(c!=-1) addl(c, a);
    }
    InOrder(root);
    return 0;
}
