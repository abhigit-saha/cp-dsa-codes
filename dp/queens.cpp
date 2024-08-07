#include <bits/stdc++.h>

using namespace std;

using lli = long long;
#define endl "\n";
int n;
int queens[20]; // array storing col of queens at index i.

bool check(int row, int col)
{
    for (int prow = 0; prow < row; prow++)
    {
        int pcol = queens[prow];
        if (pcol == col || abs(row - prow) == abs(col - pcol))
        {
            return false;
        }
    }
    return true;
}
int rec(int row) // returns the number of ways to place queens from row...n-1;
{
    // pruning

    // base case
    if (row == n)
    {
        return 1;
    }
    int ans = 0;
    // checking for all possible cols in a given row.
    for (int col = 0; col < n; col++)
    {
        if (check(row, col))
        {
            // set the queens array
            queens[row] = col;
            // explore furthur adding to the answer.
            ans += rec(row + 1);
            // now that we have explored the combinations, we need to revert placing the queens.
            // it doesn't have any effect in this problem since we are only traversing each row once.
            queens[row] = -1;
        }
    }
    return ans;
}
void solve()
{
    cin >> n;
    memset(queens, -1, sizeof(queens));
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