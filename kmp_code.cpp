#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int kmp[1001000];
signed main()
{
    string s;
    cin >> s;
    int n = s.length();

    // code for kmp
    int i = 0, j = -1;
    kmp[0] = -1;
    while (i < n)
    {
        while (j != -1 && kmp[j] != kmp[i])
            j = kmp[j];
        j++;
        i++;
        kmp[i] = j;
    }

    // note that this kmp array is 1 indexed
    for (int i = 0; i <= n; i++)
    {
        cout << kmp[i] << " ";
    }
    cout << endl;
}