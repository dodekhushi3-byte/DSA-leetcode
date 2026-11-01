class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int cnt = 0; 
        int maximum = 0;
        while(i < n){
            if(nums[i] == 1){
                cnt++;
            } else{
                cnt = 0;
            }
            maximum = max(cnt, maximum);
            i++;
        }
        return maximum;
    }
};