#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
vector<int> palindromes;
int mod = 1e9 + 7;
void precompute()
{
    for (int i = 1; i <= 40000; i++)
    {
        int el = i;
        vector<int> digs;
        while (el)
        {
            int dig = el % 10;
            digs.push_back(dig);
            el /= 10;
        }

        int n = digs.size();
        int l = 0, r = n - 1;
        bool ispalindrome = true;
        while (l <= r)
        {
            if (digs[l] != digs[r])
            {
                ispalindrome = false;
                break;
            }
            l++;
            r--;
        }

        if (ispalindrome)
            palindromes.push_back(i);
    }
}

int dp[500][40001];
int rec(int num, int maxp)
{
    if(maxp<0) return 0; 
    if(maxp==0) return 1; 
    if (num < 0)
        return 0;
    if (num == 0)
        return 1;
    if (dp[maxp][num] != -1)
        return dp[maxp][num];
    int ans = 0;
    ans=((ans%mod)+(rec(num, maxp-1)%mod))%mod;
    ans=((ans%mod)+(rec(num-palindromes[maxp], maxp)%mod))%mod;

    return dp[maxp][num] = ans; 
}
signed main()
{
    int t;
    cin >> t;

    precompute();
    memset(dp, -1, sizeof(dp));
    while (t--)
    {
        int n;
        cin >> n;
        int maxp = palindromes.size()-1; 
        cout << rec(n, maxp) << endl;
        // for(int i = 20; i<30; i++) {
        //     cout<<palindromes[i] << " ";
        // }
        // cout<< endl;
        // cout<<palindromes.size() << endl;
    }
    return 0;
}