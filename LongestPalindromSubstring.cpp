#include <bits/stdc++.h>
#include <string>
using namespace std;

bool checkPalindrome(string s)
{
    int n = s.length();
    int low = 0, high = n - 1;
    while (low < high)
    {
        if (s[low] == s[high])
        {
            low++;
            high--;
        }
        else
            return false;
    }
    return true;
}

string palindromeSubstring(string s)
{
    int n = s.length();
    int start = 0, maxlen = 1;
    vector<vector<bool>> V(n, vector<bool>(n, 0));
    for (int i = 0; i < n; i++)
    {
        V[i][i] = 1;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            V[i][i + 1] = 1;
            start = i;
            maxlen = 2;
        }
    }
    for (int l = 3; l <= n; l++)
    {
        for (int i = 0; i < n; i++)
        {
            int j = i + l - 1;
            if (j < n)
            {
                if (s[i] == s[j] && V[i + 1][j - 1])
                {
                    V[i][j] = 1;
                    if (l > maxlen)
                    {
                        maxlen = l;
                        start = i;
                    }
                }
            }
        }
    }
    return s.substr(start, maxlen);
}

int main()
{
    string s;
    cin >> s;
    cout << palindromeSubstring(s);
}