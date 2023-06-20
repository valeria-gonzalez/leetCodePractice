class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int sz = nums.size();
        vector<int>cpy = nums;
        for(int i = 0; i < sz; i++){
            int pos = (i + k) % sz;
            nums[pos] = cpy[i];
        }
    }
};

// best
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};