#include <bits/stdc++.h>
#include <array>
using namespace std;
void selection_sort(int A[], int n){
    for(int i=0; i<n-1; i++){
        int m=i;
        for(int j=i+1; j<n; j++){
            if(A[j]<A[m]){
                m=j;
            }
        }
        if(m!=i){
            swap(A[i], A[m]);
        }
    }
}
void insertion_sort(int A[], int n){
    for(int i=1; i<n; i++){
        int temp=A[i];
        int j=i-1;
        while(j>=0 && A[j]>temp){
                A[j+1]=A[j];
                j--;
        }
        A[j+1]=temp;
    }
}
void bubble_sort(int A[], int n){
    bool swappy=true;
    while(swappy==true){
        swappy=false;
        for(int i=0; i<n-1; i++){
            if(A[i]>A[i+1]){
                swap(A[i], A[i+1]);
                swappy=true;
            }
        }
    }
}
void merge(int A[], int left, int mid, int right){
    int const sub1=mid-left+1, sub2=right-mid;
    int leftarr[sub1], rightarr[sub2];
    for(int i=0; i<sub1; i++){
        leftarr[i]=A[left+i];
    }
    for(int i=0; i<sub2; i++){
        rightarr[i]=A[mid+1+i];
    }
    int sub1_index=0, sub2_index=0, merged_index=left;
    while(sub1_index<sub1 && sub2_index<sub2){
        if(leftarr[sub1_index]<=rightarr[sub2_index]){
            A[merged_index]=leftarr[sub1_index];
            sub1_index++;
        }
        else{
            A[merged_index]=rightarr[sub2_index];
            sub2_index++;
        }
        merged_index++;
    }
    while(sub1_index<sub1){
        A[merged_index]=leftarr[sub1_index];
        merged_index++;
        sub1_index++;
    }
    while(sub2_index<sub2){
        A[merged_index]=rightarr[sub2_index];
        merged_index++;
        sub2_index++;
    }
    delete[] leftarr;
    delete[] rightarr;
}
void merge_sort(int A[], int L, int R){
    if(L>=R){
        return;
    }
    int mid=(L+R)/2;
    merge_sort(A, L, mid);
    merge_sort(A, mid+1, R);
    merge(A, L, mid, R);
}
int partition(int A[], int L, int R){
    int pivot=A[R];
    int i=L-1;
    for(int j=L; j<=R; j++){
        if(A[j]<pivot){
            i++;
            swap(A[j],A[i]);
        }
    }
    swap(A[i+1],A[R]);
    return i+1;
}
void quick_sort(int A[], int L, int R){
    if(L<R){
        int pivot=partition(A, L, R);
        quick_sort(A, L, pivot-1);
        quick_sort(A, pivot+1, R);
    }
}
void heapify(int A[], int n, int i){
    int max=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && A[l]>A[max]){
        max=l;
    }
    if(r<n && A[r]>A[max]){
        max=r;
    }
    if(max!=i){
        swap(A[i], A[max]);
        heapify(A, n, max);
    }
}
void heap_sort(int A[], int n){
    for(int i=n/2-1; i>=0; i--){
        heapify(A, n, i);
    }
    for(int j=n-1; j>0; j--){
        swap(A[0], A[j]);
        heapify(A, j, 0);
    }
}
int main(){
    int n;
    cin >>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >>a[i];
    }
    //1_sort(a, 0, n-1);
    //2_sort(a, n);
    for(int i=0; i<n; i++){
        cout <<a[i] <<' ';
    }
    return 0;
}