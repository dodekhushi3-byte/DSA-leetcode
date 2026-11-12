class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        int i = 0;
        int n = s.size();
        string ans = "";
        while (i < n) {
            if (st.empty() || st.top() != s[i]) {
                st.push(s[i]);
            } else {
                st.pop();
            }
            i++;
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans; 
    }
};