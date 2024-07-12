#include <bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* next;
};
Node* head1;
bool check(Node** h, int n){
    bool ck=0;
    Node* z=*h;
    while(z!=NULL){
        if(z->val==n){
            ck=1;
            break;
        }
        z=z->next;
    }
    return ck;
}
void head_insert(Node** h, int i){
    Node* Newnode= new Node;
    Newnode->val=i;
    Newnode->next=*h;
    *h=Newnode;
}
void butt_insert(Node** h, int i){
    Node* temp=*h;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node* Newnode= new Node;
    Newnode->val=i;
    Newnode->next=NULL;
    temp->next=Newnode;
}
void insert_after(Node** h, int i, int n){
    Node* q=*h;
    Node* w= NULL;
    while(q!=NULL){
        if(q->val==n){
            w=q;
        }
        q=q->next;
    } 
    if(w!=NULL){
        Node* Newnode= new Node;
        Newnode->val=i;
        Newnode->next=w->next;
        w->next=Newnode;
    }
}
void insert_before(Node** h, int i, int n){
    Node* q=*h;
    Node* w= NULL;
    while(q!=NULL){
        Node* q1=q->next;
        if(q1->val=n){
            w=q;
        }
        q=q->next;
    }
    if(q==*h && q->val==n){
        head_insert(h, i);
    }
    else if(w!=NULL){
        Node* Newnode= new Node;
        Newnode->val=i;
        Newnode->next=w->next;
        w->next=Newnode;
    }
}
void remove(Node** h, int i){
    Node* q=*h;
    if(q==*h && q->val==i){
        *h=q->next;
    }
    else{
        while(q!=NULL){
            Node* q1=q->next;
            if(q1->val==i){
                q->next=q1->next;
                delete[] q1;
                break;
            }
        }
    }
}
void reverse(Node** h){
    int a[1001], c=0;
    Node* q=*h;
    while(q!=NULL){
        a[c]=q->val;
        c++;
        q=q->next;
    }
    q=*h;
    while(q!=NULL){
        q->val=a[c-1];
        c--; 
        q=q->next;
    }
}
int main(){
    int n; 
    cin >>n;
    if(n<=1000 && n>=1){
        int c=0;
        for(int i=0; i<n; i++){
            int a;
            cin >>a;
            if(i!=0){
                butt_insert(&head1, a);
            }
            else{
                head_insert(&head1, a);
            }
        }
        Node* p1=head1;
        char inp[50], al[10]="addlast", af[10]="addfirst", aa[10]="addafter", ab[10]="addbefore", rm[10]="remove", rv[10]="reverse", out[2]="#";  
        int n, p; 
        Node* q=head1;
        while(1){
            cin >>inp;
            bool ck=0;
            Node* z=head1;
            if(strcmp(inp, al)==0){
                cin >>n;
                ck=check(&head1, n);
                if(ck==1){
                    continue;
                }
                else{
                    butt_insert(&head1, n);
                }
            }
            else if(strcmp(inp, af)==0){
                cin >>n;
                ck=check(&head1, n);
                if(ck==1){
                    continue;
                }
                else{
                    head_insert(&head1, n);
                }
            }
            else if(strcmp(inp, aa)==0){
                cin >>n >>p;
                ck=check(&head1, n);
                if(ck==1){
                    continue;
                }
                else{
                    insert_after(&head1, n, p);
                }
            }
            else if(strcmp(inp, ab)==0){
                cin >>n >>p;
                ck=check(&head1, n);
                if(ck==1){
                    continue;
                }
                else{
                    insert_before(&head1, n, p);
                }
            }
            else if(strcmp(inp, rm)==0){
                cin >>n;
                remove(&head1, n);
            }
            else if(strcmp(inp, rv)==0){
            reverse(&head1);
            }
            else if(strcmp(inp, out)==0){
                break;
            }
        }
        while(p1!=NULL){
            cout <<p1->val <<' ';
            p1=p1->next;
        }
    }
    return 0;
}
