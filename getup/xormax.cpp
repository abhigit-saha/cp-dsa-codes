#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

struct node
{
    node *child[2];
    int cnt;
    node()
    {
        child[1] = NULL;
        child[0] = NULL;
        cnt = 0;
    }
};
struct trie
{
    node *root;
    trie()
    {
        root = new node;
    }
    void insert(int n)
    {
        node *cur = root;
        for (int i = 31; i >= 0; i--)
        {
            int x = (n & (1 << i)) ? 1 : 0;
            if (cur->child[x] == NULL)
            {
                cur->child[x] = new node;
            }

            cur = cur->child[x];
            cur->cnt++;
        }
    }

    void remove(int n)
    {
        node *cur = root;
        for (int i = 31; i >= 0; i--)
        {
            int x = (n & (1 << i)) ? 1 : 0;
            if (cur->child[x] == NULL)
            {
                cur->child[x] = new node;
            }

            cur = cur->child[x];
            cur->cnt--;
        }
    }

    int query(int n)
    {
        node *cur = root;
        int ans = 0;
        for (int i = 31; i >= 0; i--)
        {
            int x = (n & (1 << i)) ? 1 : 0;
            if (cur->child[0] == NULL && cur->child[1] == NULL)
                break;
            if (cur->child[1 ^ x] != NULL && cur->child[1 ^ x]->cnt != 0)
            {
                cur = cur->child[1 ^ x];
                ans ^= (1 << i);
            }
            else
            {
                cur = cur->child[x];
            }
        }

        return ans;
    }
};
signed main()
{
    int q;
    cin >> q;
    trie tt;
    tt.insert(0);
    while (q--)
    {
        char t;
        cin >> t;
        int x;
        cin >> x;
        if (t == '+')
        {
            tt.insert(x);
        }
        if (t == '-')
        {
            tt.remove(x);
        }
        if (t == '?')
        {
            cout << tt.query(x) << endl;
        }
    }
}