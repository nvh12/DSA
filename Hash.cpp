#include <bits/stdc++.h>
#include <string>
using namespace std;
struct Node{
    int key; 
    Node* next;
};
typedef Node* Hash_Table[10];
Hash_Table tab;
void start(Hash_Table &HT){
    for(int i=0; i<10; i++){
        HT[i]=NULL;
    }
}
void insert(Hash_Table &HT, int k){
    int i=k%10;
    Node *newNode= new Node{k, NULL};
    if(HT[i]==NULL){
        HT[i]=newNode;
    }
    else{
        Node* p=HT[i];
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=newNode;
    }
}
bool find(Hash_Table HT, int k){
    int i=k%10;
    Node *p=HT[i];
    while(p!=NULL && p->key!=k){
        p=p->next;
    }
    if(p==NULL){
        return 0;
    }
    return 1;
}
int main(){
    while(1){
        string i;
        cin >>i;
        if(i=="*") break;
        int k=stoi(i, 0, 10);
        insert(tab, k);
    }
    string a="find", b="insert";
    while(1){
        string inp;
        cin >>inp;
        if(inp=="***") break;
        else if(inp==a){
            int i;
            cin >>i;
            cout <<find(tab, i) <<'\n';
        }
        else if(inp==b){
            int i; 
            cin >>i;
            int r=find(tab, i);
            if(r){
                cout <<0 <<'\n';
            }
            else{
                insert(tab, i);
                cout <<1 <<'\n';
            }
        }
    }
    return 0;
}