class Solution {
public:
    char processStr(string s, long long k) {
        long long len = 0;

        // Compute final length
        for (char ch : s) {
            if ('a' <= ch && ch <= 'z') {
                len++;
            }
            else if (ch == '*') {
                if (len > 0) len--;
            }
            else if (ch == '#') {
                len *= 2;
            }
        }

        if (k >= len) return '.';

        // Work backwards
        for (int i = s.size() - 1; i >= 0; i--) {
            char ch = s[i];

            if ('a' <= ch && ch <= 'z') {
                if (k == len - 1)
                    return ch;
                len--;
            }
            else if (ch == '*') {
                len++;
            }
            else if (ch == '#') {
                len /= 2;
                k %= len;
            }
            else if (ch == '%') {
                k = len - 1 - k;
            }
        }

        return '.';
    }
};