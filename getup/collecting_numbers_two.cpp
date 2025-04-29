#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

signed main()
{
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    int arr[n + 1];
    for (int i = 1; i <= n; i++)
    {
        int el;
        cin >> el;
        arr[i] = el;
        mp[el] = i;
    }
    int ans = 1;
    for (int i = 2; i <= n; i++)
    {
        if (mp[i - 1] > mp[i])
        {
            ans++;
        }
    }
    while (m--)
    {
        int a, b;
        cin >> a >> b;

        if (a > b)
            swap(a, b);
        int l = arr[a], r = arr[b];

        int prevl = 0, prevr = 0, sucl = 0, sucr = 0;
        if (l != 1)
        {
            if (mp[l - 1] >= a && mp[l - 1] <= b)
            {
                prevl = 1;
            }
        }
        // todo: handle edge cases where next of l is prev of r or r itself

        if (r != 1)
        {
            if (mp[r - 1] >= a && mp[r - 1] <= b)
            {
                prevr = 1;
            }
        }
        if (l != n)
        {
            if (mp[l + 1] >= a && mp[l + 1] <= b)
            {
                sucl = 1;
            }
        }
        if (r != n)
        {
            if (mp[r + 1] >= a && mp[r + 1] <= b)
            {
                sucl = 1;
            }
        }
        mp[l] = b;
        mp[r] = a;
        cout << prevl << " " << prevr << " " << sucl << " " << sucr << endl;
        ans = ans - prevl + prevr + sucl - sucr;
        cout << ans << endl;
    }
}