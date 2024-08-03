class Solution
{
public:
    int minSetSize(vector<int> &arr)
    {
        priority_queue<int> maxHeap;
        int removedCount = 0;
        int ans = 0;
        unordered_map<int, int> freq;
        for (int i = 0; i < arr.size(); i++)
        {
            freq[arr[i]]++;
        }
        for (auto [key, val] : freq)
        {
            maxHeap.push(val);
        }

        for (int i = 0; i < maxHeap.size(); i++)
        {
            if (removedCount >= (arr.size()) / 2)
            {
                break;
            }
            removedCount += maxHeap.top();
            ans++;
            maxHeap.pop();
        }

        return ans;
    }
};