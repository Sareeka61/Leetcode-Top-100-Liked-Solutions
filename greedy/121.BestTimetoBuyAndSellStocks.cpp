// You are given an array prices where prices[i] is the price of a given stock on the ith day.

//     You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

//     Return the maximum profit you can achieve from this transaction.If you cannot achieve any profit,
//     return 0

// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() <= 1)
        {
            return 0;
        }

        int minPrice = prices[0];
        int maxProfit = 0;

        for (size_t i = 1; i < prices.size(); i++)
        {
            minPrice = std::min(minPrice, prices[i]);
            maxProfit = std::max(maxProfit, prices[i] - minPrice);
        }

        return maxProfit;
    }
};
