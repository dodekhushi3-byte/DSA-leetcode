class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.size();
        int sum = 0;
        for(int i = 0; i<n; i++){
            char ch = columnTitle[i];
            int val = ch - 'A' + 1;
            sum = sum*26 + val;
        }
        return sum;
    }
};