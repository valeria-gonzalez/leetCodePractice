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
