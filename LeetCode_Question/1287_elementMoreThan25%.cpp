class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        
        int n = arr.size();

        unordered_map<int, int> mpp;
        
        for(int i = 0; i < n; i++)
        {
            mpp[arr[i]]++;
        }

        vector<int> ans;

        for(auto i : mpp)
        {
            if(i.second > n/4){
                return i.first;
            }
        }
        return -1;
    }
};