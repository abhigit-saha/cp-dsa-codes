class Solution
{
public:
    int maximum69Number(int num)
    {
        std::string strNum = std::to_string(num);
        char *numArr = &strNum[0]; // Get pointer to the first character
        int n = strNum.size();     // Get the size of the string
        for (int i = 0; i < n; i++)
        {
            if (numArr[i] == '6')
            {
                numArr[i] = '9';
                break;
            }
        }
        std::string strValue(numArr); // Convert the modified char array back to string
        return std::stoi(strValue);   // Convert the string to integer
    }
};