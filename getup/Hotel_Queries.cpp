#include <bits/stdc++.h>
using namespace std;
int arr[1001000];
int t[4004000];
int allot[1001000];
int sizes[1001000];
void build(int index, int l, int r)
{
    if (l == r)
    {
        t[index] = arr[l];
        return;
    }

    int mid = (l + r) / 2;

    build(2 * index, l, mid);
    build(2 * index + 1, mid + 1, r);
    t[index] = max(t[2 * index], t[2 * index + 1]);
}
void query(int index, int l, int r, int grp)
{
    if (t[index] < sizes[grp] || allot[grp] != -1)
        return;

    if (l == r)
    {
        allot[grp] = l;
        t[index] -= sizes[grp];
        return;
    }

    int mid = (l + r) / 2;
    query(2 * index, l, mid, grp);
    query(2 * index + 1, mid + 1, r, grp);
    t[index] = max(t[2 * index], t[2 * index + 1]);
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int j = 0; j < m; j++)
    {
        cin >> sizes[j];
    }
    build(1, 0, n - 1);
    for (int i = 0; i < m; i++)
        allot[i] = -1;
    for (int i = 0; i < m; i++)
    {
        query(1, 0, n - 1, i);
    }
    for (int i = 0; i < m; i++)
    {
        cout << allot[i] + 1 << " ";
    }
    cout << endl;
}