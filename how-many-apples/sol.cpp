class Solution
{
public:
    int maxNumberOfApples(vector<int> &weight)
    {
        int weightToCheck = 5000;
        int ans = 0;
        sort(weight.begin(), weight.end());
        for (int i = 0; i < weight.size(); i++)
        {
            if (weight[i] <= weightToCheck && weightToCheck >= 0)
            {
                ans += 1;
                weightToCheck -= weight[i];
            }
        }
        return ans;
    }
};