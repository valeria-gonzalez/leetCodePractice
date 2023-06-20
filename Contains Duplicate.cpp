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