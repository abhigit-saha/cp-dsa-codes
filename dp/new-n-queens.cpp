#include <bits/stdc++.h>

using namespace std;

using lli = long long;
#define endl "\n";

int n;
int queens[100100];
int check(int row, int col)
{

    for (int prow = 0; prow < row; prow++)
    {
        int pcol = queens[prow];
        if (col == pcol || abs(prow - row) == abs(pcol - col) || abs(row - prow) * abs(col - pcol) == 2)
        {
            return 0;
        }
    }
    return 1;
}
int rec(int row)
{
    if (row == n)
    {
        return 1;
    }
    int ans = 0;
    for (int col = 0; col < n; col++)
    {
        if (check(row, col))
        {

            queens[row] = col;
            ans += rec(row + 1);
            queens[row] = -1;
        }
    }

    return ans;
}
void solve()
{
    memset(queens, -1, sizeof(queens));
    cin >> n;
    cout << rec(0) << endl;
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