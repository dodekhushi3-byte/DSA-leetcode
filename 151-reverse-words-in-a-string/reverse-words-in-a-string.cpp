
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        reverse(s.begin(), s.end());

        int l = 0, r = 0, i = 0;

        while (i < n) {

            while (i < n && s[i] == ' ')
                i++;

            if (i >= n) break;

            if (r > 0)
                s[r++] = ' ';

            l = r;

            while (i < n && s[i] != ' ')
                s[r++] = s[i++];

            reverse(s.begin() + l, s.begin() + r);
        }

        s.resize(r);
        return s;
    }
};
