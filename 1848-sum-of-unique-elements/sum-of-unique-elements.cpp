class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        vector<int> freq(101, 0);
        for(int num : nums){
            freq[num]++;
        }

        int ans = 0;
        for(int i=0; i<freq.size(); i++){
            if(freq[i] == 1){
                ans += i;
            }
        }
        return ans;
    }
};