#include <iostream>
#include <vector>

using lli = long long;

void solve()
{
    int n, q;
    std::cin >> n >> q;
    std::vector<int> arr(n);
    int lastTime = 0;

    while (q--)
    {
        int t, k, d;
        std::cin >> t >> k >> d;

        int l = 0, r = 0;
        lli ans = 0;

        for (int i = 0; i < n; ++i)
        {
            if (arr[i] > 0)
            {
                arr[i] = std::max(0, arr[i] - (t - lastTime));
            }

            if (arr[i] == 0)
            {
                ++r;
                if (r - l == k)
                {
                    for (int j = l; j < r; ++j)
                    {
                        ans += j + 1;
                    }
                    break;
                }
            }
            else
            {
                l = r = i + 1;
            }
        }

        if (ans == 0)
        {
            std::cout << -1 << std::endl;
        }
        else
        {
            std::cout << ans << std::endl;
            for (int i = l; i < r; ++i)
            {
                arr[i] = d;
            }
        }

        lastTime = t;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    solve();
    return 0;
}