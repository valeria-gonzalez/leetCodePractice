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

// best
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