/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
*/

// this solution was all too much 
class Solution {
public:
    bool bsearch(int startpos, int search, int n, vector<int>& nums){
       int lo = startpos + 1, hi = n - 1;
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            if(nums[mid] == search) return true;
            if(nums[mid] > search) hi = mid - 1;
            else lo = mid + 1;
        }
        return false;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>copyNums = nums; // to maintain original order of nums
        sort(nums.begin(), nums.end());
        int size = nums.size();
        vector<int>ans;
        int a, b;
        for(int i = 0; i < size; i++){
            int search = target - nums[i];
            int pos = bsearch(i, search, size, nums);
            if(pos){
                a = nums[i];
                b = search;
                break;
            } 
        }

        // have to seartch for original position of num a and b
        for(int i = 0; i < size; i++){
            if(copyNums[i] == a){
                ans.push_back(i);
                break;
            }
        }
        
        for(int i = size - 1; i >= 0; i--){
            if(copyNums[i] == b){
                ans.push_back(i);
                break;
            }
        }
        
        return ans;
        
    }
};

// best
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        vector<int> res(2);
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            if(mp.find(target - nums[i]) != mp.end() && mp[target - nums[i]] != i) {
                res[0] = i;
                res[1] = mp[target - nums[i]];
                return res;
            }
            mp[nums[i]] = i; // interesting concept, one can fill a map as they go
        }

        return res;
    }
};
