class Solution
{
public:
    static bool comp(vector<int> &v1, vector<int> &v2)
    {
        if (v1[1] > v2[1])
        {
            return true;
        }
        return false;
    }
    int maximumUnits(vector<vector<int>> &boxTypes, int &truckSize)
    {
        int ans = 0;

        sort(boxTypes.begin(), boxTypes.end(), comp);
        for (int i = 0; i < boxTypes.size(); i++)
        {
            if (boxTypes[i][0] < truckSize)
            {
                ans += boxTypes[i][0] * boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            }
            else
            {
                ans += boxTypes[i][1] * truckSize;
                break;
            }
        }

        return ans;
    }
};