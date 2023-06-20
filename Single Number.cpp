class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(auto i: nums){
           if(count(nums.begin(), nums.end(), i) == 1){
               ans = i; 
               break;
           }
        }
        return ans;
    }
};

// best
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int res = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            res = res^nums[i];
        }
        return res;
    }
};