#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

signed main()
{
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; t++)
    {
        cout << "Test case #" << tc << endl;
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> kmp(n + 1);
        int i = 0, j = -1;
        kmp[0] = -1;
        while (i < n)
        {
            cout << i << " " << j << endl;
            while (j != -1 && s[j] != s[i])
                j = kmp[j];
            i++;
            j++;
            kmp[i] = j;
        }
        for (int i = 0; i <= n; i++)
            cout << kmp[i] << " ";
        cout << endl;
    }
}