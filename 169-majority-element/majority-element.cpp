class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = 0;
        int freq = 0;
        int i = 0;
        while(i < nums.size()){
            if(freq == 0){
                ans = nums[i];
            }
            if(ans == nums[i]){
                freq++;
            }
            else{
                freq--;
            }
            i++;
        }
        return ans;
    }
};