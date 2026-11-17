class Solution {
public:
    string intToRoman(int num) {
        string result = "";
        int arr[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string arr2[] = {"M",  "CM", "D",  "CD", "C",  "XC", "L", "XL", "X",  "IX", "V","IV","I"};
        for (int i = 0; i < 13; i++) {
            while (num >= arr[i]) {
                    num = num - arr[i];
                    result += arr2[i];                
            }
           
        }
         return result;
    }
};