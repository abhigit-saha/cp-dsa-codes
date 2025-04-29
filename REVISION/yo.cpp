#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        stack<int> st;
        st.push(0);
        int lastGrt[n];
        lastGrt[0] = -1;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] >= arr[st.top()])
            {
                while (arr[st.top()] <= arr[i])
                {
                    st.pop();
                    if (st.empty())
                    {
                        break;
                    }
                }
            }
            if (st.empty())
            {
                lastGrt[i] = -1;
                st.push(i);
            }
            else
            {
                lastGrt[i] = st.top();
                st.push(i);
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << lastGrt[i] << " ";
        }
        cout << endl;
        while (q--)
        {
            int x, y;
            cin >> x >> y;

            if (lastGrt[y] == -1 || lastGrt[y] < x)
            {
                cout << "YES" << endl;
            }
            else if (lastGrt[y] >= x)
            {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}