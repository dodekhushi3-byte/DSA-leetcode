class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool> present(26, false);
        for(char ch : sentence){
            present[ch - 'a'] = true;
        }
        for(int i = 0; i< 26; i++){
            if(present[i] == false){
                return false;
            }
        }
        return true;
    }
};