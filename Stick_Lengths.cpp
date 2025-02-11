#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

signed main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int l = 0, r = n - 1;

    int ans = 0;
    while (r > l)
    {
        ans += arr[r] - arr[l];
        r--;
        l++;
    }
    cout << ans << endl;
}