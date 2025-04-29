#include <bits/stdc++.h>
using namespace std;

struct node
{
    int child[26];
    node()
    {
        memset(child, -1, sizeof(child));
    }
};

struct trie
{
    vector<node> nodes;
    trie()
    {
        node rootnode;
        nodes.push_back(rootnode);
    }

    void insert(string s)
    {
        int cur_node_idx = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (nodes[cur_node_idx].child[s[i] - 'a'] == -1)
            {
                node new_node;
                nodes.push_back(new_node);
                nodes[cur_node_idx].child[s[i] - 'a'] = nodes.size() - 1;
            }
            cur_node_idx = nodes[cur_node_idx].child[s[i] - 'a'];
        }
    }

    int get_node_count()
    {
        return nodes.size();
    }
};

signed main()
{
    trie t;
    string s;
    cin >> s;
    t.insert(s);
    cout << t.get_node_count() - 1 << endl; //-1 since the first node is the root node.
}