#include <bits/stdc++.h>

using namespace std;
#define int long long
#define endl "\n"

signed main()
{
    int n, m;
    cin >> n >> m;
    int arr[n + 2];
    arr[0] = -1;
    int pos[n + 2];
    pos[0] = -1;
    pos[n + 1] = 1e9;
    arr[n + 1] = 1e9;
    int rounds = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        pos[arr[i]] = i;
    }

    for (int i = 1; i <= n; i++)
        if (pos[i] < pos[i - 1])
            rounds++;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        if (a > b)
            swap(a, b);

        set<int> st;
        for (int i = arr[a] - 1; i <= arr[a] + 1; i++)
        {
            if (i > 0 && i <= n)
                st.insert(i);
        }
        for (int j = arr[b] - 1; j <= arr[b] + 1; j++)
        {
            if (j > 0 && j <= n)
                st.insert(j);
        }

        for (auto el : st)
        {
            if (el > 0 && pos[el] < pos[el - 1])
                rounds--;
        }
        swap(pos[arr[a]], pos[arr[b]]);
        swap(arr[a], arr[b]);

        for (auto el : st)
        {
            if (el > 0 && pos[el] < pos[el - 1])
                rounds++;
        }
        cout << rounds << endl;
    }
}