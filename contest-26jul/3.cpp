#include <bits/stdc++.h>
using namespace std;

using lli = long long;

void solve()
{
    string a, b;
    int n, q;
    cin >> n >> q;
    cin >> a >> b;

    vector<map<char, int>> freq_a(n + 1), freq_b(n + 1);

    for (int i = 1; i <= n; i++)
    {
        freq_a[i] = freq_a[i - 1];
        freq_b[i] = freq_b[i - 1];
        freq_a[i][a[i - 1]]++;
        freq_b[i][b[i - 1]]++;
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;

        int operations = 0;
        unordered_map<char, int> diff;

        for (char c = 'a'; c <= 'z'; c++)
        {
            int count_a = freq_a[r][c] - freq_a[l - 1][c];
            int count_b = freq_b[r][c] - freq_b[l - 1][c];
            diff[c] = count_b - count_a;
            operations += abs(diff[c]);
        }

        cout << operations / 2 << "\n";
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}