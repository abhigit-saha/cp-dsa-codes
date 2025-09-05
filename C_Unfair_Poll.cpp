#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

signed main()
{
    int t = 1;
    while (t--)
    {
        int n, m, k, x, y;
        cin >> n >> m >> k >> x >> y;
        x--;
        y--;
        int res = k / (n * m); 
        if(k%(n*m)!=0) { 
            cout<< res+1 << endl; 
            cout<< res << endl; 
        }else { 
            cout<< res << endl; 
            cout<< res<< endl; 
        } 
        if (res % 2 == 0)
        {

            if ((x * m + y > (k % (n * m))))
            {
                cout << res << endl;
            }
            else
            {
                if(x==0&&y==0&&res==0) { 
                    cout<< res+1 << endl; 
                }else if(x==0&&y==0) { 
                    cout<< res << endl; 
                }else { 
                    cout<< res+1 << endl; 
                }
            }
        }
        else
        {
            if ((x * m + y < (k % (n * m))))
            {
                cout << res << endl;
            }
            else
            {
                if(x==n-1&&y==m-1) { 
                    cout<< res << endl; 
                }else { 
                    cout<< res+1 << endl; 
                }
            }        
        } 
    }
    return 0;
}