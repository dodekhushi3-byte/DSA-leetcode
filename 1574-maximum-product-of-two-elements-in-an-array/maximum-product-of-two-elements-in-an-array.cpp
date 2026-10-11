class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int first = INT_MIN;
        int second = INT_MIN;

        for(int i = 0;i<n; i++){
            if(nums[i] > first){
                second = first;
                first = nums[i];
            }
            else if(nums[i] > second){
                second = nums[i];
            }
        }
        return (first - 1) * (second - 1);
   
        // sort(nums.begin(),nums.end(),greater<int>());
        // int first = nums[0] - 1;
        // int second = nums[1] - 1;
        // return first * second;
    }
};