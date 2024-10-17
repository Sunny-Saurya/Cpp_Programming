class Solution {
private:
    bool isPrime(int num) {
        if (num <= 1) return false;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int r = nums.size();
        int c = nums[0].size();
        vector<int> ans;
        vector<int> finali;

        // checkig primary diagonal
        for (int i = 0; i < r; i++) {
            ans.push_back(nums[i][i]);
        }

        // checking secondary or anti-diagonal

        for(int i = r -1; i >=0; i--)
         for (int i = 0; i < r; i++) {
            if (i != r - i - 1) { 
                ans.push_back(nums[i][r - i - 1]);
            }
        }

        for (int i = 0; i < ans.size(); i++) {
            if (isPrime(ans[i])) {
                finali.push_back(ans[i]);
            }
        }

        if(finali.empty()) return 0;

        int maxi = *max_element(finali.begin(), finali.end());
        return maxi;
    }
};
