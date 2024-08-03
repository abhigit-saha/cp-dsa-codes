#include <bits/stdc++.h>

using namespace std;

using lli = long long;

void solve()
{
    map<char, int> freq;
    map<char, set<char>> suiteToNum;
    int n;
    cin >> n;
    char trump;
    cin >> trump;
    for (int i = 0; i < 2 * n; i++)
    {
        string card;
        cin >> card;
        freq[card[1]]++;
        suiteToNum[card[1]].insert(card[0]);
    }
    vector<string> ans;
    // for (auto el : freq)
    // {
    //     cout << el.first << " " << el.second << endl;
    // }
    for (auto el : freq)
    {
        if (el.first != trump)
        {
            for (int i = 0; i < el.second / 2; i++)
            {

                string ans1 = string(1, *suiteToNum[el.first].begin()) + el.first;
                suiteToNum[el.first].erase(ans1[0]);
                string ans2 = string(1, *suiteToNum[el.first].begin()) + el.first;
                suiteToNum[el.first].erase(ans2[0]);
                ans.push_back(ans1);
                ans.push_back(ans2);
            }
            if (!suiteToNum[el.first].empty())
            {
                if (!suiteToNum[trump].empty())
                {
                    string ans1 = string(1, *suiteToNum[el.first].begin()) + el.first;
                    suiteToNum[el.first].erase(ans1[0]);
                    string ans2 = string(1, *suiteToNum[trump].begin()) + trump;
                    suiteToNum[trump].erase(ans2[0]);
                    ans.push_back(ans1);
                    ans.push_back(ans2);
                }
                else
                {
                    cout << "IMPOSSIBLE" << endl;
                    return;
                }
            }
        }
    }
    if (!suiteToNum[trump].empty())
    {
        int size = suiteToNum[trump].size();
        for (int i = 0; i < size / 2; i++)
        {
            string ans1 = string(1, *suiteToNum[trump].begin()) + trump;
            suiteToNum[trump].erase(ans1[0]);
            string ans2 = string(1, *suiteToNum[trump].begin()) + trump;
            suiteToNum[trump].erase(ans2[0]);
            ans.push_back(ans1);
            ans.push_back(ans2);
        }
        // cout << "trump size" << suiteToNum[trump].size() << endl;
    }
    for (int i = 0; i < ans.size(); i += 2)
    {
        cout << ans[i] << " " << ans[i + 1] << endl;
    }
    return;
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