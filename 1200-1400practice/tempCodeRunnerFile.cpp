for (auto el : freq)
    // {
    //     if (el.first != trump)
    //     {
    //         for (int i = 0; i < el.second / 2; i++)
    //         {
    //             string ans1 = string(1, *suiteToNum[el.first].begin()) + el.first;
    //             suiteToNum[el.first].erase(ans1[0]);
    //             string ans2 = string(1, *suiteToNum[el.first].begin()) + el.first;
    //             suiteToNum[el.first].erase(ans2[0]);
    //             cout << ans1 << " " << ans2 << " ";
    //         }
    //         if (!suiteToNum[el.first].empty())
    //         {
    //             if (!suiteToNum[trump].empty())
    //             {
    //                 string ans1 = string(1, *suiteToNum[el.first].begin()) + el.first;
    //                 suiteToNum[el.first].erase(ans1[0]);
    //                 string ans2 = string(1, *suiteToNum[trump].begin()) + trump;
    //                 suiteToNum[trump].erase(ans2[0]);
    //                 cout << ans1 << " " << ans2 << " ";
    //             }
    //             else
    //             {
    //                 cout << "IMPOSSIBLE" << endl;
    //                 return;
    //             }
    //         }
    //     }
    // }
    // if (!suiteToNum[trump].empty())
    // {
    //     for (int i = 0; i < suiteToNum[trump].size() / 2; i++)
    //     {
    //         string ans1 = string(1, *suiteToNum[trump].begin()) + trump;
    //         suiteToNum[trump].erase(ans1[0]);
    //         string ans2 = string(1, *suiteToNum[trump].begin()) + trump;
    //         suiteToNum[trump].erase(ans2[0]);
    //         cout << ans1 << " " << ans2 << " ";
    //     }
    // }
    // cout << endl;
    // return;