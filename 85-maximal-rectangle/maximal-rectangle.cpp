class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n);
        stack<int> st;

        // NSR
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if (st.empty())
                right[i] = n;
            else
                right[i] = st.top();

            st.push(i);
        }

        while (!st.empty()) {
            st.pop();
        }

        // NSL
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if (st.empty())
                left[i] = -1;
            else
                left[i] = st.top();

            st.push(i);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            int currans = heights[i] * width;
            ans = max(ans, currans);
        }

        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> heights(m,0);

        // for(int i = 0; i<n; i++){
        //     if(matrix[0][i] == '1'){
        //         heights[i] = 1;
        //     } else{
        //         heights[i] = 0;
        //     }
        // }

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(matrix[i][j] == '1'){
                    heights[j] ++;
                } else{
                    heights[j] = 0;
                }
            }
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        return maxArea;
    }
};