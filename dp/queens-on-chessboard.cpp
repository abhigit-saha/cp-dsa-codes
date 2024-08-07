#include <bits/stdc++.h>

using namespace std;

using lli = long long;
#define endl "\n";

int queens[100100], occ[8][8];
int check(int row, int col)
{
    if (occ[row][col] == 1)
    {
        return 0;
    }
    for (int prow = 0; prow < row; prow++)
    {
        int pcol = queens[prow];
        if (col == pcol || abs(prow - row) == abs(pcol - col))
        {
            return 0;
        }
    }
    return 1;
}
int rec(int row)
{
    if (row == 8)
    {
        return 1;
    }
    int ans = 0;
    for (int col = 0; col < 8; col++)
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
    memset(occ, 0, sizeof(occ));
    memset(queens, -1, sizeof(queens));
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            char el;
            cin >> el;
            if (el == '*')
            {
                occ[i][j] = 1;
            }
        }
    }
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