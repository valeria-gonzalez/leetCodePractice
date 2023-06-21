/*
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
*/

// is also best
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int n = nums1.size(), m = nums2.size();
        int i = 0, j = 0;
        vector<int>ans;
        
        while(i < n and j < m){
            if(nums1[i] < nums2[j]) i++;
            else if(nums1[i] > nums2[j]) j++;
            else{
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        return ans;   
    }
};
