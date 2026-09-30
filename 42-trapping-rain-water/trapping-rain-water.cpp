class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int n = height.size();
        int r = n - 1;
        int total = 0;
        int lmax = 0; 
        int rmax = 0;
        while(l < r){
            if(height[l] <= height[r]){
                if(lmax <  height[l]){
                    lmax = height[l];
                } else{
                    total += min(lmax, height[r]) - height[l];
                }
                l++;
            } else{
                if(rmax < height[r]){
                    rmax = height[r];
                } else{
                    total += min(rmax, height[l]) - height[r];
                }
               r--;
            }
        }
        return total;
    }
};