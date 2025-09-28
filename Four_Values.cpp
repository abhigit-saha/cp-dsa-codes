#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

signed main()
{
    //     int t;
    //     cin >> t;
    //     while(t--) {
    int n, x;
    cin >> n >> x;
    map<int, int> sum;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (sum[x - arr[i] - arr[j]])
            {

                cout << "YES" << endl;

                return 0;
            }
        }
        for (int k = i + 1; k < n; k++)
        {
            sum[arr[k] + arr[i]] = 1;
        }
    }
    cout << "NO" << endl;

    return 0;
}