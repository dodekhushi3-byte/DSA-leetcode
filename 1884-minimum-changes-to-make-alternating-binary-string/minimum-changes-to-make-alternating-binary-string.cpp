class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int str_0 = 0;  //01010101
        int str_1 = 0;  //10101010
        for(int i = 0; i<n; i++){
            if(i%2 == 0){
                if(s[i] == '0'){
                    str_1++;
                } else{
                    str_0++;
                }
            } else{
                if(s[i] == '0'){
                    str_0++;
                } else{
                    str_1++;
                }
            }
        }
        return min(str_1, str_0);
    }
};