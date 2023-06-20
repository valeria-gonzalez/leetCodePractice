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