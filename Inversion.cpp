#include <bits/stdc++.h>
using namespace std;
const int modulo = 1e9 + 7;

void merge(vector<int> &A, int &res, int L, int mid, int R)
{
    const int subLeft = mid - L + 1, subRight = R - mid;
    int sub1_index = 0, sub2_index = 0, merged_index = L;
    vector<int> left(subLeft), right(subRight);
    for (int i = 0; i < subLeft; i++)
    {
        left[i] = A[L + i];
    }
    for (int i = 0; i < subRight; i++)
    {
        right[i] = A[mid + 1 + i];
    }
    while (sub1_index < subLeft && sub2_index < subRight)
    {
        if (left[sub1_index] <= right[sub2_index])
        {
            A[merged_index] = left[sub1_index];
            sub1_index++;
        }
        else
        {
            A[merged_index] = right[sub2_index];
            sub2_index++;
            res = (res + subLeft - sub1_index) % modulo;
        }
        merged_index++;
    }
    while (sub1_index < subLeft)
    {
        A[merged_index] = left[sub1_index];
        merged_index++;
        sub1_index++;
    }
    while (sub2_index < subRight)
    {
        A[merged_index] = right[sub2_index];
        merged_index++;
        sub2_index++;
    }
}

void mergeSort(vector<int> &A, int &res, int L, int R)
{
    if (L >= R)
    {
        return;
    }
    int mid = (L + R) / 2;
    mergeSort(A, res, L, mid);
    mergeSort(A, res, mid + 1, R);
    merge(A, res, L, mid, R);
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    int res = 0;
    mergeSort(A, res, 0, n - 1);
    cout << res;
}