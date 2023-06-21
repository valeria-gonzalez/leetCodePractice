/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
You must implement a solution with a linear runtime complexity and use only constant extra space.

Example 1:
Input: nums = [2,2,1]
Output: 1
*/
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
