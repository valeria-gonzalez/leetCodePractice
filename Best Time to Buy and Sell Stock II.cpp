/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.
Find and return the maximum profit you can achieve.

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int lastMin = INT_MAX;
        for(auto price: prices){
            if(price - lastMin > 0){
                ans += price - lastMin;
                lastMin = price;
            } else {
                lastMin = min(lastMin, price);
            }
            
        }
        return ans;
    }
};

// best
class Solution {
public:
    int maxProfit(vector<int>& a) {
        
        int sum=0;
        for(int i=1;i<a.size();i++){
            int t=a[i]-a[i-1];
            if(t>0)
            sum+=t;
        }
        return sum;
    }
};
