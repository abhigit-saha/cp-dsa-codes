#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

int factorial[20];
int fact(int n)
{
    if (n == 0 || n == 1)
        return 1;
    if (factorial[n] != -1)
        return factorial[n];
    return factorial[n] = n * fact(n - 1);
}

// void precompute() {
//     for(int i = 1; fact(i)<=1e12; i++) {

//     }
// }

int n;
int cntrec;
int rec(int level, int mask)
{
    int sum = 0;
    int nmask = mask | (1 << level);
    int setcnt = 0;

    for (int i = 0; i < level; i++)
    {
        int set = (mask & (1 << i)) ? 1 : 0;
        // sum+=fact()
        if (set)
        {
            setcnt++;
            sum += fact(i + 1);
        }
    }
    if (sum > n)
    {
        return 1e9;
    }
    int ans = __builtin_popcountll(n - sum) + setcnt;
    if (level <= 14)
        ans = min({ans, rec(level + 1, nmask), rec(level + 1, mask)});
    return ans;
}

signed main()
{
    int t;
    cin >> t;
    memset(factorial, -1, sizeof(factorial));
    while (t--)
    {
        cin >> n;
        cout << rec(0, 0) << endl;
    }
    return 0;
}