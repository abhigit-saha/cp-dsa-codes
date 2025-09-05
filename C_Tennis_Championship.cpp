#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

vector<int> fib;

int f(int num)
{
    if (fib[num] != -1)
        return fib[num];
    if (num == 0)
        return 1;
    if (num == 1)
        return 2;
    return fib[num] = f(num - 1) + f(num - 2);
}
signed main()
{
    int t = 1;
    while (t--)
    {
        int n;
        cin >> n;

        int lim = 1e5;
        fib.clear();
        fib.resize(lim, -1);

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (f(i) <= n)
                ans = i;
            else
                break;
        }
        cout << ans << endl;
    }
    return 0;
}