/*
You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.
Increment the large integer by one and return the resulting array of digits.

Example 1:
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>ans;
        int acum = 0;
        int n = digits.size();
        if(n == 1 and digits[0] == 9) return {1, 0};
        else if(digits[n - 1] + 1 == 10){
            acum = 1;
            digits[n - 1] = 0;
            for(int i = n - 2; i >= 0; i--){
                if(digits[i] + acum == 10){
                    digits[i] = 0;
                    acum = 1;
                }
                else {
                    digits[i] += acum;
                    acum = 0;
                }
            }
            if(acum > 0){
                ans.push_back(1);
                for(auto i: digits) ans.push_back(i);
                return ans;
            } 
            return digits;
        } else {
            digits[n-1] += 1;
            return digits;
        }
    }
};

// better
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
   for (int i =n-1;i>=0;i--){
       if (digits[i]<9){
           digits[i]++;
           return digits;
       }else{
       digits[i]=0;}

   }
   digits.insert(digits.begin(),1);
   return digits;
        
    }
};

// best
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        int keep = 1;
        for (auto it = digits.rbegin(); it != digits.rend(); ++it)
        {
            *it += keep;
            if (*it == 10)
            {
                *it = 0;
                keep = 1;
            }
            else
            {
                keep = 0;
                break;
            }
        }
        if (keep)
        {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
