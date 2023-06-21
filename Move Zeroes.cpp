/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.
Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
*/

// Hint 1
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>cpy(nums.size());
        int last = nums.size() - 1;
        int start = 0;
       for(int i = 0; i < nums.size(); i++){
           if(nums[i] == 0){
               cpy[last] = nums[i]; last--;
           }
           else {
               cpy[start] = nums[i];
               start++;
           }
       }
        nums = cpy;
    }
};

// Hint 2 (also best)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int fast = 0, slow = 0;
        for(; fast < nums.size(); fast++){
            if(nums[fast]){
                nums[slow++] = nums[fast];
            }
        }
        
        for(; slow < nums.size(); slow++){
            nums[slow] = 0;
        }
    }
};
