// question: return the array such that arr[i] represents the height of the tree if you root at i
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

vector<int> g[1001000];
int dpin[1001000], dpout[1001000];
void dfsin(int node, int par)
{
    dpin[node] = 0;
    for (auto ch : g[node])
    {
        if (ch != par)
        {
            dfsin(ch, node);
            dpin[node] = max(dpin[ch] + 1, dpin[node]);
        }
    }
}
// since we know all the required info for the child at the parent itself, we pass it to the child
void dfsout(int node, int par, int outval)
{
    dpout[node] = outval;
    int max1 = -1, max2 = -1;
    for (auto ch : g[node])
    {
        if (ch != par)
        {
            if (dpin[ch] >= max1)
            {
                max2 = max1;
                max1 = dpin[ch];
            }
            else if (dpin[ch] > max2)
            {
                max2 = dpin[ch];
            }
        }
    }
    int child_dpout = 0;
    for (auto ch : g[node])
    {
        if (ch != par)
        {
            if (dpin[ch] == max1)
                child_dpout = max(dpout[par] + 1, max2 + 2);
            else
                child_dpout = max(dpout[par] + 1, max1 + 2);

            dfsout(ch, node, child_dpout);
        }
    }
}

signed main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfsin(1, 0);
    dfsout(1, 0, 0);

    for (int i = 1; i <= n; i++)
    {
        cout << max(dpin[i], dpout[i]) << endl;
    }
}