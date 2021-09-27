#include <iostream>
#include <vector>

using namespace std;

class Solution {

    int profix = 0;
    int min = -1;
public:
    int maxProfit(vector<int>& prices) {
        for (int i = 0; i < prices.size(); ++i)
        {
            if (min == -1 || min > prices[i])
            {
                min = prices[i];
                continue;
            }

            if (min < prices[i])
            {
                profix += prices[i] - min;
                min = prices[i];
            }
        }

        return profix;
    }
};

string ArrayToString(const vector<int>& input)
{
    string output = "";
    char buffer[16] = "";

    for (int i = 0; i < input.size(); ++i)
    {
        if (i != 0)
            output += ", ";

        _itoa_s(input[i], buffer, 10);
        output += buffer;
    }

    return output;
}

int main()
{
    vector<int> prices = { 7,1,5,3,6,4 };

    Solution s;
    int profit = s.maxProfit(prices);

    string input = ArrayToString(prices);

    printf("prices:[%s]\n", input.c_str());
    printf("profig:%d\n", profit);
}
