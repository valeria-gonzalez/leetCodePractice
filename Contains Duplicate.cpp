/*Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
Example 1:

Input: nums = [1,2,3,1]
Output: true
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool>v;
        
        for(int i = 0; i < nums.size(); i++){
            if(v.count(nums[i]) != 0) return true;
            v[nums[i]] = true;
        }
        return false;
        
    }
};

// best solution
auto init = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 1; ++i){
            if(nums[i] == nums[i+1]){
                return true;
            };
        };
        return false;
    };
};
