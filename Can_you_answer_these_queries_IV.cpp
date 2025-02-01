#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int sp[1001000];
void precompute()
{
    memset(sp, -1, sizeof(sp));
    for (int i = 2; i * i <= 1001000; i++)
    {
        if (sp[i] == -1)
            continue;
        for (int j = i; j <= 1001000; j += i)
        {
            sp[j] = i;
        }
    }
}

int arr[1001000];
int t[4004000];
void build(int id, int l, int r)
{
    if (l == r)
    {
        t[id] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    t[id] = max(t[2 * id], t[2 * id + 1]);
}

void update(int id, int l, int r, ) signed main()
{
}