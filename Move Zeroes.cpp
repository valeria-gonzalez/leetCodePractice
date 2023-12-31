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

// Hint 2 (also best) O(n)
class Solution {
public:
    void moveZeroes(vector<int>& nums) { 
        // fast is equivalent to start and slow to end
        int fast = 0, slow = 0;
        for(; fast < nums.size(); fast++){
            // put all positive numbers at the front, fast also maintains their order
            if(nums[fast]){
                nums[slow++] = nums[fast];
                //slow will save the first position from which we need
                // to fill the array with zeroes, since all zeroes, order is indistinct
            }
        }
        
        for(; slow < nums.size(); slow++){
            nums[slow] = 0;
        }
    }
};
