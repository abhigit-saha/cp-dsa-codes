#include <bits/stdc++.h>
using namespace std;

struct node
{
    node *child[26];
    int prefix; // the number of strings starting from this set of chars.

    vector<string> wend;
    node()
    {
        prefix = 0;
        for (int i = 0; i < 26; i++)
        {
            child[i] = nullptr;
        }
    }
};

struct trie
{
    node *t; // root node;
    trie()
    {
        t = new node;
    }
};

void insert(string s)
{
    node *cur = new node;
    for (int i = 0; i < 26; i++)
    {
        cur->prefix++;
    }
}