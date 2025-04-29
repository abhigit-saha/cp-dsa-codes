#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    int curr = 1;
    for (int i = 2; i <= n; i += 2)
    {
        arr.push_back(i);
    }
    for (int i = 1; i <= n; i += 2)
    {
        arr.push_back(i);
    }
    int exists = true;
    for (int i = 1; i < n; i++)
    {
        if (abs(arr[i] - arr[i - 1]) == 1)
        {
            exists = false;
        }
    }
    if (!exists)
    {
        cout << "NO SOLUTION" << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}