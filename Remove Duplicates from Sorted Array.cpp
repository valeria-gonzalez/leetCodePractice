// Runtime: beats 94.72%
// Memory: beats 90.85%
//7ms
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto it = unique(nums.begin(), nums.end());
        nums.resize(it-nums.begin());
        return nums.size();
    }
};

// best solution
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int distinctElements;
        int i = 0;
        int j = 1;

        while (j < nums.size()) {
            if (nums[i] != nums[j]) {
                nums[i+1] = nums[j];
                i++;
                j++;
            } else {
                j++;
            }
        }
        distinctElements = i+1;
        return distinctElements;
    }
};