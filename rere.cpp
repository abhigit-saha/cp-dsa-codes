#include <bits/stdc++.h>

using namespace std;

using lli = long long;

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int el;
        cin >> el;
        arr[i] = {el, i};
    }
    sort(arr.begin(), arr.end());
    vector<int> arr1, arr2;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 1)
        {
            arr1.push_back(arr[i].second);
        }
        else
        {
            arr2.push_back(arr[i].second);
        }
    }
    cout << arr1.size() << endl;
    for (int i = 0; i < arr1.size(); i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
    cout << arr2.size() << endl;
    for (int i = 0; i < arr2.size(); i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;
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