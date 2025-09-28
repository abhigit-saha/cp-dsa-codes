#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
string comp;
void rev(map<string, int> &r, string s, int k)
{
    if (k == 0)
    {
        r[s] = 1;
        return;
    }
    int n = s.size();
    string nstr = s;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = i; k <= j; k++)
                nstr[k] = s[j + (i - k)];
            rev(r, nstr, k - 1);
            nstr = s;
        }
    }
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, T;
        cin >> S >> T;

        map<string, int> rev1, rev2;
        rev(rev1, S, 2);
        rev(rev2, T, 2);

        bool possible = false;
        for (auto el : rev1)
        {

            if (rev2.find(el.first) != rev2.end())
            {
                possible = true;
                break;
            }
        }

        cout << (possible ? "YES" : "NO") << endl;
    }
    return 0;
}