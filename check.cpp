#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int count = 0;
        vector<int> ans;
        int start = 0;
        int end = n - 1;
        if (n % 2 == 0)
        {
            while (count <= 300)
            {
                if (start > end)
                    break;
                if (s[start] == s[end])
                {
                    if (s[start] == '1')
                    {
                        s = s.substr(0, start) + "01" + s.substr(start, end + 1);
                        ans.push_back(start);
                    }
                    else
                    {
                        s = s.substr(0, end + 1) + "01" + s.substr(end + 1, s.size() + 1);
                        ans.push_back(end + 1);
                    }
                    count++;
                }
                start++;
                end = s.size() - start - 1;
            }
            if (start < end)
                cout << -1 << endl;
            else
            {
                cout << count << endl;
                for (int i = 0; i < ans.size(); i++)
                {
                    cout << ans[i] << ' ';
                }
                cout << endl;
            }
        }
        else
            cout << -1 << endl;
    }
}