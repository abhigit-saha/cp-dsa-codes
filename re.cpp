#include <bits/stdc++.h>

using namespace std;

using lli = long long;
#define endl "\n";
void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        int el;
        cin >> el;
        arr[i] = {el, i};
    }
    sort(arr.begin(), arr.end());
    vector<int> arr1, arr2;
    lli sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            arr1.push_back(arr[i].second);
            sum1 += arr[i].first;
        }
        else
        {
            arr2.push_back(arr[i].second);
            sum2 += arr[i].first;
        }
    }

    sort(arr1.begin(), arr1.end(), [arr](int a, int b)
         { return arr[a].second < arr[b].second; });
    sort(arr2.begin(), arr2.end(), [arr](int a, int b)
         { return arr[a].second < arr[b].second; });

    int remFrom1 = -1;
    int remFrom2 = -1;
    if (abs(sum1 - sum2) > arr[n - 1].second * 1LL)
    {
        for (int i = 0; i < min(arr1.size(), arr2.size()); i++)
        {
            if (sum1 > sum2)
            {
                if (abs(sum1 - sum2 - 2 * arr[arr1[i]].first * 1LL) <= arr[n - 1].first)
                {
                    remFrom1 = arr[arr1[i]].first;
                    arr2.push_back(arr1[i]);
                    break;
                }
            }
            else if (sum1 < sum2)
            {
                if (abs(sum2 - sum1 - 2 * arr[arr2[i]].first * 1LL) <= arr[n - 1].first)
                {
                    remFrom2 = arr[arr2[i]].first;
                    arr1.push_back(arr2[i]);
                    break;
                }
            }
        }
    }

    cout << arr1.size() << endl;
    int count = 0;
    for (int i = 0; i < arr1.size(); i++)
    {
        if (arr[arr1[i]].first == remFrom1 && count < 1)
        {
            count++;
            continue;
        }
        cout << arr[arr1[i]].first << " ";
    }
    cout << endl;
    cout << arr2.size() << endl;
    for (int i = 0; i < arr2.size(); i++)
    {
        if (arr[arr2[i]].first == remFrom2 && count < 1)
        {
            count++;
            continue;
        }
        cout << arr[arr2[i]].first << " ";
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