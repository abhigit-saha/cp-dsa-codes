#include <bits/stdc++.h>

using namespace std;

using lli = long long;
int dir(char d)
{
    switch (d)
    {
    case 'R':
        return 1;
    case 'L':
        return -1;
    case 'U':
        return 1;
    case 'D':
        return -1;
    default:
        return 0;
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<char> arr(n);

    int x = 0, y = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int prevAns = 0;
    int ans = 0;
    int lastDis = 0;
    for (int i = 0; i < n; i++)
    {
        cout << "x: " << x << " y: " << y << " " << ans << endl;
        prevAns = ans;
        char prevX = x, prevY = y;
        if (arr[i] == 'L' || arr[i] == 'R')
        {
            if (abs(prevX) > abs(x + dir(arr[i])))
            {
                ans++;
                x = 0;
                y = 0;
            }
            x += dir(arr[i]);
        }
        if (arr[i] == 'U' || arr[i] == 'D')
        {
            if (abs(prevY) > abs(y + dir(arr[i])))
            {
                ans++;
                lastDis = i;
                x = 0;
                y = 0;
            }
            y += dir(arr[i]);
        }
    }
    if (prevAns == ans || n - 1 - lastDis == 0) // last turn didn't lead to a non-zig-zag condition
    {
        ans++;
    }
    cout << ans << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int t;cin>>t;while(t--)
    solve();
    return 0;
}